#ifndef B_FUNCIONARIOS_H_INCLUDED
#define B_FUNCIONARIOS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include <conio.h>
#include <time.h>
#include <locale.h>

void criaArquivoFuncionario(FILE *f);
void inclui_funcionario(FILE *f);
int localiza_funcionario(FILE *f,int cod);
void imprime_funcionario(FILE *f);
void exclui_funcionario(FILE *f);
void altera_funcionario(FILE *f);

#endif // B_FUNCIONARIOS_H_INCLUDED
