#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"studenci.h"

int wczytaj(student dane[100])
{
    FILE * fin;
    fin = fopen("studenci.txt", "r");

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

void wypisz(student dane[100], int n) {
    int i;
    for (i=0; i<n;i++) {
        printf("Student: %s - %s %s, z przedmiotu: [%s] %s za ECTS: %d otrzymał %.1f\n",
            dane[i].nr_albumu, dane[i].imie, dane[i].nazwisko,
            dane[i].kod_przedmiotu, dane[i].nazwa_przedmiotu,
            dane[i].ects, dane[i].ocena
        );
    }
}


int szukajp(char *szukany_przedmiot, char nr_przedmiotu[100][10], int n)
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
        if (szukajp(dane[i].kod_przedmiotu, nr_przedmiotu, znalezione_przedmioty ) == -1)
        {
            strncpy(nr_przedmiotu[znalezione_przedmioty], dane[i].kod_przedmiotu, 9);
            znalezione_przedmioty++;
        }
    }
    return znalezione_przedmioty; //liczba przedmiotow lacznie
}


int znajdz(char *szukany_nr, char nr_albumow[100][10], int n) {
    int i;
    for (i=0; i<n; i++) {
        if (strcmp(szukany_nr, nr_albumow[i]) == 0)
            return i;
    }
    return -1;
}

int znajdz_studentow(char nr_albumow[100][10], student dane[100], int n) {
    int ile_znalazlem = 0;
    int i;

    for (i=0; i <n; i++) {
        if (znajdz(dane[i].nr_albumu, nr_albumow, ile_znalazlem) == -1) 
        {
            strncpy(nr_albumow[ile_znalazlem], dane[i].nr_albumu, 9);
            ile_znalazlem++; 
        }
    }
    return ile_znalazlem; //realna liczbe studentow
}

