//retirer les valeures restantes//

void viderTampon() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}


//pour les différents choix dans le menu//

void saisirEntierSecurise() {
    int entier;
    while (scanf("%d", &entier) != 1) {
        printf("Erreur : tapez un chiffre.\n");
        viderTampon();
    }
    viderTampon();  //nettoie le \n restant//
    return valeur;
