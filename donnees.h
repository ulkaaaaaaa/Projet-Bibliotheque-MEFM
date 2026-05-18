#ifdef DONNEES_H
#define DONNEES_H
#define MAX_LIVRES 200
#define MAX_UTILISATEURS 100
#define MAX_LIVRES_PROF 5
#define MAX_LIVRES_ETUDIANT 3

typedef struct {
  int id;
  char titre[100];
  char auteur[100];
  char categorie[50];
  int disponible; // 1 = disponible , 0 = emprunté
} Livre;

typedef struct {
  char login[50];
  char motdepasse[21];       
  char role[20];
  int emprunts[MAX_EMPRUNTS];
  int nbEmprunts;
} Utilisateur;

extern Livre tabLivres[MAX_LIVRES];
extern Utilisateurs tabUtilisateurs[MAX_UTILISATEURS];

extern int nbUtilisateurs;
extern int nbUtilisatuers;   //?//

void initialiserBibliotheque();

int chargerLivres(char nomFichier[]);
int chargerUtilisateurs(char nomFichiers[]);

int sauvegarderLivres(char nomFichiers[]);
int sauvegarderUtilisateurs(char nomFichier[]);

int authentifier(char login[], char motdepasse[]);
int creerCompte(char login[], char motdepasse[], char role[]);

void afficherLivres();
void afficherUtilisateurs();

#endif




#ifndef DONNEES_H
#define DONNEES_H

#include <time.h>
#include <string.h>

/* =========================================
   1. CONSTANTES DE REGLAGE
   ========================================= */
#define MAX_LIVRES 200
#define MAX_UTILISATEURS 100

/* Quotas */
#define MAX_LIVRES_PROF 5
#define MAX_LIVRES_ETUDIANT 3

/* Roles */
#define ETUDIANT 0
#define PROFESSEUR 1


/* =========================================
   2. STRUCTURES UNIFIEES
   ========================================= */
typedef struct {
    int id;
    char titre[100];
    char auteur[100];
    char categorie[50];
    int estEmprunte;      /* 0 = libre, 1 = pris */
    time_t dateRetour;    /* Heure limite calculee par Uliana */
    char loginEmprunteur[50]; 
} Livre;

typedef struct {
    char login[50];
    char mdp[21];
    int role;             /* 0 pour etudiant, 1 pour prof */
    int nbLivresActuels;  /* Compteur gere par le code d'Uliana */
} Utilisateur;


/* =========================================
   3. VARIABLES GLOBALES PARTAGEES
   ========================================= */
extern Livre tabLivres[MAX_LIVRES];
extern Utilisateur tabUtilisateurs[MAX_UTILISATEURS];
extern int nbLivres;
extern int nbUtilisateurs;


/* =========================================
   4. FONCTIONS DE YOUSSEF (Donnees et Fichiers)
   ========================================= */
void initialiserBibliotheque();
int chargerLivres(char nomFichier[]);
int chargerUtilisateurs(char nomFichier[]);
int sauvegarderLivres(char nomFichier[]);
int sauvegarderUtilisateurs(char nomFichier[]);
int authentifier(char login[], char motDePasse[]);
int creerCompte(char login[], char motDePasse[], int role);
void afficherLivres();
void afficherUtilisateurs();


/* =========================================
   5. FONCTIONS D'ULIANA (Logique Metier)
   ========================================= */
time_t calculerDateRetour(int role);
int verifierRetard(time_t limite);
int avoirDesRetards(Utilisateur u, Livre inventaire[], int nbLivres);
int peutEmprunter(Utilisateur u, Livre inventaire[], int nbLivres);
int peutAjouterLivre(Utilisateur u);

int traiterEmprunt(int idLivre, char loginUtilisateur[], Livre inventaire[], int nbLivres, Utilisateur liste[], int nbUtilisat);
int traiterRetour(int idLivre, char loginUtilisateur[], Livre inventaire[], int nbLivres, Utilisateur liste[], int nbUtilisat);

void trierLivresTitre(Livre inventaire[], int nbLivres);
void trierLivresAuteur(Livre inventaire[], int nbLivres);
void rechercherParCategorie(Livre inventaire[], int nbLivres, char categorieCible[]);

#endif



