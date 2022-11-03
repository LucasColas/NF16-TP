#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tp3.h"


int main()
{
    printf("Hello world!\n");
    //test42();
    T_Electeur e = creationelecteur();
    e = sentinelle(e);
    ajoutelecteur(&e, "Farles", 12345, 2);
    ajoutelecteur(&e, "David", 123459, 2);
    ajoutelecteur(&e, "Max", 123457, 2);
    ajoutelecteur(&e, "Alex", 123456, 2);
    ajoutelecteur(&e, "Jeff", 123458, 2);
    //printf("Oui");
    afficheliste(e);
    //printf("Oui");
    int c = comptelecteur(e);
    Supprimelecteur(&e,123457);
    afficheliste(e);
    libereliste(e);

    return 0;
}
