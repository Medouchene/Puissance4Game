#include <stdio.h>
#include <string.h>
#include "puissance4.h"

int main()
{
    int tableau[LIGNES][COLONNES] = {
        {0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0}
    };

    struct joueur joueurs[2];
    
    char a[20]; char b[20];

    printf("Le nom du premier joueur : \n");
    scanf(" %s",a);
    printf("Le nom du deuxième joueur : \n");
    scanf(" %s",b);

    strcpy(joueurs[0].pseudo,a);
    joueurs[0].couleur = CROIX;
    strcpy(joueurs[1].pseudo,b);
    joueurs[1].couleur = ROND;
    


    do {
        for (int i=0;i<2;i++){

            afficher_plateau(tableau);

            int p;
            printf("Le tour de %s \n",joueurs[i].pseudo);
            scanf("%i",&p);

            while(p<1 || p>7 || combien_dans_colonne(tableau, p)==6){
                printf("Choisissez une colonne #(1-7) : \n");
                scanf("%i",&p);
            }
            
            empiler(tableau, p, joueurs[i].couleur);

        }
        
    } while(TRUE);
    
    return 0;
}