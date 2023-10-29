#include <stdio.h>
#include <stdlib.h>
#define LIGNES 6
#define COLONNES 7

#define TRUE 256
#define FALSE 0

enum jeton {CROIX=1, ROND=2};
typedef struct {
  char pseudo[20];
  enum jeton couleur;
}joueur;

void afficher_plateau(int tableau[LIGNES][COLONNES]) {
    for (int i = 0; i < LIGNES; i++) {
        for (int j = 0; j < COLONNES; j++) {
            printf("| ");
            if (tableau[i][j] == CROIX) {
                printf("X ");
            } else if (tableau[i][j] == ROND) {
                printf("O ");
            } else {
                printf("  "); 
            }
        }
        printf("|\n");
    }
    
    for (int j = 0; j < 4*COLONNES+1; j++) {
        printf("-");
    }
    printf("\n");
}
