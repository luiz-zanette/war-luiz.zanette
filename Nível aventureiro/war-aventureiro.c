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
#include <time.h>

// Inclusão do arquivo de cabeçalho com definições de estruturas e constantes.
#include "funcoes.h"
#include "estruturas.h"


// Função principal para cadastrar exibir menu, cadastrar territórios e listar territórios
int main() {
    struct Territorio* mapa;
    mapa = calloc(MAX_TERRITORIOS, sizeof(struct Territorio));
    int totalTerritorios = 0;
    int opcao;

    // Loop principal do menu
    do {
        printf("\n=== SISTEMA DE CADASTRO DE TERRITORIOS ===\n"); // exibe o menu
        printf("\n1 - Cadastrar novo territorio\n");
        printf("2 - Listar todos os territorios\n");
        printf("3 - Simular Ataque entre Territorios\n");
        printf("0 - Sair\n");
        printf("--------------------------------------------\n");
        printf("\nEscolha uma opcao: ");
        scanf("%d", &opcao); // Le a opção do usuário
        limparBufferEntrada(); // Limpa o buffer do teclado

        // Processa a opção escolhida
        switch (opcao) {
            case 1: // Cadastrar novo territorio
                cadastrarTerritorio(mapa, &totalTerritorios);
                break;

            case 2: // Listar todos os territorios
                listarTerritorios(mapa, totalTerritorios);
                break;

            case 3: // Simular Ataque entre Territorios
                combate(mapa, totalTerritorios);
                break;

                case 0: // Sair
                    printf("\nLiberando memória e saindo do sistema. Ate mais!\n");
                    free(mapa); // Libera a memória alocada para o mapa
                    break;
        }
    } while (opcao != 0); // Continua até o usuário escolher sair
    return 0;
}