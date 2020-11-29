#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include"operacje.h"

struct macierz *suma(struct macierz *m1, struct macierz *m2)
{ // sumowanie 
    struct macierz *m3;

    m3 = (struct macierz*) malloc(sizeof(struct macierz));
    m3->w = m1->w;
    m3->k = m1->k;

    m3->tab = (float**) malloc(sizeof(float*) * m3->w);
    for (int i = 0; i < m3->w; i++)
    {
        m3->tab[i] = (float*) malloc(sizeof(float) * m3->k);
    }

    for(int i = 0; i < m3->w; i++)
    {
        for(int j = 0; j < m3->k; j++)
        {
            m3->tab[i][j] = m1->tab[i][j] + m2->tab[i][j];
        }
    }
    return m3;
}

struct macierz *substract(struct macierz *m1, struct macierz *m2)
{ //odejmowanie
    struct macierz *m3;

    m3 = (struct macierz*) malloc(sizeof(struct macierz));
    m3->w = m1->w;
    m3->k = m1->k;

    m3->tab = (float**) malloc(sizeof(float*) * m3->w);
    for (int i = 0; i < m3->w; i++)
    {
        m3->tab[i] = (float*) malloc(sizeof(float) * m3->k);
    }

    for(int i = 0; i < m3->w; i++)
    {
        for(int j = 0; j < m3->k; j++)
        {
            m3->tab[i][j] = m1->tab[i][j] - m2->tab[i][j];
        }
    }
    return m3;
}

struct macierz *prod(struct macierz *m1, struct macierz *m2)
{ //mnozenie
    struct macierz *m3;

    m3 = (struct macierz*) malloc(sizeof(float));
    m3->w = m1->w;
    m3->k = m2->k;
    
    m3->tab = (float**) malloc(sizeof(float) * m3->w);
    for(int i = 0; i < m3->w; i++)
    {   
        m3->tab[i] = (float*) malloc(sizeof(float) * m3->k);
        for(int j = 0; j < m3->k; j++)
        {
            m3->tab[i][j] = 0;
        }
    }

    for(int i = 0; i < m1->w; i++)
    {
        for(int j = 0; j < m2->k; j++)
        {
            for(int k =0; k < m1->k; k++)
            {
                m3->tab[i][j] += m1->tab[i][k] * m2->tab[k][j];
            }
        }
    }
    return m3;
}

float norm(struct macierz *m1)
{ //norma
    float m3 = 0;

    for (int i = 0; i < m1->w; i++)
    {
        for (int j = 0; j < m1->k; j++)
        {
            m3 += m1->tab[i][j] * m1->tab[i][j];
        }
    }
    return sqrt(m3);
}

struct macierz *multiply(struct macierz *m1, float k)
{ //iloczyn skalarny
    struct macierz *m3;
    m3 = (struct macierz*) malloc(sizeof(float));
    m3->w = m1->w;
    m3->k = m1->k;
    
    m3->tab = (float**) malloc(sizeof(float) * m3->w);
    for(int i = 0; i < m3->w; i++)
    {   
        m3->tab[i] = (float*) malloc(sizeof(float) * m3->k);
        for(int j = 0; j < m3->k; j++)
        {
            m3->tab[i][j] = 0;
        }
    }

    for(int i = 0; i < m1->w; i++)
    {
        for(int j = 0; j < m1->k; j++)
        {
            m3->tab[i][j] = k * m1->tab[i][j];
        }
    }
    return m3;
}