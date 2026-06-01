#ifndef DONNEES_H
#define DONNEES_H

#include <time.h>
#include <string.h>

#define MAX_LIVRES 200
#define MAX_UTILISATEURS 100
#define MAX_LIVRES_PROF 5
#define MAX_LIVRES_ETUDIANT 3
#define ETUDIANT 0
#define PROFESSEUR 1

/*Structures*/
typedef struct {
    int id;
    char titre[100];
    char auteur[100];
    char categorie[50];
    int estEmprunte;/* 0 = libre, 1 = pris */
    time_t dateRetour;/* Heure limite*/
    char loginEmprunteur[50]; 
} Livre;

typedef struct {
    char login[50];
    char mdp[21]; 
    int role;/* 0 pour etudiant, 1 pour prof */
    int nbLivresActuels;/* Compteur gere par le code d'Uliana */
} Utilisateur;


extern Livre tabLivres[MAX_LIVRES];
extern Utilisateur tabUtilisateurs[MAX_UTILISATEURS];
extern int nbLivres;
extern int nbUtilisateurs;


/* Fonction de youssef */
void initialiserBibliotheque();
int ajouterLivre(char titre[],char auteur[],char categorie[]);
int chargerLivres(char nomFichier[]);
int chargerUtilisateurs(char nomFichier[]);
int sauvegarderLivres(char nomFichier[]);
int sauvegarderUtilisateurs(char nomFichier[]);
int authentifier(char login[], char motDePasse[]);
int creerCompte(char login[], char motDePasse[], int role);
void afficherLivres();
void afficherUtilisateurs();



/* fonction uliana */
time_t calculerDateRetour(int role);
int verifierRetard(time_t limite);
int avoirDesRetards(Utilisateur u, Livre inventaire[], int nbLivres);
int peutEmprunter(Utilisateur u, Livre inventaire[], int nbLivres);
int peutAjouterLivre(Utilisateur u);

int traiterEmprunt(int idLivre, char loginUtilisateur[], Livre inventaire[], int nbLivres, Utilisateur liste[], int nbUtilisat);
int traiterRetour(int idLivre, char loginUtilisateur[], Livre inventaire[], int nbLivres, Utilisateur liste[], int nbUtilisat);

void trierLivresTitre(Livre inventaire[], int nbLivres);
void trierLivresAuteur(Livre inventaire[], int nbLivres);
int rechercherParCategorie(Livre inventaire[], int nbLivres, char categorieCible[]);

#endif



