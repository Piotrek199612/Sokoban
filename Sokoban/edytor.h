#ifdef edytor_h

#define edytor_h

void wyswietlmenuedytora(FONT * czciaka);
void edytor(int *speed,BITMAP *bufor,BITMAP *obraz,BITMAP *gracz,int * obraz_x,int * obraz_y,BITMAP *podmenutlo,BITMAP *skrzynia,BITMAP *sciana,BITMAP *meta,BITMAP * pustepole,BITMAP *plansza,BITMAP * kratownica,int tablica[20][14],char Levele[50][40],int wybranylevel,FONT * czciaka);
void Zerojtablicepoziomu(int **tablica[19][13]);


#endif // edytor_h


