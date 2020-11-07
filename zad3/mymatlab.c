#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

struct macierz {
    int w;
    int k;
    float tab[50][50];
};

int wczytaj(FILE *fmacierz, struct macierz *m)
{ //wczytywanie
    fscanf(fmacierz, "%d", &(m->w));
    fscanf(fmacierz, "%d", &(m->k));

    for (int i=0; i < m->w; i++)
    {
        for (int j=0; j < m->k; j++)
        {
            fscanf(fmacierz, "%f", &(m->tab[i][j]));
        }
    }
    return 0;
}

struct macierz suma(struct macierz m1, struct macierz m2)
{ // sumowanie 
    struct macierz m3;
    m3.w = m1.w;
    m3.k = m2.k;

    for(int i = 0; i < m1.w; i++)
    {
        for(int j = 0; j < m1.k; j++)
        {
            m3.tab[i][j] = m1.tab[i][j] + m2.tab[i][j];
        }
    }
    return m3;
}

struct macierz substract(struct macierz m1, struct macierz m2)
{ //odejmowanie
    struct macierz m3;
    m3.w = m1.w;
    m3.k = m2.k;
    
    for(int i = 0; i < m1.w; i++)
    {
        for(int j = 0; j < m1.k; j++)
        {
            m3.tab[i][j] = m1.tab[i][j] - m2.tab[i][j];
        }
    }
    return m3;
}

struct macierz prod(struct macierz m1, struct macierz m2)
{
    struct macierz m3;
    m3.w = m1.w;
    m3.k = m2.k;
    
    for(int i = 0; i < (m1.w); i++)
    {
        for(int j = 0; j < (m2.k); j++)
        {
            for(int k =0; k < (m1.k); k++)
            {
                m3.tab[i][j] += m1.tab[i][k] * m2.tab[k][j];
            }
        }
    }
    return m3;
}

float norm(struct macierz m1)
{
    float m3 = 0;
    for (int i = 0; i < m1.w; i++)
    {
        for (int j = 0; j < m1.k; j++)
        {
            m3 += m1.tab[i][j] * m1.tab[i][j];
        }
    }
    return sqrt(m3);
}

struct macierz multiply(struct macierz m1, float k)
{
    struct macierz m3;
    m3.w = m1.w;
    m3.k = m1.k;

    for(int i = 0; i < m1.w; i++)
    {
        for(int j = 0; j < m1.k; j++)
        {
            m3.tab[i][j] = k * m1.tab[i][j];
        }
    }
    return m3;
}

int main(int argc, char *argv[])
{
    FILE *fmacierz;
    struct macierz m1;
    struct macierz m2;
    struct macierz m3;
    float norma = 0;

    if(strcmp(argv[1], "suma") == 0)
    {
        fmacierz = fopen(argv[2], "r");
        wczytaj(fmacierz, &m1);
        fclose(fmacierz);
        fmacierz = fopen(argv[3], "r");
        wczytaj(fmacierz, &m2);
        fclose(fmacierz);

        if((m1.k) == (m2.w))
        {
            m3 = suma(m1, m2);
            if(argv[4] == 0) 
            {
                printf("Suma macierzy jest równa:\n");
                for(int i = 0; i < (m1.w); i++)
                {
                    printf("[");
                    for(int j = 0; j < (m1.k); j++)
                    {
                        printf("%2.0f", m3.tab[i][j]);
                    }
                    printf(" ]\n");
                }
            }
            else 
            {
                fmacierz = fopen(argv[4], "w+");
                for(int i = 0; i < (m1.w); i++)
                {  
                    fprintf(fmacierz, "[");
                    for(int j = 0; j < (m1.k); j++)
                    {
                        fprintf(fmacierz, "%3.0f", m3.tab[i][j]);
                    }       
                    fprintf(fmacierz, "]\n");
                }
                fclose(fmacierz);
            }
        }
        else
        {
            printf("Nie da sie zsumowac podanych macierzy lub podana macierz nie istnieje.\n");
            exit(-1);
        }
    }

    if(strcmp(argv[1], "substract") == 0) 
    {
        fmacierz = fopen(argv[2], "r");
        wczytaj(fmacierz, &m1);
        fclose(fmacierz);
        fmacierz = fopen(argv[3], "r");
        wczytaj(fmacierz, &m2);
        fclose(fmacierz);

        if((m1.k) == (m2.w))
        {
            m3 = substract(m1, m2);
            if(argv[4] == 0) 
            {
                printf("Różnica macierzy jest równa:\n");
                for(int i = 0; i < (m1.w); i++)
                {
                    printf("[");
                    for(int j = 0; j < (m1.k); j++)
                    {
                        printf("%2.0f", m3.tab[i][j]);
                    }
                    printf(" ]\n");
                }
            }
            else 
            {
                fmacierz = fopen(argv[4], "w+");
                for(int i = 0; i < (m1.w); i++)
                {  
                    fprintf(fmacierz, "[");
                    for(int j = 0; j < (m1.k); j++)
                    {
                        fprintf(fmacierz, "%3.0f", m3.tab[i][j]);
                    }       
                    fprintf(fmacierz, "]\n");
                }
                fclose(fmacierz);
            }
        }
        else
        {
            printf("Nie da się odjąć podanych macierzy lub podana macierz nie istnieje.\n");
            exit(-1);
        }
    }

    if(strcmp(argv[1], "prod") == 0) 
    {
        fmacierz = fopen(argv[2], "r");
        wczytaj(fmacierz, &m1);
        fclose(fmacierz);
        fmacierz = fopen(argv[3], "r");
        wczytaj(fmacierz, &m2);
        fclose(fmacierz);
        if((m1.k) == (m2.w))
        {
            m3 = prod(m1, m2);
            if(argv[4] == 0) 
            {
                printf("Iloczyn macierzy jest równy:\n");
                for(int i = 0; i < (m1.w); i++)
                {
                    printf("[");
                    for(int j = 0; j < (m1.k); j++)
                    {
                        printf("%2.0f", m3.tab[i][j]);
                    }
                    printf(" ]\n");
                }
            }
            else 
            {
                fmacierz = fopen(argv[4], "w+");
                for(int i = 0; i < (m1.w); i++)
                {  
                    fprintf(fmacierz, "[");
                    for(int j = 0; j < (m1.k); j++)
                    {
                        fprintf(fmacierz, "%3.0f", m3.tab[i][j]);
                    }       
                    fprintf(fmacierz, "]\n");
                }
                fclose(fmacierz);
            }
        }
        else
        {
            printf("Nie da się pomnożyć podanych macierzy lub wybrana macierz nie istnieje.\n");
            exit(-1);
        }
    }

    if(strcmp(argv[1], "norm") == 0) 
    {
        fmacierz = fopen(argv[2], "r");
        wczytaj(fmacierz, &m1);
        fclose(fmacierz);
        
        norma = norm(m1);
        if(argv[3] == 0) 
        {
            printf("Norma macierzy jest równa: [%f].\n", norma); 
        }
        else 
        {
            fmacierz = fopen(argv[3], "w+");
            fprintf(fmacierz, "Norma macierzy jest równa: [%f].\n", norma); 
            
            fclose(fmacierz);
        }
    }

    if(strcmp(argv[1], "multiply") == 0) 
    {
        fmacierz = fopen(argv[2], "r");
        wczytaj(fmacierz, &m1);
        fclose(fmacierz);
        
        m3 = multiply(m1, atof(argv[3]));
        if(argv[4] == 0) 
            {
                printf("Iloczyn skalarny macierzy jest równy:\n");
                for(int i = 0; i < (m1.w); i++)
                {
                    printf("[");
                    for(int j = 0; j < (m1.k); j++)
                    {
                        printf("%2.0f", m3.tab[i][j]);
                    }
                    printf(" ]\n");
                }
            }
        else 
            {
                fmacierz = fopen(argv[4], "w+");
                for(int i = 0; i < (m1.w); i++)
                {  
                    fprintf(fmacierz, "[");
                    for(int j = 0; j < (m1.k); j++)
                    {
                        fprintf(fmacierz, "%3.0f", m3.tab[i][j]);
                    }       
                    fprintf(fmacierz, "]\n");
                }
                fclose(fmacierz);
            }
    }

    else
    {
        exit(-1);
    }
    return 0;
}