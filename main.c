#include <stdio.h>
#include <string.h>
#include "donnees.h"
#include "interface.h"

int main() {
    int choixDepart;
    int choixPrincipal;
    int indiceUtilisateur;
    int deconnecte;
    int ok;
    
    initialiserBibliotheque();          

  
    ok = chargerLivres("livres.txt");
    if (ok == 0) {
        printf("\033[33m"); /* Texte en Jaune */
        printf("Info : Fichier livres.txt introuvable. Demarrage avec un catalogue vide.\n");
        printf("\033[0m");
    }

    ok = chargerUtilisateurs("utilisateurs.txt");
    if (ok == 0) {
        printf("\033[33m"); /* Texte en Jaune */
        printf("Info : Fichier utilisateurs.txt introuvable. Demarrage avec un registre vide.\n");
        printf("\033[0m");
    }

    /* lancement de l'interface */
    afficherAccueil();         

    /* Menu d'accueil (Connexion / Inscription) */
    do {            
        afficherMenuDepart();            

        do {
            choixDepart = saisirEntierSecurise();
            if (choixDepart < 1 || choixDepart > 3) {
                printf("\033[31mChoix invalide.\033[0m\n");
            }
        } while (choixDepart < 1 || choixDepart > 3);

        if (choixDepart == 1) {
            /* connexion*/
            indiceUtilisateur = afficherSeConnecter();
            afficherStatusUtilisateur(tabUtilisateurs[indiceUtilisateur]);

            deconnecte = 0;
            
            /* Menu de l'utilisateur connecte */
            do {
                afficherMenuPrincipal(tabUtilisateurs[indiceUtilisateur]);

                do {
                    choixPrincipal = saisirEntierSecurise();
                    if (choixPrincipal < 1 || choixPrincipal > 3) {
                        printf("\033[31mChoix invalide.\033[0m\n");
                    }
                } while (choixPrincipal < 1 || choixPrincipal > 3);

                if (choixPrincipal == 1) {
                    afficherEmprunterLivre(tabUtilisateurs[indiceUtilisateur]);
                } else if (choixPrincipal == 2) {
                    afficherRendreLivre(tabUtilisateurs[indiceUtilisateur]);
                } else if (choixPrincipal == 3) {
                    if (afficherVerifDeconnexion() == 2) { /* 2 correspond a "Oui" */
                        deconnecte = 1;
                    }
                }

            } while (deconnecte == 0);

        } else if (choixDepart == 2) {
            /* creer un compte */
            afficherCreerCompte();
        }

    } while (choixDepart != 3); /* 3 = Quitter */

    /* fermeture et sauvegarde finale */
    sauvegarderLivres("livres.txt");
    sauvegarderUtilisateurs("utilisateurs.txt");

    /* Petit message de fin avec ecran nettoye */
    printf("\033[2J\033[H"); 
    printf("\033[32mSauvegarde effectuee. Au revoir et a bientot !\033[0m\n\n");

    return 0;
}

