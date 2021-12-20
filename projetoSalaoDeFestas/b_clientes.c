#include "b_menus.h"
#include "b_clientes.h"

struct TCliente
{
    int excluido, telefone;
    char nome[50], endereco[50], dtnascimento[9];
    float codigo;
};
typedef struct TCliente Cliente;

void CriaArquivoCliente(FILE *fcli)
{
    setlocale(LC_ALL,"portuguese");

    if((fcli = fopen("Clientes.dat", "r+b"))==NULL) // arquivo existe
    {
        printf("Arquivo não existia ... criando arquivo!\n ");

        if((fcli = fopen("Clientes.dat", "w+b"))==NULL) //arqnão existe
        {
            printf("Erro na criação do arquivo!!");
            exit(1);
        }
        printf("Arquivo criado com sucesso!\n ");
        system("pause");
    }
}

void IncluiCliente()
{
    FILE *fcli;
    fcli = NULL;
    CriaArquivoCliente(fcli);
    fcli = fopen("Clientes.dat", "r+b"); // abrindo arquivo
    Cliente cli;
    int posicao;
//lendo os dados do teclado
    printf("Digite o código do cliente...: ");
    fflush(stdin);
    scanf("%f",&cli.codigo);
    posicao = localiza_codigo(fcli, cli.codigo);

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
        printf("Digite a data de nascimento no formato XX/XX/XX...: ");
        fflush(stdin);
        gets(cli.dtnascimento);

        fseek(fcli,0,SEEK_END); // posicionado o arquivo no final
        fwrite(&cli, sizeof(cli),1,fcli); //gravando os dados
        fflush(fcli);
        printf("\nRegistro salvo com sucesso!\n\n ");
    }
    else
    {
        printf("\nCódigo %0.f já existe no arquivo. Inclusão não realizada!\n\n", cli.codigo);
    }
}

int localiza_codigo(FILE *f, float codigo)
{
    int posicao = -1, achou = 0;

    Cliente cli;
    fseek(f,0,SEEK_SET); // do inicio
    fread(&cli, sizeof(cli),1, f); // lendo o arquivo

    while(!feof(f) && !achou)
    {
        posicao++;
        if(cli.codigo == codigo)
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
void localiza_cliente()
{
    FILE *f;

    f = fopen("Clientes.dat", "r+b");

    int posicao = -1, achou = 0;
    float codigo;

    printf("Digite o código do cliente...: ");
    fflush(stdin);
    scanf("%f",&codigo);
    fflush(stdin);

    Cliente cli;
    fseek(f,0,SEEK_SET); // do inicio
    fread(&cli, sizeof(cli),1, f); // lendo o arquivo

    while(!feof(f) && !achou)
    {
        posicao++;
        if(cli.codigo == codigo)
        {
            achou = 1;
            printf("Código....................:%f\n",cli.codigo);
            printf("Nome......................:%s \n",cli.nome);
            printf("Telefone..................:%d\n",cli.telefone);
            printf("Endreço...................:%s\n",cli.endereco);
            printf("Data de Nascimento........:%s\n",cli.dtnascimento);
        }
        fread(&cli, sizeof(cli),1, f); // ver com o prof.
    }
    if(achou)
    {
        printf("Cliente encontrado. Deseja buscar por mais algum? \n");
    }
    else
    {
        printf("Cliente não encontrado, tente outro código\n");
    }
    fclose(f);

}


