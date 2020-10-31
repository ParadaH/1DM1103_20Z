#include<stdio.h>
#include<stdlib.h> //biblioteka standardowa jezyka C
#include<string.h> 

int main(int argc, char *argv[]){
    char n[100]; //zarezerwuj pamiec dla tablicy 100 znakow
    char tab[10][10]; //zawiera 10 tablic kazda po 10 znakow
    // napis to tablica znakow --- char napis[255]; rezerwuje nam 255 znakow (przechowuje 254 znakow znaczacych)
    // zero "\0" oznacza koniec napisu jest uwzgledniony w [255] ww
    strcpy(tab[0], "wieczór");
    strcpy(tab[1], "Dobry");
    strcpy(n, "Ala"); //skopiuj napis w miejsce n, skopiuj Ala [A|L|A|\0] (tabelka)
    int i;
    // char n2[] = "Wielki i dlugi napis"; //zarezerwuje sobie tyle pamieci ile jest znakow za znakiem "="
    // n2 = "Nowy napis!";
    
    printf("%s\n", n); //bedzie pisac dopki nie napotka 0 w tabelce ALA
    printf("%s %s\n", tab[1], tab[0]);
    printf("Znak polecenia %c\n", argv[0][3]);

    for(i = 0; i < 4; i++){
        printf("[%d] %c %d\n", i, n[i], n[i]);
    }
    return 0;


}



