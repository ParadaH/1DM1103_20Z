#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "baza.h"

int main(int argc, char **argv)
{
    Sbaza *baza;
    baza = wczytaj_baze(argv[1]);
    // listuj_studentow(baza);

    if(strcmp("listofstudents", argv[2]) == 0)
    {
        listuj_studentow(baza);
    }
    if(strcmp("addstudent", argv[2]) == 0)
    {
        dodaj_studentow(baza, argv[3], argv[4], argv[5], argv[6]);
    }
    if(strcmp("addcourse", argv[2]) == 0)
    {
        dodaj_przedmiot(baza, argv[3], argv[4], argv[5]);
    }
    if(strcmp("addstudenttocourse", argv[2]) == 0)
    {
        dodaj_studenta_do_przedmiotu(baza, argv[3], argv[4]);
    }
    if(strcmp("countstudents", argv[2]) == 0)
    {
        printf("Number of students: %d\n", ile_studentow(baza));
    }
    //sortowanie malejaco i rosnaco
    // if(strcmp("sortascending", argv[2]) == 0)
    // {
    //     sortuj_rosnaco();
    // }
    // if(strcmp("sortdescending", argv[2]) == 0)
    // {
    //     sortuj_malejaco();
    // }

    zapisz_baze(argv[1], baza);
    zwolnij(baza);
    return 0;
}