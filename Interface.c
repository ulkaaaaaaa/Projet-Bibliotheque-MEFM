//retirer les valeures restantes//

void viderTampon() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}


//pour les différents choix dans le menu//

int saisirEntierSecurise() {
    int entier;
    while (scanf("%d", &entier) != 1) {
        printf("Erreur : tapez un chiffre.\n");
        viderTampon();
    }
    viderTampon();  //nettoie le \n restant//
    return entier;

void menuDepart() {
    printf("╔═══════════════════════════════════════════════════════════════════════════════╗\n");
    printf("║   ");
    printf("\033[1;36m");  //bleu pour tout le texte + gras avec "1"//

    printf("Bienvenue dans la bibliothèque en ligne de votre établissement CY-Tech"    \n");

    printf("\033[0m");   // retour noir //
    printf("║");
    printf("╚═══════════════════════════════════════════════════════════════════════════════╝\n");
    printf("║");

    printf("\033[1;36m");  //bleu pour tout le texte//
    printf(" 1. Se connecter                                                               ");

    printf("\033[0m");   // retour noir //
    printf("║\n");

    printf("\033[1;36m");  //bleu pour tout le texte//
    printf(" 2. Créer un compte                                                            ");
    printf("║");

    printf("\033[0m");   // retour noir //
    printf("\033[31m");  // rouge //
    printf(" 3. Quitter                                                                    ");

    printf("\033[0m"); // retour noir //
    printf("║\n");
    printf("╚═══════════════════════════════════════════════════════════════════════════════╝\n");
    printf("\n");




    printf("▬▬▶Entrer le chiffre correspondant à votre demande."\n);


void menuPrincipal() {
}
