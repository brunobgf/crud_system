#ifndef B_CLIENTES_H_INCLUDED
#define B_CLIENTES_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include <conio.h>
#include <time.h>
#include <locale.h>
void inclui_cliente(FILE *f);
int localiza_cliente(FILE *f, float codigo);
void imprime_cliente(FILE *f);

#endif // B_CLIENTES_H_INCLUDED
