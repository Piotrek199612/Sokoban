#include <stdio.h>
#include <allegro.h>
#include "edytor.h"
#include <dirent.h>
#include <string.h>
void zapiszplanszejako(int tablica[20][14], char nazwapliku[40])
{
    FILE* plansza;
        char sciezka[60]="Poziomy/";
      const char rozszerzenienie[10]=".lvl\0";
        sprintf(sciezka+strlen(sciezka),"%s",nazwapliku);
        sprintf(sciezka+strlen(sciezka)-1,"%s",rozszerzenienie);
        plansza = fopen(sciezka,"w");
    if (plansza == NULL)
      {
        perror("Nie udalo sie zapisac pliku");
        return 1;
      }
    int i, j;
    for (i = 0; i <= 19; i++) {
        for (j = 0; j <= 13; j++) {
            fprintf(plansza, "%d\n", tablica[i][j]);
        }
    }

    fclose(plansza);
}

void wczytajplansze(int* speed, BITMAP* bufor, BITMAP* obraz, BITMAP* gracz, int* obraz_x, int* obraz_y, BITMAP* podmenutlo, BITMAP* skrzynia, BITMAP* sciana, BITMAP* meta,BITMAP * pustepole, BITMAP* plansza,
                     int tablica[20][14],char Levele[50][40],int wybranylevel,FILE * wczytanaplansza)
{       int i,j;
    for (i=0;i<=19;i++){
        for (j=0;j<=13;j++){
            tablica[i][j]=0;
        }
    }
    clear_to_color(screen, 48);
    clear_to_color(plansza,48);
    char szukanyplik[50]="Poziomy/";
    strcat(szukanyplik,Levele[wybranylevel]);

    wczytanaplansza = fopen(szukanyplik, "r");
    if (wczytanaplansza == NULL)
      {
        perror("Nie mam tablicy");
        return 1;
      }
    int x;
    for (i = 0; i <= 19; i++) {
        for (j = 0; j <= 13; j++) {
            fscanf(wczytanaplansza, "%d", &x);
            tablica[i][j] = x;
        }
    }

    fclose(wczytanaplansza);

    rysujplansze(bufor, gracz, obraz_x, obraz_y, plansza, skrzynia, sciana, meta,pustepole, plansza, tablica);
    i = 0;
    j = 0;
    for (i = 0; i <= 19; i++) {
        for (j = 0; j <= 13; j++) {
            if (tablica[i][j] == 0) { //puste pole
                masked_blit(pustepole, plansza, 0, 0, i * 50, j * 50, 50, 50);
                ;
            };
            if (tablica[i][j] == 1) { //gracz
                masked_blit(gracz, plansza, 0, 0, i * 50, j * 50, 50, 50);
                ;
            };

            if (tablica[i][j] == 2) { //sciana
                masked_blit(sciana, plansza, 0, 0, i * 50, j * 50, 50, 50);
                ;
            };
            if (tablica[i][j] == 3) { //skrzynia
                masked_blit(skrzynia, plansza, 0, 0, i * 50, j * 50, 50, 50);
                ;
            };
            if (tablica[i][j] == 4) { //meta
                masked_blit(meta, plansza, 0, 0, i * 50, j * 50, 50, 50);
                ;
            };
        }
    }
}

void wyszukajpliki( char Levele[50][40],int *maxdown,BITMAP *listaplansz)
{
    struct dirent* plik;
    DIR* sciezka;
    int x = 140;
    int y = 1;
    int i =0;
    int j=1;
    if ((sciezka = opendir("./Poziomy/"))) {
        while (1) {
            while ((plik = readdir(sciezka))) {
                if (strlen(plik->d_name) > 4 && !strcmp(plik->d_name + strlen(plik->d_name) - 4, ".lvl")) {
                    if (x <= 570) {
                        strcpy(Levele[i], plik->d_name);
                        textprintf_ex(listaplansz, font, 400, x, makecol(255, 255, 255),-1, "%d- ", i);
                        textout_ex(listaplansz, font, Levele[i], 420, x, makecol(255, 255, 255), -1);
                        *maxdown=x;
                        x = x + 20;
                        i++;

                    }
                }
            }
            break;
        }

        closedir(sciezka);
    }
    else
        printf("Blad otwarcia pliku\n");
}







void rysujplansze(BITMAP* bufor, BITMAP* gracz, int* obraz_x, int* obraz_y, BITMAP* skrzynia, BITMAP* sciana, BITMAP* meta,BITMAP * pustepole, BITMAP* plansza, int tablica[20][14])
{
    int i,j;
    clear_to_color(plansza,48);

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

        }
    }
    blit(plansza, screen, 0, 0, 0, 0, 1000, 700);
}
