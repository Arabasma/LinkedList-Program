#include<time.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include "conio2.h"
#include "fonction.h"
#include "affichage.h"

int Main()
{
     //system("mode con lines=400 cols=116");
     /**cette commande permet de definir la taille de la fenetre console mais elle n'est pas reconue
     par le windows 7 dans ce cas il faut regler la taille manuellement afin que l'affichage soit correct**/

     int choix,b,y,tai,begin,end,nombre,i;
     int t[1000];
     struct ski  *mat=NULL;
     struct vski *tab=malloc (sizeof(vski));
     struct vres *skieu=(struct vres*)malloc (sizeof(vres));
     srand(time(NULL));
       page_1();
       page_2();

     while (choix != 7)
    {
            char *name= (char*)malloc(30*sizeof(char)),*adress=(char*)malloc(30*sizeof(char));
            char *nam= (char*)malloc(30*sizeof(char)) ;
            affich_menu();
            scanf("%d",&choix);

    switch (choix)

       {
        case (1):
        system("cls");etoile_cadre();textcolor(1);
        cadre_aff(49,9,30,15);gotoxy(39,19);textcolor(0);
        printf("LA");Sleep(100);printf(" LISTE");Sleep(100);printf(" A ");Sleep(100);
        printf("ETE ");Sleep(100);printf("INITIALISEE");
        mat=chargement_alea_ski();
        chargement_skieur (mat,tab);
        retour(33,40);
        break;

        case (2):
        system("cls");
        afficher_ski(mat);
        retour(15,380);
        system("cls");
        break;

        case (3):
        system("cls");etoile_cadre();textcolor(1);cadre_aff(55,12,33,15);gotoxy(35,17);
        printf("veuillez entrez le nombre de paires de skis que ");gotoxy(35,19);
        printf("vous voulez reserv%c :",130);scanf("%d",&b);
        skieu->nr=b;
        system("cls");textcolor(1);cadre_aff(55,12,33,15);textcolor(0);
        gotoxy(35,17);printf("veuillez entrez le nom du client voulant ");
        gotoxy(35,19);printf("passer cette reservation : ");textcolor(RED);
        gotoxy(35,21);printf("NB: juste la premiere lettre en majuscule ");
        gotoxy(61,19);textcolor(0);scanf("%s",name);
        gotoxy(34,23);printf("l'adresse du cilent : ");scanf("%s",adress);
        system("cls");textcolor(1);cadre_aff(58,10,30,15);
        for (y=0;y<b;y++)
        {
            system("cls");textcolor(1);cadre_aff(61,16,30,15);textcolor(0);
            gotoxy(32,20);printf ("veuillez entrer la taille  de la reservation numero %d : ",y+1);
            scanf ("%d",&tai);
            skieu->res[y].t = tai ;
            gotoxy(32,22);printf ("veuillez entrer le 1er jour de la reservation: ");
            scanf("%d",&begin);
            skieu->res[y].de = begin;
            gotoxy(32,24);printf ("veuillez entrer le dernier jour de la reservation: ");
            scanf ("%d",&end);
            skieu->res[y].fi =end;
        }
        reservation(skieu ,&name ,&adress, mat,tab);
        retour(33,40);
        break;

        case (4):
        system("cls");etoile_cadre();textcolor(1);cadre_aff(55,16,28,10);
        gotoxy(33,12);
        printf("entrez la taille du paire du ski: ");
        scanf("%d",&tai);
        nbloct(mat,tai,t,&nombre);
        gotoxy(33,14);
        textcolor(0);
        for (i=0 ;i<nombre ; i++)
        {
            printf("|le nombre de location de la %d paire :%d|\n ",i+1, t[i]);
            gotoxy(33,15+i);
        }
        retour(33,40);
        break;

        case 5:
             system("cls");etoile_cadre();textcolor(1);
             cadre_aff(49,9,30,10);
             gotoxy(33,12);textcolor(0);
             printf("donnez le nom du client");
             scanf("%s",nam);
             annuleres(&nam,&mat,tab);
             retour(33,40);

        break;

        case (6):
             system("cls");etoile_cadre();
             affich_skieur(tab);
             retour(33,40);


        break;

        case (7):
             system("cls");textbackground(BLACK);ending();
        break;

        default:
            system("cls");textcolor(1);cadre_aff(52,12,30,16);
            gotoxy(36,19);textcolor(4);
            printf("ONT A PAS CE CHOIX DANS LE MENU");
            retour(33,40);
           }
    }

    return 0;
}
