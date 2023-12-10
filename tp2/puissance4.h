#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <strings.h>
#include <unistd.h>

#define LEPORT 2020

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

