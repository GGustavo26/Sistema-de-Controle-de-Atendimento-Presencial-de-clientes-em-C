#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

struct Cliente {
    char nome[100];
    char cpf[15];
    int tipoAtendimento;
};

void MenuInicial () {
	printf("\t$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n");
    printf("\t$       Bem-Vindo ao Sistema de Atendimento    $\n");
    printf("\t$  1 - Solicitar Atendimento                   $\n");
    printf("\t$  2 - Listar Atendimentos Registrados         $\n");
    printf("\t$  3 - Listar Atendimento por Setor            $\n");
    printf("\t$  4 - Sair                                    $\n");
    printf("\t$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n");
}

void cadastrarCliente(struct Cliente clientes[], int *totalClientes) {
    printf("Nome: ");
    scanf(" %[^\n]", clientes[*totalClientes].nome);
    printf("CPF: ");
    scanf("%s", clientes[*totalClientes].cpf);
    printf("Tipo de Atendimento: \n\t-1- Abertura de Conta\n\t-2- Caixa\n\t-3- Gerente Pessoa Física\n\t-4- Gerente Pessoa Jurídica\n -> ");
    scanf("%d", &clientes[*totalClientes].tipoAtendimento);
    (*totalClientes)++;
    system("cls");
    printf("Cliente cadastrado com sucesso!\n");
    system("pause");
    system("cls");
}

void listarTodosAtendimentos(struct Cliente clientes[], int totalClientes) {
	int i;
    for (i = 0; i < totalClientes; i++) {
        printf("Nome: %s\n", clientes[i].nome);
        printf("CPF: %s\n", clientes[i].cpf);
        printf("Tipo Atendimento - %d\n", clientes[i].tipoAtendimento);
        printf("========================================\n");
    }
}

void listarAtendimentosPorTipo(struct Cliente clientes[], int totalClientes, int tipo) {
	int i;
    for (i = 0; i < totalClientes; i++) {
        if (clientes[i].tipoAtendimento == tipo) {
            printf("Nome: %s\n", clientes[i].nome);
            printf("CPF: %s\n", clientes[i].cpf);
            printf("Tipo Atendimento - %d\n", clientes[i].tipoAtendimento);
            printf("====================================\n");
        }
    }
}

int main() {
    setlocale(LC_ALL, "Portuguese");

    struct Cliente clientes[200];
    int totalClientes = 0;
    int escolha;

    do {
    	MenuInicial();
        printf("\tEscolha uma opção: ");
        scanf("%d", &escolha);
        system("cls");

        switch (escolha) {
            case 1:
                cadastrarCliente(clientes, &totalClientes);
                system("cls");
                break;
            case 2:
                listarTodosAtendimentos(clientes, totalClientes);
                system("pause");
                system("cls");
                break;
            case 3:
                printf("Digite o tipo de atendimento (1-Abertura de Conta, 2-Caixa, 3-Gerente Pessoa Física, 4-Gerente Pessoa Jurídica): ");
                int tipo;
                scanf("%d", &tipo);
                system("cls");
                listarAtendimentosPorTipo(clientes, totalClientes, tipo);
                system("pause");
                system("cls");
                break;
            case 4:
                printf("Saindo do sistema. Obrigado!\n");
				system("pause");
                break;
            default:
            	system("cls");
                printf("Opção inválida. Tente novamente!\n");
                system("pause");
                system("cls");
                
        }

    } while (escolha != 4);

    return 0;
}
