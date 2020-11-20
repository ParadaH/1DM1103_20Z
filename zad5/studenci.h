#ifndef STUDENCI_H_
#define STUDENCI_H_

typedef struct _student {
    char imie[25];
    char nazwisko[50];
    char nr_albumu[10];
    char kod_przedmiotu[10];
    char nazwa_przedmiotu[255];
    float ocena;
    int ects;
} student;

int wczytaj(student dane[100]);
void wypisz(student dane[100], int n);

int szukajp(char *szukany_przedmiot, char nr_przedmiotu[100][10], int n);
int szukaj_przedmiotow(char nr_przedmiotu[100][10], student dane[100], int n);

int znajdz(char *szukany_nr, char nr_albumow[100][10], int n);
int znajdz_studentow(char nr_albumow[100][10], student dane[100], int n);

#endif
