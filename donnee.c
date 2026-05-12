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

  for (i = 0
