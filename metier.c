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

    /* Blocage si retard en cours */
    if (aDesRetards(u, inventaire, nbLivres) == 1) {
        return 0; /* Refusé=  L'utilisateur doit d'abord rendre ses livres en retard */
    }
    return 1; /* Tout est bon */
}
