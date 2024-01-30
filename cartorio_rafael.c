#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

int registro()
{
    char arquivo[40];
    char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];

    printf("digite o cpf:");
    scanf("%s", cpf);

    strcpy(arquivo, cpf);
    FILE *file;
    file = fopen(arquivo, "w");
    fprintf(file, cpf);
    fclose(file);

    file = fopen(arquivo, "a");
    fprintf(file, ",");
    fclose(file);

    printf("digite o nome:");
    scanf("%s", nome);

    file = fopen(arquivo, "a");
    fprintf(file, nome);
    fclose(file);

    file = fopen(arquivo, "a");
    fprintf(file, ",");
    fclose(file);

    printf("digite o sobrenome:");
    scanf("%s", sobrenome);

    file = fopen(arquivo, "a");
    fprintf(file, sobrenome);
    fclose(file);

    file = fopen(arquivo, "a");
    fprintf(file, ",");
    fclose(file);

    printf("digite o cargo:");
    scanf("%s", cargo);

    file = fopen(arquivo, "a");
    fprintf(file, cargo);
    fclose(file);

    file = fopen(arquivo, "a");
    fprintf(file, ",");
    fclose(file);

    system("pause");
}

int consulta()
{
    setlocale(LC_ALL, "portuguese");

    char cpf[40];
    char conteudo[200];

    printf("digite o cpf a ser consultado:");
    scanf("%s", cpf);

    FILE *file;
    file = fopen(cpf, "r");

    if (file == NULL)
    {
        fprintf(stderr, "Não foi possível abrir o arquivo, não localizado!\n");
    }
    else
    {
        while (fgets(conteudo, 200, file) != NULL)
        {
            printf("\nEssas são as informações do usuário: ");
            printf("%s", conteudo);
            printf("\n\n");
        }
        fclose(file);
    }

    system("pause");
}

 int deletar()
{
    char cpf[40];

    printf("digite o cpf a ser deletado:");
    scanf("%s", cpf);

    if (remove(cpf) == 0)
    {
        printf("Usuário deletado com sucesso!\n");
    }
    else
    {
        printf("Usuário não encontrado!\n");
    }

    system("pause");
    return 0;
}

    


int main()
{

    int opcao = 0;
    int laco = 1;

    for (laco = 1; laco == 1;)
    {

        system("cls");
        setlocale(LC_ALL, "portuguese");

        printf("### cartório da ebac ###\n\n");
        printf("Escolha uma opção:\n\n");
        printf("\t1 - Registrar nomes\n\n");
        printf("\t2 - Consultar nomes\n\n");
        printf("\t3 - Deletar nomes\n\n");
        printf("Opção:");

        scanf("%d", &opcao);
        system("cls");

        switch (opcao)
        {
        case 1:
            registro();
            break;

        case 2:
            consulta();
            break;

        case 3:
            deletar();
            break;

        default:
            printf("Essa opção não existe!\n");
            system("pause");
            break;
        }
    }
}



