#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"studenci.h"
#include"dziekanat.h"

int main(int argc, char **argv)
{
    student dane[100];
    int ile = wczytaj(dane);

    if(strcmp(argv[1], "najlepszy_student") == 0)
    {
        najlepszy_student(dane, ile);
    }

    if(strcmp(argv[1], "najlepszy_przedmiot") == 0)
    {
        najlepszy_przedmiot(dane, ile);
    }

    if(strcmp(argv[1], "najgorszy_przedmiot") == 0)
    {
        najgorszy_przedmiot(dane, ile);
    }
}