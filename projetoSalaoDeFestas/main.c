#include "b_funcionarios.h"
#include "b_fornecedores.h"
#include "b_menus.h"

/*

TRABALHO AED I - SALAO DE FESTAS

Alunos:
- Bruno Gomes Ferreira
- Samara Martins Ferreira

*/


/*

DADOS DE CLIENTES/FUNCIONARIOS/FORNECEDORES CADASTRADOS PARA REALIZAR O TESTE

- Clientes: Código 1313 e 1414
- Funcionários: Código 2212
- Fornecedores: Código 123
- Festas: Código de festa 112021 e 155 ; Festas cadastradas no momento: 10/12/21

*/


int main()
{
    int  op;
    setlocale(LC_ALL,"portuguese");
    do
    {
        printf("MENU PRINCIPAL:\n");
        printf("Escolha um tipo de entidade você deseja acessar:\n");
        printf ("a - Clientes \n");
        printf ("b - Funcionarios \n");
        printf ("c - Fornecedores \n");
        printf ("d - Festas \n");
        printf ("e - sair do programa\n");
        op=getch ();
        switch (op)
        {
        case 'a':
            printf("Obtendo informações dos clientes...\n");
            menuClientes();
            break;
        case 'b':
            printf("Obtendo informações dos funcionarios...\n");
            menuFuncionarios();
            break;
        case 'c':
            printf("Obtendo informações dos fornecedores...\n");
            menuFornecedores();
            break;
        case 'd':
            printf("Obtendo informações das festas...\n");
            menuFestas();
            break;
        }
    }
    while(op!='e');
    return 0;
}

