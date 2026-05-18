#include <stdio.h>
#include <string.h>
#include <time.h>
#include "donnee.h" 

/* gestion des fichiers */

int chargerLivres(char nomFichier[]) {
    FILE *fichier = fopen(nomFichier, "r");
    int retour;
    long dateTempo; /* Pour lire le temps calcule */

    if (fichier == NULL) {
        printf("Erreur : ouverture du fichier livres impossible.\n");
        return 0;
    }

    nbLivres = 0;
    while (nbLivres < MAX_LIVRES) {
        char emprunteur[50] = "";
        
        /* on lit les 7 infos du livre, separees par des points-virgules */
        retour = fscanf(fichier, "%d;%99[^;];%99[^;];%49[^;];%d;%ld;%49[^\n]\n",
                        &tabLivres[nbLivres].id, tabLivres[nbLivres].titre, tabLivres[nbLivres].auteur,
                        tabLivres[nbLivres].categorie, &tabLivres[nbLivres].estEmprunte, &dateTempo, emprunteur);

        if (retour == 7) { 
            tabLivres[nbLivres].dateRetour = (time_t)dateTempo;
            if (strcmp(emprunteur, "VIDE") == 0) {
                strcpy(tabLivres[nbLivres].loginEmprunteur, "");
            } else {
                strcpy(tabLivres[nbLivres].loginEmprunteur, emprunteur);
            }
            nbLivres++;
        } else {
            break; /* Fin du fichier atteinte */
        }
    }
    fclose(fichier);
    return 1;
}

int sauvegarderLivres(char nomFichier[]) {
    FILE *fichier = fopen(nomFichier, "w");
    int i;
    char emprunteur[50];

    if (fichier == NULL) {
        printf("Erreur : sauvegarde des livres impossible.\n");
        return 0;
    }

    for (i = 0; i < nbLivres; i++) {
        /* Astuce pour eviter les bugs d'espaces vides dans le texte */
        if (strlen(tabLivres[i].loginEmprunteur) == 0) {
            strcpy(emprunteur, "VIDE");
        } else {
            strcpy(emprunteur, tabLivres[i].loginEmprunteur);
        }

        fprintf(fichier, "%d;%s;%s;%s;%d;%ld;%s\n",
                tabLivres[i].id, tabLivres[i].titre, tabLivres[i].auteur, tabLivres[i].categorie,
                tabLivres[i].estEmprunte, (long)tabLivres[i].dateRetour, emprunteur);
    }
    fclose(fichier);
    return 1;
}

int chargerUtilisateurs(char nomFichier[]) {
    FILE *fichier = fopen(nomFichier, "r");
    int retour;

    if (fichier == NULL) {
        printf("Erreur : ouverture du fichier utilisateurs impossible.\n");
        return 0;
    }

    nbUtilisateurs = 0;
    while (nbUtilisateurs < MAX_UTILISATEURS) {
        /* On lit le login, mdp, role (0 ou 1) et le nb de livres actuels */
        retour = fscanf(fichier, "%49[^;];%20[^;];%d;%d\n",
                        tabUtilisateurs[nbUtilisateurs].login, tabUtilisateurs[nbUtilisateurs].mdp,
                        &tabUtilisateurs[nbUtilisateurs].role, &tabUtilisateurs[nbUtilisateurs].nbLivresActuels);

        if (retour == 4) {
            nbUtilisateurs++;
        } else {
            break; 
        }
    }
    fclose(fichier);
    return 1;
}

int sauvegarderUtilisateurs(char nomFichier[]) {
    FILE *fichier = fopen(nomFichier, "w");

    if (fichier == NULL) {
        printf("Erreur : sauvegarde des utilisateurs impossible.\n");
        return 0;
    }

    for(int i = 0; i < nbUtilisateurs; i++) {
        fprintf(fichier, "%s;%s;%d;%d\n",
                tabUtilisateurs[i].login, tabUtilisateurs[i].mdp,
                tabUtilisateurs[i].role, tabUtilisateurs[i].nbLivresActuels);
    }
    fclose(fichier);
    return 1;
}

          
                     
       


