// ============================================================================
//         PROJETO WAR ESTRUTURADO - DESAFIO DE CÓDIGO
// ============================================================================
//        
// OBJETIVOS:
// - Modularizar completamente o código em funções especializadas.
// - Implementar um sistema de missões para um jogador.
// - Criar uma função para verificar se a missão foi cumprida.
// - Utilizar passagem por referência (ponteiros) para modificar dados e
//   passagem por valor/referência constante (const) para apenas ler.
// - Foco em: Design de software, modularização, const correctness, lógica de jogo.
//
// ============================================================================

// Inclusão das bibliotecas padrão necessárias para entrada/saída, alocação de memória, manipulação de strings e tempo.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// - Constantes Globais - Fixa o número de territórios, missões e tamanho máximo de strings, facilitando a manutenção.
#define MAX_STRING 30
#define MAX_COR 10
#define MAX_TERRITORIOS 5

// - Estrutura de Dados - Define a estrutura para um território, contendo seu nome, a cor do exército que o domina e o número de tropas.
struct Territorio {
    char nome[MAX_STRING];
    char cor[MAX_COR];
    int tropas;
};

// Buffer
void limparBufferEntrada() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Função principal para cadastrar exibir menu, cadastrar territórios e listar territórios
int main() {
    struct Territorio mapa[MAX_TERRITORIOS];
    int totalTerritorios = 0;
    int opcao;

    // Loop principal do menu
    do {
        printf("\n=== SISTEMA DE CADASTRO DE TERRITORIOS ===\n"); // exibe o menu
        printf("\n1 - Cadastrar novo territorio\n");
        printf("2 - Listar todos os territorios\n");
        printf("3 - Sair\n");
        printf("--------------------------------------------\n");
        printf("\nEscolha uma opcao: ");
        scanf("%d", &opcao); // Le a opção do usuário
        limparBufferEntrada(); // Limpa o buffer do teclado

        // Processa a opção escolhida
        switch (opcao) {
            case 1: // Cadastrar novo territorio
                printf("\n--- CADASTRO DE NOVO TERRITORIO ---\n");
                if (totalTerritorios < MAX_TERRITORIOS) {

                    printf("Digite o nome do territorio: ");
                    fgets(mapa[totalTerritorios].nome, MAX_STRING, stdin);

                    printf("Digite a cor do exercito: ");
                    fgets(mapa[totalTerritorios].cor, MAX_COR, stdin);

                    printf("Digite o numero de tropas no local: ");
                    scanf("%d", &mapa[totalTerritorios].tropas);

                    mapa[totalTerritorios].nome[strcspn(mapa[totalTerritorios].nome, "\n")] = 0;
                    mapa[totalTerritorios].cor[strcspn(mapa[totalTerritorios].cor, "\n")] = 0;
                    
                    totalTerritorios++;
                    printf("\nTerritorio cadastrado com sucesso!\n");

                } else {
                    printf("\nLimite de territorios atingido!\n");
                }
                break;

            case 2: // Listar todos os territorios
                printf("\n--- LISTA DE TERRITORIOS CADASTRADOS ---\n");

                if (totalTerritorios == 0) {
                    printf("Nenhum territorio cadastrado.\n");

                } else {
                    for (int i = 0; i < totalTerritorios; i++) {
                        printf("\nTerritório cadastro: %d:\n", i + 1);
                        printf("Nome: %s\n", mapa[i].nome);
                        printf("Cor do exército: %s\n", mapa[i].cor);
                        printf("Número de tropas: %d\n", mapa[i].tropas);
                    }
                }

                printf("Pressione Enter para continuar...");
                getchar(); // Espera o usuário intergari para seguir adiante
                break;

                case 3: // Sair
                    printf("\nSaindo do sistema. Ate mais!\n");
                    break;
                    }
        }
        
        while (opcao != 3); // Continua até o usuário escolher sair
    return 0;
}