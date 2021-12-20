#include "b_funcionarios.h"
#include "b_menus.h"

struct Tfuncionario
{
    char nome[50],tipo[3];
    int cod, tel;
    float salario;
};
typedef struct Tfuncionario funcionario;


void inclui_funcionario(FILE *f)
{

    funcionario fun;
    int posicao;
    //lendo os dados do teclado
    printf("Digite o numero do codigo...:");
    fflush(stdin);
    scanf("%d",&fun.cod);
    posicao=localiza_funcionario(f,fun.cod);
    if (posicao==-1) //não tinha codigo no arquivo
    {

        printf("Digite o nome do funcionario...:");
        fflush(stdin);
        gets(fun.nome);
        printf("Digite o telefone do funcionario...:");
        fflush(stdin);
        scanf("%d",&fun.tel);
        printf("Digite T para - temporário ou F para - fixo :");
        fflush(stdin);
        gets(fun.tipo);
        printf("Digite o salario do funcionario:");
        fflush(stdin);
        scanf("%f",&fun.salario);
        fseek(f,0,SEEK_END); // posicionado o arquivo no final
        fwrite(&fun, sizeof(fun),1,f); //gravando os dados
        fflush(f);
    }
    else
    {
        printf("Código %d já existe no arquivo. Inclusão não realizada!\n",fun.cod);
    }
}

/*
void imprime_funcionario(FILE *f, int cod)
{
    funcionario fun;
    fseek(f,0,SEEK_SET);
    fread(&fun, sizeof(fun),1, f);
    while (!feof(f))
    {
        if(fun.cod!=0)
        {
            printf("Código....................:%d \n",fun.cod);
            printf("Nome......................:%s \n",fun.nome);
            printf("Telefone..................:%d\n",fun.tel);
            printf("Tipo(1-Fixo, 2-Temporario):%s\n",fun.tipo);
            printf("Salario.................:R$%.2f\n",fun.salario);

        }

        fread(&fun, sizeof(fun),1, f);
    }
}

*/

void imprime_funcionario(FILE *f)
{
    int posicao=-1,achou=0;
    int cod;
    funcionario fun;

    printf("Digite o numero do codigo...:");
    fflush(stdin);
    scanf("%d",&cod);


    fseek(f,0,SEEK_SET);
    fread(&fun, sizeof(fun),1, f);
    while (!feof(f) && !achou)
    {
        posicao++; // semelhante a posicao = posicao +1;
        if (fun.cod==cod)
        {
            achou=1;
            printf("Código....................:%d \n",fun.cod);
            printf("Nome......................:%s \n",fun.nome);
            printf("Telefone..................:%d\n",fun.tel);
            printf("Tipo(1-Fixo, 2-Temporario):%s\n",fun.tipo);
            printf("Salario.................:R$%.2f\n",fun.salario);
        }
        fread(&fun, sizeof(fun),1, f);
    }
    if (achou)
    {
        printf("Funcionario encontrado. Deseja buscar por mais algum? \n");
    }
    else
    {
        printf("Funcionario não encontrado, tente outro código\n");
    }
}

int localiza_funcionario(FILE *f,int cod)
{
    int posicao=-1,achou=0;
    funcionario fun;
    fseek(f,0,SEEK_SET);
    fread(&fun, sizeof(fun),1, f);
    while (!feof(f) && !achou)
    {
        posicao++; // semelhante a posicao = posicao +1;
        if (fun.cod==cod)
        {
            achou=1;
        }
        fread(&fun, sizeof(fun),1, f);
    }
    if (achou)
    {
        return posicao;
    }
    else
    {
        return -1;
    }
}

