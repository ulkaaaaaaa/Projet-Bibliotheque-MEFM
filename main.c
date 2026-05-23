#include <stdio.h>
#include <string.h>
#include "donnee.h"
#include "interface.h"

int main() {
    int choixDepart;
    int choixPrincipal;
    int indiceUtilisateur;
    int deconnecte;
    int ok;
    int limiteMax;

    initialiserBibliotheque();      //initialisation de la memoire globale 

    ok = chargerLivres("livres.txt");         //chargement des fichiers de sauvegarde 
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

    afficherAccueil();        //lancement de l'interface graphique 

    do {        //BOUCLE NIVEAU 1 : menu d'accueil 
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

            indiceUtilisateur = afficherSeConnecter();  //connection

            if (indiceUtilisateur != -1) {                      //si l'utilisateur a tapé retour 

                afficherStatusUtilisateur(tabUtilisateurs[indiceUtilisateur]);      //status dès la connexion 

                deconnecte = 0;

                do {       //BOUCLE NIVEAU 2 : menu principal 
                    afficherMenuPrincipal(tabUtilisateurs[indiceUtilisateur]);

                    if (tabUtilisateurs[indiceUtilisateur].role == PROFESSEUR) {
                        limiteMax = 4;  // prof peut choisir 1, 2, 3 ou 4
                    } else {
                        limiteMax = 3;  // étudiant peut choisir 1, 2 ou 3
                    }
                    
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
                        if (afficherVerifDeconnexion() == 0) {    //0 = Oui se déconnecter dans afficherVerifDeconnexion
                            deconnecte = 1;
                        }

                    } else if (choixPrincipal == 4) {     //uniquement prof 
                        
                        afficherAjouterLivre(tabUtilisateurs[indiceUtilisateur]);

                    } else if (choixPrincipal == 0) {
                        deconnecte = 1;   //retour au menu départ 
                    }

                } while (deconnecte == 0);
            }

        } else if (choixDepart == 2) {
            afficherCreerCompte();
        }

    } while (choixDepart != 3);

    
    sauvegarderLivres("livres.txt");     //sauvegarde finale 
    sauvegarderUtilisateurs("utilisateurs.txt");

    printf("\033[2J\033[H");   
    printf("\033[32m");
    printf("Sauvegarde effectuee. Au revoir et a bientot !\n");         //message de fin 
    printf("\033[0m");

    return 0;
}


