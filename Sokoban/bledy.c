#include"bledy.h"
#include<allegro.h>

void sprawdzwczytanie(BITMAP *bitmapa){
if( !bitmapa )
{
    set_gfx_mode( GFX_TEXT, 0, 0, 0, 0 );
    allegro_message( "Blad! Nie wczytalem obrazu." );
    exit(1);
    return 0;

}
}

