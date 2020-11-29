#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include"wczytaj.h"

macierz *wczytaj(FILE *fmacierz, macierz *m)
{ 
    m = (macierz*) malloc(sizeof(macierz)); //alokacja pamieci dla typu struktura
    
    fscanf(fmacierz, "%d", &m->w);
    fscanf(fmacierz, "%d", &m->k);
    
    m->tab = (float**) malloc(sizeof(float*) * m->w);
    for (int i = 0; i < m->w; i++)
    {
        m->tab[i] = (float*) malloc(sizeof(float) * m->k);
        for (int j=0; j < m->k; j++)
        {
            fscanf(fmacierz, "%f", &m->tab[i][j]);
        }
    }
    fclose(fmacierz);
    return m;
}

void wypisz(macierz *m)
{
    printf("Suma macierzy jest równa:\n");
    for(int i = 0; i < m->w; i++)
    {
        printf("[");
        for(int j = 0; j < m->k; j++)
        {
            printf("%2.0f", m->tab[i][j]);
        }
        printf(" ]\n");
    }
}

void wypiszdopliku(char *nazwa, macierz *m)
{
    FILE *fmacierz;
    fmacierz = fopen(nazwa, "w+");

    for(int i = 0; i < m->w; i++)
    {  
        fprintf(fmacierz, "[");
        for(int j = 0; j < m->k; j++)
        {
            fprintf(fmacierz, "%3.0f", m->tab[i][j]);
        }       
        fprintf(fmacierz, "]\n");
    }
    fclose(fmacierz);
}

void zwolnijpamiec(macierz *m)
{
    for(int i = 0; i < m->w ; i++)
    {
        free(m->tab[i]);
    }
    free(m->tab);
    free(m);
}