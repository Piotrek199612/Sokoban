#include "menu.h"
#include <allegro.h>
#include <stdio.h>
#include <stdlib.h>
#include "ruch.h"
#include "edytor.h"
#include "odczyt_zapis.h"

void wyswietlmenu(FONT * czciaka)
{
    clear_to_color(screen, 48);
    textout_ex(screen, czciaka, "1 - Nowa Gra.", 380, 200, makecol(255, 255, 255), -1);
    textout_ex(screen, czciaka, "2 - Edytor.", 380, 260, makecol(255, 255, 255), -1);
    textout_ex(screen, czciaka, "ESC - Wyjdz.", 380, 320, makecol(255, 255, 255), -1);
    textout_ex(screen, font, "Autor", 700, 550, makecol(255, 255, 255), -1);
    textout_ex(screen, font, "Piotr Sturmer    2016", 700, 560, makecol(255, 255, 255), -1);
}

void obslugamenu(int* speed, BITMAP* bufor, BITMAP* obraz, BITMAP* gracz, int* obraz_x,
    int* obraz_y, BITMAP* podmenutlo, BITMAP* skrzynia, BITMAP* sciana, BITMAP* meta,BITMAP * pustepole,BITMAP * wygrana,
    BITMAP* plansza, BITMAP* wskaznik,FONT * czciaka)
{
    wyswietlmenu(czciaka);
    char znak = 0;
    char Levele[50][40];   // lista poziomow w pliku
    int metatab [20][14]; //tablica przechowujaca pola docelowe
    int tablica[20][14];  // tablica planszy
    int maxdown = 0;
    int wskaznik_y = 140;
    int wybranylevel = 0;
    int i=0;
    int j=0;
    int x=0;
    int y=0;
    FILE * wczytanaplansza;
    BITMAP* listaplansz = create_bitmap(1000, 700);
    clear_to_color(listaplansz, 48);
     BITMAP *kratownica = create_bitmap(1000,700);
    clear_to_color( kratownica, makecol( 255, 0, 255 ) );


    char klawisz=0;
    while (1) {

        klawisz = readkey();

        if (klawisz=='1') {// Gra
            while (1) {
                    for (i=0;i<=49;i++){
                        for (j=0;j<=39;j++){
                            Levele[i][j]=0;
                        }
                    }
                    clear_to_color(listaplansz, 48);
                    Zerojtablicepoziomu(tablica);
                    clear_to_color(screen, 48);
                    textout_ex(listaplansz, czciaka, "Dostepne poziomy:", 360, 100,makecol(255, 255, 255), -1);
                    textout_ex(listaplansz, czciaka, "2 - Cofnij", 450, 620,makecol(255, 255, 255), -1);
                    textout_ex(listaplansz, czciaka, "ENTER - Wybierz", 650, 620,makecol(255, 255, 255), -1);
                    wyszukajpliki(Levele, &maxdown, listaplansz);

                    while (!key[KEY_ENTER]&&!key[KEY_2]) {
                        clear_to_color(screen, 48);
                        blit(listaplansz, screen, 0, 0, 0, 0, 1000, 700);
                        masked_blit(wskaznik, screen, 0, 0, 360, wskaznik_y, obraz->w, obraz->h);
                        readkey();
                        if (key[KEY_DOWN] && wskaznik_y < maxdown && wskaznik_y >= 140) {//Ruch wskanika w dol
                            wskaznik_y += 20;
                            continue;
                        }
                        if (key[KEY_UP] && wskaznik_y <= maxdown && wskaznik_y > 140) {//Ruch wskaznika w gore
                            wskaznik_y -= 20;
                            continue;
                        }

                    }
                    if (key[KEY_ENTER]){
                        for (i=0;i<=19;i++){
                        for (j=0;j<=13;j++){
                            metatab[i][j]=0;

                            }}

                    wybranylevel=(wskaznik_y-140)/20;
                    wczytajplansze(speed, bufor, obraz, gracz, obraz_x, obraz_y, podmenutlo,skrzynia, sciana, meta,pustepole, plansza, tablica,Levele,wybranylevel,wczytanaplansza);
                    for (i=0;i<=19;i++){
                        for (j=0;j<=13;j++){
                            if (tablica[i][j]==1){
                                *obraz_x=i*50;
                                *obraz_y=j*50;
                                continue;

                            }
                            if (tablica[i][j]==4){
                                metatab[i][j]=4;

                           }
                        }
                    }
                        while (1) {
                                if (!key[KEY_ESC]){

                            ruch(speed,bufor,gracz,obraz_x,obraz_y,plansza,podmenutlo,tablica,metatab,obraz,sciana,skrzynia,meta,pustepole,wygrana,&x,&y);
                            }
                            else {
                                    wyswietlmenu(czciaka);
                            break;

                    }
                        }continue;}
                         if (key[KEY_2]){
                         wyswietlmenu(czciaka);
                    break;

                        }
                continue;}
                continue;}



       if (klawisz=='2') { //Edytor
            wyswietlmenuedytora(czciaka);
            while (1) {
                klawisz=readkey();


                if (key[KEY_1]) { // Stworz nowy poziom
                    Zerojtablicepoziomu(tablica);
                    clear_to_color(plansza,48);
                    while (1) {
                        while (!key[KEY_ESC]) {
                            edytor(speed, bufor, obraz, gracz, obraz_x, obraz_y, podmenutlo,skrzynia, sciana, meta,pustepole, plansza,kratownica, tablica,czciaka);
                        }
                        break;
                    }
                    wyswietlmenuedytora(czciaka);
                    continue;
                }
                if (key[KEY_2]) { // Wczytaj poziom do edycji

                    clear_to_color(listaplansz, 48);
                    for (i=0;i<=49;i++){
                    for (j=0;j<=39;j++){
                            Levele[i][j]=0;
                        }}
                    Zerojtablicepoziomu(tablica);
                    clear_to_color(screen, 48);
                    textout_ex(listaplansz, czciaka, "Dostepne poziomy:", 360, 100,makecol(255, 255, 255), -1);
                    wyszukajpliki(Levele, &maxdown, listaplansz);
                    while (!key[KEY_ENTER]) {
                        clear_to_color(screen, 48);
                        blit(listaplansz, screen, 0, 0, 0, 0, 1000, 700);
                        masked_blit(wskaznik, screen, 0, 0, 360, wskaznik_y, obraz->w, obraz->h);
                        readkey();
                        if (key[KEY_DOWN] && wskaznik_y < maxdown && wskaznik_y >= 140) {
                            wskaznik_y += 20;
                            continue;
                        }
                        if (key[KEY_UP] && wskaznik_y <= maxdown && wskaznik_y > 140) {
                            wskaznik_y -= 20;
                            continue;
                        }
                    }
                    wybranylevel=(wskaznik_y-140)/20;
                    wczytajplansze(speed, bufor, obraz, gracz, obraz_x, obraz_y, podmenutlo,skrzynia, sciana, meta,pustepole, plansza, tablica,Levele,wybranylevel);
                    while (1) {
                        while (!key[KEY_ESC]) {
                            edytor(speed, bufor, obraz, gracz, obraz_x, obraz_y, podmenutlo,skrzynia, sciana, meta,pustepole, plansza,kratownica, tablica,Levele,wybranylevel,czciaka);
                        }
                        break;
                    }
                    wyswietlmenuedytora(czciaka);
                    continue;
                }
                if (key[KEY_ESC]) { // Wyjdz do menu
                    wyswietlmenu(czciaka);
                    break;
                }
               continue;
            }
            continue;
        }

        if (key[KEY_ESC]) {//wyjdz z gry
            exit(1);
        }
    }
}
