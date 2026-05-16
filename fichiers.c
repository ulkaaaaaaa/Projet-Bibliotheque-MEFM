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

      while (retour == 4 && nbUtilisateurs < MAX_UTILSATEURS) {

          for (i = 0; i < MAX_EMPRUNTS; i++) {
              tabUtilisateurs[Utilisateurs].emprunts[i] = -1;
          }

          for (i = 0; i < tabUtilisateurs[nbUtilisateurs].nbEmprunts; i++) {
              fscanf(fichier, ";%d", &tabUtilisateurs[nbUtilisateurs].emprunts[i]);
          }

          fscanf(fichier, "\n");

          nbUtilisateurs++;

          retour = fscanf(fichier, "%49[^;];%49[^;];%19[^;];%d",
                          tabUtilisateurs[nbUtilisateurs].login,
                          tabUtilisateurs[nbUtilisateurs].motDePasse,
                          tabUtilisateurs[nbUtilisateurs].role, 
                          &tabUtilisateurs[nbUtilisateurs].nbEmprunst);
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
          fprintf(fichier, "%s;%s;%s;%d",
                  tabUtilisateurs[i].login,
                  tabUtilisateurs[i].motDePasse,
                  tabUtilisateurs[i].role,
                  tabUtilisateurs[i].nbEmprunts);

        for (j = 0; j < tabUtilisateurs[i].nbEmprunts; j++) {
            fprintf(fichier, ";%d", tab

  
      
      



          
                     
       


