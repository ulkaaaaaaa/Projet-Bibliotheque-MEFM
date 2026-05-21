#include <stdio.h>
#include <string.h>
#include "donnee.h"
#include "metier.h"
#include "interface.h"

int main() {
    int choixDepart;
    int choixPrincipal;
    int indiceUtilisateur;
    int deconnecte;
    int ok;
    int limiteMax;

    /* 1. Initialisation de la memoire globale */
    initialiserBibliotheque();

    /* 2. Chargement des fichiers de sauvegarde */
    ok = chargerLivres("livres.txt");
    if (ok == 0) {
        printf("\033[33m");
        printf("Info : Fichier livres.txt introuvable. Demarrage avec un catalogue vide.\n");
        printf("\033[0m");
    }

    ok = chargerUtilisateurs("utilisateurs.txt");
    if (ok == 0) {
        printf("\033[33m");
        printf("Info : Fichier utilisateurs.txt introuvable. Demarrage avec un registre vide.\n");
        printf("\033[0m");
    }

    /* 3. Lancement de l'interface graphique */
    afficherAccueil();

    /* BOUCLE NIVEAU 1 : Menu d'accueil */
    do {
        afficherMenuDepart();

        do {
            choixDepart = saisirEntierSecurise();
            if (choixDepart < 1 || choixDepart > 3) {
                printf("\033[31m");
                printf("Choix invalide.");
                printf("\033[0m");
                printf("\n");
            }
        } while (choixDepart < 1 || choixDepart > 3);

        if (choixDepart == 1) {

            /* --- CONNEXION --- */
            indiceUtilisateur = afficherSeConnecter();

            /* si l'utilisateur a tapé retour */
            if (indiceUtilisateur != -1) {

                /* status dès la connexion */
                afficherStatusUtilisateur(tabUtilisateurs[indiceUtilisateur]);

                deconnecte = 0;

                /* BOUCLE NIVEAU 2 : Menu principal */
                do {
                    afficherMenuPrincipal(tabUtilisateurs[indiceUtilisateur]);

                    /* saisie sécurisée selon le rôle */
                    limiteMax = (tabUtilisateurs[indiceUtilisateur].role == PROFESSEUR) ? 4 : 3;

                    do {
                        choixPrincipal = saisirEntierSecurise();
                        if (choixPrincipal < 0 || choixPrincipal > limiteMax) {
                            printf("\033[31m");
                            printf("Choix invalide.");
                            printf("\033[0m");
                            printf("\n");
                            ok = 0;
                        } else {
                            ok = 1;
                        }
                    } while (ok == 0);

                    if (choixPrincipal == 1) {
                        afficherEmprunterLivre(tabUtilisateurs[indiceUtilisateur]);

                    } else if (choixPrincipal == 2) {
                        afficherRendreLivre(tabUtilisateurs[indiceUtilisateur]);

                    } else if (choixPrincipal == 3) {
                        /* 0 = Oui se déconnecter dans afficherVerifDeconnexion */
                        if (afficherVerifDeconnexion() == 0) {
                            deconnecte = 1;
                        }

                    } else if (choixPrincipal == 4) {
                        /* uniquement accessible au prof */
                        afficherAjouterLivre(tabUtilisateurs[indiceUtilisateur]);

                    } else if (choixPrincipal == 0) {
                        /* retour au menu départ */
                        deconnecte = 1;
                    }

                } while (deconnecte == 0);
            }

        } else if (choixDepart == 2) {
            afficherCreerCompte();
        }

    } while (choixDepart != 3);

    /* 4. Sauvegarde finale */
    sauvegarderLivres("livres.txt");
    sauvegarderUtilisateurs("utilisateurs.txt");

    /* Message de fin */
    printf("\033[2J\033[H");
    printf("\033[32m");
    printf("Sauvegarde effectuee. Au revoir et a bientot !\n");
    printf("\033[0m");

    return 0;
}


