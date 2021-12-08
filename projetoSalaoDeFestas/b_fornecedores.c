#include "b_menus.h"
#include "b_fornecedores.h"
#include "b_funcionarios.h"

struct Tfornecedor
{
    char nome[50],prodOferecido[50];
    int cod, tel;
};
typedef struct Tfornecedor fornecedor;

void inclui_fornecedor(FILE *f)
{
    fornecedor  fnd;
    int posicao;
    //lendo os dados do teclado
    printf("Digite o numero do codigo...:");
    fflush(stdin);
    scanf("%d",&fnd.cod);
    posicao=localiza_fornecedor(f,fnd.cod);
    if (posicao==-1) //não tinha codigo no arquivo
    {

        printf("Digite o nome do fornecedor...:");
        fflush(stdin);
        gets(fnd.nome);
        printf("Digite o telefone do fornecedor...:");
        fflush(stdin);
        scanf("%d",&fnd.tel);
        printf("Digite o produto do fornecedor...:");
        fflush(stdin);
        gets(fnd.prodOferecido);
        fseek(f,0,SEEK_END); // posicionado o arquivo no final
        fwrite(&fnd, sizeof(fnd),1,f); //gravando os dados
        fflush(f);
    }
    else
    {
        printf("Código %d já existe no arquivo. Inclusão não realizada!\n",fnd.cod);
    }
}


void imprime_fornecedor(FILE *f)
{
    fornecedor fnd;
    fseek(f,0,SEEK_SET);
    fread(&fnd, sizeof(fnd),1, f);
    while (!feof(f))
    {
        if(fnd.cod!=0)
        {
            printf("Código....................:%d \n",fnd.cod);
            printf("Nome......................:%s \n",fnd.nome);
            printf("Telefone..................:%d\n",fnd.tel);
            printf("Produto oferecido.........:%s\n",fnd.prodOferecido);

        }

        fread(&fnd, sizeof(fnd),1, f);
    }
}


void altera_fornecedor(FILE *f)
{
    int cod,posicao;
    fornecedor fnd;
    printf("Diga qual o numero do codigo para alterar:");
    scanf("%d",&cod);
    posicao=localiza_fornecedor(f,cod);
    if (posicao!=-1) // localizou a mercadoria
    {
        fseek(f,sizeof(fnd)*(posicao),SEEK_SET); //encontra posição escolhida
        fread(&fnd, sizeof(fnd),1, f);
        printf("Codigo atual:%d Nome: %s telefone: %d produto oferecido: %s\n",fnd.cod,fnd.nome,fnd.tel,fnd.prodOferecido);
        printf("Novo nome...:");
        fflush(stdin);
        gets(fnd.nome);
        printf("Novo telefone...:");
        fflush(stdin);
        scanf("%d",&fnd.tel);
        printf("Digite o produto do fornecedor...:");
        fflush(stdin);
        gets(fnd.prodOferecido);
        fseek(f,sizeof(fnd)*(posicao),SEEK_SET);
        fwrite(&fnd, sizeof(fnd),1, f); //escreve a alteração
        fflush(f);
    }
}


void exclui_fornecedor(FILE *f)
{
    int cod,posicao;
    int escolha;
    fornecedor fnd;
    printf("Diga qual o codigo do fornecedor você deseja excluir:");
    scanf("%d",&cod);
    printf("Realmente deseja excluir? Digite 1 para confirmar ou outra tecla para desfazer a operação\n");
    scanf("%d",&escolha);

    if(escolha==1)
    {
        posicao=localiza_fornecedor(f,cod);
        if (posicao!=-1) // localizou a mercadoria
        {
            fseek(f,sizeof(fnd)*(posicao),SEEK_SET); //encontra posição escolhida
            fread(&fnd, sizeof(fnd),1, f);


            // a.nome[50]='excluida';
            fnd.cod=0;
            fnd.tel=0;
            //fnd.tipo=0;

            fseek(f,sizeof(fnd)*(posicao),SEEK_SET);
            fwrite(&fnd, sizeof(fnd),1, f); //escreve a alteração
            printf("fornecedor excluido\n");
            fflush(f);
        }

    }
    else
    {
        printf("O fornecedor foi excluido.\n");

    }
}

int localiza_fornecedor(FILE *f,int cod)
{
    int posicao=-1,achou=0;
    fornecedor fnd;
    fseek(f,0,SEEK_SET);
    fread(&fnd, sizeof(fnd),1, f);
    while (!feof(f) && !achou)
    {
        posicao++; // semelhante a posicao = posicao +1;
        if (fnd.cod==cod)
        {
            achou=1;
        }
        fread(&fnd, sizeof(fnd),1, f);
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

