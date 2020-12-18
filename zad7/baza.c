#include "baza.h"

Sbaza *wczytaj_baze(char *nazwa_pliku)
{
    FILE *fin = fopen(nazwa_pliku, "r");
    if(fin == NULL)
    {
        printf("BŁĄD! Nie moge otworzyć pliku: %s.\n", nazwa_pliku);
        exit(-1);
    }
    Sbaza *baza = (Sbaza*) malloc(sizeof(Sbaza));
    baza->lista_studentow = wczytaj_studentow(fin);
    baza->lista_przedmiotow = wczytaj_przedmioty(fin);
    baza->lista_ocen = wczytaj_oceny(fin);

    fclose(fin);
    return baza;
}

Student *wczytaj_studentow(FILE *fin)
{
    char bufor[255];
    int n;
    char *s;
    Student *glowa = NULL;
    Student *last_student = NULL;

    fgets(bufor, 254, fin);
    sscanf(bufor, "%d", &n);
    for(int i = 0; i < n; i++)
    {
        Student *student = (Student*) malloc(sizeof(Student));
        student->nast = NULL;

        if(last_student == NULL)
        {
            glowa = student;
        }
        else
        {
            last_student->nast = student;
        }
        last_student = student;

        fgets(bufor, 254, fin);
        s = strtok(bufor, ";");
        student->imie = (char*) malloc(sizeof(char) * (strlen(s) + 1));
        strcpy(student->imie, s);

        s = strtok(NULL, ";");
        student->nazwisko = (char*) malloc(sizeof(char) * (strlen(s) + 1));
        strcpy(student->nazwisko, s);

        s = strtok(NULL, ";");
        student->nr_albumu = (char*) malloc(sizeof(char) * (strlen(s) + 1));
        strcpy(student->nr_albumu, s);

        s = strtok(NULL, "\n");
        student->email = (char*) malloc(sizeof(char) * (strlen(s) + 1));
        strcpy(student->email, s);
    }

    return glowa;
}

Przedmiot *wczytaj_przedmioty(FILE *fin)
{
    char bufor[255];
    int n;
    char *s;
    Przedmiot *glowa = NULL;
    Przedmiot *last_subject = NULL;

    fgets(bufor, 254, fin);
    sscanf(bufor, "%d", &n);
    for(int i = 0; i < n; i++)
    {
        Przedmiot *przed = (Przedmiot*) malloc(sizeof(Przedmiot));
        przed->nast = NULL;

        if(last_subject == NULL)
        {
            glowa = przed;
        }
        else
        {
            last_subject->nast = przed;
        }
        last_subject = przed;

        fgets(bufor, 254, fin);
        s = strtok(bufor, ";");
        przed->kod_przedmiotu = (char*) malloc(sizeof(char) * (strlen(s) + 1));
        strcpy(przed->kod_przedmiotu, s);

        s = strtok(NULL, ";");
        przed->nazwa_przedmiotu = (char*) malloc(sizeof(char) * (strlen(s) + 1));
        strcpy(przed->nazwa_przedmiotu, s);

        s = strtok(NULL, "\n");
        przed->semestr = (char*) malloc(sizeof(char) * (strlen(s) + 1));
        strcpy(przed->semestr, s);
    }
    return glowa;
}

Ocena *wczytaj_oceny(FILE *fin)
{
    char bufor[255];
    int n;
    char *s;
    Ocena *glowa = NULL;
    Ocena *last_grade = NULL;

    fgets(bufor, 254, fin);
    sscanf(bufor, "%d", &n);
    for(int i = 0; i < n; i++)
    {
        Ocena *grade = (Ocena*) malloc(sizeof(Ocena));
        grade->nast = NULL;

        if(last_grade == NULL)
        {
            glowa = grade;
        }
        else
        {
            last_grade->nast = grade;
        }
        last_grade = grade;

        fgets(bufor, 254, fin);
        s = strtok(bufor, ";");
        grade->kod_przedmiotu = (char*) malloc(sizeof(char) * (strlen(s) + 1));
        strcpy(grade->kod_przedmiotu, s);

        s = strtok(NULL, "\n");
        grade->nr_albumu = (char*) malloc(sizeof(char) * (strlen(s) + 1));
        strcpy(grade->nr_albumu, s);

    }
    return glowa;
}

void zapisz_baze(char *nazwa_pliku, Sbaza *baza)
{
    FILE *fout;
    fout = fopen(nazwa_pliku, "w+");

    Student *student = baza->lista_studentow;
    Przedmiot *przedmiot = baza->lista_przedmiotow;
    Ocena *ocena = baza->lista_ocen;

    fprintf(fout, "%d\n", ile_studentow(baza));
    for(int i = 0; i < ile_studentow(baza); i++)
    {
        fprintf(fout, "%s;%s;%s;%s\n", student->imie, student->nazwisko, student->nr_albumu, student->email);
        student = student->nast;
    }

    fprintf(fout, "%d\n", ile_przedmiotow(baza));
    for(int j = 0; j < ile_przedmiotow(baza); j++)
    {
        fprintf(fout, "%s;%s;%s\n", przedmiot->kod_przedmiotu, przedmiot->nazwa_przedmiotu, przedmiot->semestr);
        przedmiot = przedmiot->nast;
    }

    fprintf(fout, "%d\n", ile_ocen(baza));
    for(int k = 0; k < ile_ocen(baza); k++)
    {
        fprintf(fout, "%s;%s\n", ocena->kod_przedmiotu, ocena->nr_albumu);
        ocena = ocena->nast;
    }
    fclose(fout);
}

Sbaza *dodaj_studentow(Sbaza *baza, char *imie, char *nazwisko, char *nr_albumu, char *email)
{
    Student *nowy = (Student*) malloc(sizeof(Student));
  	Student *teraz = NULL;
  	nowy->nast = NULL;

  	nowy->imie = (char*) malloc(sizeof(char) * (strlen(imie) + 1));
    strcpy(nowy->imie, imie);
    nowy->nazwisko = (char*) malloc(sizeof(char) * (strlen(nazwisko) + 1));
    strcpy(nowy->nazwisko, nazwisko);
    nowy->nr_albumu = (char*) malloc(sizeof(char) * (strlen(nr_albumu) + 1));
    strcpy(nowy->nr_albumu, nr_albumu);
    nowy->email = (char*) malloc(sizeof(char) * (strlen(email) + 1));
    strcpy(nowy->email, email);

    teraz = baza->lista_studentow;
    
    if(ile_studentow(baza) == 0)
    {
        baza->lista_studentow = nowy;
    }
    else
    {
        for(int i = 1; i < ile_studentow(baza); i++)
        {
            teraz = teraz->nast;
        }
        teraz->nast = nowy;
    }   
    return NULL;
}

Sbaza *dodaj_przedmiot(Sbaza *baza, char *kod_przedmiotu, char *nazwa_przedmiotu, char *semestr)
{
 	Przedmiot *nowy = (Przedmiot*) malloc(sizeof(Przedmiot));
  	Przedmiot *teraz = NULL;
  	nowy->nast = NULL;
    
  	nowy->kod_przedmiotu = (char*) malloc(sizeof(char) * (strlen(kod_przedmiotu) + 1));
    strcpy(nowy->kod_przedmiotu, kod_przedmiotu);

    nowy->nazwa_przedmiotu = (char*) malloc(sizeof(char) * (strlen(nazwa_przedmiotu) + 1));
    strcpy(nowy->nazwa_przedmiotu, nazwa_przedmiotu);

    nowy->semestr = (char*) malloc(sizeof(char) * (strlen(semestr) + 1));
    strcpy(nowy->semestr, semestr);

    teraz = baza->lista_przedmiotow;
    
    if(ile_przedmiotow(baza) == 0)
    {
        baza->lista_przedmiotow = nowy;
    }
    else
    {
        for(int i = 1; i< ile_przedmiotow(baza); i++)
        {
            teraz = teraz->nast;
        }
        teraz->nast = nowy;
    }
    return NULL;
}
    
Sbaza *dodaj_studenta_do_przedmiotu(Sbaza *baza, char *kod_przedmiotu, char *nr_albumu)
{
	Ocena *nowy = (Ocena*) malloc(sizeof(Ocena));
  	Ocena *teraz = NULL;
	nowy->nast = NULL;

  	nowy->kod_przedmiotu = (char*) malloc(sizeof(char) * (strlen(kod_przedmiotu) + 1));
    strcpy(nowy->kod_przedmiotu, kod_przedmiotu);
    
    nowy->nr_albumu = (char*) malloc(sizeof(char) * (strlen(nr_albumu) + 1));
    strcpy(nowy->nr_albumu, nr_albumu);

    teraz = baza->lista_ocen;
    
    if(ile_ocen(baza) == 0)
    {
        baza->lista_ocen = nowy;
    }
    else
    {
        for(int i = 1; i < ile_ocen(baza); i++)
        {
            teraz = teraz->nast;
        }
        teraz->nast = nowy;
    }
    return NULL;
}

int ile_studentow(Sbaza *baza) 
{
    
    int n = 0;
    Student *student = baza->lista_studentow;
    while (student != NULL) 
    {
        n++;
        student = student->nast;
    }
    return n;
}

int ile_przedmiotow(Sbaza *baza)
{
	int n = 0;
    Przedmiot * przedmiot = baza->lista_przedmiotow;
    while (przedmiot != NULL) 
    {
        n++;
        przedmiot = przedmiot->nast;
    }
    return n;
}

int ile_ocen(Sbaza *baza)
{
	int n = 0;
    Ocena *ocena = baza->lista_ocen;
    while (ocena != NULL) 
    {
        n++;
        ocena = ocena->nast;
    }
    return n;
}

void listuj_studentow(Sbaza *baza) 
{
    Student *student = baza->lista_studentow;
    while (student != NULL) 
    {
        printf("%s %s %s %s\n", student->imie, student->nazwisko, student->nr_albumu, student->email);
        student = student->nast;
    }
}



void zwolnij_student(Student *s) 
{
    free(s->imie);
    free(s->nazwisko);
    free(s->nr_albumu);
    free(s->email);
    free(s);
}

void zwolnij_przedmiot(Przedmiot *s) 
{
    free(s->kod_przedmiotu);
    free(s->nazwa_przedmiotu);
    free(s->semestr);
    free(s);
}

void zwolnij_ocena(Ocena *s) 
{
    free(s->kod_przedmiotu);
    free(s->nr_albumu);
    free(s);
}

void zwolnij_liste_studentow(Student *s) 
{
    Student *n;
    while (s != NULL) 
    {
        n = s->nast;
        zwolnij_student(s);
        s = n;
    }
}

void zwolnij_liste_przedmiotow(Przedmiot *s) 
{
    Przedmiot *n;
    while (s != NULL) 
    {
        n = s->nast;
        zwolnij_przedmiot(s);
        s = n;
    }
}

void zwolnij_liste_ocen(Ocena *s) 
{
    Ocena *n;
    while (s != NULL) 
    {
        n = s->nast;
        zwolnij_ocena(s);
        s = n;
    }
}

void zwolnij(Sbaza *baza) 
{
    zwolnij_liste_studentow(baza->lista_studentow);
    zwolnij_liste_przedmiotow(baza->lista_przedmiotow);
    zwolnij_liste_ocen(baza->lista_ocen);
    free(baza);
} 