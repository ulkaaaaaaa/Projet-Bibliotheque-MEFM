#ifdef DONNEES_H
#define DONNEES_H
#define MAX_LIVRES 200
#define MAX_UTILISATEURS 100
#define MAX_EMPRUNTS 5

typdef struct {
  int id;
char titre[100];
char auteur[100];
char categorie[50];
int disponible;
}Livre;

typedef struct {
char login[50];
char motDePasse[50];        /
char role[20];
int emprunts[MAX_EMPRUNTS];
int nbEmprunts;
}Utilisateur;



