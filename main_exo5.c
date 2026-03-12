#include <stdio.h> // for printf, scanf , fgets
#include <time.h> // time()
#include <stdlib.h> // malloc, calloc, rand, srand, free, realloc

int main() {
    // init algo aleatoire
    srand(time(NULL));

    // variables
    int **tab = NULL;
    int nbL, nbC;

    // input
    printf("Donnez le nb lignes et colonnes:");
    scanf("%d %d", &nbL, &nbC);


    // allocation memoire
    tab = calloc(nbL,sizeof(int*));
    for (int i = 0; i < nbL; ++i) {
        tab[i] = calloc(nbC, sizeof(int));
    }

    // remplisage de la matrice
    for (int i = 0; i < nbL; i++) {
        for (int j = 0; j < nbC; j++) {
            tab[i][j] = rand()%256;
        }
    }

    // affichage
    for (int i = 0; i < nbL; i++) {
        for (int j = 0; j < nbC; j++) {
            printf("%d\t", tab[i][j]);
        }
        printf("\n");
    }

    // libération memoire
    for (int i = 0; i < nbL; ++i) {
        free(tab[i]);
    }
    free(tab);


    return 0;
}