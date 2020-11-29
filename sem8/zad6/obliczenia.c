#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include "wczytaj.h"


macierz suma(macierz m1, macierz m2)
{
    macierz *m3;
    m3 = (macierz*) malloc(sizeof(macierz));

    m3->w = m1.w;
    m3->k = m1.k;
    float a = 0;

    m3->tab = (float**) malloc(sizeof(float*) * m3->w); //alokacja pamieci dla wyniku
    for(int i = 0; i < m3->w; i++)
    {
        m3->tab[i] = (float*) malloc(sizeof(float) * m3->k);
    }

    for(int i = 0; i < m3->w; i++) //obliczenie
    {
        for(int j = 0; j < m3->k; j++)
        {
            a += m1.tab[i][j] + m2.tab[i][j];
            m3->tab[i][j] = m1.tab[i][j] + m2.tab[i][j];
        }
    }
    return *m3;
}
