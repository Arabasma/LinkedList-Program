#ifndef FONCTION_H_INCLUDED
#define FONCTION_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <String.h>
#include <time.h>
#include "conio2.h"

/**================================= structures de donnees definies===================================================**/
  typedef struct reserv       /**la structure des maillons de la LLC des reseservation**/
  {

    int deb ;
    int fin;
    int ind;
    struct reserv *ressuiv ; } reserv ;


  typedef struct ski         /**la structure des maillons de le LLC  des paires de ski**/
   {
     int taille;
     struct reserv *loc ;
     struct ski *skisuiv ;} ski ;


  typedef struct vectski         /**la structure des elements du vecteur skieur**/
  {
    char *nom;
    char *adresse;
    int psk; } vectski;


  typedef struct vectres /**la strucutre des elements du vecteur res qui contient les reservation d'un client**/
  {
    int t;
    int de;
    int fi; } vectres ;


  typedef struct vski vski ;  /** la structure contenant le vecteur "skieur" et "nsk" l'indice de la dernière case occupée **/
  struct vski
  {
    vectski skieur[1000] ;
    int nsk;} ;


  typedef struct  vres vres;  /**la structure contenant le vecteur des reservations d'un client "res" et le nombre de réservations "nr"**/
   struct vres
  {
    vectres res[1000] ;
    int nr;}  ;


    //*************************************************************************************************************************//
void allouer_ski ( struct ski **nouveau);
struct ski *suivant_ski (struct ski *p);
int taille_ski( struct ski *p);
void aff_adr_ski (struct ski *p , struct ski *q);
void aff_val_ski ( struct ski *p , int valeur);
void allouer_reserv ( struct reserv **nouveau);
struct reserv *suivant_reserv (struct reserv *p);
int taille_reserv( struct reserv *p);
int  valeur_deb (  struct reserv *p);
int  valeur_fin (  struct reserv *p);
void aff_adr_reserv (struct  reserv *p , struct reserv *q);
void aff_val_reserv ( struct reserv *p , int valdeb , int valfin , int indice );
void liberer  (struct reserv **ancien);
int nbskis ( ski *mat );
struct ski *skit (struct ski *mat , int t );
int nbjloc (struct ski *pairski);
int nbskit (struct ski *mat, int T);
void nbloct (struct ski *mat , int Tai ,int T[], int *N);
int alea(int a,int b);
void chargement_alea_reserv ( struct ski *p );
struct ski *chargement_alea_ski();
void chargement_skieur (struct ski *mat , struct vski *T);
int cherchskieur ( char* nom, struct vski *str );
void reservation (vres *T ,  char **nom, char **adresse , struct ski *mat ,vski *str );
void annuleres (char **nom , struct ski **mat , vski *str );
void supprim_ind (struct vski *T , int indice);
void insertete (struct reserv **skiloc, int deb, int fin ,int ind );
int location (struct reserv **premloc , int deb , int fin , int ind);

#endif // FONCTION_H_INCLUDED
