#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include"operacje.h"
#include"calculate.h"

int main(int argc, char *argv[])
{
    FILE *fmacierz;

    struct macierz *m1;
    struct macierz *m2;
    struct macierz *m3;
    float norma = 0;

    if(strcmp(argv[1], "suma") == 0)
    {
        fmacierz = fopen(argv[2], "r");
        m1 = wczytaj(fmacierz);
        fclose(fmacierz);
        fmacierz = fopen(argv[3], "r");
        m2 = wczytaj(fmacierz);
        fclose(fmacierz);

        if(m1->w == m2->w && m1->k == m2->k)
        {
            m3 = suma(m1, m2);
            if(argv[4])
            {
                zapiszdopliku(argv[4], m3);
                zwolnijpamiec(m1);
                zwolnijpamiec(m2);
            }
            else
            {
                wypisz(m3);
                zwolnijpamiec(m1);
                zwolnijpamiec(m2);
            }
        }
        else
        {
            printf("Nie da się zsumowac podanych macierzy lub podana macierz nie istnieje.\n");
            exit(-1);
        }
        
    }

    if(strcmp(argv[1], "substract") == 0)
    {
        fmacierz = fopen(argv[2], "r");
        m1 = wczytaj(fmacierz);
        fmacierz = fopen(argv[3], "r");
        m2 = wczytaj(fmacierz);

        if(m1->w == m2->w && m1->k == m2->k)
        {
            m3 = substract(m1, m2);
            if(argv[4])
            {
                zapiszdopliku(argv[4], m3);
                zwolnijpamiec(m1);
                zwolnijpamiec(m2);
            }
            else
            {
                wypisz(m3);
                zwolnijpamiec(m1);
                zwolnijpamiec(m2);
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
        m1 = wczytaj(fmacierz);
        fclose(fmacierz);
        fmacierz=fopen(argv[3], "r");
        m2 = wczytaj(fmacierz);
        fclose(fmacierz);

        if(m1->k == m2->w)
        {
            m3 = prod(m1, m2);
            if(argv[4])
            {
                zapiszdopliku(argv[4], m3);
                zwolnijpamiec(m1);
                zwolnijpamiec(m2);
            }
            else
            {
                wypisz(m3);
                zwolnijpamiec(m1);
                zwolnijpamiec(m2);
            }
        }
        else
        {
            printf("Nie da się pomnożyć podanych macierzy lub wybrana macierz nie istnieje.\n");
            exit(-1);
        }

    }
    if(strcmp(argv[1], "multiply") == 0)
    {
        fmacierz = fopen(argv[2], "r");
        m1 = wczytaj(fmacierz);
        fclose(fmacierz);
        m3 = multiply(m1, atof(argv[3]));                       
        if(argv[4])
        {
            zapiszdopliku(argv[4], m3);
            zwolnijpamiec(m3);
        }
        else
        {
            wypisz(m3);
            zwolnijpamiec(m3);
        }
    }

    if(strcmp(argv[1],"norm") == 0)
    {
        fmacierz = fopen(argv[2], "r");
        m1 = wczytaj(fmacierz);
        norma = norm(m1);

        if(argv[3]) 
        {
            fmacierz = fopen(argv[3], "w+");
            fprintf(fmacierz, "Norma macierzy jest równa: [%f].\n", norma); 
            fclose(fmacierz);

        }
        else 
        {
            printf("Norma macierzy jest równa: %3.2f.\n", norma); 
        }
    }
    else
    {
        exit(-1);
    }
    
    return 0;
}