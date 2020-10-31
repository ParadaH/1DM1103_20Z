#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int wiersz;
int kolumna;
int wiersz2;
int kolumna2;

int wczytaj1 (FILE *fmacierz1, float tablica1[][10])//wczytywanie danych z podanych argumentów i zapisanie ich w tablicy
{   
    wiersz = 0;
    kolumna = 0;
    float liczba;
    
    fscanf(fmacierz1, "%d", &wiersz);
    fscanf(fmacierz1, "%d", &kolumna);
  
    for(int i = 0; i < wiersz; i++)
        for(int j = 0; j < kolumna; j++)
        {
            fscanf(fmacierz1, "%f", &liczba);
            tablica1[i][j] = liczba;
        }
    return 0;
}

int wczytaj2 (FILE *fmacierz2, float tablica2[][10])//wczytywanie danych z podanych argumentów i zapisanie ich w tablicy
{
    wiersz2 = 0;
    kolumna2 = 0;
    float liczba;

    fscanf(fmacierz2, "%d", &wiersz2);
    fscanf(fmacierz2, "%d", &kolumna2);
  
    for(int i = 0; i < wiersz2; i++)
        for(int j = 0; j < kolumna2; j++)
        {
            fscanf(fmacierz2, "%f", &liczba);
            tablica2[i][j] = liczba;
        }
    return 0;
}

int iloczyn (float tablica1[][10], float tablica2[][10], float tablica3[][10])//iloczyn 2 argumentów i zapisanie ich w 3 tablicy
{
    float suma;
    for(int i = 0; i < wiersz; i++)
    {
        suma = 0;
        for(int j = 0; j < kolumna; j++)
        {
            suma = suma + (tablica1[i][j] * tablica2[j][0]);
        }
        tablica3[i][0] = suma;
    }
    return 0;
}

int wynik(float macierz3[][10], int n)//wypisanie wyniku
{
    printf("(%d) [", n);
    for(int i = 0; i < n; i++)
    { 
        printf("%f ", macierz3[i][0]);
    }
    printf("]\n");
    return 0;
}

int main (int argc, char *argv[])
{
    FILE *fmacierz1;
    fmacierz1 = fopen(argv[1], "r");
    FILE *fmacierz2;
    fmacierz2 = fopen(argv[2], "r");

    float macierz1[10][10];
    float macierz2[10][10];
    float macierz3[10][10];

    wczytaj1(fmacierz1, macierz1);
    wczytaj2(fmacierz2, macierz2);

    if(kolumna != wiersz2) //kontrolka przed wykonaniem obliczenia
    {
        printf("Macierzy nie da sie wymnozyc!");
    }

    iloczyn(macierz1, macierz2, macierz3);
    wynik(macierz3, wiersz);
    
    return 0;
}