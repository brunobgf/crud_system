#ifndef B_CLIENTES_H_INCLUDED
#define B_CLIENTES_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include <conio.h>
#include <stdbool.h>
#include <time.h>
#include <locale.h>

void CriaArquivoCliente(FILE *fcli);
void IncluiCliente();
int localiza_codigo(FILE *f, float codigo);
void localiza_cliente();


#endif // B_CLIENTES_H_INCLUDED
