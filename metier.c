#include <time.h>
#include "metier.h"

/* Calcule l'heure exacte à laquelle le livre doit être rendu */
time_t calculerDateRetour(int role) {
    time_t actuelle = time(NULL); /* heure actuelle */
    
    if (role == ETUDIANT) {
        return actuelle +120; /* ajoute 120 secondes(2 minutes) pour etudiant*/
    } else {
        return actuelle+180;/* ajoute 180 secondes (3 minutes) pour un prof */
    }
}

/*  Vérifie si l'heure actuelle a dépassé la date limite */
int verifierRetard(time_t limite) {
    time_t actuelle = time(NULL);
    if (maintenant > limite) {
        return 1; /*Il y a du retard */
    }
    
    return 0; /* Le livre est dans les temps */
}


/* Cherche si l'utilisateur possède au moins un livre en retard */
int avoirDesRetards(Utilisateur u, Livre inventaire[], int nbLivres) {
    int i;
    for (i = 0; i < nbLivres; i++) {
        if (inventaire[i].estEmprunte == 1) {
            if (strcmp(inventaire[i].loginEmprunteur, u.login) == 0) {
                if (verifierRetard(inventaire[i].dateRetourPrevue) == 1) {
                    return 1;
                }
            }
        }
    }
    return 0; /* Aucun retard */
}

/* Décide si l'utilisateur a le droit d'emprunter ou non */
int peutEmprunter(Utilisateur u, Livre inventaire[], int nbLivres) {
    
    /*  Vérification des Quotas (3 pour étudiant, 5 pour prof) */
    if (u.role == ETUDIANT && u.nbLivresActuels >= MAX_LIVRES_ETUDIANT) {
        return 0; /* Refusé= Quota étudiant atteint */
    }
    
    if (u.role == PROFESSEUR && u.nbLivresActuels >= MAX_LIVRES_PROF) {
        return 0; /* Refuse =Quota profatteint */
    }
    if (aDesRetards(u, inventaire, nbLivres) == 1) {
        return 0; /* Refusé=  L'utilisateur doit d'abord rendre ses livres en retard */
    }
    return 1; /* Tout est bon */
}



/* Valide l'emprunt d'un livre par un utilisateur */
void traiterEmprunt(Livre *l, Utilisateur *u) {
    l->estEmprunte = 1;                           /* Le livre est pas libre */
    strcpy(l->loginEmprunteur, u->login);         
    l->dateRetour = calculerDateRetour(u->role);  
    u->nbLivresActuels = u->nbLivresActuels + 1;  
}

/* Valide le retour d'un livre à la bibliothèque */
void traiterRetour(Livre *l, Utilisateur *u) {
    l->estEmprunte = 0;                           /* Le livre est libre */
    strcpy(l->loginEmprunteur, "");               
    l->dateRetour = 0;                            
    u->nbLivresActuels = u->nbLivresActuels - 1;  
}


