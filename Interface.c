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
    viderTampon();   //Evite : utilisateur déjà appuyé sur Entrée avant d'arriver à getchar --> tampon a déjà un \n et donc pas de logo car passe toujt de suite
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
