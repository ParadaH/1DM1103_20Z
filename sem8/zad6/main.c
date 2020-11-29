#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include"wczytaj.h"
#include"obliczenia.h"

int main(int argc, char *argv[])
{
    FILE *fmacierz;
    macierz *m1;
    macierz *m2;
    macierz *m3;
    float norma = 0;

    if(strcmp(argv[1], "suma") == 0)
    {
        fmacierz = fopen(argv[2], "r");
        wczytaj(fmacierz, &m1);
        fclose(fmacierz);
        fmacierz = fopen(argv[3], "r");
        wczytaj(fmacierz, &m2);
        fclose(fmacierz);

        m3 = suma(m1, m2);

        if(argv[4] == 0)
        {
            //wypisz(m3);
            printf("Suma macierzy jest równa:\n");
                for(int i = 0; i < (m1.w); i++)
                {
                    printf("[");
                    for(int j = 0; j < 3; j++)
                    {
                        printf("%2.0f", m3.tab[i][j]);
                    }
                    printf(" ]\n");
                }
        }
        else
        {
            wypiszdopliku(argv[4], &m3);
        }
    }
    else
    {
        printf("Nie da sie zsumowac podanych macierzy lub podana macierz nie istnieje.\n");
        exit(-1);
    }











}
    






