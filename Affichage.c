#include<time.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include "conio2.h"
#include "Affichage.h"
//#include "fonction.h"





/**============================== fonctions permerttant l'affichages des LLC et du vecteur skieur==========================**/



void affich_skieur  (vski *str) /**role : permet d'afficher le vecteur skieur**/
{
int i=0 ,j=0 ;
gotoxy (10,3);
textcolor(3);
printf ("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",201,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,203,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,203,205,205,205,205,205,205,205,205,205,205,205,187);
gotoxy (10,4);
textcolor(3);
printf ("%c                    %c                      %c nombre de %c",186,186,186,186);
gotoxy(10,5);
textcolor(3);
printf ("%c     nom            %c adresse              %c           %c",186,186,186,186);
gotoxy (10,6);
textcolor (3);
printf ("%c                    %c                      %c  paires   %c",186,186,186,186);
gotoxy (10,7);
textcolor(3);
printf ("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",204,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,206,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,206,205,205,205,205,205,205,205,205,205,205,205,185);

while ( i< (str->nsk)+1 )
{
   if ((str->skieur[i].nom )!= "")

     {  gotoxy (10,8+j);
        printf ("%c ",186);
        textcolor(0);
        printf ("  %s",str->skieur[i].nom);
        gotoxy (31,8+j);
        textcolor(3);
        printf ("%c",186);
        textcolor(0);
        printf (" %s",str->skieur[i].adresse);
        gotoxy(54,8+j);
        textcolor (3);
        printf ("%c",186);
        textcolor(0);
        printf (" %d",str->skieur[i].psk);
        gotoxy (66,8+j);
        textcolor(3);
        printf ("%c",186);
        j++;
     }
    i++;
}
gotoxy (10,8+j);
textcolor(3);
printf ("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",200,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,202,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,202,205,205,205,205,205,205,205,205,205,205,205,188);
}



int afficher_reserv (struct reserv *q,int r)  /**permet d'afficher une liste de reservations**/
{
int cpt=0;
while (q!= NULL)
{
textcolor(3);gotoxy(13,r);printf("%c",186);
gotoxy(52,r);printf("%C",186);
gotoxy(34,r);printf("%c",186);
gotoxy(65,r);printf("%c",186);
gotoxy(72,r);printf("%c",186);
gotoxy(87,r);printf("%c",186);
textcolor(0);gotoxy(60,r);printf("%d",valeur_deb(q));
gotoxy(67,r);printf("%d",valeur_fin(q));
gotoxy(78,r);printf("%d",q->ind);
q = suivant_reserv(q) ;
cpt++;
r++;
}
return cpt;
}

void afficher_ski(struct ski *s)
{
int x=5,m=1,n=0,cpt=0;
struct reserv *q;
if (s==NULL)
{
printf("la liste n'existe pas");
}
gotoxy(13,2);textcolor(3);
printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",201,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205);
printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",203,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205);
printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%C%C%c%c",203,205,205,205,205,205,205,205,205,205,205,205,205,203,205,205,205,205,205,205,203,205,205,205,205,205,205,205,205,205,205,205,205,205,205,187);
gotoxy(13,4);
printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",204,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205);
printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",206,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205);
printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%C%C%c%c",206,205,205,205,205,205,205,205,205,205,205,205,205,206,205,205,205,205,205,205,206,205,205,205,205,205,205,205,205,205,205,205,205,205,205,185);
gotoxy(13,3);textcolor(0);
printf("%c nombre de la paire %c        taille   %c     debut  %c  fin %c indice       %C ",186,186,186,186,186,186);
while (s!= NULL)
{
cpt++;
gotoxy(17,x);textcolor(0);
printf ("%d ",m);
gotoxy(38,x);printf("%d",taille_ski(s));
q=s->loc;
gotoxy(60,x);
n=afficher_reserv(q,x);
x=x+n+1;
m++;
s=suivant_ski(s);
gotoxy(13,x-1);textcolor(3);
printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",204,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,2055,205,205,205,205,205,205,205,205,205,205,205,205,205,185);
}

}

/**=========================================partie affichage============================================================**/


void cadre_aff ( int l , int L , int x , int y ) /// Dessine un cadre de longeur == L et de largeur == l à partir du point M(x,y) de la console
{
    int i ;
    gotoxy(x,y);
    printf("%c",201);
    gotoxy(x,y + L);
    printf("%c",200);
    gotoxy(x+l,y);
    printf("%c",187);
    gotoxy(x+l,y+L);
    printf("%c",188);
    for (i=1 ; i <= l-1 ; i++  )
    {
        gotoxy(x+i,y);
        printf("%c",205);
        gotoxy(x+i,y+L);
        printf("%c",205);
    }
    for (i=1 ; i <= L-1; i++ )
    {
        gotoxy(x,y+i);
        printf("%c",186);
        gotoxy(x+l,y+i);
        printf("%c",186);
    }
}

void ordinateur(int x,int y) /// dessiner un pc a partir des coordonnes x,y de la curseur
{
        cputsxy(x,y,"     __________________________");y++;
    	cputsxy(x,y,"    /_________________________/|");y++;
    	cputsxy(x,y,"    ||     ecole              ||");y++;
    	cputsxy(x,y,"    ||     nationale          ||");y++;
    	cputsxy(x,y,"    ||     superieur          || ");y++;
    	cputsxy(x,y,"    ||     d'informatique     || ");y++;
    	cputsxy(x,y,"    ||________________________||");y++;
    	cputsxy(x,y,"     ________________________   ");y++;
    	cputsxy(x,y,"    /oooo  oooo  oooo  oooo /!   ");y++;
    	cputsxy(x,y,"   /ooooooooooooooooooooooo/ /  ");y++;
    	cputsxy(x,y,"  /ooooooooooooooooooooooo/ /    ");y++;
    	cputsxy(x,y," /_______________________/_/    ");y++;
    	cputsxy(x,y,"/__________|____|_________/    ");y++;
}
void cadre1()               /// "CADR2" EST UN PROCEDEUR PERMET D'AFFICHER UN CADRE DANS LA CONSOLE(pour le menu)
{
       int i;
       gotoxy(1,2);
       for (i=0;i<=115;i++)
        {
                            textcolor (BLACK);
                            printf("%c",176);
                          }
       gotoxy(1,13) ;
       for (i=0;i<=115;i++){
                            textcolor (3);
                            printf("%c",176);
                          }
       gotoxy(1,42);
       for (i=0;i<=115;i++){
                            textcolor (BLACK);
                            printf("%c",176);
                          }
       for (i=3;i<=41;i++){
                           gotoxy(1,i) ;
                           textcolor (3);
                           printf("%c",186) ;
                           printf("%c",186) ;
                           gotoxy(115,i);
                           textcolor (3);
                           printf("%c",186) ;
                           printf("%c",186) ;
                         }
      textcolor (15);
}
void parler(char *chaine)  ///faire du sens on introduit juste la chaine de charactere
{
            char temp1[256];
            sprintf(temp1,"echo m=\"%s\" > file.vbs",chaine);
            system(temp1);
            sprintf(temp1,"echo CreateObject(\"SAPI.SpVoice\").Speak m >> file.vbs");
            system(temp1);
            sprintf(temp1,"file.vbs");
            system(temp1);
            remove("file.vbs");
         }
void etoile_cadre()       ///cadre avec des etoiles
{
      int j,k,u;
    textcolor(3);
    Sleep(1000);
    for (j=0;j<28;j++)
    {
     delay(15);
     printf("* * ");
    }
    gotoxy(1,2);
    for(k=0 ; k<38 ; k++)
    {
        delay(15);
        printf("*\n");
    }
    for(u=0;u<41; u++)
    {
    gotoxy(111,u);
    delay(15);
     printf("*");
    }
    gotoxy(3,40);int r;
    for(r=0;r<27;r++){
        delay(15);
        printf("* * ");

    }

}
void page_1()            ///page de couverture
{

    system("color F1");textbackground(WHITE);
     etoile_cadre();

    printf("\n");
    gotoxy(5,3);
    Sleep(500);textcolor(0);
    printf("                                   REPUBLIQUE ALGERIENNE DEMOCRATIQUE ET POPULAIRE \n ");Sleep(200);
    printf("                               MINISTERE DE L'ENSEIGNEMET ET DE LA RECHERCHE SCIENTIFIQUE \n");Sleep(200);
    printf("                                      1ere annee classes preparatoires integres              \n");Sleep(200);
    gotoxy(3,4);
    textcolor(0);
    printf("%C%C%C%C%c%c  %C%C%C%C%C",219,219,219,219,219,219,219,219,219,219,219);gotoxy(3,5);
    printf("%C%C      %c%c            ",219,219,219,219);gotoxy(3,6);
    Sleep(500);
    printf("%c%c      %C%c      %C%C   ",219,219,219,219,219,219);gotoxy(3,7);
    printf("%c%c%C%C%C%C  %c%C%C%C%C   %C%C",219,219,219,219,219,219,219,219,219,219,219,219,219);gotoxy(3,8);
    Sleep(500);
    printf("%C%C         %C%c   %C%C",219,219,219,219,219,219);gotoxy(3,9);
    printf("%C%C         %C%C   %C%C",219,219,219,219,219,219);gotoxy(3,10);
    printf("%C%C%C%C%C%C  %C%C%C%C%C   %C%C",219,219,219,219,219,219,219,219,219,219,219,219,219);gotoxy(3,11);
    gotoxy(19,4);
    Sleep(500);
    textcolor(3);
    printf("%c%c",219,219);
    ordinateur(3,12);


        gotoxy(56,14); textcolor(0);
    Sleep(500);
    cadre_aff(45,7,56,14);


    textcolor(1);Sleep(500);
    gotoxy(58,16);Sleep(200);
    printf(" TP en algorithmiqque et structure     ");Sleep(200);
    gotoxy(58,18);
    printf("   de donnees dynamique (ALSDD)        ");Sleep(200);
    textcolor(0);
    gotoxy(47,26);Sleep (500);cadre_aff(50,9,47,26);
    Sleep(500);
    gotoxy(49,28);textcolor(1);Sleep(200);
    printf("       Realise par:                     ");gotoxy(49,30);textcolor(3);Sleep(200);
    printf("       BEROUAKEN MAROUA ~~ ARAB ASMA     ");gotoxy(49,32);textcolor(1);Sleep(200);
    printf("       section : B ~~ groupe : 4        ");

    gotoxy(14,39);
    system("pause");
}
void page_2()           ///procedure pour ecrire :tp de gestion de projet (2eme page)
{
    clrscr();
    system("color F9");etoile_cadre();
    gotoxy(10,6);
    textcolor(1);textbackground(WHITE);
    printf("***** ****    ****    *****     ****   ***** ***** ***** %c%C  ****  ****    **   ****    ***** ",219,219);gotoxy(10,7);Sleep(200);
    printf("  *   *    *  *    *  *        *       *     *       *   ** *    * ** **   **   *    *  *       ");gotoxy(10,8);Sleep(200);
    printf("  *   ****    *     * *****   *   ***  ***** *****   *   ** *    * **  **  **   *     * *****  ");gotoxy(10,9);Sleep(200);
    printf("  *   *       *    *  *        *     * *         *   *   ** *    * **   ** **   *    *  *      ");gotoxy(10,10);Sleep(200);
    printf("  *   *       ****    *****     ****   ***** *****   *   **  ****  **    ****   ****    *****   ");gotoxy(10,11);Sleep(200);
    gotoxy(4,14);
    printf("*      ***   ****    ***   ***** %c%C  ****  ****    **   ****    ***** *****   ***** *   *  %c%c   *****",219,219,219,219);gotoxy(4,15);Sleep(200);
    printf("*     *   * *       *   *    *   ** *    * ** **   **   *    *  *     *       *     *  *   **   *  ");gotoxy(4,16);Sleep(200);
    printf("*     *   * *      *******   *   ** *    * **  **  **   *     * ***** *****   ***** * *    **   *****");gotoxy(4,17);Sleep(200);
    printf("*     *   * *      *     *   *   ** *    * **   ** **   *    *  *         *       * *  *   **       *   ");gotoxy(4,18);Sleep(200);
    printf("*****  ***   ****  *     *   *   **  ****  **    ****   ****    ***** *****   ***** *    * **   *****   ");gotoxy(4,19);Sleep(200);
    char *ch=" Welcome in our program ";
    parler(ch);
    textcolor(BLACK);
    int i;
    gotoxy(18,27);
    for(i=1;i<86;i++)
    {
        gotoxy( wherex() , 23);
        printf("%c",219);
        gotoxy( wherex()-1 ,24 );
        printf("%c",219);
        Sleep(10);
    }
    gotoxy(20,25);
    printf("tappez une touche pour rentrer au menu...\n\n");
    getch();

}
void dessin_menu()
{

    clrscr();
    system("color F6");
                textbackground(WHITE);


        cadre1();
        gotoxy(35,5) ;
        textcolor(GREEN);
            printf(" ___    ___    _____   __   _   _   _  \n");gotoxy(35,6);
            printf("/   |  /   |  | ____| |  \\ | | | | | | \n");gotoxy(35,7);
            printf("| | | /  | |  | |__   |   \\| | | | | | \n");gotoxy(35,8);
            printf("| | |/   | |  |  __|  | |\\   | | | | |\n");gotoxy(35,9);
            printf("| |      | |  | |___  | | \\  | | |_| | \n");gotoxy(35,10);
            printf("|_|      |_|  |_____| |_|  \\_| \\_____/  \n");gotoxy(35,11);
}
void affich_menu()
{
    int  c;
    system ("cls");
    dessin_menu();
    gotoxy(36,17);textcolor(1);
    printf("1/ initialisation de la liste des paires de skis");gotoxy(36,20);Sleep(100);
    printf("2/ afficher les reservations des paires de skis");gotoxy(36,23);Sleep(100);
    printf("3/ reservation des paires de skis ");gotoxy(36,26);Sleep(100);
    printf("4/ afficher le nombre de location d'une paire de skis ");gotoxy(36,29);Sleep(100);
    printf("5/ annuler la reservation d'une paire de ski");gotoxy(36,32);Sleep(100);
    printf("6/ affiche les clients qui ont des reservations ");gotoxy(36,35);Sleep(100);
    printf("7/ quitter le programme ");gotoxy(3,38);
    for (c=0;c<=111;c++){   textcolor (3);
                            delay(10);
                            printf("%c",176);}gotoxy(36,39);
    printf(" votre choix :");
}
void ending() ///Graphisme de fin
{
    system("cls");
    textcolor(WHITE);
    gotoxy(1,10);
    printf("                ######      ######                           ###-   \n");
    delay(5);
    printf("                   ####      #####                            #### \n ");
    delay(5);
    printf("                  #####     #####                            ###=\n ");
    delay(5);
    printf("                  #####    #####                                  \n ");
    delay(5);
    printf("                  #:####   #.###     ####  #### ###   ##### ####= \n");
    delay(5);
    printf("                   # ####  =# ###   ####### ###/###- #######  ###= \n ");
    delay(5);
    printf("                  #  #### ## ###   ###  ##= ####### ###.  ## ###=\n ");
    delay(5);
    printf("                  #  ######  ###   ###  ### ####    ###   ## ###=\n");
    delay(5);
    printf("                   #  ######  ###   ######## ####    ###      ###= \n  ");
    delay(5);
    printf("                 #  -####-  ###   ###      ###/    ###      ###= \n");
    delay(5);
    printf("                   #   ####   ###   ###      ###=    ####     ###= \n  ");
    delay(5);
    printf("                 #    ##    ###   ####  ## ###=    ####   # ###= \n");
    delay(5);
    printf("                   #    ##    ####  /###### .####     #######.#### .\n  ");
    delay(5);
    printf("              #####  /#..#######;.#####. ######.   @#####.######.\n");
    gotoxy (3,30);
    system("pause");
}

void retour(int A,int B)
{
        textcolor(BLACK);
        gotoxy(A,B);
        printf("appuyez sur n'importe quel touche pour revenir au menu...");
        getch();
 }


