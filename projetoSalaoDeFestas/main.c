#include "b_funcionarios.h"
#include "b_fornecedores.h"
#include "b_menus.h"


int main()
{
    int  op;
    setlocale(LC_ALL,"portuguese");
    do
    {
        printf("MENU PRINCIPAL:\n");
        printf("Escolha um tipo de entidade voc� deseja acessar:\n");
        printf ("a - Clientes \n");
        printf ("b - Funcionarios \n");
        printf ("c - Fornecedores \n");
        printf ("d - Festas \n");
        printf ("e - sair do programa\n");
        op=getch ();
        switch (op)
        {
        case 'a':
            printf("Obtendo informa��es dos clientes...\n");
            menuClientes();
            break;
        case 'b':
            printf("Obtendo informa��es dos funcionarios...\n");
            menuFuncionarios();
            break;
        case 'c':
            printf("Obtendo informa��es dos fornecedores...\n");
            menuFornecedores();
            break;
        case 'd':
            printf("Obtendo informa��es das festas...\n");
            menuFestas();
            break;
        }
    }
    while(op!='e');
    return 0;
}




/*

    do
    {

        printf("Escolha:\n");
        printf ("a - incluir funcionario \n");
        printf("b - alterar funcionario\n");
        printf ("c - imprimir funcionario\n");
        printf ("d - excluir funcionario\n");
        printf ("e - sair do programa\n");
        op=getch ();
        switch (op)
        {
        case 'a':
            printf("preenchendo o arquivo...\n");
            inclui_funcionario(f);
            break;

        case 'b':
            printf("alterando o arquivo...\n");
            altera_funcionario(f);
            break;

        case 'c':
            printf("imprmindo o arquivo...\n");
            imprime_funcionario(f);
            system("pause");
            break;

        case 'd':
            printf("deletando linha...\n");
            exclui_funcionario(f);
            system("pause");
            break;
        }
    }
    while(op!='e');
    fclose(f);

    return 0;
}
*/
