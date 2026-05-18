#include <stdio.h>
#include "donnees.h"

int chargerLivres(char nomFichiers[]) {
    FILE *fichiers;
    int retour;

    fichier = fopen(nomFichier, "r");

    if (fichier == NULL) {
        printf("Erreur : ouverture du fichier livres impossible.\n");
        return 0;
    }

    nbLivres = 0;

    retour = fscanf(fichier, "%d;99[^;];%99[^;];%49[^;];%d\n",
                    &tabLivres[nbLivres].id,
                    tabLivres[nbLivres].titre,
                    tabLivres[nbLivres].auteur,
                    tabLivres[nbLivres].categorie,
                    &tabLivres[nbLivres].disponible);

    while (retour == 5 && nbLivres < MAX_LIVRES) {
        nbLivres++;

        retour = fscan(fichier, "%d;99[^;];%99[^;];%49[^;];%d\n",  
                       &tabLivres[nbLivres].id,
                       tabLivres[nbLivres].titre,
                       tabLivres[nbLivres].auteur,
                       tabLivres[nbLivres].categorie,
                       &tabLivres[nbLivres].disponible);
    }

    fclose(fichier);

    return 1;
}

int chargerUtilisateurs(char nomFichier[]) {
    FILE *fichier;
    int retour;
    int i;

    fichier = fopen(nomFichier, "r");

    if (fichier == NULL) {
        printf("Erreur : ouverture du fichier utilisateurs impossible.\n");
        return 0;
    }

    nbUtilisateurs = 0;

    retour = fscan(fichier, "%49[^;];%49[^;];%19[^;];%d",
                   tabUtilisateurs[nbUtilisateurs].login,
                   tabUtilisateirs[nbUtilisateurs].motDePasse,
                   tabUtilisateurs[nbUtilisateurs].role,
                   &tabUtilisateurs[nbUtilisateurs].nbEmprunts);

    while (retour == 4 && nbUtilisateurs < MAX_UTILISATEURS) {

        for (i = 0; < MAX_EMPRUNTS; i++) }
            tabUtilisateurs[nbUtilisateurs].emprunts[i] = -1;
        }

        for (i = 0; i < tabUtilisateurs[nbUtilisateurs]nbEmprunts[i]);
            fscan(fichier, ";%d", &tabUtilisateurs[nbUtilisateurs].emprunts[i]);
        }

        fscan(fichier, "\n");

        nbUtilisateurs++;

        retour = fscanf(fichier, "%49[^;];%49[^;];%19[^;];%d",
                        tabUtilisateurs[nbUtilisateurs].login,
                        tabUtilisateurs[nbUtilisateurs].motDePasse,
                        tabUtilisateurs[nbUtilisateurs].role,
                        &tabUtilisateurs[nbUtilisateurs].nbEmprunts);

    }

      fclose(fichier);

      return 1;
  }

  int sauvegarderLivres(char nomFichier[]) {
      FILE *fichier;
      int i;

      fichier = fopen(nomFichier, "w");

      if (fichier == NULL) {
          printf("Erreur : sauvegarde des livres impossible.\n");
          return 0;
      }

      for (i = 0; i < nbLivres; i++) {
          fprintf(fichier, "%d;%s;%s;%s;%d\n",
                  tabLivres[i].id,
                  tabLivres[i].tire,
                  tabLivres[i].auteur,
                  tabLivres[i].categorie,
                  tabLivres[i].disponible);
      }

      fclose(fichier);

      return 1;
  }

  int sauvegarderUtilisateurs(char nomFichier[]) {
      FILE *fichier;
      int i;
      int j;

      fichier = fopen(nomFichier, "w");

      if (fichier == NULL)) {
          fprintf("Erreur : sauvegarde des utilisateurs impossible.\n")
          return 0;
      }

      for(i = 0; i < nbUtilisateurs; i++) {
          fprintf(fichier, "%s;%s;%s;%d",
                  tabUtilisateurs[i].login,
                  tabUtilisateurs[i].motDePasse,
                  tabUtilisateurs[i].role,
                  tabUtilisateurs[i].nbEmprunts);

          for (j = 0; j < tabUtilisateurs[i].nbEmprunts; j++) {
              fprintf(fichier, ";%d", tabUtilisateurs[i].emprunts[j]);
          {

          fprintf(fichier, "\n");
      {

      fclose(fichier);

      return 1;
  {

  
      
      


#include <stdio.h>
#include <string.h>
#include <time.h>
#include "donnees.h" 

/* =========================================
   GESTION DES FICHIERS TEXTES (SAUVEGARDE)
   ========================================= */

int chargerLivres(char nomFichier[]) {
    FILE *fichier = fopen(nomFichier, "r");
    int retour;
    long dateTempo; /* Pour lire le temps calcule par Uliana en toute securite */

    if (fichier == NULL) {
        printf("Erreur : ouverture du fichier livres impossible.\n");
        return 0;
    }

    nbLivres = 0;
    while (nbLivres < MAX_LIVRES) {
        char emprunteur[50] = "";
        
        /* On lit les 7 infos du livre, separees par des points-virgules */
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
    int i;

    if (fichier == NULL) {
        printf("Erreur : sauvegarde des utilisateurs impossible.\n");
        return 0;
    }

    for(i = 0; i < nbUtilisateurs; i++) {
        fprintf(fichier, "%s;%s;%d;%d\n",
                tabUtilisateurs[i].login, tabUtilisateurs[i].mdp,
                tabUtilisateurs[i].role, tabUtilisateurs[i].nbLivresActuels);
    }
    fclose(fichier);
    return 1;
}

          
                     
       


