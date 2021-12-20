#include "b_menus.h"
#include "b_clientes.h"
#include "b_festas.h"


struct TFesta
{
    int excluido, convidados, horarioini, horariofim, formapag;
    char data[50], diadasemana[50], tema[9], DataHorario[50], status[10];
    float codfesta, codcliente, valorbruto, valorliquido, desconto;
};
typedef struct TFesta Festa;


void CriaArquivoFesta(FILE *ffes)
{
    setlocale(LC_ALL,"portuguese");

    if((ffes = fopen("Festas.dat", "r+b"))==NULL) // arquivo existe
    {
        printf("Arquivo não existia ... criando arquivo!\n ");

        if((ffes = fopen("Festas.dat", "w+b"))==NULL) //arqnão existe
        {
            printf("Erro na criação do arquivo!!");
            exit(1);
        }
        printf("Arquivo criado com sucesso!\n ");
        system("pause");
    }
}

void IncluiFesta()
{
    FILE *ffes;
    ffes = NULL;
    CriaArquivoFesta(ffes);
    ffes = fopen("Festas.dat", "r+b"); // abrindo arquivo
    Festa fes;
    int posicao, xDataEmUso, xHorarioDisponivel, op, opDia;


    printf("Digite o código da festa...: ");
    fflush(stdin);
    scanf("%f",&fes.codfesta);
    fflush(stdin);
    posicao = localiza_codigo_festa(ffes, fes.codfesta);

    if(posicao == -1) //não tinha código no arquivo
    {
        printf("Digite o códido do cliente...: ");
        scanf("%f",&fes.codcliente);

        if (!BuscaCliente(fes.codcliente))
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
            printf("Digite o dia da semana do evento...: \n");
            fflush(stdin);
            printf("1 - Segunda\n");
            printf("2 - Terça\n");
            printf("3 - Quarta\n");
            printf("4 - Quinta\n");
            printf("5 - Sexta\n");
            printf("6 - Sábado\n");
            printf("7 - Domingo\n");
            scanf("%d", &opDia);
            switch (opDia)
            {
            case 1:
                strcpy(fes.diadasemana,"Segunda");
                break;

            case 2:
                strcpy(fes.diadasemana, "Terça");
                break;

            case 3:
                strcpy(fes.diadasemana, "Quarta");
                break;

            case 4:
                strcpy(fes.diadasemana, "Quinta");
                break;

            case 5:
                strcpy(fes.diadasemana, "Sexta");
                break;

            case 6:
                strcpy(fes.diadasemana, "Sábado");
                break;

            case 7:
                strcpy(fes.diadasemana, "Domingo");
                break;
            }

            if (strcmp(fes.diadasemana, "Sábado") == 0)
            {
                printf("Para os sábados existem 2 horários disponíveis. Escolha: \n");
                printf("1 - 12h às 16h.\n");
                printf("2 - 18h às 22h.\n");
                scanf("%d",&op);
                switch (op)
                {
                case 1:
                    fes.horarioini = 12;
                    fes.horariofim = 16;
                    break;

                case 2:
                    fes.horarioini = 18;
                    fes.horariofim = 22;
                    break;
                }
            }
            else
            {
                printf("Digite o horário de inicio (No formato 24 horas Ex: 8,12,15,23)...: ");
                scanf("%d",&fes.horarioini);
                printf("Digite o horário de encerramento (No formato 24 horas Ex: 8,12,15,23)...: ");
                scanf("%d",&fes.horariofim);
            }
            while (fes.horariofim - fes.horarioini > 4)
            {
                printf("\n-->Duração da festa deve ser até 4 horas!\n\n");
                printf("Digite o horário de inicio...: ");
                scanf("%d",&fes.horarioini);
                printf("Digite o horário de encerramento...: ");
                scanf("%d",&fes.horariofim);
            }
            xDataEmUso = VerificaDataDisponivel(ffes, fes.data);
            xHorarioDisponivel = VerificaHorario(ffes, fes.horarioini, fes.horariofim);
            while (xDataEmUso != -1 && xHorarioDisponivel != -1)
            {
                printf("\n-->Já existe uma festa agendada para esta data e horário. Escolha uma nova...\n\n");
                printf("Digite a data do evento...: ");
                fflush(stdin);
                gets(fes.data);
                printf("Digite o dia da semana do evento...: \n");
                fflush(stdin);
                printf("1 - Segunda\n");
                printf("2 - Terça\n");
                printf("3 - Quarta\n");
                printf("4 - Quinta\n");
                printf("5 - Sexta\n");
                printf("6 - Sábado\n");
                printf("7 - Domingo\n");
                scanf("%d", &opDia);
                switch (opDia)
                {
                case 1:
                    strcpy(fes.diadasemana,"Segunda");
                    break;

                case 2:
                    strcpy(fes.diadasemana, "Terça");
                    break;

                case 3:
                    strcpy(fes.diadasemana, "Quarta");
                    break;

                case 4:
                    strcpy(fes.diadasemana, "Quinta");
                    break;

                case 5:
                    strcpy(fes.diadasemana, "Sexta");
                    break;

                case 6:
                    strcpy(fes.diadasemana, "Sábado");
                    break;

                case 7:
                    strcpy(fes.diadasemana, "Domingo");
                    break;
                }
                gets(fes.diadasemana);
                if (strcmp(fes.diadasemana, "Sábado") == 0)
                {
                    printf("Para os sábados existem 2 horários disponíveis. Escolha: \n");
                    printf("1 - 12h às 16h.\n");
                    printf("2 - 18h às 22h.\n");
                    scanf("%d",&op);
                    switch (op)
                    {
                    case 1:
                        fes.horarioini = 12;
                        fes.horariofim = 16;
                        break;

                    case 2:
                        fes.horarioini = 18;
                        fes.horariofim = 22;
                        break;
                    }
                }
                else
                {
                    printf("Digite o horário de inicio...: ");
                    scanf("%d",&fes.horarioini);
                    printf("Digite o horário de encerramento...: ");
                    scanf("%d",&fes.horariofim);
                }
                while (fes.horariofim - fes.horarioini > 4)
                {
                    printf("\n-->Duração da festa deve ser até 4 horas!\n\n");
                    printf("Digite o horário de inicio...: ");
                    scanf("%d",&fes.horarioini);
                    printf("Digite o horário de encerramento...: ");
                    scanf("%d",&fes.horariofim);
                }
                xDataEmUso = VerificaDataDisponivel(ffes, fes.data);
                xHorarioDisponivel = VerificaHorario(ffes, fes.horarioini, fes.horariofim);
            }
            printf("Digite o tema da festa...: ");
            fflush(stdin);
            gets(fes.tema);
            fes.excluido = 0;
            fes.valorbruto = CalculaTotalFesta(fes.convidados, opDia);
            printf("O valor a ser pago com as especificações descritas será: R$%f\n",fes.valorbruto);
            strcpy(fes.status,"a pagar");
            printf("O status do contrato está padronizado para: %s\n",fes.status);

            printf("Escolha a forma de pagamento: \n");
            printf("1 - A vista \n");
            printf("2 - Parcelado em 2 vezes \n");
            printf("3 - Parcelado em 3 vezes \n");
            printf("4 - Parcelado em 4 ou mais vezes \n");
            scanf("%d", &fes.formapag);

            fes.desconto = CalculaDesconto(fes.formapag, fes.valorbruto);
            fes.valorliquido = fes.valorbruto - fes.desconto;

            if (fes.desconto > 0)
            {
                printf("Será aplicado um desconto de %f sobre o valor bruto. Total a pagar: %f\n", fes.desconto, fes.valorliquido);
            }

            fseek(ffes,0,SEEK_END); // posicionado o arquivo no final
            fwrite(&fes, sizeof(fes),1,ffes); //gravando os dados
            fflush(ffes);
            printf("\nRegistro salvo com sucesso!\n\n ");

        }
    }
    else
    {
        printf("\nCódigo %0.f já existe no arquivo. Inclusão não realizada!\n\n", fes.codfesta);
    }
}

int localiza_codigo_festa(FILE *f, float codigo)
{
    int posicao = -1, achou = 0;

    Festa fe;
    fseek(f,0,SEEK_SET); // do inicio
    fread(&fe, sizeof(fe),1, f); // lendo o arquivo

    while(!feof(f) && !achou)
    {
        posicao++;
        if(fe.codfesta == codigo)
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

int VerificaDataDisponivel(FILE *f, char data[50])
{
    int posicao = -1, achou = 0;

    Festa fe;
    fseek(f,0,SEEK_SET); // do inicio
    fread(&fe, sizeof(fe),1, f); // lendo o arquivo

    while(!feof(f) && !achou)
    {
        posicao++;
        if(strcmp (fe.data, data) == 0)
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

int VerificaHorario(FILE *f, int horaini, int horafim)
{
    int posicao = -1, achou = 0;

    Festa fe;
    fseek(f,0,SEEK_SET); // do inicio
    fread(&fe, sizeof(fe),1, f); // lendo o arquivo

    while(!feof(f) && !achou)
    {
        posicao++;
        if(horaini >= fe.horarioini && horafim <= fe.horariofim)
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

bool BuscaCliente(float codigo)
{
    FILE *fcli;
    fcli = NULL;
    CriaArquivoCliente(fcli);
    fcli = fopen("Clientes.dat", "r+b"); // abrindo arquivo

    if (localiza_codigo(fcli, codigo) != -1)
    {
        return true;
    }
    else
    {
        return false;
    }
}


float CalculaTotalFesta(int convidados, int diadasemana )
{
    Festa f;


    if (convidados <= 30 && (diadasemana >= 1 && diadasemana <= 4))
    {
        return 1899.0;
        printf("Valor a pagar: R$%f", f.valorbruto);
    }
    else if (convidados <= 30 && (diadasemana >= 5 && diadasemana <= 7))
    {
        return 2099.0;
        printf("Valor a pagar: R$%f", f.valorbruto);

    }
    else if (convidados <= 50 && (diadasemana >= 1 && diadasemana <= 4))
    {
        return 2199.0;
        printf("Valor a pagar: R$%f", f.valorbruto);

    }
    else if (convidados <= 50 && (diadasemana >= 5 && diadasemana <= 7))
    {
        return 2299.0;
        printf("Valor a pagar: R$%f", f.valorbruto);
    }
    else if (convidados <= 80 && (diadasemana >= 1 && diadasemana <= 4))
    {
        return 3199.0;
        printf("Valor a pagar: R$%f", f.valorbruto);

    }
    else if (convidados <= 80 && (diadasemana >= 5 && diadasemana <= 7))
    {
        return 3499.0;
        printf("Valor a pagar: R$%f", f.valorbruto);

    }
    else if (convidados <= 100 && (diadasemana >= 1 && diadasemana <= 4))
    {
        return 3799.0;
        printf("Valor a pagar: R$%f", f.valorbruto);

    }
    else if (convidados <= 100 && (diadasemana >= 5 && diadasemana <= 7))
    {
        return 3999.0;
        printf("Valor a pagar: R$%f", f.valorbruto);
    }
}

float CalculaDesconto(int formapag, float valorbruto)
{
    float xliquido;

    switch (formapag)
    {
    case 1:
        xliquido = (10 * valorbruto)/100;
        return xliquido;
        break;
    case 2:
        xliquido = (5 * valorbruto)/100;
        return xliquido;
        break;
    case 3:
        xliquido = (2 * valorbruto)/100;
        return xliquido;
        break;
    case 4:
        return 0;
        break;
    }
}

void localiza_festas_cliente()
{
    FILE *f;

    f = fopen("Festas.dat", "r+b");

    int posicao = -1;
    float codigo;

    printf("Digite o código do cliente...: ");
    fflush(stdin);
    scanf("%f",&codigo);
    fflush(stdin);

    Festa fes;
    fseek(f,0,SEEK_SET); // do inicio
    fread(&fes, sizeof(fes),1, f); // lendo o arquivo

    while(!feof(f))
    {
        posicao++;
        if(fes.codcliente == codigo)
        {
            //achou = 1;
            printf("Código do cliente....................:%f\n",fes.codcliente);
            printf("Código da festa......................:%f \n",fes.codfesta);
            printf("Data.................................:%s\n",fes.data);
            printf("Horário de inicio....................:%d\n",fes.horarioini);
            printf("Horário de termino...................:%d\n",fes.horariofim);
            printf("Horário de termino...................:%s\n",fes.tema);
            printf("Quantidade de pessoas................:%d\n",fes.convidados);
            printf("Valor a pagar........................:%f\n",fes.valorliquido);
            printf("Status do pagamento..................:%s\n",fes.status);
        }
        fread(&fes, sizeof(fes),1, f); // ver com o prof.
    }

}

//Função para verificar o código de uma determinada festa
int verifica_codigo_festa(FILE *f)
{


    f = fopen("Festas.dat", "r+b");

    int posicao = -1, achou = 0;
    float codigo;

    printf("Digite o código da festa...: ");
    fflush(stdin);
    scanf("%f",&codigo);
    fflush(stdin);

    Festa fes;
    fseek(f,0,SEEK_SET); // do inicio
    fread(&fes, sizeof(fes),1, f); // lendo o arquivo

    while(!feof(f))
    {
        posicao++;
        if(fes.codfesta == codigo)
        {
            achou = 1;
        }
        fread(&fes, sizeof(fes),1, f); // ver com o prof.
    }
    if (achou)
    {
        return posicao;
    }
    else
    {

        return 0;
    }
}

void altera_status_contrato()
{
    FILE *f;
    int posicao;
    Festa fes;
    f = fopen("Festas.dat", "r+b");
    posicao=verifica_codigo_festa(f);
    if (posicao!=-1) // localizou a mercadoria
    {
        fseek(f,sizeof(fes)*(posicao),SEEK_SET); //encontra posição escolhida
        fread(&fes, sizeof(fes),1, f);
        printf("\n\nFoi encontrado a festa de código:%f Data: %s horario de inicio: %d H horario do fim: %d e status %s, deseja alterar os status?\n\n",fes.codfesta,fes.data, fes.horarioini, fes.horariofim, fes.status);
        printf("Novo status da festa...:");
        fflush(stdin);
        gets(fes.status);
        fseek(f,sizeof(fes)*(posicao),SEEK_SET);
        fwrite(&fes, sizeof(fes),1, f); //escreve a alteração
        fflush(f);
    }
    printf("\n\nAlteração feita com sucesso \n\n");
}

void localiza_festas_data()
{
    FILE *f;

    f = fopen("Festas.dat", "r+b");

    int posicao = -1;
    char dataInput[50];
    Festa fes;

    printf("Digite a data que deseja buscar no formato XX/XX/XX...: ");
    fflush(stdin);
    gets(dataInput);
    fflush(stdin);




    fseek(f,0,SEEK_SET); // do inicio
    fread(&fes, sizeof(fes),1, f); // lendo o arquivo

    while(!feof(f))
    {
        posicao++;
        if(strcmp(dataInput,fes.data)==0)
        {
            printf("Código do cliente....................:%f\n",fes.codcliente);
            printf("Código da festa......................:%f \n",fes.codfesta);
            printf("Data.................................:%s\n",fes.data);
            printf("Horário de inicio....................:%d\n",fes.horarioini);
            printf("Horário de termino...................:%d\n",fes.horariofim);
            printf("Horário de termino...................:%s\n",fes.tema);
            printf("Quantidade de pessoas................:%d\n",fes.convidados);
            printf("Valor a pagar........................:%f\n",fes.valorliquido);
            printf("Status do pagamento..................:%s\n",fes.status);
        }
        printf("\n");
        fread(&fes, sizeof(fes),1, f);
    }
}
