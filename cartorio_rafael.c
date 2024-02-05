#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

int registro() {
    char arquivo[40];
    char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];

    printf("Digite o CPF: ");
    scanf("%s", cpf);

    strcpy(arquivo, cpf);
    FILE *file;
    file = fopen(arquivo, "a");

    if (file == NULL) {
        fprintf(stderr, "N�o foi poss�vel abrir o arquivo para escrita!\n");
        return 1;
    }

    fprintf(file, cpf);
    fprintf(file, ",");

    printf("Digite o nome: ");
    scanf("%s", nome);
    fprintf(file, nome);
    fprintf(file, ",");

    printf("Digite o sobrenome: ");
    scanf("%s", sobrenome);
    fprintf(file, sobrenome);
    fprintf(file, ",");

    printf("Digite o cargo: ");
    scanf("%s", cargo);
    fprintf(file, cargo);
    fprintf(file, ",");

    fclose(file);

    printf("Registro conclu�do com sucesso!\n");
    system("pause");

    return 0;
}

int consulta() {
    setlocale(LC_ALL, "portuguese");

    char cpf[40];
    char conteudo[200];

    printf("Digite o CPF a ser consultado: ");
    scanf("%s", cpf);

    FILE *file;
    file = fopen(cpf, "r");

    if (file == NULL) {
        fprintf(stderr, "N�o foi poss�vel abrir o arquivo, n�o localizado!\n");
        system("pause");
        return 1;
    } else {
        while (fgets(conteudo, 200, file) != NULL) {
            printf("\nEssas s�o as informa��es do usu�rio: ");
            printf("%s", conteudo);
            printf("\n\n");
        }
        fclose(file);
    }

    system("pause");
    return 0;
}

int deletar() {
    char cpf[40];

    printf("Digite o CPF a ser deletado: ");
    scanf("%s", cpf);

    if (remove(cpf) == 0) {
        printf("Usu�rio deletado com sucesso!\n");
    } else {
        printf("Usu�rio n�o encontrado!\n");
    }

    system("pause");
    return 0;
}

int main() {
    int opcao = 0;
    int laco = 1;
    char digitarsenha[10] = "a";
    int comparacao;

    printf("### Cart�rio da EBAC ###\n\n");
    printf("Login de administrador!\n\nDigite sua senha: ");
    scanf("%s", digitarsenha);

    comparacao = strcmp(digitarsenha, "admin");

    if (comparacao == 0) {
        do {
            system("cls");
            setlocale(LC_ALL, "portuguese");

            printf("### Cart�rio da EBAC ###\n\n");
            printf("Escolha uma op��o:\n\n");
            printf("\t1 - Registrar nomes\n\n");
            printf("\t2 - Consultar nomes\n\n");
            printf("\t3 - Deletar nomes\n\n");
            printf("\t4 - Sair do sistema\n\n");
            printf("Op��o: ");
            scanf("%d", &opcao);

            system("cls");

            switch (opcao) {
                case 1:
                    registro();
                    break;

                case 2:
                    consulta();
                    break;

                case 3:
                    deletar();
                    break;

                case 4:
                    printf("Obrigado por utilizar o sistema.\n");
                    return 0;

                default:
                    printf("Essa op��o n�o existe!\n");
                    system("pause");
                    break;
            }
        } while (laco == 1);
    } else {
        printf("Senha incorreta!\n");
    }

    return 0;
}




