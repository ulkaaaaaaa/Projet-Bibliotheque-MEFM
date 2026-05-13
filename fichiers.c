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


          
                     
       


