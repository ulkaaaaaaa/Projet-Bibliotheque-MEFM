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
    printf("\033[1;36m"); //cyan pour tout le texte + gras avec "1"//
    printf("╔═══════════════════════════════════════════════════════════════════════════════╗\n");
    printf("║   Bienvenue dans la bibliothèque en ligne de votre établissement CY-Tech")    ║\n");
    printf("╚═══════════════════════════════════════════════════════════════════════════════╝\n");
    printf("║ 1. Se connecter                                                               ║\n");
    printf("
    printf("║ 2. Créer un compte                                                            ║\n");
    printf("║ 3. Quitter                                                                    ║\n");
    printf("╚═══════════════════════════════════════════════════════════════════════════════╝\n");
    printf("\n");
    printf("▬▬▶Entrer le chiffre correspondant à votre demande."\n);


void menuPrincipal() {
}
