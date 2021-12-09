#include "b_menus.h"
#include "b_clientes.h"
#include "b_festas.h"

struct TFesta
{
    int excluido, convidados, horarioini, horariofim;
    char data[50], diadasemana[50], tema[9];
    int codfesta, codcliente;
};
typedef struct TFesta Festa;


void inclui_festa(FILE *f)
{
    Festa fes;
    int posicao;
//lendo os dados do teclado
    printf("Digite o código da festa...: ");
    scanf("%d",&fes.codfesta);
    posicao = localiza_codigo_festa(f, fes.codfesta);

    if(posicao == -1) //não tinha código no arquivo
    {
        printf("Digite o códido do cliente...: ");
        scanf("%d",&fes.codcliente);

        if (!busca_cliente(fes.codcliente))
        {
            printf("Cliente não cadastrado. Digite outro código ou cadastre o cliente.");
            exit(1);
        }
        else
        {
            printf("Digite a quantidade de convidados...: ");
            scanf("%d",&fes.convidados);
            printf("Digite a data do evento...: ");
            fflush(stdin);
            gets(fes.data);
            printf("Digite o dia da semana do evento...: ");
            fflush(stdin);
            gets(fes.diadasemana);
            printf("Digite o horário de inicio...: ");
            scanf("%d",&fes.horarioini);
            printf("Digite o horário de encerramento...: ");
            scanf("%d",&fes.horariofim);
            printf("Digite o tema da festa...: ");
            fflush(stdin);
            gets(fes.tema);
            fes.excluido = 0;

            fseek(f,0,SEEK_END); // posicionado o arquivo no final
            fwrite(&fes, sizeof(fes),1,f); //gravando os dados
            fflush(f);
            printf("\nRegistro salvo com sucesso!\n\n ");

        }
    }
    else
    {
        printf("\nCódigo %d já existe no arquivo. Inclusão não realizada!\n\n", fes.codfesta);
    }
}

int localiza_codigo_festa(FILE *f, int codigo)
{
    int posicao = -1, achou = 0;

    Festa fe;
    fseek(f,0,SEEK_SET); // do inicio
    fread(&fe, sizeof(fe),1, f); // lendo o arquivo

    while(!feof(f) && !achou)
    {
        posicao++;
        if(fe.codfesta == codigo && fe.excluido != 1)
        {
            achou = 1;
        }
        fread(&fe, sizeof(fe),1, f); // ver com o prof.
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


bool busca_cliente(int codigo)
{
    FILE *fcli;
    if ((fcli = fopen("controleClientes.dat", "r+b"))==NULL) // arquivo existe
    {
        printf("Arquivo não existia ... criando arquivo!\n");
        if((fcli = fopen("controleClientes.dat", "w+b"))==NULL) //arq não existe
        {
            printf("Erro na criação do arquivo!!");
            exit(1);
        }
    }

    if (localiza_cliente(fcli, codigo) != -1)
    {
        return true;
    }
    else
    {
        return false;
    }
    fclose(fcli);
}


