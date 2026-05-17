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
            if (choix != 1 && choix != 2) {                   //Securisation du choix
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
    printf("Votre compte a été créé avec succès ");
    printf("%s", login);
    printf("!");
    printf("\033[0m");
    printf("\n");
    printf("\n▬▬▶ Appuyez sur Entrée pour continuer.");
    viderbuffer();
    getchar();
}







void menuPrincipal() {    // Utilisateur choix : emprunt, retour, savoir où il en est//
    printf("\033[2J\033[H");  // efface écran 
    printf("╔═══════════════════════════════════════════════════════════════════════════════╗\n");
    printf("║    ");
    printf("\033[1;36m");  //bleu pour tout le texte + gras avec "1"//
    printf("Nom utilisateur : %s                                                         ", &Utilisateur.nom); 
    printf("\033[0m");   // retour blanc //
    printf("║\n");
    printf("╠═══════════════════════════════════════════════════════════════════════════════╣\n");
    printf("║");
    printf("\033[1;36m");  //bleu pour tout le texte//
    printf(" 1. Emprunter un nouveau livre                                                 ");
    printf("\033[0m");   // retour blanc //
    printf("║\n");
    printf("║");
    printf("\033[1;36m");  //bleu pour tout le texte//
    printf(" 2. Rendre un livre                                                            ");
    printf("\033[0m");   // retour blanc //
    printf("║\n");
    printf("║");
    printf("\033[31m");  // rouge //
    printf(" 3. Se deconnecter                                                             ");
    printf("\033[0m"); // retour blanc //
    printf("║\n");
    printf("╚═══════════════════════════════════════════════════════════════════════════════╝\n");
    printf("\n");
    printf("\n");

    printf("▬▬▶Entrer le chiffre correspondant à votre demande.\n");
    return 0;
}



int deconnection(){
    printf("\033[2J\033[H");  // efface écran 
    int a;
    printf("┌────────────────────────────────────────────────────────────┐\n"); 
    printf("│");
    printf("\033[1;36m");  //bleu pour tout le texte//
    printf("          Voulez-vous vraiment vous deconnecter?            ");
    printf("\033[0m"); // retour blanc //
    printf("│\n");
    printf("│");
    printf("\033[1;36m");  //bleu pour tout le texte//
    printf(" 1.Oui                                                      ");
    printf("\033[0m"); // retour blanc //    
    printf("│\n");
    printf("│");
    printf("\033[31m");  // rouge //
    printf(" 2.Non                                                      ");
    printf("\033[0m"); // retour blanc //
    printf("│\n");
    printf("└────────────────────────────────────────────────────────────┘\n");
    printf("\n");
    printf("\n");
    
    printf("▬▬▶Entrer le chiffre correspondant à votre demande.\n");

    do{
    a = saisirEntierSecurise(a);
    }while(a != 1 && a != 2);
    if (a == 1){
        return 1;
    } else{ 
        return 0;
    }
}




void emprunterlivre(){
    printf("\033[2J\033[H");  // efface écran 
    printf("╔═══════════════════════════════════════════════════════════════════════════════╗\n");
    printf("║    ");
    printf("\033[1;36m");  //bleu pour tout le texte + gras avec "1"//
    printf("                     Emprunter un nouveau livre                            "); 
    printf("\033[0m");   // retour blanc //
    printf("║\n");
    printf("╠═══════════════════════════════════════════════════════════════════════════════╣\n");
    printf("║");
    printf("\033[1;36m");  //bleu pour tout le texte//
    printf(" 1.Rechercher                                                                  ");
    printf("\033[0m");   // retour blanc //
    printf("║\n");
    printf("║");
    printf("\033[1;36m");  //bleu pour tout le texte//
    printf(" 2. Voir la liste complète                                                     ");
    printf("\033[0m");   // retour blanc //
    printf("║\n");
    printf("║");
    printf("\033[1;36m");  //bleu pour tout le texte//
    printf(" 3. Quitter                                                                    ");
    printf("\033[0m"); // retour blanc //
    printf("║\n");
    printf("╚═══════════════════════════════════════════════════════════════════════════════╝\n");
    printf("\n");
    printf("\n");

    printf("▬▬▶Entrer le chiffre correspondant à votre demande.\n");
    return 0;
}





void rendrelivre(Utilisateur u) {
    printf("\033[2J\033[H");  // efface écran 
    printf("╔═══════════════════════════════════════════════════════════════════════════════╗\n");
    printf("║    ");
    printf("\033[1;36m");
    printf("                        Rendre un livre                                   ");
    printf("\033[0m");
    printf("║\n");
    printf("╠═══════════════════════════════════════════════════════════════════════════════╣\n");

    // si l'utilisateur n'a aucun livre
    if (u.nbEmprunts == 0) {
        printf("║");
        printf("\033[31m");
        printf(" Vous n'avez aucun livre emprunté                                              ");
        printf("\033[0m");
        printf("║\n");

    } else {
        // afficher chaque livre emprunté
        for (int i = 0; i < u.nbEmprunts; i++) {
            printf("║");
            printf("\033[1;36m");
            printf(" %d. %-30s | %-20s | %-15s | ID: %d",bi+1, tabLivres[u.emprunts[i]].titre, tabLivres[u.emprunts[i]].auteur, tabLivres[u.emprunts[i]].categorie, u.emprunts[i]);
            printf("\033[0m");
            printf("║\n");
        }
    }

    printf("╚═══════════════════════════════════════════════════════════════════════════════╝\n");
    printf("\n");
    printf("▬▬▶Entrer le chiffre correspondant à votre demande.\n");
}
