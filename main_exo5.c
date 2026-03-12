#include <stdio.h> // for printf, scanf , fgets
#include <time.h> // time()
#include <stdlib.h> // malloc, calloc, rand, srand, free, realloc

// creation matrice
int**  creationMatf(int *pnbL, int *pnbC) {
    int** tab= NULL;

    // input
    printf("Donnez le nb lignes et colonnes:");
    scanf("%d %d", pnbL, pnbC);

    // allocation memoire
    tab = calloc(*pnbL,sizeof(int*));
    for (int i = 0; i < *pnbL; ++i) {
        tab[i] = calloc(*pnbC, sizeof(int));
    }

    return  tab;
}

void creationMats(int *** ptab, int *pnbL, int *pnbC) {
    // input
    printf("Donnez le nb lignes et colonnes:");
    scanf("%d %d", pnbL, pnbC);

    // allocation memoire
    // *ptab = tab(main)
    *ptab = calloc(*pnbL,sizeof(int*));
    for (int i = 0; i < *pnbL; ++i) {
        (*ptab)[i] = calloc(*pnbC, sizeof(int));
    }
}


void remMat(int ** tab,const int nbL,const int nbC) {
    // remplisage de la matrice
    for (int i = 0; i < nbL; i++) {
        for (int j = 0; j < nbC; j++) {
            tab[i][j] = rand()%256;
        }
    }
}

void affMat(int **tab, const int nbL,const int nbC) {
    for (int i = 0; i < nbL; i++) {
        for (int j = 0; j < nbC; j++) {
            printf("%d\t", tab[i][j]);
        }
        printf("\n");
    }
}


int main() {
    // init algo aleatoire
    srand(time(NULL));

    // variables
    int **tab = NULL;
    int nbL, nbC;

    // creation de la matrice
    //tab = creationMatf(&nbL, &nbC);
    creationMats(&tab, &nbL, &nbC);
    remMat(tab,nbL,nbC);

    // affichage
    affMat(tab, nbL,nbC);

    // libération memoire
    for (int i = 0; i < nbL; ++i) {
        free(tab[i]);
    }
    free(tab);


    return 0;
}