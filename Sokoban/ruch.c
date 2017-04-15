#include"ruch.h"
#include<allegro.h>
#include<stdio.h>

void ruch(int *speed,BITMAP *bufor,BITMAP *gracz,int * obraz_x,int * obraz_y,BITMAP *plansza,BITMAP *podmenutlo,int tablica [20][14],int metatab [20][14],BITMAP *obraz,BITMAP *sciana,BITMAP *skrzynia
         ,BITMAP *meta,BITMAP * pustepole,BITMAP * wygrana,int * x,int *y){

 int dlruchu=50;//dlugosc ruchu w pikselach

if (SprawdzWygrana(tablica,metatab)==1){ //Sprawdzenie warunku wygranej


    while (!key[KEY_ESC]){
    textout_ex( wygrana, font, "Gratulacje wygrales", 150, 200, 48, - 1 );
    textout_ex( wygrana, font, "Kliknij ESC, aby wyjsc do menu.", 150, 250, 48, - 1 );
    blit(wygrana,screen,0,0,250,100,500,400);
   }
    }
rysujpoziomgry(plansza,gracz,skrzynia,obraz_x,obraz_y,sciana,meta,tablica,metatab,pustepole,wygrana);
readkey();

 while(*speed>0){

if( (key[ KEY_LEFT ]|| key[KEY_A])&&(tablica[(*obraz_x/50)-1][(*obraz_y/50)]!=2)&&!((tablica[(*obraz_x/50)-1][(*obraz_y/50)]==3)&&tablica[(*obraz_x/50)-2][(*obraz_y/50)]==3)&&!((tablica[(*obraz_x/50)-1][(*obraz_y/50)]==3)&&tablica[(*obraz_x/50)-2][(*obraz_y/50)]==2) )
        {
            if (*obraz_x-dlruchu<0){}
                else{*obraz_x-=dlruchu;
                        if (tablica[((*obraz_x)/50)][((*obraz_y)/50)]==3)
                        {
                            tablica[((*obraz_x)/50)-1][((*obraz_y)/50)]=3;
                            tablica[((*obraz_x)/50)][((*obraz_y)/50)]=0;
                        }
 tablica[((*obraz_x)/50)+1][((*obraz_y)/50)]=0;



                tablica[((*obraz_x)/50)][((*obraz_y)/50)]=1;


                break;}
        }

    if( (key[ KEY_RIGHT ]|| key[KEY_D])&&(tablica[(*obraz_x/50)+1][(*obraz_y/50)]!=2)&&!((tablica[(*obraz_x/50)+1][(*obraz_y/50)]==3)&&tablica[(*obraz_x/50)+2][(*obraz_y/50)]==3)&&!((tablica[(*obraz_x/50)+1][(*obraz_y/50)]==3)&&tablica[(*obraz_x/50)+2][(*obraz_y/50)]==2) )
        {
            if (*obraz_x+dlruchu>950){}//rozdzielczosc - szerokosc obrazka
                else {*obraz_x+=dlruchu;

                if (tablica[((*obraz_x)/50)][((*obraz_y)/50)]==3){
                            tablica[((*obraz_x)/50)+1][((*obraz_y)/50)]=3;
                            tablica[((*obraz_x)/50)][((*obraz_y)/50)]=0;
                        }
                tablica[((*obraz_x)/50)-1][((*obraz_y)/50)]=0;

                tablica[((*obraz_x)/50)][((*obraz_y)/50)]=1;
                break;}
        }
    if( (key[ KEY_UP ]|| key[KEY_W])&&(tablica[(*obraz_x/50)][(*obraz_y/50)-1]!=2)&&!((tablica[(*obraz_x/50)][(*obraz_y/50)-1]==3)&&tablica[(*obraz_x/50)][(*obraz_y/50)-2]==3)&&!((tablica[(*obraz_x/50)][(*obraz_y/50)-1]==3)&&tablica[(*obraz_x/50)][(*obraz_y/50)-2]==2) )
        {
            if (*obraz_y-dlruchu<0){}
                else{*obraz_y-=dlruchu;

                if (tablica[((*obraz_x)/50)][((*obraz_y)/50)]==3){
                            tablica[((*obraz_x)/50)][((*obraz_y)/50)-1]=3;
                            tablica[((*obraz_x)/50)][((*obraz_y)/50)]=0;
                        }

                tablica[((*obraz_x)/50)][((*obraz_y)/50)+1]=0;

                tablica[((*obraz_x)/50)][((*obraz_y)/50)]=1;
                break;}
        }

    if(( key[ KEY_DOWN ]|| key[KEY_S]) &&(tablica[(*obraz_x/50)][(*obraz_y/50)+1]!=2)&&!((tablica[(*obraz_x/50)][(*obraz_y/50)+1]==3)&&tablica[(*obraz_x/50)][(*obraz_y/50)+2]==3)&&!((tablica[(*obraz_x/50)][(*obraz_y/50)+1]==3)&&tablica[(*obraz_x/50)][(*obraz_y/50)+2]==2))
        {
            if (*obraz_y+dlruchu>650){}//rozdzielczoœæ - szerokoœæ obrazka
                else {*obraz_y+=dlruchu;
                        if (tablica[((*obraz_x)/50)][((*obraz_y)/50)]==3){
                            tablica[((*obraz_x)/50)][((*obraz_y)/50)+1]=3;
                            tablica[((*obraz_x)/50)][((*obraz_y)/50)]=0;}

                tablica[((*obraz_x)/50)][((*obraz_y)/50)-1]=0;

                tablica[((*obraz_x)/50)][((*obraz_y)/50)]=1;
                break;}
        }
    if  ((key[ KEY_DOWN ]|| key[KEY_S])&& (key[ KEY_LEFT ]|| key[KEY_A]) ){*obraz_x+=dlruchu; *obraz_y-=dlruchu;break;};//blokowanie ruchu po skosie
    if  ((key[ KEY_DOWN ]|| key[KEY_S])&& (key[ KEY_RIGHT ]|| key[KEY_D]) ){*obraz_x-=dlruchu; *obraz_y-=dlruchu;break;};//blokowanie ruchu po skosie
    if  ((key[ KEY_UP ]|| key[KEY_W])&& (key[ KEY_LEFT ]|| key[KEY_A]) ){*obraz_x+=dlruchu; *obraz_y+=dlruchu;break;};//blokowanie ruchu po skosie
    if  ((key[ KEY_UP ]|| key[KEY_W])&& (key[ KEY_RIGHT ]|| key[KEY_D]) ){*obraz_x-=dlruchu; *obraz_y+=dlruchu;break;};//blokowanie ruchu po skosie


      *speed--;
        }


}


void rysujpoziomgry(BITMAP *plansza, BITMAP* gracz, BITMAP* skrzynia, int* obraz_x, int* obraz_y, BITMAP* sciana, BITMAP* meta, int tablica[20][14],int metatab[20][14],BITMAP * pustepole,BITMAP * wygrana){
    int x =0;
    int y =0;

    int i,j;

    clear_to_color(plansza, 48);
    i = 0;
    j = 0;
    for (i = 0; i <= 19; i++) {
        for (j = 0; j <= 13; j++) {


            if (tablica[i][j] == 0) { //puste pole
                masked_blit(pustepole, plansza, 0, 0, i * 50, j * 50, 50, 50);
            };
            if (tablica[i][j] == 1) { //gracz
               masked_blit(gracz, plansza, 0, 0, i * 50, j * 50, 50, 50);
            };

            if (tablica[i][j] == 2) { //sciana
                masked_blit(sciana, plansza, 0, 0, i * 50, j * 50, 50, 50);
            };
            if (tablica[i][j] == 3) { //skrzynia
               masked_blit(skrzynia, plansza, 0, 0, i * 50, j * 50, 50, 50);
            };
            if (tablica[i][j] == 4) { //meta
                masked_blit(meta, plansza, 0, 0, i * 50, j * 50, 50, 50);
            };
            if ((metatab[i][j] == 4)&&(tablica[i][j]!=1)&&(tablica[i][j]!=3)) { //meta

                masked_blit(meta, plansza, 0, 0, i * 50, j * 50, 50, 50);
            };

        }
    }

    blit(plansza,screen,0,0,0,0,1000,700);


}

int SprawdzWygrana(int tablica [20][14],int metatab [20][14]){
int i,j;
for (i = 0; i <= 19; i++) {
        for (j = 0; j <= 13; j++) {
            if(metatab[i][j]==4)
                {
                if (tablica[i][j]!=3){return 0;}
            }

        }
    }
    return 1;
}


