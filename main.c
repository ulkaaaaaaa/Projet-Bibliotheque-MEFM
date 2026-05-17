#include <stdio.h>
#include "donnees.h"

int main() {
    int ok;
    int indice;

    initialiserBibliotheque();

    ok = chargerLivres("livres.txt");
    if (ok == 0) {
        printf("Chargelent des livres impossible.\n");
    }

    ok = chargerUtilisateurs("utilisateurs.txt");
    if (ok == 0) {
        printf("Chargement des utilisateurs impossible.\n");
    }

    afficherLivres();
    afficherUtilisateurs();

    indice = authentifier("etudiant1", "1234");

    if (indice != -1) {
        printf("\nConnesion reussie : %s\n", tabUtilisateurs[indice].login);
    } else {
        printf("\nLogin ou mot de passe incorrect.\n");
    }

    ok = creerCompte("nouveau", "0000", "etudiant");

    if (ok == 1) {
        printf("\nCompte cree avec succes.\n");
    } else{
        printf("\nCreation du compte impossible.\n");
    }

    sauvegarderUtilisateurs("utilisateurs.txt");
    sauvegarderLivres("livres.txt");

    return 0;
}

//Avant main de Youssef, on peut retirer?


#include <stdio.h>
#include <string.h>
#include "donnees.h"
#include "metier.h"
#include "interface.h"

int main() {
    int choixDepart;
    int choixPrincipal;
    int indiceUtilisateur;
    int deconnecte;
    int ok;

    
    initialiserBibliotheque();          // chargement des données avec vérification

    ok = chargerLivres("livres.txt");
    if (ok == 0) {
        printf("\033[31m");
        printf("Erreur : chargement des livres impossible.");
        printf("\033[0m");
        printf("\n");
        return 1;  // quitte le programme 
    }

    ok = chargerUtilisateurs("utilisateurs.txt");
    if (ok == 0) {
        printf("\033[31m");       //rouge
        printf("Erreur : chargement des utilisateurs impossible.");
        printf("\033[0m");
        printf("\n");
        return 1;  // quitte le programme 
    }

    afficherAccueil();         // logo de démarrage

    do {            // boucle menu départ
        afficherMenuDepart();            

        do {
            choixDepart = saisirEntierSecurise();
            if (choixDepart < 1 || choixDepart > 3) {
                printf("\033[31m");       //rouge
                printf("Choix invalide.");
                printf("\033[0m");
                printf("\n");
            }
        } while (choixDepart < 1 || choixDepart > 3);

        if (choixDepart == 1) {

            indiceUtilisateur = afficherSeConnecter();
            afficherStatusUtilisateur(tabUtilisateurs[indiceUtilisateur]);

            deconnecte = 0;
            do {
                afficherMenuPrincipal(tabUtilisateurs[indiceUtilisateur]);

                do {
                    choixPrincipal = saisirEntierSecurise();
                    if (choixPrincipal < 1 || choixPrincipal > 3) {
                        printf("\033[31m");       //rouge
                        printf("Choix invalide.");
                        printf("\033[0m");
                        printf("\n");
                    }
                } while (choixPrincipal < 1 || choixPrincipal > 3);

                if (choixPrincipal == 1) {
                    afficherEmprunterLivre(tabUtilisateurs[indiceUtilisateur]);
                } else if (choixPrincipal == 2) {
                    afficherRendreLivre(tabUtilisateurs[indiceUtilisateur]);
                } else if (choixPrincipal == 3) {
                    if (afficherVerifDeconnexion() == 2) {
                        deconnecte = 1;
                    }
                }

            } while (deconnecte == 0);

        } else if (choixDepart == 2) {
            afficherCreerCompte();
        }

    } while (choixDepart != 3);

    // sauvegarde avant de quitter
    sauvegarderLivres("livres.txt");
    sauvegarderUtilisateurs("utilisateurs.txt");

    afficherAccueil();

    return 0;
}
