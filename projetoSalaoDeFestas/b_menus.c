#include "b_menus.h"
#include "b_clientes.h"
#include "b_funcionarios.h"
#include "b_fornecedores.h"
#include "b_festas.h"

void menuClientes()
{
    int op;
    setlocale(LC_ALL,"portuguese");

    do
    {

        printf("Escolha:\n");
        printf ("a - Cadastro de Clientes \n");
        printf ("b - Imprimir cliente por código\n");
        printf ("e - Voltar para o menu principal\n");
        op=getch ();
        switch (op)
        {
        case 'a':
            printf("Cadastrando um novo cliente...\n");
            printf("preenchendo o arquivo...\n");
            IncluiCliente();
            break;


        case 'b':
            printf("Buscando pelo cliente...\n");
            printf("preenchendo o arquivo...\n");
            localiza_cliente();
            break;

        }
    }
    while(op!='e');

    printf("\nVoltando para o menu principal...\n\n");
}


void menuFuncionarios()
{
    int op;
    FILE *f;
    setlocale(LC_ALL,"portuguese");

    if ((f = fopen("controleFuncionarios.dat", "r+b"))==NULL) // arquivo existe
    {
        printf("Arquivo não existia ... criando arquivo!\n");
        if((f = fopen("controleFuncionarios.dat", "w+b"))==NULL) //arq não existe
        {
            printf("Erro na criação do arquivo!!");
            exit(1);
        }
    }
    do
    {

        printf("Escolha:\n");
        printf ("a - Cadastro de Funcionarios \n");
        printf ("b - Imprimir funcionario por código\n");
        printf ("e - Voltar para o menu principal\n");
        op=getch ();
        switch (op)
        {
        case 'a':
            printf("Cadastrando um novo funcionário...\n");
            printf("preenchendo o arquivo...\n");
            inclui_funcionario(f);
            break;
        case 'b':
            printf("Procurando pelo funcionário...\n");
            printf("preenchendo o arquivo...\n");
            imprime_funcionario(f);
            break;
        }
    }
    while(op!='e');
    fclose(f);
    printf("\nVoltando para o menu principal...\n\n");
}


void menuFornecedores()
{
    int op;
    FILE *f;
    setlocale(LC_ALL,"portuguese");

    if ((f = fopen("controleFornecedores.dat", "r+b"))==NULL) // arquivo existe
    {
        printf("Arquivo não existia ... criando arquivo!\n");
        if((f = fopen("controleFornecedores.dat", "w+b"))==NULL) //arq não existe
        {
            printf("Erro na criação do arquivo!!");
            exit(1);
        }
    }
    do
    {

        printf("Escolha:\n");
        printf ("a - Cadastro de Fornecedores \n");
        printf ("b - Pesquise fornecedor por código\n");
        printf ("e - Voltar para o menu principal\n");
        op=getch ();
        switch (op)
        {
        case 'a':
            printf("Cadastrando um novo fornecedor...\n");
            printf("preenchendo o arquivo...\n");
            inclui_fornecedor(f);
            break;
        case 'b':
            printf("Pesquisando por fornecedor...\n");
            printf("preenchendo o arquivo...\n");
            imprime_fornecedor(f);
            break;
        }
    }
    while(op!='e');
    fclose(f);
    printf("\nVoltando para o menu principal...\n\n");
}


void menuFestas()
{
    int op;

    setlocale(LC_ALL,"portuguese");

    do
    {

        printf("Escolha:\n");
        printf ("a - Cadastro de Festas \n");
        printf ("b - Relatório de festas por código do cliente\n");
        printf ("c - Alterar status contrato \n");
        printf ("d - Relatório de festas por data\n");
        printf ("e - Voltar para o menu principal\n");
        op=getch ();
        switch (op)
        {
        case 'a':
            printf("Cadastrando uma nova festa...\n");
            printf("preenchendo o arquivo...\n");
            IncluiFesta();
            break;
        case 'b':
            printf("Buscando festas...\n");
            printf("preenchendo o arquivo...\n");
            localiza_festas_cliente();
            break;
        case 'c':
            printf("Buscando contrato...\n");
            printf("preenchendo o arquivo...\n");
            altera_status_contrato();
            break;
        case 'd':
            printf("Buscando festas na data especifica...\n");
            printf("preenchendo o arquivo...\n");
            localiza_festas_data();
            break;
        }
    }
    while(op!='e');
    printf("\nVoltando para o menu principal...\n\n");
}


