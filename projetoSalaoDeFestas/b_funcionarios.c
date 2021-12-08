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


void imprime_funcionario(FILE *f)
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


void altera_funcionario(FILE *f)
{
    int cod,posicao;
    funcionario fun;
    printf("Diga qual o numero do codigo para alterar:");
    scanf("%d",&cod);
    posicao=localiza_funcionario(f,cod);
    if (posicao!=-1) // localizou a mercadoria
    {
        fseek(f,sizeof(fun)*(posicao),SEEK_SET); //encontra posição escolhida
        fread(&fun, sizeof(fun),1, f);
        printf("Codigo atual:%d Nome: %s telefone: %d tipo: %s salario:%.2f\n",fun.cod,fun.nome,fun.tel,fun.tipo,fun.salario);
        printf("Novo nome...:");
        fflush(stdin);
        gets(fun.nome);
        printf("Novo telefone...:");
        fflush(stdin);
        scanf("%d",&fun.tel);
        printf("Digite 1 para - temporário ou 2 para - fixo :");
        fflush(stdin);
        gets(fun.tipo);
        printf("Digite o novo salario do funcionario:");
        fflush(stdin);
        scanf("%f",&fun.salario);
        fseek(f,sizeof(fun)*(posicao),SEEK_SET);
        fwrite(&fun, sizeof(fun),1, f); //escreve a alteração
        fflush(f);
    }
}


void exclui_funcionario(FILE *f)
{
    int cod,posicao;
    int escolha;
    funcionario fun;
    printf("Diga qual o codigo do funcionario você deseja excluir:");
    scanf("%d",&cod);
    printf("Realmente deseja excluir? Digite 1 para confirmar ou outra tecla para desfazer a operação\n");
    scanf("%d",&escolha);

    if(escolha==1)
    {
        posicao=localiza_funcionario(f,cod);
        if (posicao!=-1) // localizou a mercadoria
        {
            fseek(f,sizeof(fun)*(posicao),SEEK_SET); //encontra posição escolhida
            fread(&fun, sizeof(fun),1, f);


            // a.nome[50]='excluida';
            fun.cod=0;
            fun.salario=0;
            fun.tel=0;
            //fun.tipo=0;

            fseek(f,sizeof(fun)*(posicao),SEEK_SET);
            fwrite(&fun, sizeof(fun),1, f); //escreve a alteração
            printf("Funcionario excluido\n");
            fflush(f);
        }

    }
    else
    {
        printf("O funcionario foi excluido.\n");

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


