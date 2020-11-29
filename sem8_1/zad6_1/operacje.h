#ifndef OPERACJE_H
#define OPERACJE_H

#include"operacje.h"

struct macierz {
    int w;
    int k;
    float **tab;
};

struct macierz *wczytaj(FILE *fmacierz);
void wypisz(struct macierz *m);
void zapiszdopliku(char *matrix, struct macierz *m);
void zwolnijpamiec(struct macierz *m);

#endif