#include <stdio.h>
#include <unistd.h>   //pour les pauses entre les points pour la fonction


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



void afficherAccueil(){
    printf("\033[2J\033[H");  // efface écran 
    printf("╔═══════════════════════════════════════════════════════════════════════════════╗\n");
    printf("║                                ");
    printf("\033[1;36m");
    printf("CY-biblioTECH                                  ");   //bleu pour tout le texte + gras avec "1"//
    printf("\033[0m");   // retour blanc //
    printf("║\n");
    printf("║                         ");
    printf("\033[1;36m");
    printf("Bibliothèque universitaire                            ");
    printf("\033[0m"); // retour blanc //
    printf("║\n");
    printf("╚═══════════════════════════════════════════════════════════════════════════════╝\n");
    
    // chargement  ...//
    printf("\nChargement");
    fflush(stdout);
    for (int i = 0; i < 7; i++) {
        usleep(300000);
        printf(".");
        fflush(stdout);
    }

    // attendre entrée
    printf("\n\n");
    printf("▬▬▶ Appuyez sur Entrée pour continuer.");
    viderbuffer();   //Evite : utilisateur déjà appuyé sur Entrée avant d'arriver à getchar --> tampon a déjà un \n et donc pas de logo car passe toujt de suite
    getchar();
}







void afficherMenuDepart() {
    printf("\033[2J\033[H");  // efface écran 
    printf("╔═══════════════════════════════════════════════════════════════════════════════╗\n");
    printf("║    ");
    printf("\033[1;36m");  //bleu pour tout le texte + gras avec "1"//
    printf("Bienvenue dans la bibliothèque en ligne de votre établissement CY-Tech     ");
    printf("\033[0m");   // retour blanc //
    printf("║\n");
    printf("╠═══════════════════════════════════════════════════════════════════════════════╣\n");
    printf("║");
    printf("\033[1;36m");  //bleu pour tout le texte//
    printf(" 1. Se connecter                                                               ");
    printf("\033[0m");   // retour blanc //
    printf("║\n");
    printf("║");
    printf("\033[1;36m");  //bleu pour tout le texte//
    printf(" 2. Créer un compte                                                            ");
    printf("\033[0m");   // retour blanc //
    printf("║\n");
    printf("║");
    printf("\033[31m");  // rouge //
    printf(" 3. Quitter                                                                    ");
    printf("\033[0m"); // retour blanc //
    printf("║\n");
    printf("╚═══════════════════════════════════════════════════════════════════════════════╝\n");
    printf("\n");
    printf("\n");

    printf("▬▬▶Entrer le chiffre correspondant à votre demande.\n");
}




void afficherCreerCompte(){
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
    printf("                        Créer un compte                                   ");
    printf("\033[0m");
    printf("║\n");
    printf("╚═══════════════════════════════════════════════════════════════════════════════╝\n");
 
    do {         // boucle globale : recommence si identifiant déjà pris
        resultat = 0;

        // boucle identifiant
        do {
            valide = 1;
            printf(" ▫ Identifiant (entre 4 et 20 caractères) : ");
            fgets(login, sizeof(login), stdin);
            if (login[strlen(login)-1] != '\n') {
                viderbuffer();  // vide le reste si trop long
            }
            login[strcspn(login, "\n")] = '\0';

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
                    printf("\033[31mErreur : caractère interdit.\033[0m\n");
                    sleep(1);
                    printf("\033[1A\033[2K");    //Remonte le curseur d'une ligne vers le haut
                    printf("\033[1A\033[2K");        //Efface toute la ligne où est le curseur
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

            if (strlen(mdp) < 4 || strlen(mdp) > 20) {            
                printf("\033[31mErreur : entre 4 et 20 caractères.\033[0m\n");
                sleep(1);
                printf("\033[1A\033[2K");   //Remonte le curseur d'une ligne vers le haut
                printf("\033[1A\033[2K");        //Efface toute la ligne où est le curseur
                valide = 0;
                continue;
            }

            for (i = 0; i < strlen(mdp); i++) {               //Securisation des caracteres entrés
                if (!isprint(mdp[i])) {
                    printf("\033[31mErreur : caractère interdit.\033[0m\n");
                    sleep(1);
                    printf("\033[1A\033[2K");   //Remonte le curseur d'une ligne vers le haut
                    printf("\033[1A\033[2K");        //Efface toute la ligne où est le curseur
                    valide = 0;
                    break;
                }
            }
        } while (valide == 0);

        // choix du rôle
        printf("\n");
        printf("\033[1;36m");
        printf(" ▫ Choix du rôle :  1. Etudiant  ou  2. Professeur \n");
        printf("\033[0m");
        printf("\n");
        do {
            choixrole = saisirEntierSecurise();
            if (choixrole != 1 && choixrole != 2) {                   //Securisation du choix
                printf("\033[31mErreur : tapez 1 ou 2.\033[0m\n");
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
            printf("\033[31m");
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
            printf("╚═══════════════════════════════════════════════════════════════════════════════╝\n");
            printf("\n");
        }

    } while (resultat == 0);

    printf("\033[32m");
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
    printf("                          Se connecter                                    ");
    printf("\033[0m");
    printf("║\n");
    printf("╚═══════════════════════════════════════════════════════════════════════════════╝\n");
    printf("\n");

    do {           //on vérifie, la combinaison entre le mot de passe et l'identifiant
        // saisie de l'identifiant
        printf(" ▫ Identifiant : ");
        fgets(login, sizeof(login), stdin);
        if (login[strlen(login)-1] != '\n') {
            viderbuffer();
        }
        login[strcspn(login, "\n")] = '\0';

        // saisie mot de passe
        printf(" ▫ Mot de passe : ");
        fgets(mdp, sizeof(mdp), stdin);
        if (mdp[strlen(mdp)-1] != '\n') {
            viderbuffer();
        }
        mdp[strcspn(mdp, "\n")] = '\0';

        // vérification combinaison
        index = authentifier(login, mdp);

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




void afficherMenuPrincipal(Utilisateur u) {    // Utilisateur choix : emprunt, retour, savoir où il en est//
    printf("\033[2J\033[H");  // efface écran 
    printf("╔═══════════════════════════════════════════════════════════════════════════════╗\n");
    printf("\033[1;36m");  //bleu pour tout le texte 
    printf("                                 Menu Principal                                  "); 
    printf("\033[0m");   // retour blanc //
    printf("║\n");
    printf("╠═══════════════════════════════════════════════════════════════════════════════╣\n");
    printf("║    ");
    printf("\033[1;36m");  //bleu pour tout le texte 
    printf("Nom utilisateur : %s", u.login); 
    printf("\033[0m");   // retour blanc 
    printf("║\n");
    printf("║");
    printf("\033[1;36m");  //bleu pour tout le texte
    printf(" 1. Emprunter un nouveau livre                                                 ");
    printf("\033[0m");   // retour blanc 
    printf("║\n");
    printf("║");
    printf("\033[1;36m");  //bleu pour tout le texte
    printf(" 2. Rendre un livre                                                            ");
    printf("\033[0m");   // retour blanc 
    printf("║\n");
    printf("║");
    printf("\033[31m");  // rouge 
    printf(" 3. Se deconnecter                                                             ");
    printf("\033[0m"); // retour blanc 
    printf("║\n");
    printf("╚═══════════════════════════════════════════════════════════════════════════════╝\n");
    printf("\n");
    printf("\n");

    printf("▬▬▶Entrer le chiffre correspondant à votre demande.\n");
}



int afficherVerifDeconnection(){
    int a;
    printf("\033[2J\033[H");  // efface écran 
    printf("┌────────────────────────────────────────────────────────────┐\n"); 
    printf("│");
    printf("\033[1;36m");  //bleu pour tout le texte
    printf("          Voulez-vous vraiment vous deconnecter?            ");
    printf("\033[0m"); // retour blanc 
    printf("│\n");
    printf("│");
    printf("\033[1;36m");  //bleu pour tout le texte
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

    do{
    a = saisirEntierSecurise();
    }while(a != 1 && a != 2);
    if (a == 1){
        return 1;
    } else{ 
        return 0;
    }
}




void afficherEmprunterLivre(Utilisateur u){
    int choix;
    int idChoisi;
    int resultat;
    char categorie[50];

    printf("\033[2J\033[H");  // efface écran 

    // vérification du nombre de livre autorisé et retards 
    if (peutEmprunter(u, tabLivres, nbLivres) == 0) {
        printf("┌────────────────────────────────────────────────────────────┐\n");
        printf("│");
        if (avoirDesRetards(u, tabLivres, nbLivres) == 1) {
            printf("\033[31m");        //rouge
            printf("            ◬ Vous avez des livres en retard! ◬             ");
            printf("\033[0m");
            printf("\n");
        } else {
            printf("\033[31m");         //rouge
            printf("           ◬ Nombre d'emprunt maximum atteint! ◬            ");
            printf("\033[0m");
            printf("\n");
        }
        printf("│\n");
        printf("└────────────────────────────────────────────────────────────┘\n");
        printf("\n▬▬▶ Appuyez sur Entrée pour continuer.");
        viderbuffer();
        getchar();
        return;        //Retourne au menu principal
    }
    
    printf("╔═══════════════════════════════════════════════════════════════════════════════╗\n");
    printf("║    ");
    printf("\033[1;36m");  //bleu pour tout le texte + gras avec "1"
    printf("                     Emprunter un nouveau livre                            "); 
    printf("\033[0m");   // retour blanc 
    printf("║\n");
    printf("╠═══════════════════════════════════════════════════════════════════════════════╣\n");
    printf("║");
    printf("\033[1;36m");  //bleu pour tout le texte
    printf(" 1. Rechercher par titre                                                        ");
    printf("\033[0m");   // retour blanc 
    printf("║\n");
    printf("║");
    printf("\033[1;36m");  //bleu pour tout le texte
    printf(" 2. Rechercher par auteur                                                     ");
    printf("\033[0m");   // retour blanc 
    printf("║\n");
    printf("║");
    printf("\033[1;36m");  //bleu pour tout le texte
    printf(" 3. Rechercher par catégorie                                                  ");
    printf("\033[0m");   // retour blanc 
    printf("║\n");
    printf("║");
    printf("\033[1;36m");  //bleu pour tout le texte
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
        printf("▬▬▶ Entrez la catégorie : ");         //Choix de la categorie
        fgets(categorie, sizeof(categorie), stdin);
        if (categorie[strlen(categorie)-1] != '\n') {
            viderbuffer();
        }
        categorie[strcspn(categorie, "\n")] = '\0';
        rechercherParCategorie(tabLivres, nbLivres, categorie);
    }

    printf("\n");
    printf("\n▬▬▶ Entrez l'ID du livre : ");           // saisie ID et traitement
    idChoisi = saisirEntierSecurise();

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





void afficherRendreLivre(Utilisateur u) {
    int idChoisi;
    int resultat;
    int i;
    
    printf("\033[2J\033[H");  // efface écran 
    printf("╔═══════════════════════════════════════════════════════════════════════════════╗\n");
    printf("║    ");
    printf("\033[1;36m");
    printf("                        Rendre un livre                                   ");
    printf("\033[0m");
    printf("║\n");
    printf("╠═══════════════════════════════════════════════════════════════════════════════╣\n");

    if (u.nbLivresActuels == 0) {    // si l'utilisateur n'a aucun livre
        printf("║");
        printf("\033[32m");       //vert
        printf("    Vous n'avez aucun livre emprunté.                                          ");
        printf("\033[0m");
        printf("║\n");
        printf("╚═══════════════════════════════════════════════════════════════════════════════╝\n");
        printf("\n▬▬▶ Appuyez sur Entrée pour continuer.");
        viderBuffer();
        getchar();
        return;     //retour au menu principal
    }
    printf("\033[1m");
    printf(" N° | %-30s | %-20s | %-15s | ID  ", "Titre", "Auteur", "Categorie");   //affichage numérotation | titre | auteur | categorie | ID
    printf("\033[0m");
    for (i = 0; i < u.nbLivresActuels; i++) {       // afficher chaque livre emprunté
        printf("║");
        printf("\033[1m");
        printf(" %d. %-30s | %-20s | %-15s | ID: %d", i+1, tabLivres[u.emprunts[i]].titre, tabLivres[u.emprunts[i]].auteur, tabLivres[u.emprunts[i]].categorie, u.emprunts[i]);
        printf("\033[0m");
        printf("║\n");
    }

    printf("╚═══════════════════════════════════════════════════════════════════════════════╝\n");
    printf("\n");

    do {          // saisie sécurisée de l'ID
        printf("▬▬▶ Entrez l'ID du livre à rendre : ");
        idChoisi = saisirEntierSecurise();
        resultat = 0;       // vérifier que l'ID appartient bien à l'utilisateur et non à un autre
        for (i = 0; i < u.nbLivresActuels; i++) {
            if (u.emprunts[i] == idChoisi) {
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
        printf("              Livre rendu avec succès !                      ");
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
    viderBuffer();
    getchar();
}

