#ifdef menu_h

#define menu_h

void wyswietlmenu(FONT * czciaka);

void obslugamenu(int* speed, BITMAP* bufor, BITMAP* obraz, BITMAP* gracz, int* obraz_x,
    int* obraz_y, BITMAP* podmenutlo, BITMAP* skrzynia, BITMAP* sciana, BITMAP* meta,BITMAP * pustepole,BITMAP * wygrana,
    BITMAP* plansza, BITMAP* wskaznik,FONT * czciaka);

#endif // menu_h
