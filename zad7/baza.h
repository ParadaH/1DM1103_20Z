#ifndef baza_h_
#define baza_h_

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct _Student{
    char *imie;
    char *nazwisko;
    char *nr_albumu;
    char *email;

    struct _Student *nast;
} Student;

typedef struct _Przedmiot{
    char *kod_przedmiotu;
    char *nazwa_przedmiotu;
    char *semestr;

    struct _Przedmiotu *nast;
} Przedmiot;

typedef struct _Ocena{
    char *nr_albumu;
    char *kod_przedmiotu;

    struct _Ocena *nast;
} Ocena;

typedef struct _Sbaza{
    Student *lista_studentow;
    Przedmiot *lista_przedmiotow;
    Ocena *lista_ocen;
} Sbaza;

Sbaza *wczytaj_baze(char *nazwa_pliku);
Sbaza *zapisz_baze(char *nazwa_pliku, Sbaza *baza);

Student *wczytaj_studentow(FILE *fin);
Ocena *wczytaj_oceny(FILE *fin);
Przedmiot *wczytaj_przedmioty(FILE *fin);

int ile_studentow(Sbaza *baza);
int ile_przedmiotow(Sbaza *baza);
int ile_ocen(Sbaza *baza);

Sbaza *dodaj_studentow(Sbaza *baza, char *imie, char *nazwisko, char *nr_albumu, char *email);
void dodaj_przedmiot(Sbaza *baza, char *kod_przedmiotu, char *nazwa_przedmiotu, char *semestr);
Sbaza *dodaj_studenta_do_przedmiotu(Sbaza *baza, char *kod_przedmiotu, char *nr_albumu);

void listuj_studentow(Sbaza *baza);
void zwolnij(Sbaza *baza);
void zwolnij_liste_studentow(Student *s);
void zwolnij_liste_przedmiotow(Przedmiot *s);
void zwolnij_liste_ocen(Ocena *s);

#endif