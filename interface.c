#include <stdio.h>
#include <string.h>    // pour strlen, strcspn, strcmp
#include <ctype.h>     // pour isprint
#include <unistd.h>    // pour sleep et usleep : pour les pauses entre les points pour la fonction
#include <time.h>      // pour ctime dans afficherStatusUtilisateur
#include "donnee.h"
#include "interface.h"


//retirer les valeures restantes//

void viderbuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}


//pour les différents choix dans le menu//

int saisirEntierSecurise() {
    int entier;
    while (scanf("%d", &entier) != 1) {
        printf("Erreur : tapez un chiffre.\n");
        viderbuffer();
    }
    viderbuffer();  //nettoie le \n restant//
    return entier;
}


void afficherAccueil() {
    printf("\033[2J\033[H");  // efface écran 
    printf("╔═══════════════════════════════════════════════════════════════════════════════╗\n");
    printf("║                                ");
    printf("\033[1;36m");
    printf("CY-biblioTECH                                  ");   //bleu pour tout le texte + gras avec "1"//
    printf("\033[0m");   // retour blanc //
    printf("║\n");
    printf("║                          ");
    printf("\033[1;36m");
    printf("Bibliothèque universitaire                           ");
    printf("\033[0m"); // retour blanc //
    printf("║\n");
    printf("╚═══════════════════════════════════════════════════════════════════════════════╝\n");
    
    printf("\nChargement");         // chargement  ...
    fflush(stdout);
    for (int i = 0; i < 7; i++) {
        usleep(300000);
        printf(".");
        fflush(stdout);
    }

    printf("\n");     // attendre entrée
    printf("▬▬▶ Appuyez sur Entrée pour continuer.");
    viderbuffer();   //Evite : utilisateur déjà appuyé sur Entrée avant d'arriver à getchar --> tampon a déjà un \n et donc pas de logo car passe toujt de suite
    getchar();
}


void afficherStatusUtilisateur(Utilisateur u) {
    int i;
    printf("\033[2J\033[H");
    printf("┌────────────────────────────────────────────────────────────────────────────────┐\n");
    printf("│    ");
    printf("\033[1;36m");     //bleu et gras
    printf("                      Vos livres en cours                                   ");
    printf("\033[0m");
    printf("│\n");
    printf("├────────────────────────────────────────────────────────────────────────────────┤\n");

    if (u.nbLivresActuels == 0) {
        printf("│");
        printf("\033[32m");     //vert
        printf("   Aucun livre emprunté                                                         ");
        printf("\033[0m");
        printf("│\n");
        printf("└────────────────────────────────────────────────────────────────────────────────┘\n");
        }
    else {

        if (avoirDesRetards(u, tabLivres, nbLivres) == 1) {       // message retard 
            printf("│");
            printf("\033[31m");     //rouge
            printf("             ◬ Attention : vous avez des livres en retard !                     ");
            printf("\033[0m");
            printf("│\n");
            printf("└────────────────────────────────────────────────────────────────────────────────┘\n");
        }

        for (i = 0; i < nbLivres; i++) {             // liste des livres
            if (tabLivres[i].estEmprunte == 1 && strcmp(tabLivres[i].loginEmprunteur, u.login) == 0) {
    

                if (verifierRetard(tabLivres[i].dateRetour) == 1) {
                    printf("\033[31m");   // rouge si en retard
                } else {
                    printf("\033[1;36m"); // cyan si dans les temps
                }

                printf(" %-30s | Retour avant : %s",
                       tabLivres[i].titre,
                       ctime(&tabLivres[i].dateRetour));
                printf("\033[0m");
            }
        }
    }

    printf("\n▬▬▶ Appuyez sur Entrée pour continuer.");
    viderbuffer();
    getchar();
}


void afficherMenuDepart() {
    printf("\033[2J\033[H");  // efface écran 
    printf("╔═══════════════════════════════════════════════════════════════════════════════╗\n");
    printf("║    ");
    printf("\033[1;36m");  //bleu + gras 
    printf("Bienvenue dans la bibliothèque en ligne de votre établissement CY-Tech     ");
    printf("\033[0m");   // retour blanc 
    printf("║\n");
    printf("╠═══════════════════════════════════════════════════════════════════════════════╣\n");
    printf("║");
    printf("\033[36m");  //bleu pour 
    printf(" 1. Se connecter                                                               ");
    printf("\033[0m");   // retour blanc 
    printf("║\n");
    printf("║");
    printf("\033[36m");  //bleu 
    printf(" 2. Créer un compte                                                            ");
    printf("\033[0m");   // retour blanc 
    printf("║\n");
    printf("║");
    printf("\033[31m");  // rouge 
    printf(" 3. Quitter                                                                    ");
    printf("\033[0m"); // retour blanc 
    printf("║\n");
    printf("╚═══════════════════════════════════════════════════════════════════════════════╝\n");
    printf("\n");
    printf("\n");

    printf("▬▬▶Entrer le chiffre correspondant à votre demande.\n");
}


void afficherCreerCompte() {
    char login[50];
    char mdp[50];
    int role;
    int choixrole;
    int valide;
    int resultat;
    int i;

    printf("\033[2J\033[H");  // efface écran 
    printf("╔═══════════════════════════════════════════════════════════════════════════════╗\n");
    printf("║    ");
    printf("\033[1;36m");
    printf("                         Créer un compte                                   ");
    printf("\033[0m");
    printf("║\n");
    printf("╠═══════════════════════════════════════════════════════════════════════════════╣\n");
    printf("║");
    printf("\033[31m");
    printf(" 0. Retour (taper 'retour' lors de la saisie)                                  ");
    printf("\033[0m");
    printf("║\n");
    printf("╚═══════════════════════════════════════════════════════════════════════════════╝\n");
    printf("\n");
 
    do {         // boucle globale : recommence si identifiant déjà pris
        resultat = 0;

        // boucle identifiant
        do {
            valide = 1;
            printf("Mettre retour pour annuler\n");
            printf(" ▫ Identifiant (entre 4 et 20 caractères) : ");
            fgets(login, sizeof(login), stdin);
            if (login[strlen(login)-1] != '\n') {
                viderbuffer();  // vide le reste si trop long
            }
            login[strcspn(login, "\n")] = '\0';
            
            if (strcmp(login, "retour") == 0) {     //retour menu
                return;      
            }     

            if (strlen(login) < 4 || strlen(login) > 20) {
                printf("\033[31m");    //rouge
                printf("Erreur");
                printf("\033[0m");    //retour blanc
                sleep(1);    //attendre 1 seconde
                printf("\033[1A\033[2K");     //Remonte le curseur d'une ligne vers le haut
                printf("\033[1A\033[2K");        //Efface toute la ligne où est le curseur
                valide = 0;
                continue;
            }
                
            for (i = 0; i < strlen(login); i++) {     //Securisation des caracteres entrés
                if (!isprint(login[i])) {
                    printf("\033[31m");    //rouge
                    printf("Erreur : caractère interdit.\n");
                    printf("\033[0m");
                    sleep(1);
                    printf("\033[1A\033[2K");    
                    printf("\033[1A\033[2K");        
                    valide = 0;
                    break;
                }
            }
        } while (valide == 0);

        // boucle mot de passe
        do {
            valide = 1;
            printf(" ▫ Mot de passe (entre 4 et 20 caractères) : ");
            fgets(mdp, sizeof(mdp), stdin);
            if (mdp[strlen(mdp)-1] != '\n') {
                viderbuffer();  // vide le reste si trop long
            }
            mdp[strcspn(mdp, "\n")] = '\0';

            if (strcmp(mdp, "retour") == 0) {     //retour menu
                return;
            }

            if (strlen(mdp) < 4 || strlen(mdp) > 20) {
                printf("\033[31m");    //rouge
                printf("Erreur : entre 4 et 20 caractères.\n");
                printf("\033[0m");
                sleep(1);
                printf("\033[1A\033[2K");   
                printf("\033[1A\033[2K");        
                valide = 0;
                continue;
            }

            for (i = 0; i < strlen(mdp); i++) {                
                if (!isprint(mdp[i])) {
                    printf("\033[31m");    //rouge
                    printf("Erreur : caractère interdit.");
                    printf("\033[0m");
                    sleep(1);
                    printf("\033[1A\033[2K");   
                    printf("\033[1A\033[2K");        
                    valide = 0;
                    break;
                }
            }
        } while (valide == 0);

        // choix du rôle
        printf("\n");
        printf("\033[33m");    //jaune
        printf(" ▫ Choix du rôle :  1. Etudiant  ou  2. Professeur \n");
        printf("\033[0m");
        printf("\n");
        do {
            choixrole = saisirEntierSecurise();
            if (choixrole != 1 && choixrole != 2) {     
                printf("\033[31m");    //rouge
                printf("Erreur : tapez 1 ou 2.\n");
                printf("\033[0m");
                sleep(1);
                printf("\033[1A\033[2K");
                printf("\033[1A\033[2K");
            }
        } while (choixrole != 1 && choixrole != 2);   

        if (choixrole == 1) {
            role = 0;   // étudiant
        } else {
            role = 1;   // professeur
        }

        resultat = creerCompte(login, mdp, role);

        // si identifiant déjà pris : effacer et recommencer depuis le début
        if (resultat == 0) {
            printf("\033[31m");    //rouge
            printf("Erreur : identifiant déjà pris ou liste pleine.\n");
            printf(" Recommencez.");
            printf("\033[0m");
            printf("\n");
            sleep(2);
            printf("\033[2J\033[H");
            printf("╔═══════════════════════════════════════════════════════════════════════════════╗\n");
            printf("║    ");
            printf("\033[1;36m");
            printf("                        Créer un compte                                   ");
            printf("\033[0m");
            printf("║\n");
            printf("╠═══════════════════════════════════════════════════════════════════════════════╣\n");
            printf("║");
            printf("\033[31m");
            printf(" 0. Retour (taper 'retour' lors de la saisie)                                  ");
            printf("\033[0m");
            printf("║\n");
            printf("╚═══════════════════════════════════════════════════════════════════════════════╝\n");
            printf("\n");
        }

    } while (resultat == 0);

    printf("\033[32m");  //vert
    printf("\nVotre compte a été créé avec succès ");
    printf("%s", login);
    printf("!");
    printf("\033[0m");
    printf("\n");
    printf("\n▬▬▶ Appuyez sur Entrée pour continuer.");
    viderbuffer();
    getchar();
}


int afficherSeConnecter() {
    char login[50];
    char mdp[50];
    int index;

    printf("\033[2J\033[H");
    printf("╔═══════════════════════════════════════════════════════════════════════════════╗\n");
    printf("║    ");
    printf("\033[1;36m");
    printf("                           Se connecter                                    ");
    printf("\033[0m");
    printf("║\n");
    printf("╚═══════════════════════════════════════════════════════════════════════════════╝\n");
    printf("\n");
    printf("Mettre retour pour annuler\n");
    
    do {            // saisie de l'identifiant
        printf(" ▫ Identifiant : ");
        fgets(login, sizeof(login), stdin);
        if (login[strlen(login)-1] != '\n') {
            viderbuffer();
        }
        login[strcspn(login, "\n")] = '\0';

        if (strcmp(login, "retour") == 0){    //retour menu
            return -1;
        }

        
        printf(" ▫ Mot de passe : ");     // saisie mot de passe
        fgets(mdp, sizeof(mdp), stdin);
        if (mdp[strlen(mdp)-1] != '\n') {
            viderbuffer();
        }
        mdp[strcspn(mdp, "\n")] = '\0';

        if (strcmp(mdp, "retour") == 0){    //retour menu
            return -1;
        }

        
        index = authentifier(login, mdp);          // vérification combinaison

        if (index == -1) {
            printf("\033[31m");
            printf("Identifiants incorrects.");
            printf(" Réessayez.");
            printf("\033[0m");
            printf("\n");
            sleep(1);
            printf("\033[1A\033[2K");  // efface erreur
            printf("\033[1A\033[2K");  // efface mdp
            printf("\033[1A\033[2K");  // efface login
        }

    } while (index == -1);

    printf("\033[32m");
    printf("Connexion réussie ! Bonjour ");
    printf("%s", login);
    printf(".");
    printf("\033[0m");
    printf("\n");

    return index;
}


void afficherMenuPrincipal(Utilisateur u) {    
    printf("\033[2J\033[H");  // efface écran 
    printf("╔═══════════════════════════════════════════════════════════════════════════════╗\n");
    printf("║");
    printf("\033[1;36m");  //bleu pour tout le texte 
    printf("                                Menu Principal                                 "); 
    printf("\033[0m");   // retour blanc //
    printf("║\n");
    printf("╠═══════════════════════════════════════════════════════════════════════════════╣\n");
    printf("║    ");
    printf("\033[36m");  //bleu 
    printf("Nom utilisateur : %s", u.login); 
    printf("\033[0m");   // retour blanc 
    printf("\n");
    printf("║");
    printf("\033[36m");  //bleu 
    printf(" 1. Emprunter un nouveau livre                                                 ");
    printf("\033[0m");   // retour blanc 
    printf("║\n");
    printf("║");
    printf("\033[36m");  //bleu 
    printf(" 2. Rendre un livre                                                            ");
    printf("\033[0m");   // retour blanc 
    printf("║\n");
    printf("║");
    printf("\033[31m");  // rouge 
    printf(" 3. Se deconnecter                                                             ");
    printf("\033[0m"); // retour blanc 
    printf("║\n");
    
    if (u.role == PROFESSEUR) {  // Si prof : ajout d'un livre possible
        printf("║");
        printf("\033[33m");  // Jaune
        printf(" 4. Ajouter un livre au catalogue                                              ");
        printf("\033[0m");   
        printf("║\n");
    }
    
    printf("╚═══════════════════════════════════════════════════════════════════════════════╝\n");
    printf("\n");
    printf("\n");

    printf("▬▬▶Entrer le chiffre correspondant à votre demande.\n");
}


int afficherVerifDeconnexion() {
    int a;
    printf("\033[2J\033[H");  // efface écran 
    printf("┌────────────────────────────────────────────────────────────┐\n"); 
    printf("│");
    printf("\033[31m");  //rouge 
    printf("          Voulez-vous vraiment vous deconnecter?            ");
    printf("\033[0m"); // retour blanc 
    printf("│\n");
    printf("│");
    printf("\033[36m");  //bleu 
    printf(" 1.Non                                                      ");
    printf("\033[0m"); // retour blanc  
    printf("│\n");
    printf("│");
    printf("\033[31m");  // rouge 
    printf(" 2.Oui                                                      ");
    printf("\033[0m"); // retour blanc 
    printf("│\n");
    printf("└────────────────────────────────────────────────────────────┘\n");
    printf("\n");
    printf("\n");
    
    printf("▬▬▶Entrer le chiffre correspondant à votre demande.\n");

    do {
        a = saisirEntierSecurise();
    } while (a != 1 && a != 2);
    
    if (a == 1) {
        return 1;
    } else { 
        return 0;
    }
}


void afficherEmprunterLivre(Utilisateur u) {
    int choix;
    int idChoisi;
    int resultat;
    char categorie[50];
    char categories[50][50];
    int nbCategories;
    int i;
    int j;
    int dejaTrouvee;
    int categorie_existe;

    printf("\033[2J\033[H");  // efface écran 

    if (peutEmprunter(u, tabLivres, nbLivres) == 0) {            // vérification du nombre de livre autorisé et retards 
        printf("┌────────────────────────────────────────────────────────────┐\n");
        printf("│");
        if (avoirDesRetards(u, tabLivres, nbLivres) == 1) {
            printf("\033[1;31m");        //rouge
            printf("            ◬ Vous avez des livres en retard! ◬             ");
            printf("\033[0m");
            printf("│\n");
        } else {
            printf("\033[1;31m");         //rouge
            printf("           ◬ Nombre d'emprunt maximum atteint! ◬             ");
            printf("\033[0m");
            printf("│\n");
        }
        printf("└────────────────────────────────────────────────────────────┘\n");
        printf("\n▬▬▶ Appuyez sur Entrée pour continuer.");
        viderbuffer();
        getchar();
        return;        //Retourne au menu principal
    }
    
    printf("╔═══════════════════════════════════════════════════════════════════════════════╗\n");
    printf("║    ");
    printf("\033[1;36m");  //bleu et gras
    printf("                      Emprunter un nouveau livre                            "); 
    printf("\033[0m");   // retour blanc 
    printf("║\n");
    printf("╠═══════════════════════════════════════════════════════════════════════════════╣\n");
    printf("║");
    printf("\033[36m");  //bleu 
    printf(" 1. Rechercher par titre                                                       ");
    printf("\033[0m");   // retour blanc 
    printf("║\n");
    printf("║");
    printf("\033[36m");  //bleu 
    printf(" 2. Rechercher par auteur                                                      ");
    printf("\033[0m");   // retour blanc 
    printf("║\n");
    printf("║");
    printf("\033[36m");  //bleu 
    printf(" 3. Rechercher par catégorie                                                   ");
    printf("\033[0m");   // retour blanc 
    printf("║\n");
    printf("║");
    printf("\033[36m");  //bleu 
    printf(" 0. Quitter                                                                    ");
    printf("\033[0m"); // retour blanc 
    printf("║\n");
    printf("╚═══════════════════════════════════════════════════════════════════════════════╝\n");
    printf("\n");
    printf("\n");

    printf("▬▬▶Entrer le chiffre correspondant à votre demande.\n");

    do {
        choix = saisirEntierSecurise();
        if (choix < 0 || choix > 3) {
            printf("\033[31m");
            printf("Choix invalide.");
            printf("\033[0m");
            printf("\n");
        }
    } while (choix < 0 || choix > 3);

    if (choix == 0) {    //Selectionner RETOUR donc retour au menu principal
        return;        
    }

    printf("\033[2J\033[H");     //efface ecran

    if (choix == 1) {         //Tri par titre
        trierLivresTitre(tabLivres, nbLivres);
        afficherLivres();
    } else if (choix == 2) {        //Tri par auteur
        trierLivresAuteur(tabLivres, nbLivres);
        afficherLivres();
    } else if (choix == 3) {        //Tri par categorie

        nbCategories = 0;         // trouver toutes les catégories sans doublon
        for (i = 0; i < nbLivres; i++) {
            dejaTrouvee = 0;
            for (j = 0; j < nbCategories; j++) {
                if (strcmp(tabLivres[i].categorie, categories[j]) == 0) {
                    dejaTrouvee = 1;
                    break;
                }
            }
            if (dejaTrouvee == 0) {
                strcpy(categories[nbCategories], tabLivres[i].categorie);
                nbCategories++;
            }
        }

        printf("Catégories disponibles : ");        // afficher des catégories disponibles
        for (j = 0; j < nbCategories; j++) {
            printf("%s", categories[j]);
            if (j < nbCategories - 1) printf(", ");
        }
        printf("\n");

        categorie_existe = 0;  // saisie de la catégorie
        while (categorie_existe != 1) {
            printf("▬▬▶ Entrez la catégorie (retour pour annuler) : ");         //Choix de la categorie
            fgets(categorie, sizeof(categorie), stdin);
            if (categorie[strlen(categorie)-1] != '\n') {
                viderbuffer();
            }
            categorie[strcspn(categorie, "\n")] = '\0';
        
            if (strcmp(categorie, "retour") == 0) {     //retour menu
                return;
            }
            categorie_existe = rechercherParCategorie(tabLivres, nbLivres, categorie);
        }
    }

    printf("\n");
    printf("\n▬▬▶ Entrez l'ID du livre (0 pour retour) : ");          // saisie ID et traitement
    idChoisi = saisirEntierSecurise();
    if (idChoisi == 0) {
        return;
    }

    resultat = traiterEmprunt(idChoisi, u.login, tabLivres, nbLivres, tabUtilisateurs, nbUtilisateurs);
    printf("┌────────────────────────────────────────────────────────────┐\n");
    printf("│");
    if (resultat == 1) {
        printf("\033[32m");    //vert
        printf("                Emprunt effectué avec succès !              ");
        printf("\033[0m");
    } else {
        printf("\033[31m");     //rouge
        printf("         Erreur : livre indisponible ou introuvable.        ");
        printf("\033[0m");
    }
    printf("│\n");
    printf("└────────────────────────────────────────────────────────────┘\n");

    printf("\n▬▬▶ Appuyez sur Entrée pour continuer.");
    viderbuffer();
    getchar();
}



cvoid afficherRendreLivre(Utilisateur u) {
    int idChoisi;
    int resultat;
    int i;
    
    printf("\033[2J\033[H");  // efface écran 
    printf("╔═══════════════════════════════════════════════════════════════════════════════╗\n");
    printf("║    ");
    printf("\033[1;36m");
    printf("                         Rendre un livre                                   ");
    printf("\033[0m");
    printf("║\n");
    printf("╠═══════════════════════════════════════════════════════════════════════════════╣\n");
    

    if (u.nbLivresActuels == 0) {    // si l'utilisateur n'a aucun livre
        printf("║");
        printf("\033[32m");        //vert
        printf("   Vous n'avez aucun livre emprunté.                                           ");
        printf("\033[0m");
        printf("║\n");
        printf("╚═══════════════════════════════════════════════════════════════════════════════╝\n");
        printf("\n▬▬▶ Appuyez sur Entrée pour continuer.");
        viderbuffer();
        getchar();
        return;     //retour au menu principal
    }

    printf("║");        // titre des colonnes
    printf("\033[1m");
    printf(" %-35s | %-20s | %-5s", "Titre", "Auteur", "ID");
    printf("\033[0m");
    printf("║\n");
    printf("╠═══════════════════════════════════════════════════════════════════════════════╣\n");

    
    for (i = 0; i < nbLivres; i++) {       //Recherche par loginEmprunteur pour retrouver les livres de l'utilisateur
        if (tabLivres[i].estEmprunte == 1 && strcmp(tabLivres[i].loginEmprunteur, u.login) == 0) {
            printf("║");
            printf("\033[1m");    //gras
            printf(" %-35s | %-20s | %-5d", tabLivres[i].titre, tabLivres[i].auteur, tabLivres[i].id);
            printf("\033[0m");
            printf("║\n");
        }
    }

    printf("╠═══════════════════════════════════════════════════════════════════════════════╣\n");
    printf("║");
    printf("\033[31m");
    printf(" 0. Retour                                                                     ");
    printf("\033[0m");
    printf("║\n");
    printf("╚═══════════════════════════════════════════════════════════════════════════════╝\n");
    printf("\n");

    do {          // saisie sécurisée de l'ID
        printf("▬▬▶ Entrez l'ID du livre à rendre : ");
        idChoisi = saisirEntierSecurise();
        
        if (idChoisi == 0) return; //retour au menu principal
        
        resultat = 0;       // vérifier que l'ID appartient bien à l'utilisateur
        for (i = 0; i < nbLivres; i++) {
            if (tabLivres[i].id == idChoisi && tabLivres[i].estEmprunte == 1 && strcmp(tabLivres[i].loginEmprunteur, u.login) == 0) {
                resultat = 1;
                break;
            }
        }
        
        if (resultat == 0) {
            printf("┌────────────────────────────────────────────────────────────┐\n");
            printf("│");
            printf("\033[31m");            //rouge
            printf("   Cet ID ne correspond pas à un de vos livres.             ");
            printf("\033[0m");
            printf("│\n");
            printf("└────────────────────────────────────────────────────────────┘\n");
        }
     } while (resultat == 0);

    resultat = traiterRetour(idChoisi, u.login, tabLivres, nbLivres, tabUtilisateurs, nbUtilisateurs);          // traitement du retour                

    if (resultat == 1) {
        printf("┌────────────────────────────────────────────────────────────┐\n");
        printf("│");
        printf("\033[32m");              //vert
        printf("              Livre rendu avec succès !                     ");
        printf("\033[0m");
        printf("│\n");
        printf("└────────────────────────────────────────────────────────────┘\n");
    } else {
        printf("┌────────────────────────────────────────────────────────────┐\n");
        printf("│");
        printf("\033[31m");         //rouge
        printf("         Erreur : livre introuvable ou déjà rendu.           ");
        printf("\033[0m");
        printf("│\n");
        printf("└────────────────────────────────────────────────────────────┘\n");
    }

    printf("\n▬▬▶ Appuyez sur Entrée pour continuer.");
    viderbuffer();
    getchar();
}





