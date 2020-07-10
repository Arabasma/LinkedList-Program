#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <windows.h>
#include <string.h>
#include "fonction.h"
#include "conio2.h"


/**===========================================MODULES DU TP=======================================================**/



/**=======================modèle de LLC permettant la manipulation de la liste des paire de ski============================**/

               void allouer_ski ( struct ski **nouveau)  /** cree une cellule pour La LLC des tailles**/
                       { *nouveau = (ski*)malloc(sizeof(ski)); }



               struct ski *suivant_ski (struct ski *p)
                        { return p->skisuiv ;}


               int taille_ski( struct ski *p)
                        { return p->taille ;}



               void aff_adr_ski (struct ski *p , struct ski *q)
                        { p->skisuiv = q ;}



               void aff_val_ski ( struct ski *p , int valeur)
                        { p->taille = valeur ;}






/**==========================modèle LLC permettant la manipulation de la sous-liste  de réservations=======================**/

                            void allouer_reserv ( struct reserv **nouveau)
                                   { *nouveau = (reserv*)malloc(sizeof(reserv)); }


                          struct reserv *suivant_reserv (struct reserv *p)
                                   { return p->ressuiv ;}


                          int taille_reserv( struct reserv *p)
                                   { return ( ((p->fin) - (p->deb) ) +1 ) ;}



                          int  valeur_deb (  struct reserv *p)
                                   {return p->deb ;}


                          int  valeur_fin (  struct reserv *p)
                                    { return p->fin ;}


                          void aff_adr_reserv (struct  reserv *p , struct reserv *q)
                                   { p->ressuiv= q ;}


                          void aff_val_reserv ( struct reserv *p , int valdeb , int valfin , int indice )
                                   { p->deb = valdeb ; p->fin = valfin ; p->ind = indice;}


                           void liberer  (struct reserv **ancien)
                                   {    free(*ancien);   *ancien= NULL ;}



/**===========================================module partie1======================================================**/



int nbskis ( ski *mat )    /** elle renvoie le nombre de paire de ski présentes dans la structure pointé par mat**/
{
    int i=0;
    struct ski *p ;        /** le fonctionnnement : on parcours  la liste jusqu'à ce que P devient nul et on incrémente un compteur i **/
    p= mat ;

     while ( p!= NULL)
       { i++ ;
         p = suivant_ski(p) ;
       }
    return i ;
}


struct ski *skit (struct ski *mat , int t )   /**elle renvoie un pointeur sur le 1er maillon contenat la taille t**/
{
    struct ski *p ;
     int trouv=0;                           /**le fonctionnnement : on parcours la LLC pointé par mat et pour chaque maillon on vérifie si p->taille == t si c'est le cas trouv=1 et ainsi on sort de la boucle while et on retourne p**/
     p=mat ;

       while ( p!= NULL && trouv==0)
         { if ( taille_ski(p)== t) { trouv = 1;}
           else  {p = suivant_ski(p) ;
         }
  }
      return p ;
}



int nbjloc (struct ski *pairski)           /**renvoie le nombre de location d'une paire de ski bien determinée**/
{
      struct reserv *p ;               /** fonctionnnement : on recupere le pointeur sur la LLC des reservation du champ loc et on parcours la liste et pour chaque maillon on incrément somme par (fin-deb+1) grace à la fonction taille l'operation s'arrete lorsque il n'y a plus de maillons i.e : p=NULL**/
      int somme= 0;
      p= pairski->loc ;
      while ( p!=NULL)
       { somme +=  taille_reserv(p) ;
         p = suivant_reserv(p) ;  }

return somme;
}



int nbskit (struct ski *mat, int T)  /**renvoie le nombre de paire de skis **/
{
    struct ski *q ;                /**fonctionnement :on parcours la liste à partir du 1er maillon contenat le taille t  et on incremente un compteur i l'operation s'arrete lorsque taille(p)!=t**/
    int i=0 ;
    q= skit(mat, T) ;

         while (taille_ski(q)== T)
          { q = suivant_ski(q) ; i++ ; }
    return i ;
}



void nbloct (struct ski *mat , int Tai ,int T[], int *N)  /**renvoie dans un tableau le nombre de location de chaque paire de taille t**/
{
     struct ski *p ,*q;                          /***on alloue dynamiquement un tableau de taille N qui est le nombre de paire de skis de taille et puis on parcours la liste des reservation a partir du 1er maillon de taille t et on calcule le nombre de location et on sauvegarde dans le tableau T*/
     int i, cpt ;
     p = mat;
     *N= nbskit (p, Tai);
     cpt= nbskit(p,Tai);
     q=skit(p,Tai);

     for (i=0; i<cpt; i++)
      {
          T[i]= nbjloc(q) ;
          q= suivant_ski(q) ; }

}


/**===================================la fonction creation ski et res et du vecteur skieur===================================**/



int alea(int a,int b)  /**renvoie un nombre aleatoire entre a et b**/
{
    int R ;
    R= (rand()%(b-a) ) +a ;
    return R;
}


void chargement_alea_reserv ( struct ski *p ) /** creation d'une LLC de reservation pour chaque maillon**/
{
     int n , i , j=1 , c , ind ,d ,val,e;
     struct reserv *q , *k ;
     allouer_reserv(&q) ;
     p->loc =  q;
     c= alea (0,20);
     ind = rand()%15;
     aff_val_reserv(q,c , c+5, ind );
     val = c+5 ;
     n = alea (0,6);
     while ( j<n)
         {
             i = rand()%15;
             d = alea (0,20);
             e = alea (0,15);
             allouer_reserv(&k);
             aff_val_reserv(k,val+e, val +e+d,i);
             aff_adr_reserv(q,k);
             val = val +e+d;
             q=k;
             j++;
         }
    aff_adr_reserv(q, NULL);
}


struct ski *chargement_alea_ski ()/**creation du la liste des paires de ski**/
{
    struct  ski *tete, *p, *q;
 int i=1 ,cpt=1 ,tai=100 ;

allouer_ski(&p);
aff_val_ski(p,tai);
tete = p ;
chargement_alea_reserv(p);
 while (i<100)
{allouer_ski(&q);
aff_val_ski (q,tai);
aff_adr_ski(p,q);
chargement_alea_reserv(q);
p=q;
i++;
cpt++;
if (cpt==5) {cpt=0; tai+=10 ;}
}

  aff_adr_ski(p, NULL);
return tete; }



void chargement_skieur (struct ski *mat , struct vski *T) /**chargement du vecteur skieur **/
{
   int i , cpt=0 ;
   struct ski *p ;
   struct reserv *q ;
   T->nsk =14;

T->skieur[0].nom = "Berouaken";           T->skieur[0].adresse = "Boudouaou";
T->skieur[1].nom = "Arab";                T->skieur[1].adresse = "Corso";
T->skieur[2].nom = "Chaib";               T->skieur[2].adresse ="Zemmouri";
T->skieur[3]. nom = "Kedour";             T->skieur[3].adresse = "Telemcen";
T->skieur[4].nom = "Saadi" ;              T->skieur [4].adresse = "Boumerdes";
T->skieur[5].nom = "Felah";               T->skieur [5].adresse = "Alger";
T->skieur[6].nom = "Nour";                T->skieur[6].adresse = "Oran";
T->skieur[7].nom = "Hammache" ;           T->skieur[7].adresse = "Tizi ouzou";
T->skieur[8].nom = "Douaidi";             T->skieur[8].adresse = "Constantine";
T->skieur[9].nom = "ATTALA";              T->skieur[9].adresse = "Bouira";
T->skieur[10].nom = "Firas" ;             T->skieur[10].adresse = "Alger" ;
T->skieur[11].nom = "Maddi";              T->skieur[11].adresse = "Blida";
T->skieur[12].nom = "Chibbah" ;           T->skieur[12].adresse = "Oran" ;
T->skieur[13].nom = "Kentar";             T->skieur[13].adresse = "Bejaia";
T->skieur[14].nom =  "Amirouche";         T->skieur[14].adresse =  "Tizi ouzou";

for (i=0; i<15; i++)
{ p = mat ;
   while (p!= NULL )
    {  q= p->loc;
          while ( q!=NULL)
          { if ((q->ind ) == i ) {  cpt++;}
            q=suivant_reserv(q); }
       p = suivant_ski(p);
    }
T->skieur[i].psk = cpt ;
cpt =0 ;
}

}

/**===========================================les modules de la partie2================================================**/

int cherchskieur ( char* nom, struct vski *str ) /**donne l'indice ou se trouve nom dnas le vecteur skieur**/
{
      int i= 0;
      int  trouv=0, L ,H=-1;
      while ( trouv ==0 && i <(str->nsk)+1 )
      { L = strcmp(nom , str->skieur[i].nom);
        if (L == 0) { trouv= 1 ; H=i ;  }
         i++;  }

return H;
}






/**============================================les modules de la partie3=====================================================**/


void insertete (struct reserv **skiloc, int deb, int fin ,int ind )   /**insere un maillon  contenant deb, fin et ind dans la LLC de reservation **/
{
      struct reserv *p,*k , *u= NULL ;
      p= *skiloc;

      if ( p==NULL)                                                  /**si la liste est initialement vide on alloue un maillon et on affecte sa valeur à skiloc**/
        { allouer_reserv(&k);
          aff_adr_reserv(k, NULL);
          *skiloc = k;
          aff_val_reserv(k,deb,fin,ind);
          }
       else
        {   while ( p!=NULL && deb > valeur_fin(p))              /**on parcours la LLC pour savoir ou inserer le maillon de sorte que la LLC rete trie**/
            {  u= p;
               p= suivant_reserv(p); }

            if ( u == NULL ) {  allouer_reserv (&k);                     /** si le maillon doir etre insere en tete de la liste on fait une allocation et on affecte sa valeur à skiloc**/
                         aff_adr_reserv(k,p) ;
                        *skiloc= k ;
                         aff_val_reserv(k,deb,fin,ind);
                      }

            else {

                  if (p==NULL && u!=NULL) { allouer_reserv (&k);             /**si le maillon doit etre insere à la fin  de la liste on le crre et on affecte à son champ ressuiv NULL **/
                                            aff_adr_reserv(k, NULL) ;
                                            aff_val_reserv(k,deb,fin,ind);
                                            aff_adr_reserv(u,k);
                                          }

                  else  {     allouer_reserv (&k);
                              aff_adr_reserv(k, p);
                              aff_val_reserv(k,deb,fin,ind);
                              aff_adr_reserv ( u, k) ;
                        }
                }
         }
}


int location (struct reserv **premloc , int deb , int fin , int ind)  /**verifie si la reservation peut etre effectue ou pas il renvoie 1 si c'est le cas et il effectue la reservation en faisant appel  à insertete et 0 dans le cas contraire**/
{
   int possible=0;
   struct reserv *p;
   struct reserv *q ;
   int sauv=deb , fait=0;
   p = *premloc ;

      if (deb> fin ) {
          gotoxy(33,27);textcolor(BLACK);
          printf("le debut ne peut etre supeireur a la fin du reservation");}
      if ( deb>151 || fin>151 || deb<1 || fin<1) {gotoxy(33,27);

            printf("vous ne pouvez pas resrevez plus que 151 jours");}

      while (  p!=NULL && possible==0)                              /**verifie si les la periode est disponible i.e en verifiant qu'il n'existe reservation commencent le jour deb ou le jour fin ou une reservation **/

          { if ((valeur_deb(p)== deb) || (valeur_deb(p)==fin) )
                    { possible=1 ;}

            p= suivant_reserv(p);
         }


     if ( possible == 0)
       {     for (sauv=deb ; sauv<= fin ; ++sauv )
             {  q = *premloc ;
                 while ( q!=NULL && possible==0)
                    {  if ( (sauv >= valeur_deb(q))  &&  (sauv <= valeur_fin(q))  )
                            {    possible=1;   }
                       if ( (sauv==valeur_deb(q)) || (valeur_fin(q)==sauv) )
                            {  possible=1;  }
                        q=suivant_reserv(q);
                    }

             }

        }

   if (possible==0)  /** possible=0 veut dire que la periode demandee est disponible**/
   {  fait= 1;
      insertete ( premloc , deb, fin,ind ) ;
   }
return fait;
}


void reservation (vres *T ,  char **nom, char **adresse , struct ski *mat ,vski *str )/**effectue toutes les reservations transmises dans le tableau T**/
{
     int i , done, j, don, k , compt=0 , ind=0, l;
     struct ski *p=NULL , *q= NULL;
     int cpt=0 , indice = 0 , trouv= 0;
     struct vres tab;
      trouv = cherchskieur(*nom, str );textcolor(RED);
     if (   trouv == -1)
      { indice = (str->nsk) +1 ;

        for (i=0 ; i<T->nr ; i++)
         {   done = 0;
              p= skit (mat,T->res[i].t);
                    while( done!= 1 && (taille_ski(p)== T->res[i].t) )
                {   done= location( &p->loc,T->res[i].de ,T->res[i].fi , indice );
                    p = suivant_ski(p); }

                if (done==0)
                    {  tab.res[cpt].de =  T->res[i].de;
                       tab.res[cpt].fi = T->res[i].fi;
                       tab.res[cpt].t = T->res[i].t ;
                       cpt++ ;
                    }
         }

                if (cpt== (T->nr)  )
                    {
                        clrscr();textcolor(1);cadre_aff(52,14,32,20);gotoxy(35,23);textcolor(0);
                        printf("aucune des reservations n'a pu se faire\n\n");}


                if ( cpt==0)
                    { str->nsk = (str->nsk)+1;
                       str->skieur[indice].nom = *nom;
                       str->skieur[indice].adresse= *adresse;
                       str->skieur[indice].psk = T->nr;
                       clrscr();textcolor(1);cadre_aff(52,14,32,20);gotoxy(36,23);textcolor(0);
                       printf ("la reservation a ete faite avec");
                       gotoxy(39,25);printf("succes");

                    }

                if ((cpt > 0)  && (cpt< T->nr))

                   {  str->nsk = (str->nsk)+1;
                       str->skieur[indice].nom = *nom;
                       str->skieur[indice].adresse= *adresse;
                       str->skieur[indice].psk = (T->nr)-cpt;
                       clrscr();textcolor(1);cadre_aff(66,15,32,20);gotoxy(33,23);textcolor(0);
                       printf("les reservations ont ete faites sauf les reservations  suivantes\n");
                       for (j=0; j< cpt ; j++)
                       {   gotoxy(33,25+j);//textcolor(0);
                           printf ("la paire de ski de taille : %d  | reservee du : %d  au : %d\n\n", tab.res[j].t, tab.res[j].de , tab.res[j].fi ); }
                   }
    }
    else {ind = trouv ;
      for (k=0 ; k<T->nr ; k++)
        {   don = 0;
            q= skit (mat,T->res[k].t);
             while( don!= 1 && taille_ski(q)== T->res[k].t)
                    {
                      don= location( &q->loc,T->res[k].de ,T->res[k].fi , ind );
                      q = suivant_ski(q);
                    }

                if (don==0)
                    {  tab.res[compt].de =  T->res[k].de ;
                       tab.res[compt].fi = T->res[k].fi;
                       tab.res[compt].t = T->res[k].t ;
                       compt++ ;
                    }
         }
                if (compt== (T->nr)  )
                    {
                        clrscr();textcolor(1);cadre_aff(52,14,32,20);gotoxy(35,24);textcolor(0);
                        printf("aucune des reservations n'a pu se faire\n\n");}


                if ( compt==0)
                    {
                       str->skieur[ind].psk = (str->skieur[ind].psk)+(T->nr);
                       clrscr();textcolor(1);cadre_aff(52,14,30,18);gotoxy(36,22);textcolor(0);
                       printf ("la reservation a ete faite avec");
                       gotoxy(38,24);printf("succes");

                    }

                if ((compt > 0)  && (compt< T->nr))

                   {
                       str->skieur[ind].psk = (str->skieur[ind].psk )+ (T->nr)- compt;
                       clrscr();textcolor(1);cadre_aff(66,14,32,20);gotoxy(33,22);textcolor(0);
                       printf("les reservations ont ete faites sauf les reservations  suivantes\n");
                       for (l=0; l< compt ; l++)
                       {   gotoxy(33,24+l);//textcolor(0);
                           printf ("la paire de ski de taille : %d  || reserve du : %d  au : %d\n\n", tab.res[l].t, tab.res[l].de , tab.res[l].fi ); }
                   }


    }
}


/**==========================================les modules de la partie 4=============================================== **/


void supprim_ind (struct vski *T , int indice) /**la procedure qui enleve un elelement du tableau**/
{   if (indice== T->nsk) { T->nsk= T->nsk -1 ;}
   else
      { T->skieur[indice].nom = ""; T->skieur[indice].adresse=""; T->skieur[indice].psk = 0; }
}


void annuleres (char **nom , struct ski **mat , vski *str )/**la procedure qui annule la reservation du client nom**/
{
   struct ski *p ;
   struct reserv *q ;
   struct reserv *u;
   int trouv=0, nbpair=0 , cpt=0 , i=0;
   p=*mat;
   trouv= cherchskieur(*nom,str);
    if (trouv==-1)
              {   clrscr();textcolor(1);cadre_aff(70,14,32,17);gotoxy(35,21);textcolor(0);
                  printf("Monsieur ou Madame %s n'a effectue aucune location", *nom);}

          else
          {nbpair= str->skieur[trouv].psk;

               while (p!= NULL && cpt < nbpair )
                { i++;
                  if ( p->loc->ind==trouv) { p->loc = suivant_reserv(p->loc);cpt++;}
                  q= p->loc;
                  u = p->loc;

                      while ( q!=NULL)
                       { if ( q->ind == trouv && (suivant_reserv(q) != NULL) ) { aff_adr_reserv(u,suivant_reserv(q));
                                                                                 free(q) ;
                                                                                 cpt++; }
                         if ( q->ind == trouv && suivant_reserv(q)== NULL) {  aff_adr_reserv(u, NULL); cpt++;}
                         u=q ;
                         q=suivant_reserv(q);

                       }

                  p= suivant_ski(p);
                }


                 supprim_ind(str ,trouv);
                 if (cpt==nbpair) {
                 clrscr();textcolor(1);cadre_aff(70,14,32,17);gotoxy(34,22);textcolor(0);
                  printf("Toutes les reservations de Monsieur ou Madame %s ont ete annulees", *nom);}

          }
}



