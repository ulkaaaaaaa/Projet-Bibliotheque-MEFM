#include <time.h>
#include <string.h> 
#include "metier.h"

/* Calcule l'heure alaquelle le livre doit être rendu */
time_t calculerDateRetour(int role) {
    time_t actuelle = time(NULL); /* heure actuelle */
    
    /*  Si l'utilisateur n'est pas PROFESSEUR, on applique la regle etudiant par defauf pour eviter un bug*/
    if (role == PROFESSEUR) {
        return actuelle+180; /* ajoute 180 secondes (3 minutes) pour un prof */
    } else {
        return actuelle +120; /* ajoute 120 secondes(2 minutes) pour etudiant*/
    }
}

/* Verif  si l'heure actuelle a depasse la date limite */
int verifierRetard(time_t limite) {
    if (limite == 0) return 0;

    time_t actuelle = time(NULL);
    if (actuelle > limite) { 
        return 1; /*Il y a du retard */
    }
    else{
    return 0; /* Le livre est dans les temps */
    }
}

/* Cherche si l'utilisateur possede au moins un livre en retard */
int avoirDesRetards(Utilisateur u, Livre inventaire[], int nbLivres) {
    int i;
    
    /* verifie que l'inventaire existe et n'est pas vide */
    if (inventaire == NULL || nbLivres <= 0) {
        return 0;
    }

    for (i = 0; i < nbLivres; i++) {
        if (inventaire[i].estEmprunte == 1) {
            if (strcmp(inventaire[i].loginEmprunteur, u.login) == 0) {
                if (verifierRetard(inventaire[i].dateRetour) == 1) { 
                    return 1;
                }
            }
        }
    }
    return 0; /* Aucun retard */
}

/* Decide si l'utilisateur a le droit d'emprunter ou non */
int peutEmprunter(Utilisateur u, Livre inventaire[], int nbLivres) {
    
    if (inventaire == NULL || nbLivres <= 0){
        return 0;
    }

    /* Verification  des Quotas (3 pour étudiant, 5 pour prof) */
    if (u.role == ETUDIANT && u.nbLivresActuels >= MAX_LIVRES_ETUDIANT) {
        return 0; /* Refuse= Quota étudiant atteint */
    }
    
    if (u.role == PROFESSEUR && u.nbLivresActuels >= MAX_LIVRES_PROF) {
        return 0; /* Refuse =Quota profatteint */
    }
    if (avoirDesRetards(u, inventaire, nbLivres) == 1) {
        return 0; /* Refuse= L'utilisateur doit d'abord rendre ses livres en retard */
    }
    return 1; /* Tout est bon */
}



/* Valide l'emprunt d'un livre en cherchant directement dans les tableaux */
int traiterEmprunt(int idLivre, char loginUtilisateur[], Livre inventaire[], int nbLivres, Utilisateur liste[], int nbUtilisat) {
    int i;
    int indexLivre = -1; /* pas encore trouvé */
    int indexUser = -1;

    /* verifie que les listes existent et ne sont pas vides */
    if (inventaire == NULL || nbLivres <= 0 || liste == NULL || nbUtilisat <= 0) {
        return 0; 
    }

    /* Chercher la case du livre dans l'inventaire */
    for (i = 0; i < nbLivres; i++) {
        if (inventaire[i].id == idLivre) {
            indexLivre = i; 
            break; 
        }
    }
    /*  Chercher la case de l'utilisateur dans la liste */
    for (i = 0; i < nbUtilisat; i++) {
        if (strcmp(liste[i].login, loginUtilisateur) == 0) {
            indexUser = i; /* On a trouvé la case ! */
            break;
        }
    }
   /* Si on a trouve le livre  et l'utilisateur on lance l'emprunt */
    if (indexLivre != -1 && indexUser != -1) {
        
        /* verifie si le livre n'est pas  pris */
        if (inventaire[indexLivre].estEmprunte == 1) {
            return 0; 

        }
        inventaire[indexLivre].estEmprunte = 1;  
        
        /* eviter le debordement avec strncpy */
        strncpy(inventaire[indexLivre].loginEmprunteur, liste[indexUser].login, sizeof(inventaire[indexLivre].loginEmprunteur) - 1);  
        inventaire[indexLivre].loginEmprunteur[sizeof(inventaire[indexLivre].loginEmprunteur) - 1] = '\0';         
        
        /* On lance le chrono */
        inventaire[indexLivre].dateRetour = calculerDateRetour(liste[indexUser].role);  
        liste[indexUser].nbLivresActuels = liste[indexUser].nbLivresActuels + 1;  

        return 1; /* ca fonctionne */
    }

    return 0; /* Livre ou utilisateur introuvable */
}


/* Valide le retour d'un livre a la bibliotheque */
int traiterRetour(int idLivre, char loginUtilisateur[], Livre inventaire[], int nbLivres, Utilisateur liste[], int nbUtilisat) {
    int i;
    int indexLivre = -1;
    int indexUser = -1;

    if (inventaire == NULL || nbLivres <= 0 || liste == NULL || nbUtilisat <= 0) {
        return 0;
    }

    /* chercher le livre */
    for (i = 0; i < nbLivres; i++) {
        if (inventaire[i].id == idLivre) {
            indexLivre = i;
            break;
        }
    }

    /* chercher l'utilisateur */
    for (i = 0; i < nbUsers; i++) {
        if (strcmp(liste[i].login, loginUtilisateur) == 0) {
            indexUser = i;
            break;
        }
    }

    /*  retourne le livre  */
    if (indexLivre != -1 && indexUser != -1) {
        
        /*  on ne peut rendre qu'un livre qui est vraiment emprunté */
        if (inventaire[indexLivre].estEmprunte == 0) {
            return 0; /* Echec : ce livre est déjà en rayon */
        }

        inventaire[indexLivre].estEmprunte = 0; 
        strcpy(inventaire[indexLivre].loginEmprunteur, "");               
        inventaire[indexLivre].dateRetour = 0;                            
        
        /* secu si nb de livres negatifs */
        if (liste[indexUser].nbLivresActuels > 0) {  
            liste[indexUser].nbLivresActuels = liste[indexUser].nbLivresActuels - 1;  
        }

        return 1; /* Succes */
    }

    return 0; /* Echec */
}




/* Trie le catalogue par ordre alphabétique des Titres */
void trierLivresTitre(Livre inventaire[], int nbLivres) {
    int i, j;
    int echanges; 
    Livre temp; 
 if (inventaire == NULL || nbLivres <= 1) {
        return;
    }
 for (i = 0; i < nbLivres - 1; i++) {
        echanges = 0; 
        for (j = 0; j < nbLivres - i - 1; j++) {
            if (strcmp(inventaire[j].titre, inventaire[j+1].titre) > 0) {
                temp = inventaire[j];
                inventaire[j] = inventaire[j+1];
                inventaire[j+1] = temp;
                echanges = 1; 
            }
        }
        if (echanges == 0) {
            break; 
        }
    }
}

/* Trie le catalogue par ordre alphabétique des Auteurs */
void trierLivresAuteur(Livre inventaire[], int nbLivres) {
    int i, j;
    int echanges;
    Livre temp;

    if (inventaire == NULL || nbLivres <= 1) {
        return;
    }

    for (i = 0; i < nbLivres - 1; i++) {
        echanges = 0;
        for (j = 0; j < nbLivres - i - 1; j++) {
            if (strcmp(inventaire[j].auteur, inventaire[j+1].auteur) > 0) {
                temp = inventaire[j];
                inventaire[j] = inventaire[j+1];
                inventaire[j+1] = temp;
                echanges = 1;
            }
        }
        if (echanges == 0) {
            break;
        }
    }
}
