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






            /* remplacer BOUCLE NIVEAU 2 : Menu de l'utilisateur connecte */
            do {
                afficherMenuPrincipal(tabUtilisateurs[indiceUtilisateur]);

                do {
                    choixPrincipal = saisirEntierSecurise();
                    
                    /* Sécurité : On adapte la limite du choix (3 pour etudiant, 4 pour prof) */
                    int limiteMax = (tabUtilisateurs[indiceUtilisateur].role == PROFESSEUR) ? 4 : 3;
                    
                    if (choixPrincipal < 1 || choixPrincipal > limiteMax) {
                        printf("\033[31mChoix invalide.\033[0m\n");
                        ok = 0;
                    } else {
                        ok = 1;
                    }
                } while (ok == 0);

                /* Redirection des boutons */
                if (choixPrincipal == 1) {
                    afficherEmprunterLivre(tabUtilisateurs[indiceUtilisateur]);
                } else if (choixPrincipal == 2) {
                    afficherRendreLivre(tabUtilisateurs[indiceUtilisateur]);
                } else if (choixPrincipal == 3) {
                    /* Le choix 3 deconnecte toujours l'utilisateur */
                    if (afficherVerifDeconnexion() == 2) { // 2 = Oui
                        deconnecte = 1;
                    }
                } else if (choixPrincipal == 4) {
                    /* Le choix 4 n'est accessible qu'au prof pour ajouter un livre */
                    afficherAjouterLivre(tabUtilisateurs[indiceUtilisateur]);
                }

            } while (deconnecte == 0);






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
    
    /* 1. Initialisation de la mémoire globale */
    initialiserBibliotheque();          

    /* 2. Chargement des fichiers de sauvegarde */
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

    /* 3. Lancement de l'interface graphique */
    afficherAccueil();         

    /* BOUCLE NIVEAU 1 : Menu d'accueil (Connexion / Inscription / Quitter) */
    do {            
        afficherMenuDepart();            

        do {
            choixDepart = saisirEntierSecurise();
            if (choixDepart < 1 || choixDepart > 3) {
                printf("\033[31mChoix invalide.\033[0m\n");
            }
        } while (choixDepart < 1 || choixDepart > 3);

        if (choixDepart == 1) {
            /* --- CONNEXION --- */
            indiceUtilisateur = afficherSeConnecter();
            afficherStatusUtilisateur(tabUtilisateurs[indiceUtilisateur]);

            deconnecte = 0;
            
            /* BOUCLE NIVEAU 2 INTÉGRÉE : Menu de l'utilisateur connecté */
            do {
                afficherMenuPrincipal(tabUtilisateurs[indiceUtilisateur]);

                do {
                    choixPrincipal = saisirEntierSecurise();
                    
                    /* Sécurité : On adapte la limite du choix (3 pour etudiant, 4 pour prof) */
                    int limiteMax = (tabUtilisateurs[indiceUtilisateur].role == PROFESSEUR) ? 4 : 3;
                    
                    if (choixPrincipal < 1 || choixPrincipal > limiteMax) {
                        printf("\033[31mChoix invalide.\033[0m\n");
                        ok = 0;
                    } else {
                        ok = 1;
                    }
                } while (ok == 0);

                /* Redirection des actions selon le bouton pressé */
                if (choixPrincipal == 1) {
                    afficherEmprunterLivre(tabUtilisateurs[indiceUtilisateur]);
                } else if (choixPrincipal == 2) {
                    afficherRendreLivre(tabUtilisateurs[indiceUtilisateur]);
                } else if (choixPrincipal == 3) {
                    /* Correction : 0 correspond au choix "Oui" dans l'interface de Jeanne */
                    if (afficherVerifDeconnexion() == 0) { 
                        deconnecte = 1;
                    }
                } else if (choixPrincipal == 4) {
                    /* Le choix 4 n'est accessible qu'au prof pour ajouter un livre */
                    afficherAjouterLivre(tabUtilisateurs[indiceUtilisateur]);
                }

            } while (deconnecte == 0);

        } else if (choixDepart == 2) {
            /* --- CRÉATION DE COMPTE --- */
            afficherCreerCompte();
        }

    } while (choixDepart != 3); /* 3 = Quitter */

    /* 4. Fermeture et sauvegarde finale automatique sur le disque */
    sauvegarderLivres("livres.txt");
    sauvegarderUtilisateurs("utilisateurs.txt");

    /* Petit message de fin avec écran nettoyé */
    printf("\033[2J\033[H"); 
    printf("\033[32mSauvegarde effectuee. Au revoir et a bientot !\033[0m\n\n");

    return 0;
}


