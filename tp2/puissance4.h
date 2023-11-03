#include <stdio.h>
#include <stdlib.h>

#ifndef PUISSANCE4_H
#define PUISSANCE4_H

#define LIGNES 6
#define COLONNES 7

#define TRUE 256
#define FALSE 0

enum jeton {CROIX=1, ROND=2};
struct joueur {
  char pseudo[20];
  enum jeton couleur;
};

#endif

//Prototypes de fonctions
void afficher_plateau(int tableau[LIGNES][COLONNES]);
int combien_dans_colonne(int tableau[LIGNES][COLONNES],int colonne);
void empiler(int tableau[LIGNES][COLONNES],int colonne, int couleur);
int combien_dans_direction(int tableau[LIGNES][COLONNES], int couleur,
                           int colonne, int delta_i,int delta_j);
int test_lignes(int tableau[LIGNES][COLONNES], int couleur,int colonne);
int test_colonnes(int tableau[LIGNES][COLONNES], int couleur,int colonne);
int test_diagonales(int tableau[LIGNES][COLONNES], int couleur,int colonne);
int test_tout(int tableau[LIGNES][COLONNES], int couleur,int colonne);


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

int combien_dans_colonne(int tableau[LIGNES][COLONNES],int colonne)
{
  colonne--;
  int c=0;
  for (int i=0;i<LIGNES;i++){
    if (tableau[i][colonne]!=0){
      c++;
    }
  }
  return c;
}

void empiler(int tableau[LIGNES][COLONNES],int colonne, int couleur)
{
  
  int k=combien_dans_colonne(tableau, colonne);
  colonne--;
  if (k!=LIGNES){
    tableau[LIGNES-(k+1)][colonne]=couleur;
  }else {
    printf("%s\n","YOU CAN'T!!");
  }
}

int combien_dans_direction(int tableau[LIGNES][COLONNES], int couleur,
 int colonne, int delta_i,int delta_j)
{
  int compteur=0;
  if (colonne<0 || colonne>COLONNES){
    return 0;
  }

  int i=LIGNES-1;
  while (i>=0 && i<LIGNES && colonne>=0 && colonne<COLONNES){
    if (tableau[i][colonne]==couleur){
      compteur++;
    } else {
      break;
    }
    i-=delta_i;
    colonne+=delta_j;

  }
  return compteur;
}

int test_lignes(int tableau[LIGNES][COLONNES], int couleur,int colonne)
{
  
  if ((combien_dans_direction(tableau, couleur, colonne, 0, 1) + combien_dans_direction(tableau, couleur, colonne, 0, -1))>=4){
    return couleur;
  }
  
  return 0;
}

int test_colonnes(int tableau[LIGNES][COLONNES], int couleur,int colonne)
{
  if ((combien_dans_direction(tableau, couleur, colonne, 1, 0) + combien_dans_direction(tableau, couleur, colonne, -1, 0))>=4){
    return couleur;
  }
  
  return 0;
}

int test_diagonales(int tableau[LIGNES][COLONNES], int couleur,int colonne)
{
  if ((combien_dans_direction(tableau, couleur, colonne, 1, 1) + combien_dans_direction(tableau, couleur, colonne, -1, -1))>=4){
    return couleur;
  } else if ((combien_dans_direction(tableau, couleur, colonne, -1, 1) + combien_dans_direction(tableau, couleur, colonne, 1, -1))>=4){
    return couleur;
  }

  return 0;
}

int test_tout(int tableau[LIGNES][COLONNES], int couleur,int colonne)
{
  if (test_lignes(tableau, couleur, colonne)!=0 || test_colonnes(tableau, couleur, colonne)!=0 || test_diagonales(tableau, couleur, colonne)!=0){
    return couleur;
  }
  return 0;
}