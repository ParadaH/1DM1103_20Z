#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include"operacje.h"
#include"calculate.h"

struct macierz *wczytaj(FILE *fmacierz)
{ 
    struct macierz *m;
    m = (struct macierz*) malloc(sizeof(struct macierz)); //alokacja pamieci dla typu struktura
    
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

void wypisz(struct macierz *m)
{
    for(int i = 0; i < m->w; i++)
    {
        printf("[ ");
        for(int j = 0; j < m->k; j++)
        {
            printf("%3.2f ", m->tab[i][j]);
        }        
        printf("]\n");
    }
}

void zapiszdopliku(char *matrix, struct macierz *m)
{
    FILE *fmacierz = fopen(matrix, "w");

    for(int i = 0; i < m->w; i++)
    {
        fprintf(fmacierz, "[");
        for(int j = 0; j < m->k; j++)
        {
            fprintf(fmacierz, "%3.2f ", m->tab[i][j]);
        }
        fprintf(fmacierz, "]\n");
    }
    fclose(fmacierz);
}

void zwolnijpamiec(struct macierz *m)
{
    for(int i = 0; i < m->w ; i++)
    {
        free(m->tab[i]);
    }
    free(m->tab);
    free(m);
}