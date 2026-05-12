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

int authentifier(char login[], char motDePasse[]){
  int i;

  for (i = 0; i < nbUtilisateurs; i++){
    if (strcmp(tabUtilisateurs[i].login ,login) == 0 &&
        strcmp(tabUtilisateurs[i].motDePasse, motDePasse) == 0) {
        return i;
    }
  }
  return -1;
}
int creerCompte(char[], char motDePasse[], char role[]){
  int i;
  int j ;

  if(nbUtilisateurs >= MAX_UTILISATEURS) {
    return 0;
  }

  if (strcmp(role, "etudiant") != 0 && strcmp(role, "professeur") != 0) {
    return 0; 
  }

  for (i = 0; i < nbUtilisateurs; i++) {
    if (strcmp(tabUtilisateurs[i].login, login) == 0) {
    }
  }

  strcpy(tabUtilisateurs[nbUtilisateurs].login, login);
  strcpy(tabUtilisateurs[nbUtilisateurs].motDePasse, motDePasse);
  strcpy(tabUtilisateurs[nbUtilisateurs].role, role);

  tabUtilisateurs[nbUtilisateurs].nbEmprunts = 0;
  for (j = 0; < MAX_EMPRUNTS; j++) {
    tabUtilisateursnbUtilisateurs].emprunts[j] = -1;
  }

  nbUtilisateurs++;

  return 1;
}
void afficherLivres() {
  int i;

  printf("\n--- Liste des livres ---\n");

  for (i = 0; i < nbLivres; i++) {
    printf("%d | %s | %s | %s | ",
          tabLivres[i].id,
          tabLivres[i].titre,
          tabLivres[i].auteur,
          tabLivres[i].categrie);
   
    if (tabLivres[i].disponible == 1) {
      printf("Disponible\n");
    } else {
      printf("Emprunts\n");
    }
  }
}

void afficherUtilisateurs() {
  int i;

  printf("\n--- Liste des utilisateurs ---\n");

  for (i = 0; i < nbUtilisateurs; i++) {
    printf("%s | %s | %d emprunt(s)\n",
      tabUtilisateurs[i].login,  
      tabUtilisateurs[i].role,   
      tabUtilisateurs[i].nbEmprunts);
  }
}
