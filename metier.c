#include <time.h>
#include <string.h> 
#include "metier.h"

/* Calcule l'heure alaquelle le livre doit être rendu */
time_t calculerDateRetour(int role) {
    time_t actuelle = time(NULL); /* heure actuelle */
    
    /*  Si l'utilisateur n'est pas PROFESSEUR, on applique la regle etudiant par defauf pour eviter un bug*/
    if (role == PROFESSEUR) {
        return actuelle+180;/* ajoute 180 secondes (3 minutes) pour un prof */
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

/* Valide l'emprunt d'un livre par un utilisateur */
void traiterEmprunt(Livre *l, Utilisateur *u) {
    if (l == NULL || u == NULL){
        return; /* verif pour eviter le crash*/
    }

    l->estEmprunte = 1; /* Le livre est pas libre */
    strncpy(l->loginEmprunteur, u->login, sizeof(l->loginEmprunteur) - 1); /*eviter le debordement avzc strncpy*/
    l->loginEmprunteur[sizeof(l->loginEmprunteur) - 1] = '\0';         
    l->dateRetour = calculerDateRetour(u->role);  
    u->nbLivresActuels = u->nbLivresActuels + 1;  
}

/* Valide le retour d'un livre à la bibliotheque */
void traiterRetour(Livre *l, Utilisateur *u) {
    if (l == NULL || u == NULL){
        return;
    }

    l->estEmprunte = 0;/* Le livre est libre */
    strcpy(l->loginEmprunteur, "");               
    l->dateRetour = 0;                            
    
    /* secu si nb de livres negatifs */
    if (u->nbLivresActuels > 0) {
        u->nbLivresActuels = u->nbLivresActuels - 1;  
    }
}
