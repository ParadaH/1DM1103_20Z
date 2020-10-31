#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char *argv[]) //obliczanie kwadratow liczb 
{
        float v;
        float a; 
        a = atof(argv[1]);
        v = a*a;
        printf("Wartość %f do kwadratu to %f.\n", a, v);

        return 0;
    }