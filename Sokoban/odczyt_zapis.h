#ifdef odczyt_zapis_h

#define odczyt_zapis_h

void zapiszplanszejako(int tablica[20][14], char nazwapliku[40])
void wyszukajpliki( char Levele[50][40],int *maxdown,BITMAP *listaplansz)
void rysujplansze(BITMAP* bufor, BITMAP* gracz, int* obraz_x, int* obraz_y, BITMAP* skrzynia, BITMAP* sciana, BITMAP* meta,BITMAP * pustepole, BITMAP* plansza, int tablica[20][14])
void wczytajplansze(int* speed, BITMAP* bufor, BITMAP* obraz, BITMAP* gracz, int* obraz_x, int* obraz_y, BITMAP* podmenutlo, BITMAP* skrzynia, BITMAP* sciana, BITMAP* meta,BITMAP * pustepole, BITMAP* plansza,
                     int tablica[20][14],char Levele[50][40],int wybranylevel,FILE * wczytanaplansza);
#endif // odczyt_zapis_h


