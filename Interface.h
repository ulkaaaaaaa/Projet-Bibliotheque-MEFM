#ifndef INTERFACE_H
#define INTERFACE_H

#include "donnees.h"

void viderbuffer();
int saisirEntierSecurise();
void afficherAccueil();   //logo debut avec chargement
void afficherStatusUtilisateur(Utilisateur u);      //indication des livres en cours; emprunt et retour
void afficherMenuDepart();      //choix entre creer un compte, se connecter ou quitter
void afficherCreerCompte();      //creation d'un compte
int afficherSeConnecter();          //connexion
void afficherMenuPrincipal(Utilisateur u);        //choix entre emprunter/rendre un livre ou se deconnecter
int afficherVerifDeconnexion();            //verification de deconnexion
void afficherEmprunterLivre(Utilisateur u);            //choix entre rechercher par titre/auteur/catégorie ou retour au menu principal
void afficherRendreLivre(Utilisateur u);        //affichage des livres à rendre

#endif



