#ifndef INTERFACE_H
#define INTERFACE_H

#include "donnees.h"

void viderbuffer();
int saisirEntierSecurise();
void afficherAccueil();
void afficherStatusUtilisateur(Utilisateur u);
void afficherMenuDepart();
void afficherCreerCompte();
int afficherSeConnecter();
void afficherMenuPrincipal(Utilisateur u);
int afficherVerifDeconnection();
void afficherEmprunterLivre(Utilisateur u);
void afficherRendreLivre(Utilisateur u);

#endif



