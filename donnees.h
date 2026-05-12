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
  int disponible; // 1 = libre , 0 = emprunté
} Livre;

typedef struct {
  char login[50];
  char motdepasse[50];       
  char role[20];
  int emprunts[MAX_EMPRUNTS]; // i
  int nbEmprunts;
} Utilisateur;

extern Livre tabLivres[MAX_EMPRUNTS];
extern UtilisateurstabUtilisateurs[MAX_UTILISATEURS];

extern int nbUtilisateurs;
extern int nbUtilisatuers;

void initialiserBibliotheque()

int chargerLivres(char nomFichier[]);
int chargerUtilisateurs(char nomFichiers[]);

int sauvegarderLivres(char nomFichiers[]);
int sauvegarderUtilisateurs(char nomFichier[]);

int authentifier(char login[], char motdepasse[]);
int creerCompte(char login[], char motdepasse[], char role[]);

void afficherLivres();
void afficherUtilisateurs();

#endif







