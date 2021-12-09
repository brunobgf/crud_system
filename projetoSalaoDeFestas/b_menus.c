#include "b_menus.h"
#include "b_clientes.h"
#include "b_funcionarios.h"
#include "b_fornecedores.h"
#include "b_festas.h"

void menuClientes()
{
    int op;
    FILE *fcli;
    setlocale(LC_ALL,"portuguese");

    if ((fcli = fopen("controleClientes.dat", "r+b"))==NULL) // arquivo existe
    {
        printf("Arquivo não existia ... criando arquivo!\n");
        if((fcli = fopen("controleClientes.dat", "w+b"))==NULL) //arq não existe
        {
            printf("Erro na criação do arquivo!!");
            exit(1);
        }
    }
    do
    {

        printf("Escolha:\n");
        printf ("a - Cadastro de Clientes \n");
        printf ("b - Imprimir cliente por código\n");
        printf ("c - Imprimir todos os clientes\n");
        printf ("d - Alterar cliente\n");
        printf ("e - Excluir cliente\n");
        printf ("f - Voltar para o menu principal\n");
        op=getch ();
        switch (op)
        {
        case 'a':
            printf("Cadastrando um novo cliente...\n");
            printf("preenchendo o arquivo...\n");
            inclui_cliente(fcli);
            break;
       case 'c':
            printf("Mostrando todos os clientes...\n");
            printf("preenchendo o arquivo...\n");
            imprime_cliente(fcli);
            break;
        }
    }
    while(op!='e');
    fclose(fcli);
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
        printf ("c - Imprimir todos os funcionarios\n");
        printf ("d - Alterar funcionario\n");
        printf ("e - Excluir funcionario\n");
        printf ("f - Voltar para o menu principal\n");
        op=getch ();
        switch (op)
        {
        case 'a':
            printf("Cadastrando um novo funcionário...\n");
            printf("preenchendo o arquivo...\n");
            inclui_funcionario(f);
            break;
        case 'c':
            printf("Cadastrando um novo funcionário...\n");
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
        printf ("b - Imprimir fornecedor por código\n");
        printf ("c - Imprimir todos os Fornecedores\n");
        printf ("d - Alterar fornecedor\n");
        printf ("e - Excluir fornecedor\n");
        printf ("f - Voltar para o menu principal\n");
        op=getch ();
        switch (op)
        {
        case 'a':
            printf("Cadastrando um novo funcionário...\n");
            printf("preenchendo o arquivo...\n");
            inclui_fornecedor(f);
            break;
        case 'c':
            printf("Cadastrando um novo funcionário...\n");
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
    FILE *f;
    setlocale(LC_ALL,"portuguese");

    if ((f = fopen("controleFestas.dat", "r+b"))==NULL) // arquivo existe
    {
        printf("Arquivo não existia ... criando arquivo!\n");
        if((f = fopen("controleFestas.dat", "w+b"))==NULL) //arq não existe
        {
            printf("Erro na criação do arquivo!!");
            exit(1);
        }
    }
    do
    {

        printf("Escolha:\n");
        printf ("a - Cadastro de Clientes \n");
        printf ("b - Imprimir cliente por código\n");
        printf ("c - Imprimir todos os clientes\n");
        printf ("d - Alterar cliente\n");
        printf ("e - Excluir cliente\n");
        printf ("f - Voltar para o menu principal\n");
        op=getch ();
        switch (op)
        {
        case 'a':
            printf("Cadastrando um novo cliente...\n");
            printf("preenchendo o arquivo...\n");
            inclui_festa(f);
            break;
        case 'c':
            printf("Mostrando todos os clientes...\n");
            printf("preenchendo o arquivo...\n");
            imprime_cliente(f);
            break;
        }
    }
    while(op!='e');
    fclose(f);
    printf("\nVoltando para o menu principal...\n\n");
}
