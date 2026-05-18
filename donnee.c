#include <stdio.h>
#include <string.h>
#include "donnee.h" 

/* variables globales */

Livre tabLivres[MAX_LIVRES]; 
Utilisateur tabUtilisateurs[MAX_UTILISATEURS];

int nbLivres = 0;
int nbUtilisateurs = 0;

/* initialisation et compte */

void initialiserBibliotheque() {
    nbLivres = 0;
    nbUtilisateurs = 0;

    for (int i = 0; i < MAX_LIVRES; i++) {
        tabLivres[i].id = 0;
        tabLivres[i].estEmprunte = 0; 
        tabLivres[i].dateRetour = 0;
        strcpy(tabLivres[i].loginEmprunteur, "");
    }
    
    // Correction : ajout du type 'int' pour 'i'
    for (int i = 0; i < MAX_UTILISATEURS; i++) {
        tabUtilisateurs[i].nbLivresActuels = 0;
    }
}

int authentifier(char login[], char motDePasse[]) {
    for (int i = 0; i < nbUtilisateurs; i++) {
        if (strcmp(tabUtilisateurs[i].login, login) == 0 &&
            strcmp(tabUtilisateurs[i].mdp, motDePasse) == 0) { 
            return i; 
        }
    }
    return -1; 
}

int creerCompte(char login[], char motDePasse[], int role) {
    if(nbUtilisateurs >= MAX_UTILISATEURS) return 0;
    if (role != ETUDIANT && role != PROFESSEUR) return 0; 

    for (int i = 0; i < nbUtilisateurs; i++) {
        if (strcmp(tabUtilisateurs[i].login, login) == 0) return 0; 
    }

    strncpy(tabUtilisateurs[nbUtilisateurs].login, login, sizeof(tabUtilisateurs[nbUtilisateurs].login) - 1);
    tabUtilisateurs[nbUtilisateurs].login[sizeof(tabUtilisateurs[nbUtilisateurs].login) - 1] = '\0'; 

    strncpy(tabUtilisateurs[nbUtilisateurs].mdp, motDePasse, sizeof(tabUtilisateurs[nbUtilisateurs].mdp) - 1);
    tabUtilisateurs[nbUtilisateurs].mdp[sizeof(tabUtilisateurs[nbUtilisateurs].mdp) - 1] = '\0'; 

    tabUtilisateurs[nbUtilisateurs].role = role; 
    tabUtilisateurs[nbUtilisateurs].nbLivresActuels = 0;

    nbUtilisateurs++; 
    return 1; 
}

void afficherUtilisateurs() {
    printf("\n========== ANNUAIRE DES UTILISATEURS ==========\n");
    if (nbUtilisateurs == 0) {
        printf("Aucun utilisateur n'est inscrit pour le moment.\n===============================================\n");
        return;
    }
    for (int i = 0; i < nbUtilisateurs; i++) {
        printf("Compte : %s\n", tabUtilisateurs[i].login);
        if (tabUtilisateurs[i].role == PROFESSEUR) printf(" -> Statut : Professeur\n");
        else printf(" -> Statut : Etudiant\n");
        printf(" -> Livres en sa possession : %d\n-----------------------------------------------\n", tabUtilisateurs[i].nbLivresActuels);
    }
}

/* gestion des livres */

int ajouterLivre(char titre[], char auteur[], char categorie[]) {
    if (nbLivres >= MAX_LIVRES) return 0; 

    tabLivres[nbLivres].id = nbLivres + 1; 
    
    strncpy(tabLivres[nbLivres].titre, titre, sizeof(tabLivres[nbLivres].titre) - 1);
    tabLivres[nbLivres].titre[sizeof(tabLivres[nbLivres].titre) - 1] = '\0';

    strncpy(tabLivres[nbLivres].auteur, auteur, sizeof(tabLivres[nbLivres].auteur) - 1);
    tabLivres[nbLivres].auteur[sizeof(tabLivres[nbLivres].auteur) - 1] = '\0';

    strncpy(tabLivres[nbLivres].categorie, categorie, sizeof(tabLivres[nbLivres].categorie) - 1);
    tabLivres[nbLivres].categorie[sizeof(tabLivres[nbLivres].categorie) - 1] = '\0';

    tabLivres[nbLivres].estEmprunte = 0; 
    tabLivres[nbLivres].dateRetour = 0;
    strcpy(tabLivres[nbLivres].loginEmprunteur, "");

    nbLivres++;
    return 1; 
}

void afficherLivres() {
    printf("\n--- Liste des livres ---\n");
    if (nbLivres == 0) {
        printf("La bibliotheque est vide pour le moment.\n");
        return;
    }
    for (int i = 0; i < nbLivres; i++) {
        printf("%d | %s | %s | %s | ", tabLivres[i].id, tabLivres[i].titre, tabLivres[i].auteur, tabLivres[i].categorie);
        if (tabLivres[i].estEmprunte == 0) printf("Disponible\n");
        else printf("Emprunte\n");
    }
}
