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
    
    /* ========================================================
       1. DEMARRAGE DE LA MEMOIRE (Tableaux de Youssef)
       ======================================================== */
    initialiserBibliotheque();          

    /* ========================================================
       2. CHARGEMENT DES FICHIERS TEXTES 
       ======================================================== */
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

    /* ========================================================
       3. LANCEMENT DE L'INTERFACE VISUELLE (Menus de Jeanne)
       ======================================================== */
    afficherAccueil();         

    /* BOUCLE NIVEAU 1 : Menu d'accueil (Connexion / Inscription) */
    do {            
        afficherMenuDepart();            

        do {
            choixDepart = saisirEntierSecurise();
            if (choixDepart < 1 || choixDepart > 3) {
                printf("\033[31mChoix invalide.\033[0m\n"); /* Texte en Rouge */
            }
        } while (choixDepart < 1 || choixDepart > 3);

        if (choixDepart == 1) {
            /* --- CONNEXION --- */
            indiceUtilisateur = afficherSeConnecter();
            afficherStatusUtilisateur(tabUtilisateurs[indiceUtilisateur]);

            deconnecte = 0;
            
            /* BOUCLE NIVEAU 2 : Menu de l'utilisateur connecte */
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
            /* --- CREATION DE COMPTE --- */
            afficherCreerCompte();
        }

    } while (choixDepart != 3); /* 3 = Quitter */

    /* ========================================================
       4. FERMETURE ET SAUVEGARDE FINALE
       ======================================================== */
    sauvegarderLivres("livres.txt");
    sauvegarderUtilisateurs("utilisateurs.txt");

    /* Petit message de fin avec ecran nettoye */
    printf("\033[2J\033[H"); 
    printf("\033[32mSauvegarde effectuee. Au revoir et a bientot !\033[0m\n\n");

    return 0;
}

