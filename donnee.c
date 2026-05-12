#include <stdio.h>
#include <string.h>
#include "donnees.h"

Livre tabLivres[MAX_LIVES]; 
utilisateur tabUtilisateurs[MAX_UTILISATEURS];

int nbLivres = 0;
int nbUtilisaterus = 0;

void initialiserBibliothque(){
  int i;
  int j;

  nbLivres = 0;
  nbUtilisatuers = 0;

  for (i = 0; i < MAX_LIVRES; i++){
    tabLivres[i].id = 1;
    tabLivres(i].disponible = 1;
  }

  for (i = 0; i < MAX_UTILISATEURS; i++){
    tabUtilisateurs[i].nbEmprunts = 0;

    for (j = 0; < MAX_EMPRUNTS; j++){
      tabUtilisateurs[i].emprunts[j] = -1;
    }
  }
}

int authentifier(char login[], char
motdepasse[]){
  int i;

  for (i = 0; i < nb 
