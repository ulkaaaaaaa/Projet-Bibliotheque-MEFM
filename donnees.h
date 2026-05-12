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



