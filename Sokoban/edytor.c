#include"edytor.h"
#include<allegro.h>
#include<stdio.h>
#include"menu.h"
#include <string.h>

void wyswietlmenuedytora(FONT * czciaka){
    clear_to_color( screen, 48 );
    textout_ex( screen, czciaka, "1 - Stworz nowy poziom.", 380, 200, makecol( 255, 255, 255 ), - 1 );
    textout_ex( screen, czciaka, "2 - Wczytaj poziom.", 380, 250, makecol( 255, 255, 255 ), - 1 );
    textout_ex( screen, czciaka, "ESC - Wyjdz do menu.", 380, 300, makecol( 255, 255, 255 ), - 1 );
    textout_ex( screen, czciaka, "Aby edytowac pole wcisnij ENTER, a nastepnie wybierz rodzaj pola.", 100, 500, makecol( 255, 255, 255 ), - 1 );
}


void edytor(int *speed,BITMAP *bufor,BITMAP *obraz,BITMAP *gracz,int * obraz_x,int * obraz_y,BITMAP *podmenutlo,BITMAP *skrzynia,BITMAP *sciana,BITMAP *meta,BITMAP * pustepole,BITMAP *plansza,BITMAP * kratownica,int tablica[20][14],char Levele[50][40],int wybranylevel,FONT * czciaka){


    int znak=0;
    int indeksnazwy=0;
    char NazwaZapisanegoPliku[40];
    const float dlruchu=50;//dlugosc ruchu w pikselach

for (indeksnazwy=0;indeksnazwy<=29;indeksnazwy++){
    NazwaZapisanegoPliku[indeksnazwy]=NULL;
}
indeksnazwy=0;

    rysuj(bufor,obraz,obraz_x,obraz_y,plansza,kratownica);
    readkey();

 while(*speed>0){

    if( key[ KEY_LEFT ]|| key[KEY_A] )
        {
            if (*obraz_x-dlruchu<0){}
                else{*obraz_x-=dlruchu;
                rysuj(bufor,obraz,obraz_x,obraz_y,plansza,kratownica);
                break;}
        }

    if( key[ KEY_RIGHT ]|| key[KEY_D] )
        {
            if (*obraz_x+dlruchu>950){}//rozdzielczosc - szerokosc obrazka
                else {*obraz_x+=dlruchu;
                rysuj(bufor,obraz,obraz_x,obraz_y,plansza,kratownica);
                break;}
        }
    if( key[ KEY_UP ]|| key[KEY_W] )
        {
            if (*obraz_y-dlruchu<0){}
                else{*obraz_y-=dlruchu;
               rysuj(bufor,obraz,obraz_x,obraz_y,plansza,kratownica);
                break;}
        }

    if( key[ KEY_DOWN ]|| key[KEY_S] )
        {
            if (*obraz_y+dlruchu>650){}//rozdzielczosc - szerokosc obrazka
                else {*obraz_y+=dlruchu;
                rysuj(bufor,obraz,obraz_x,obraz_y,plansza,kratownica);
                break;}
        }
    if  ((key[ KEY_DOWN ]|| key[KEY_S])&& (key[ KEY_LEFT ]|| key[KEY_A]) ){*obraz_x+=dlruchu; *obraz_y-=dlruchu;break;};//blokowanie ruchu po skosie
    if  ((key[ KEY_DOWN ]|| key[KEY_S])&& (key[ KEY_RIGHT ]|| key[KEY_D]) ){*obraz_x-=dlruchu; *obraz_y-=dlruchu;break;};
    if  ((key[ KEY_UP ]|| key[KEY_W])&& (key[ KEY_LEFT ]|| key[KEY_A]) ){*obraz_x+=dlruchu; *obraz_y+=dlruchu;break;};
    if  ((key[ KEY_UP ]|| key[KEY_W])&& (key[ KEY_RIGHT ]|| key[KEY_D]) ){*obraz_x-=dlruchu; *obraz_y+=dlruchu;break;};

    if (key[KEY_ESC]){
         wyswietlmenuedytora(font);
        Zerojtablicepoziomu(tablica);
        break;
    }

    if (key[KEY_ENTER]){
        blit(podmenutlo,screen,0,0,300,150,1000,700);
        while (1){
            textout_ex( screen, font, "1 - Puste Pole.", 380, 200, makecol( 255, 255, 255 ), - 1 );
            textout_ex( screen, font, "2 - Sciana.", 380, 230, makecol( 255, 255, 255 ), - 1 );
            textout_ex( screen, font, "3 - Skrzynia.", 380, 260, makecol( 255, 255, 255 ), - 1 );
            textout_ex( screen, font, "4 - Meta.", 380, 290, makecol( 255, 255, 255 ), - 1 );
            textout_ex( screen, font, "5 - Gracz.", 380, 320, makecol( 255, 255, 255 ), - 1 );
            textout_ex( screen, font, "6 - Zapisz plansze jako.", 380, 350, makecol( 255, 255, 255 ), - 1 );
            textout_ex( screen, font, "7 - Anuluj.", 380, 380, makecol( 255, 255, 255 ), - 1 );


            if (key[KEY_1])     {//puste pole

                    tablica[*obraz_x/50][*obraz_y/50]=0;
                    masked_blit(pustepole,plansza, 0, 0, *obraz_x, *obraz_y, 50, 50 );
                    break;
            };
            if (key[KEY_2]){//sciana

                    tablica[*obraz_x/50][*obraz_y/50]=2;
                    masked_blit(sciana,plansza, 0, 0, *obraz_x, *obraz_y, 50, 50 );
                    break;
            };
             if (key[KEY_3])     {//skrzynia

                    tablica[*obraz_x/50][*obraz_y/50]=3;
                    masked_blit(skrzynia,plansza, 0, 0, *obraz_x, *obraz_y, 50, 50 );
                    break;
            };
             if (key[KEY_4])     {//meta
                   masked_blit(pustepole,plansza, 0, 0, *obraz_x, *obraz_y, 50, 50 );
                   tablica[*obraz_x/50][*obraz_y/50]=4;
                    masked_blit(meta,plansza, 0, 0, *obraz_x, *obraz_y, 50, 50 );
                    break;
            };
                 if (key[KEY_5])     {//Gracz

                    int i,j;
                    for (i=0;i<=19;i++){
                        for (j=0;j<=13;j++){
                            if (tablica[i][j]==1){
                                tablica[i][j]=0;
                                masked_blit(pustepole,plansza, 0, 0, i*50, j*50, 50, 50 );
                            }

                        }
                    }
                    tablica[*obraz_x/50][*obraz_y/50]=1;
                    masked_blit(gracz,plansza, 0, 0, *obraz_x, *obraz_y, 50, 50 );

                    break;
            };






                           if (key[KEY_6])     {//Zapisz plansze jako

                readkey();
                while ((!key[KEY_ENTER])){
                     blit(podmenutlo,screen,0,0,300,150,1000,700);
                     textout_ex( screen, font, "Podaj nazwe poziomu", 380, 250, makecol( 255, 255, 255 ), - 1 );
                     textout_ex( screen, font, NazwaZapisanegoPliku, 320, 290, makecol( 255, 255, 255 ), - 1 );
                     textout_ex( screen, font, "Nacisnij ENTER, aby kontynuowac", 320, 330, makecol( 255, 255, 255 ), - 1 );
                     znak=readkey();
                        if ((!(znak==16136))&&(!(znak==21504))&&(!(znak==21760))&&(!(znak==20992))&&(!(znak==21248))&&(indeksnazwy<=24)){
                                NazwaZapisanegoPliku[indeksnazwy] = znak;
                            indeksnazwy++;}
                        else if ((znak==16136)&&indeksnazwy>0&&(indeksnazwy<=24)){
                        indeksnazwy--;
                        NazwaZapisanegoPliku[indeksnazwy]='\0';

                        }else{};
                }

                zapiszplanszejako(tablica,NazwaZapisanegoPliku);
                    break;
            };
                           if (key[KEY_7])     {//anuluj

                    break;
            };
                };
            };
*speed--;


};



}
void rysuj(BITMAP *bufor,BITMAP *obraz,int * obraz_x,int * obraz_y,BITMAP *plansza,BITMAP * kratownica){
    clear_to_color( kratownica, makecol( 255, 0, 255 ) );
    clear_to_color( bufor, 48 );
    int x =0;
    int y =0;


    for (x;x<=1000;x+=50){
      vline(  kratownica, x,0, 700, makecol( 255, 255, 255 ) );

    }

    for (y;y<=700;y+=50){
       hline( kratownica, 0, y, 1000, makecol( 255, 255, 255 ) );
    }


    blit(plansza,bufor,0,0,0,0,1000,700);
    masked_blit(kratownica, bufor, 0, 0, 0, 0, 1000, 700 );
    masked_blit(obraz, bufor, 0, 0, *obraz_x, *obraz_y, obraz->w, obraz->h );
    blit(bufor,screen,0,0,0,0,1000,700);


}

void Zerojtablicepoziomu(int **tablica[20][14]){
    int i,j;
    for (i=0;i<=19;i++){
        for (j=0;j<=13;j++){
            tablica[i][j]=0;
        }
    }
};




