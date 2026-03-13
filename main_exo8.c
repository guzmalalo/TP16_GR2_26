#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int x;
    int y;
} Coord;

void ajouter(Coord* tab[6], int tPhys, int* tLog) {
    if (*tLog == tPhys) {
        printf("Désole le tableau est plein");
        return;
    }
    int x,y;

    printf("Donnez les coordonées x, y :");
    scanf("%d %d", &x, &y);

    Coord* temp = malloc(sizeof(Coord));
    temp->x = x;
    temp->y = y;

    tab[*tLog] = temp;
    (*tLog)++;
}

void afficher(Coord* tab[6], int tLog) {
    printf("--- Liste de coordonées :\n");

    for (int i = 0; i < tLog; ++i) {
        printf("Point %d (%d,%d)\n", i, tab[i]->x, tab[i]->y);
    }
    printf("--- Fin de la liste\n");
}

int main() {
    // variables
    Coord* tab[6] ={0};

    //a faire
    //Coord * *tab = malloc(6*sizeof(Coord*));
    int nbCoordMax  = 6;
    int nbCoord =0;
    int x, y;
    int choix=0;

    // Menu
    do {
        printf("\n-------Menu---------\n");
        printf("1 : Ajouter un point \n");
        printf("2 : Afficher les points \n");
        printf("3 : Sortir \n");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                ajouter(tab, 6, &nbCoord);
                break;
            case 2:
                afficher(tab, nbCoord);
                break;
            default:
                break;
        } // fin du switch
    } while (choix < 3 && choix > 0);


    // Liberation
    for (int i = 0; i < nbCoord; ++i) {
        free(tab[i]);
        tab[i] = NULL;
    }

    return 0;
}