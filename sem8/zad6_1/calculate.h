#ifndef KALKULATOR_H
#define KALKULATOR_H

#include"operacje.h"

struct macierz *suma(struct macierz *m1,struct macierz *m2);
struct macierz *substract(struct macierz *m1,struct macierz *m2);
struct macierz *prod(struct macierz *m1, struct macierz *m2);
float norm(struct macierz *m1);
struct macierz *multiply(struct macierz *m1, float k);

#endif