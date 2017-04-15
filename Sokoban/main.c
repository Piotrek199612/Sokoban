#include <allegro.h>
#include <winalleg.h>
#include<stdio.h>
#include"menu.h"
#include"bledy.h"
#include"ruch.h"




volatile int speed = 0;
void increment_speed()
{
speed++;
}
END_OF_FUNCTION( increment_speed );




int main()
{
    LOCK_VARIABLE( speed );
LOCK_FUNCTION( increment_speed );
    allegro_init();


    install_keyboard();
    install_timer();
    install_int_ex( increment_speed, BPS_TO_TIMER( 600 ) );
    set_color_depth( desktop_color_depth() );
    set_gfx_mode( GFX_AUTODETECT, 1000, 700, 0, 0 );
    set_palette( default_palette );
    clear_to_color( screen, 48 );

    FONT *czciaka=load_font("Tekstury\\Harry.pcx", default_palette, NULL);
if( !czciaka )
{
    set_gfx_mode( GFX_TEXT, 0, 0, 0, 0 );
    allegro_message( "Blad! Nie wczytalem obrazu." );
    exit(1);
    return 0;

}

    BITMAP *obraz=load_bmp("Tekstury\\Obraz.bmp",default_palette);
    BITMAP *bufor = create_bitmap(1000,700);
    BITMAP *podmenutlo = create_bitmap(301,300);
    BITMAP *skrzynia=load_bmp("Tekstury\\Skrzynia.bmp",default_palette);
    BITMAP *sciana=load_bmp("Tekstury\\Sciana.bmp",default_palette);
    BITMAP *meta=load_bmp("Tekstury\\Meta.bmp",default_palette);
    BITMAP *gracz=load_bmp("Tekstury\\Gracz.bmp",default_palette);
    BITMAP *wskaznik=load_bmp("Tekstury\\Wskaznik.bmp",default_palette);
    BITMAP *plansza=create_bitmap(1000,700);
    BITMAP* pustepole = create_bitmap(50, 50);
    BITMAP *wygrana=create_bitmap(500,400);
    clear_to_color(wygrana,makecol( 185, 122, 87 ));
    clear_to_color(pustepole, 48);
    clear_to_color(plansza,48);
    clear_to_color(podmenutlo,makecol( 73, 163, 48 ));
    int obraz_x = 0, obraz_y = 0;

sprawdzwczytanie(obraz);
sprawdzwczytanie(gracz);
sprawdzwczytanie(skrzynia);
sprawdzwczytanie(meta);
sprawdzwczytanie(sciana);
sprawdzwczytanie(wskaznik);
wyswietlmenu(czciaka);
obslugamenu(&speed,bufor,obraz,gracz,&obraz_x,&obraz_y,podmenutlo,skrzynia,sciana,meta,pustepole,wygrana,plansza,wskaznik,czciaka);


    destroy_bitmap(bufor);

   destroy_bitmap(obraz);
    readkey();

    allegro_exit();
    return 0;
}
END_OF_MAIN();
