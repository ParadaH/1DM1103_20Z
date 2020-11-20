/*
z najlepszą średnią ocen studentów
z najgorszą średnią ocen studentów
(Czyli najłatwiejszy przedmiot i najtrudniejszy :-))

Chciałbym, aby wynik na ekranie był wyświetlony w następującej formie:

Najlepsza średnia: 1DE0000 - Nazwa najlepszego przedmiotu: 4.5
Najgorsza średnia: 1DE1111 - Nazwa najgorszego przedmiotu: 2.5 
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct _student 
{
    char imie[25];
    char nazwisko[50];
    char nr_albumu[10];
    char kod_przedmiotu[10];
    char nazwa_przedmiotu[255];
    float ocena;
    int ects;
} student;

int wczytaj(student dane[100], char *fnazwa)
{
    FILE * fin;
    fin = fopen(fnazwa, "r");

    int cnt;
    int i;
    char bufor[1024];
    char *w;

    fgets(bufor, 1023, fin);
    sscanf(bufor, "%d", &cnt);
 
    for (i=0; i<cnt; i++) 
    {
        fgets(bufor, 1023, fin);

        w = strtok(bufor, "|");
        strncpy(dane[i].imie, w, 24);

        w = strtok(NULL, "|");
        strncpy(dane[i].nazwisko, w, 49);
        
        w = strtok(NULL, "|");
        strncpy(dane[i].nr_albumu, w, 9);

        w = strtok(NULL, "|");
        strncpy(dane[i].kod_przedmiotu, w, 9);

        w = strtok(NULL, "|");
        strncpy(dane[i].nazwa_przedmiotu, w, 254);

        w = strtok(NULL, "|");
        dane[i].ocena = atof(w);

        w = strtok(NULL, "|");
        dane[i].ects = atoi(w);
    }

    fclose(fin);
    return cnt; //zwraca ilosc 
}

//szukaj i szukaj_przedmiotow - czytanie przedmiotow z listy i zwrocenie realnej ich liczby

int szukaj(char *szukany_przedmiot, char nr_przedmiotu[100][10], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (strcmp(szukany_przedmiot, nr_przedmiotu[i]) == 0)
        {
            return i;
        }
    }
    return -1;
}

int szukaj_przedmiotow(char nr_przedmiotu[100][10], student dane[100], int n)
{
    int znalezione_przedmioty = 0;
    for (int i = 0; i < n; i++)
    {
        if (szukaj(dane[i].kod_przedmiotu, nr_przedmiotu, znalezione_przedmioty ) == -1)
        {
            strncpy(nr_przedmiotu[znalezione_przedmioty], dane[i].kod_przedmiotu, 9);
            znalezione_przedmioty++;
        }
    }
    return znalezione_przedmioty; //liczba przedmiotow lacznie
}

void przedmioty(student dane[100], int podane_dane) //ile_rekordow - 9 linijek z pliku studenci
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
        pozycja = szukaj(dane[i].kod_przedmiotu, nr_przedmiotu, liczba_przedmiotow);

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

    for(i = 0; i < podane_dane; i++)
    {
        if(strcmp(nr_przedmiotu[najgorsza_pozycja], dane[i].kod_przedmiotu) == 0)
        {
            strcpy(nazwa_przedmiotu[najgorsza_pozycja], dane[i].nazwa_przedmiotu);
        }
    }

    printf("Najlepsza średnia: %s - %s: %f.\n", nr_przedmiotu[najlepsza_pozycja], nazwa_przedmiotu[najlepsza_pozycja], srednia[najlepsza_pozycja]);
    printf("Najgorsza średnia: %s - %s: %f.\n", nr_przedmiotu[najgorsza_pozycja], nazwa_przedmiotu[najgorsza_pozycja], srednia[najgorsza_pozycja]);
}

int main(int argc, char * argv[])
{
    student dane[100];
    int ile; 

    ile = wczytaj(dane, argv[1]);

    przedmioty(dane, ile);

    return 0;
}