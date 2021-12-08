#include <stdio.h>
#include <stdlib.h>

void menuCadastros();
void menuPesquisa();
void menuRelatorio();

int main()
{
    int  op,opCadastro;
    srand(time(NULL));
    FILE *f;
    setlocale(LC_ALL,"portuguese");

    if ((f = fopen("controleSalaoDeFestas.dat", "r+b"))==NULL) // arquivo existe
    {
        printf("Arquivo n�o existia ... criando arquivo!");
        if((f = fopen("controleSalaoDeFestas.dat", "w+b"))==NULL) //arq n�o existe
        {
            printf("Erro na cria��o do arquivo!!");
            exit(1);
        }
    }

    do
    {
        printf("MENU:\n");
        printf("Escolha uma op��o:\n");
        printf ("a - Cadastrar uma entidade\n\n");
        printf ("b - Pesquisar uma entidade\n");
        printf ("c - Alterar um contrato\n");
        printf ("d - Exibir relat�rio\n");
        printf ("e - sair do programa\n");
        op=getch ();
        switch (op)
        {
        case 'a':
            printf("Cadastrando um novo funcion�rio...\n");
            menuCadastros();
            break;

        case 'b':
            printf("Pesquisando uma entidade...\n");
            menuPesquisa();
            break;

        case 'c':
            printf("Atualizando um contrato\n");
            atualiza_contrato(f);
            system("pause");
            break;

        case 'd':
            printf("Gerando relat�rio...\n");
            menuRelatorio();
            system("pause");
            break;


        }
    }
    while(op!='e');
    fclose(f);
    return 0;
}

void menuCadastros()
{
    do
    {

        printf("Escolha:\n");
        printf ("a - Cadastro de Clientes \n");
        printf("b - Cadastro de Funcion�rios\n");
        printf ("c - Cadastro de Fornecedores\n");
        printf ("d - Cadastro de Festa\n");
        printf ("e - Sair do programa\n");
        op=getch ();
        switch (op)
        {
        case 'a':
            printf("Cadastrando um novo cliente...\n");
            cadastro_cliente(f);
            break;

        case 'b':
            printf("Cadastrando um novo funcion�rio...\n");
            cadastro_funcionario(f);
            break;

        case 'c':
            printf("Cadastrando um novo fornecedor...\n");
            cadastro_fornecedor(f);
            system("pause");
            break;

        case 'd':
            printf("Cadastrando uma nova festa...\n");
            cadastro_festa(f);
            system("pause");
            break;
        }
    }
    while(op!='e');
    fclose(f);
}

void menuPesquisa()
{
    do
    {

        printf("Escolha:\n");
        printf ("a - Informa��es de Clientes \n");
        printf ("b - Informa��es de Funcion�rios\n");
        printf ("c - Informa��es de Fornecedores\n");
        printf ("d - Sair do programa\n");
        op=getch ();
        switch (op)
        {
        case 'a':
            printf("Informa��es de cliente...\n");
            pesquisa_cliente(f);
            break;

        case 'b':
            printf("Informa��es de um funcion�rio...\n");
            pesquisa_funcionario(f);
            break;

        case 'c':
            printf("Informa��es de um fornecedor...\n");
            pesquisa_fornecedor(f);
            system("pause");
            break;
        }
    }
    while(op!='d');
    fclose(f);
}

void menuRelatorio()
{
    do
    {

        printf("Escolha:\n");
        printf ("a - Relat�rios de festas por cliente \n");
        printf ("b - Relat�rios de festas por data\n");
        printf ("c - Sair do programa\n");
        op=getch ();
        switch (op)
        {
        case 'a':
            printf("Gerando relat�rio...\n");
            relatorio_cliente(f);
            break;

        case 'b':
            printf("Gerando relat�rio...\n");
            relatorio_data(f);
            break;
        }
    }
    while(op!='c');
    fclose(f);
}
