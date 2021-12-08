#include "b_menus.h"
#include "b_clientes.h"

struct TCliente
{
    int excluido, telefone;
    char nome[50], endereco[50], dtnascimento[9];
    float codigo;
};
typedef struct TCliente cliente;

void inclui_cliente(FILE *f)
{
    cliente cli;
    int posicao;
//lendo os dados do teclado
    printf("Digite o código do cliente...: ");
    fflush(stdin);
    scanf("%f",&cli.codigo);
    posicao = localiza_cliente(f, cli.codigo);

    if(posicao == -1) //não tinha código no arquivo
    {
        printf("Digite o nome do cliente...: ");
        fflush(stdin);
        gets(cli.nome);
        printf("Digite o endereço do cliente...: ");
        fflush(stdin);
        gets(cli.endereco);
        printf("Digite o telefone do cliente...: ");
        scanf("%d",&cli.telefone);
        printf("Digite a data de nascimento...: ");
        fflush(stdin);
        gets(cli.dtnascimento);

        fseek(f,0,SEEK_END); // posicionado o arquivo no final
        fwrite(&cli, sizeof(cli),1,f); //gravando os dados
        fflush(f);
        printf("\nRegistro salvo com sucesso!\n\n ");
    }
    else
    {
        printf("\nCódigo %0.f já existe no arquivo. Inclusão não realizada!\n\n", cli.codigo);
    }
}

int localiza_cliente(FILE *f, float codigo)
{
    int posicao = -1, achou = 0;

    cliente cli;
    fseek(f,0,SEEK_SET); // do inicio
    fread(&cli, sizeof(cli),1, f); // lendo o arquivo

    while(!feof(f) && !achou)
    {
        posicao++;
        if(cli.codigo == codigo && cli.excluido != 1)
        {
            achou = 1;
        }
        fread(&cli, sizeof(cli),1, f); // ver com o prof.
    }
    if(achou)
    {
        return posicao;
    }
    else
    {
        return -1;
    }

}

/*
void imprime_cliente(FILE *f)
{
    Cliente cli;
    fseek(f,0,SEEK_SET);
    fread(&cli, sizeof(cli),1, f);
    while (!feof(f))
    {
        if(cli.codigo!=0)
        {
            printf("Código....................:%.2f\n",cli.codigo);
            printf("Nome......................:%s \n",cli.nome);
            printf("Telefone..................:%d\n",cli.telefone);
            printf("Endreço...................:%s\n",cli.endereco);
            printf("Data de Nascimento........:%s\n",cli.dtnascimento);

        }

        fread(&fun, sizeof(fun),1, f);
    }
}
*/
