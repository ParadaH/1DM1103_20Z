#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"studenci.h"


void najlepszy_przedmiot(student dane[100], int podane_dane) //ile_rekordow - 9 linijek z pliku studenci
{
    char nr_przedmiotu[100][10]; //tablica z przedmiotami
    char nazwa_przedmiotu[100][100];
    int liczba_przedmiotow;
    int i;    
    int pozycja;
    int najlepsza_pozycja;
    int najgorsza_pozycja;
    float srednia[100];
    float sumy_wazonych_ocen[100];
    float ilosc_ocen[100];
    float najlepsza;
    float najgorsza;

    liczba_przedmiotow = szukaj_przedmiotow(nr_przedmiotu, dane, podane_dane); //liczenie realnej liczby przemdiotow

    for (i=0; i < podane_dane; i++) 
    {
        pozycja = szukajp(dane[i].kod_przedmiotu, nr_przedmiotu, liczba_przedmiotow);

        sumy_wazonych_ocen[pozycja] += dane[i].ocena;
        ilosc_ocen[pozycja]++;
    }

    for(i = 0; i < liczba_przedmiotow; i++)
    {
        srednia[i] = (sumy_wazonych_ocen[i] / ilosc_ocen[i]);
    }

    najlepsza = 0;
    najgorsza = 100;

    for (i = 0; i < liczba_przedmiotow; i++) 
    {

        if (najlepsza < srednia[i]) 
        {
            najlepsza = srednia[i];
            najlepsza_pozycja = i;
        }
    
        if (najgorsza > srednia[i])
        {
            najgorsza = srednia[i];
            najgorsza_pozycja = i;
        }
    }

    for(i = 0; i < podane_dane; i++)
    {
        if(strcmp(nr_przedmiotu[najlepsza_pozycja], dane[i].kod_przedmiotu) == 0)
        {
            strcpy(nazwa_przedmiotu[najlepsza_pozycja], dane[i].nazwa_przedmiotu);
        }
    }

    printf("Najlepsza średnia: %s - %s: %f.\n", nr_przedmiotu[najlepsza_pozycja], nazwa_przedmiotu[najlepsza_pozycja], srednia[najlepsza_pozycja]);
}

void najgorszy_przedmiot(student dane[100], int podane_dane) //ile_rekordow - 9 linijek z pliku studenci
{
    char nr_przedmiotu[100][10]; //tablica z przedmiotami
    char nazwa_przedmiotu[100][100];
    int liczba_przedmiotow;
    int i;    
    int pozycja;
    int najlepsza_pozycja;
    int najgorsza_pozycja;
    float srednia[100];
    float sumy_wazonych_ocen[100];
    float ilosc_ocen[100];
    float najlepsza;
    float najgorsza;

    liczba_przedmiotow = szukaj_przedmiotow(nr_przedmiotu, dane, podane_dane); //liczenie realnej liczby przemdiotow

    for (i=0; i < podane_dane; i++) 
    {
        pozycja = szukajp(dane[i].kod_przedmiotu, nr_przedmiotu, liczba_przedmiotow);

        sumy_wazonych_ocen[pozycja] += dane[i].ocena;
        ilosc_ocen[pozycja]++;
    }

    for(i = 0; i < liczba_przedmiotow; i++)
    {
        srednia[i] = (sumy_wazonych_ocen[i] / ilosc_ocen[i]);
    }

    najlepsza = 0;
    najgorsza = 100;

    for (i = 0; i < liczba_przedmiotow; i++) 
    {

        if (najlepsza < srednia[i]) 
        {
            najlepsza = srednia[i];
            najlepsza_pozycja = i;
        }
    
        if (najgorsza > srednia[i])
        {
            najgorsza = srednia[i];
            najgorsza_pozycja = i;
        }
    }

    for(i = 0; i < podane_dane; i++)
    {
        if(strcmp(nr_przedmiotu[najgorsza_pozycja], dane[i].kod_przedmiotu) == 0)
        {
            strcpy(nazwa_przedmiotu[najgorsza_pozycja], dane[i].nazwa_przedmiotu);
        }
    }

    printf("Najgorsza średnia: %s - %s: %f.\n", nr_przedmiotu[najgorsza_pozycja], nazwa_przedmiotu[najgorsza_pozycja], srednia[najgorsza_pozycja]);
}

void najlepszy_student(student dane[100], int ile_rekordow) {
    char nr_albumow[100][10];
    int ile_studentow;
    float sumy_wazonych_ocen[100];
    int sumy_ects[100];
    float srednie[100];
    int i;
    int pozycja;
    int najlepsza_pozycja;
    float najlepsza = 0.0f;

    ile_studentow = znajdz_studentow(nr_albumow, dane, ile_rekordow);

    for(i=0; i< ile_rekordow; i++)
    {
        sumy_wazonych_ocen[i] = 0;
        sumy_ects[i] = 0;
    }

    for (i=0; i < ile_rekordow; i++) {
        pozycja = znajdz( dane[i].nr_albumu, nr_albumow, ile_studentow );
        // if (pozycje >= 0)
        sumy_wazonych_ocen[pozycja] += dane[i].ocena * dane[i].ects;
        sumy_ects[pozycja] += dane[i].ects;
    }    

    // for (i=0;i<ile_studentow; i++) 
    //     printf("Student [%d]: %s - %f:%d - %f \n", i+1, nr_albumow[i], 
    //     sumy_wazonych_ocen[i], sumy_ects[i], sumy_wazonych_ocen[i] / sumy_ects[i]);

    for (i=0; i < ile_studentow; i++) {
        if (najlepsza < sumy_wazonych_ocen[i] / sumy_ects[i]) {
            najlepsza = sumy_wazonych_ocen[i] / sumy_ects[i];
            najlepsza_pozycja = i;
        }
    }

    printf("Najlepszy student: \n");
    printf("Student [%d]: %s - %f \n", 
        najlepsza_pozycja+1, nr_albumow[najlepsza_pozycja],
        sumy_wazonych_ocen[najlepsza_pozycja] / sumy_ects[najlepsza_pozycja]
    );
}
