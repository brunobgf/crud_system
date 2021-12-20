#ifndef B_FESTAS_H_INCLUDED
#define B_FESTAS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include <conio.h>
#include <time.h>
#include <locale.h>
#include <stdbool.h>

void IncluiFesta();
int localiza_codigo_festa(FILE *f, float codigo);
int VerificaDataDisponivel(FILE *f, char data[50]);
int VerificaHorario(FILE *f, int horaini, int horafim);
bool BuscaCliente(float codigo);
float CalculaTotalFesta(int, int );
void localiza_festas_cliente();
int verifica_codigo_festa(FILE *f);
void altera_status_contrato();
void localiza_festas_data();

float CalculaTotalFesta(int, int);
float CalculaDesconto(int formapag, float valorbruto);

#endif // B_FESTAS_H_INCLUDED
