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












#include <stdio.h>
#include <string.h>
#include "donnees.h" /* ou metier.h selon ce que vous avez choisi */

Livre tabLivres[MAX_LIVRES]; 
Utilisateur tabUtilisateurs[MAX_UTILISATEURS];

int nbLivres = 0;
int nbUtilisateurs = 0;

/* Remet la bibliotheque a zero au demarrage */
void initialiserBibliotheque(){
    int i;

    nbLivres = 0;
    nbUtilisateurs = 0;

    /* Initialisation securisee des livres */
    for (i = 0; i < MAX_LIVRES; i++){
        tabLivres[i].id = 0;
        tabLivres[i].estEmprunte = 0; 
    }

    /* Initialisation securisee des utilisateurs */
    for (i = 0; i < MAX_UTILISATEURS; i++){
        tabUtilisateurs[i].nbLivresActuels = 0;
    }
}

/* Verifie si le login et le mot de passe correspondent a un profil */
int authentifier(char login[], char motDePasse[]){
    int i;

    for (i = 0; i < nbUtilisateurs; i++){
        if (strcmp(tabUtilisateurs[i].login, login) == 0 &&
            strcmp(tabUtilisateurs[i].mdp, motDePasse) == 0) { 
            return i; /* Renvoie le numero de la case de l'utilisateur trouve */
        }
    }
    return -1; /* -1 veut dire Echec / Non trouve */
}

/* Cree un nouveau profil utilisateur */
int creerCompte(char login[], char motDePasse[], int role){
    int i;

    /* 1. Securite : Verification de la place disponible */
    if(nbUtilisateurs >= MAX_UTILISATEURS) {
        return 0;
    }

    /* 2. Securite : Verification du role (0 = etudiant, 1 = professeur) */
    if (role != ETUDIANT && role != PROFESSEUR) {
        return 0; 
    }

    /* 3. Securite : Verification des doublons (login unique) */
    for (i = 0; i < nbUtilisateurs; i++) {
        if (strcmp(tabUtilisateurs[i].login, login) == 0) {
            return 0; /* Erreur : l'utilisateur existe deja */
        }
    }

    /* 4. Securite Technique (Anti-plantage) : Utilisation de strncpy au lieu de strcpy */
    strncpy(tabUtilisateurs[nbUtilisateurs].login, login, sizeof(tabUtilisateurs[nbUtilisateurs].login) - 1);
    tabUtilisateurs[nbUtilisateurs].login[sizeof(tabUtilisateurs[nbUtilisateurs].login) - 1] = '\0'; /* Force la fin du mot */

    strncpy(tabUtilisateurs[nbUtilisateurs].mdp, motDePasse, sizeof(tabUtilisateurs[nbUtilisateurs].mdp) - 1);
    tabUtilisateurs[nbUtilisateurs].mdp[sizeof(tabUtilisateurs[nbUtilisateurs].mdp) - 1] = '\0'; 

    tabUtilisateurs[nbUtilisateurs].role = role; 
    tabUtilisateurs[nbUtilisateurs].nbLivresActuels = 0;

    nbUtilisateurs++; /* On augmente le compteur total d'utilisateurs */

    return 1; /* Succes */
}

/* Affiche tout l'inventaire des livres */
void afficherLivres() {
    int i;

    printf("\n--- Liste des livres ---\n");
    
    if (nbLivres == 0) {
        printf("La bibliotheque est vide pour le moment.\n");
        return;
    }

    for (i = 0; i < nbLivres; i++) {
        printf("%d | %s | %s | %s | ",
              tabLivres[i].id,
              tabLivres[i].titre,
              tabLivres[i].auteur,
              tabLivres[i].categorie);
       
        /* Utilisation de "estEmprunte" pour etre synchro avec Uliana */
        if (tabLivres[i].estEmprunte == 0) {
            printf("Disponible\n");
        } else {
            printf("Emprunte\n");
        }
    }
}

/* Affiche la liste propre et detaillee des inscrits */
void afficherUtilisateurs() {
    int i;

    printf("\n========== ANNUAIRE DES UTILISATEURS ==========\n");

    if (nbUtilisateurs == 0) {
        printf("Aucun utilisateur n'est inscrit pour le moment.\n");
        printf("===============================================\n");
        return;
    }

    for (i = 0; i < nbUtilisateurs; i++) {
        printf("Compte : %s\n", tabUtilisateurs[i].login);
        
        if (tabUtilisateurs[i].role == PROFESSEUR) {
            printf(" -> Statut : Professeur\n");
        } else {
            printf(" -> Statut : Etudiant\n");
        }

        printf(" -> Livres en sa possession : %d\n", tabUtilisateurs[i].nbLivresActuels);
        printf("-----------------------------------------------\n");
    }
}
