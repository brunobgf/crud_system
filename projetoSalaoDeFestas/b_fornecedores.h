#ifndef B_FORNECEDORES_H_INCLUDED
#define B_FORNECEDORES_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include <conio.h>
#include <time.h>
#include <locale.h>

void inclui_fornecedor(FILE *f);
int localiza_fornecedor(FILE *f,int cod);
void imprime_fornecedor(FILE *f);
void exclui_fornecedor(FILE *f);
void altera_fornecedor(FILE *f);

#endif // B_FORNECEDORES_H_INCLUDED

