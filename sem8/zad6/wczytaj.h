#ifndef WCZYTAJ_H
#define WCZYTAJ_H
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

typedef struct macierz {
    int w;
    int k;
    float **tab;
}macierz;

macierz *wczytaj(FILE *fmacierz, macierz *m);
void wypisz(macierz *m);
void wypiszdopliku(char *nazwa, macierz *m);
void zwolnijpamiec(macierz *m);

#endif