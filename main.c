#include <stdio.h>
#include "donnees.h"

int main() {
    int ok;
    int indice;

    initialiserBibliotheque();

    ok = chargerLivres("livres.txt");
    if (ok == 0) {
        printf("Chargelent des livres impossible.\n");
    }

    ok = chargerUtilisateurs("utilisateurs.txt");
    if (ok == 0) {
        printf("Chargement des utilisateurs impossible.\n");
    }

    afficherLivres();
    afficherUtilisateurs();

    indice = authentifier("etudiant1", "1234");

    if (indice != -1) {
        printf("\nConnesion reussie : %s\n", tabUtilisateurs[indice].login);
    } else {
        printf("\nLogin ou mot de passe incorrect.\n");
    }

    ok = creerCompte("nouveau", "0000", "etudiant");

    if (ok == 1) {
        printf("\nCompte cree avec succes.\n");
    } else{
        printf("\nCreation du compte impossible.\n");
    }

    sauvegarderUtilisateurs("utilisateurs.txt");
    sauvegarderLivres("livres.txt");

    return 0;
}
