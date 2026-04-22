#ifndef METIER_H
#define METIER_H

#include <time.h>
#include <string.h>

/*  Poste  */
#define ETUDIANT 0
#define PROFESSEUR 1

/*  Structure Livre */
typedef struct {
    int id;
    char titre[100];
    char auteur[100];
    char categorie[50];
    int estEmprunte;      /* 0 = libre, 1 = pris */
    time_t dateRetour;    /* Heure limite */
    char loginEmprunteur[50]; 
} Livre;

/*  Structure Utilisateur  */
typedef struct {
    char login[50];
    char mdp[50];
    int role;             /* 0 pour etudiant, 1 pour prof */
    int nbLivresActuels;  
} Utilisateur;

/* Yousef : Gestion des Données  */
void chargerLivres(Livre inventaire[], int *nbTotal);
void chargerUtilisateurs(Utilisateur liste[], int *nbUsers);
void sauvegarderTout(Livre inventaire[], int nbL, Utilisateur liste[], int nbU);

/* Uliana : Logique Métier */
time_t calculerDateRetour(int role);
int verifierRetard(time_t echeance);
void trierLivresTitre(Livre inventaire[], int n);
int peutEmprunter(Utilisateur u, Livre inventaire[], int n);

/* Jeanne : Interface et Main  */
void afficherMenuPrincipal();
void afficherListeLivres(Livre inventaire[], int n);
int saisieEntiereSecurisee();

#endif
