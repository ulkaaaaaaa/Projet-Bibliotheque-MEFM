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
    printf("Bienvenue dans la bibliothèque en ligne de votre établissement CY-Tech")
    printf(" Se connecter ")
    printf(" Créer un compte ")
    printf(" Quitter ")



void menuPrincipal() {
}
