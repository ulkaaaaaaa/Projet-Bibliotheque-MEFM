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

void menuDepart() {
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
    return 0;

}



void menuPrincipal() {    // Utilisateur choix : emprunt, retour, savoir où il en est//
    printf("╔═══════════════════════════════════════════════════════════════════════════════╗\n");
    printf("║    ");
    printf("\033[1;36m");  //bleu pour tout le texte + gras avec "1"//

    printf("Nom utilisateur : %s", &utilisateur.nom); 

    printf("\033[0m");   // retour blanc //
    printf("║\n");
    printf("╠═══════════════════════════════════════════════════════════════════════════════╣\n");
    printf("║");

    printf("\033[1;36m");  //bleu pour tout le texte//
    printf(" 1. Emprunter un nouveau livre                                               ");

    printf("\033[0m");   // retour blanc //
    printf("║\n");
    printf("║");
    printf("\033[1;36m");  //bleu pour tout le texte//
    printf(" 2. Rendre un livre                                                          ");

    printf("\033[0m");   // retour blanc //
    printf("║\n");
    printf("║");
    printf("\033[1;36m");  //bleu pour tout le texte//
    printf(" 3. Voir mes retards                                                          ");

    printf("\033[0m");   // retour blanc //
    printf("║\n");
    printf("║");
    printf("\033[31m");  // rouge //
    printf(" 4. Se deconnecter                                                                    ");

    printf("\033[0m"); // retour blanc //
    printf("║\n");
    printf("╚═══════════════════════════════════════════════════════════════════════════════╝\n");
    printf("\n");
    printf("\n");

    printf("▬▬▶Entrer le chiffre correspondant à votre demande.\n");
    return 0;
}

int deconnection(){
    int a;
    printf("┌────────────────────────────────────────────────────────────┐\n"); 
    printf("│");
    printf("│     Voulez-vous vraiment vous deconnecter?");
    printf("│\n");
    printf("│");
    printf(" 1.Oui")
    printf("│\n");
    printf("│");
    printf(" 2.Non");
    printf("│\n");
    do{
    a = saisirEntierSecurise(a);
    }while(a != 1 || a != 2);
    if (a == 1){
        return 1;
    } else{ 
        return 0;
    }
}
