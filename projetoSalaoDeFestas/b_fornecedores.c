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

/*
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
*/
void imprime_fornecedor(FILE *f)
{
    int posicao=-1,achou=0;
    int cod;
    fornecedor fnd;

    printf("Digite o numero do codigo...:");
    fflush(stdin);
    scanf("%d",&cod);


    fseek(f,0,SEEK_SET);
    fread(&fnd, sizeof(fnd),1, f);
    while (!feof(f) && !achou)
    {
        posicao++; // semelhante a posicao = posicao +1;
        if (fnd.cod==cod)
        {
            achou=1;
            printf("Código....................:%d \n",fnd.cod);
            printf("Nome......................:%s \n",fnd.nome);
            printf("Telefone..................:%d\n",fnd.tel);
            printf("Produto oferecido.........:%s\n",fnd.prodOferecido);

        }
        fread(&fnd, sizeof(fnd),1, f);
    }
    if (achou)
    {
        printf("Fornecedor encontrado. Deseja buscar por mais algum? \n");
    }
    else
    {
        printf("Fornecedor não encontrado, tente outro código\n");
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

