#ifndef B_FESTAS_H_INCLUDED
#define B_FESTAS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include <conio.h>
#include <time.h>
#include <locale.h>
#include <stdbool.h>

void inclui_festa(FILE *f);
int localiza_codigo_festa(FILE *f, float codigo);
bool busca_cliente(FILE *f, float codigo);
void imprime_cliente(FILE *f)

#endif // B_FESTAS_H_INCLUDED
