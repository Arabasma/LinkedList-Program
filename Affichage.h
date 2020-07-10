#ifndef AFFICHAGE_H_INCLUDED
#define AFFICHAGE_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <String.h>
#include <time.h>
#include "fonction.h"

void affich_skieur(vski *str);
int afficher_reserv(struct reserv *q,int r);
void afficher_ski(struct ski *s);
void cadre_aff( int l , int L , int x , int y );
void ordinateur(int x,int y);
void cadre1() ;
void parler(char *chaine);
void etoile_cadre();
void page_1();
void page_2();
void dessin_menu();
void affich_menu();
void ending();
void retour(int A,int B);
#endif // AFFICHAGE_H_INCLUDED
