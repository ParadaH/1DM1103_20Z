#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char *argv[]){
    char n[100]; //zarezerwuj pamiec dla tablicy 100 znakow
    char tab[10][10]; //zawiera 10 tablic kazda po 10 znakow
    strcpy(tab[0], "akuku");
    strcpy(tab[1], "siemanko");
    strcpy(n, "Ala"); //skopiuj napis w miejsce n, skopiuj Ala [A|L|A|\0] (tabelka)
    int i;
    // char n2[] = "Wielki i dlugi napis"; //zarezerwuje sobie pamieci bo ma po = napisane
    // n2 = "Nowego napis!";
    
    printf("%s\n", n); //bedzie pisac dopki nie napotka 0 w tabelce ALA
    printf("%s %s %s", n, tab[1], tab[0]);
    printf(" argv: %c\n", argv[0][3]);

    for(i = 0; i < 4; i++){
        printf("[%d] %c %d\n", i, n[i], n[i]);
    }
    return 0;


}