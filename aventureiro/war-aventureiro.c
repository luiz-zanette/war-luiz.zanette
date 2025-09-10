// ============================================================================
//         PROJETO WAR ESTRUTURADO - DESAFIO DE CÓDIGO
// ============================================================================
//        
// OBJETIVOS:
// - Implementar um sistema de missões para um jogador.
// - Criar uma função para verificar se a missão foi cumprida.
// - Foco em: Lógica de jogo.
//
// ============================================================================


// Inclusão das bibliotecas padrão necessárias
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Constantes e Structs
#define MAX_STRING 30
#define MAX_COR 10
#define MAX_TERRITORIOS 5

struct Territorio {
    char nome[MAX_STRING];
    char cor[MAX_COR];
    int tropas;
};

// Funcao para limpar o buffer de entrada do teclado
void limparBufferEntrada() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}


// Funcao principal
int main() {
    struct Territorio* mapa;
    mapa = calloc(MAX_TERRITORIOS, sizeof(struct Territorio));
    int totalTerritorios = 0;
    int opcao;
    
    // Verificacao de alocacao de memoria
    if (mapa == NULL) {
        printf("Erro: Falha ao alocar memoria para o mapa.\n");
        return 1;
    }

    // Loop principal do menu
    do {
        printf("\n=== SISTEMA DE CADASTRO DE TERRITORIOS ===\n");
        printf("\n1 - Cadastrar novo territorio\n");
        printf("2 - Listar todos os territorios\n");
        printf("3 - Simular Ataque entre Territorios\n");
        printf("0 - Sair\n");
        printf("--------------------------------------------\n");
        printf("\nEscolha uma opcao: ");
        scanf("%d", &opcao);
        limparBufferEntrada();

        // Processa a opcao escolhida
        switch (opcao) {
            case 1: { // Cadastrar novo territorio
                printf("\n--- CADASTRO DE NOVO TERRITORIO ---\n");
                if (totalTerritorios < MAX_TERRITORIOS) {
                    printf("Digite o nome do territorio: ");
                    fgets(mapa[totalTerritorios].nome, MAX_STRING, stdin);

                    printf("Digite a cor do exercito: ");
                    fgets(mapa[totalTerritorios].cor, MAX_COR, stdin);

                    printf("Digite o numero de tropas no local: ");
                    scanf("%d", &mapa[totalTerritorios].tropas);
                    limparBufferEntrada();
                    
                    mapa[totalTerritorios].nome[strcspn(mapa[totalTerritorios].nome, "\n")] = 0;
                    mapa[totalTerritorios].cor[strcspn(mapa[totalTerritorios].cor, "\n")] = 0;
                    
                    totalTerritorios++;
                    printf("\nTerritorio cadastrado com sucesso!\n");
                } else {
                    printf("\nLimite de territorios atingido!\n");
                }
                break;
            }

            case 2: { // Listar todos os territorios
                printf("\n--- LISTA DE TERRITORIOS CADASTRADOS ---\n");
                if (totalTerritorios == 0) {
                    printf("Nenhum territorio cadastrado.\n");
                } else {
                    for (int i = 0; i < totalTerritorios; i++) {
                        printf("\nTerritorio cadastro: %d:\n", i + 1);
                        printf("Nome: %s\n", mapa[i].nome);
                        printf("Cor do exercito: %s\n", mapa[i].cor);
                        printf("Numero de tropas: %d\n", mapa[i].tropas);
                    }
                }
                printf("Pressione Enter para continuar...");
                getchar();
                break;
            }

            case 3: { // Simular Ataque entre Territorios
                printf("\n--- SIMULACAO DE COMBATE ENTRE TERRITORIOS ---\n");
                if (totalTerritorios < 2) {
                    printf("E necessario ter pelo menos dois territorios cadastrados para simular um combate.\n");
                    break;
                }
                
                printf("===============================\n");
                printf("MAPA DE TERRITORIOS\n");
                printf("===============================\n");
                for (int i = 0; i < totalTerritorios; i++) {
                    printf("%d (Nome: %s, Cor: %s, Tropas: %d)\n", i + 1, mapa[i].nome, mapa[i].cor, mapa[i].tropas);
                }
                
                int IdAtacante, IdDefensor;
                
                printf("Escolha o territorio atacante (numero), ou 0 para sair\n");
                scanf("%d", &IdAtacante);
                limparBufferEntrada();
                
                if (IdAtacante == 0) {
                    printf("Saindo da simulacao de combate.\n");
                    break;
                }
                
                if (IdAtacante < 1 || IdAtacante > totalTerritorios || mapa[IdAtacante - 1].tropas <= 1) {
                    printf("ID de atacante invalido ou tropas insuficientes (minimo 2 para atacar).\n");
                    break;
                }
                
                printf("Escolha o numero de tropas para atacar:\n");
                int tropasAtacante;
                scanf("%d", &tropasAtacante);
                limparBufferEntrada();
                
                if (tropasAtacante < 1 || tropasAtacante >= mapa[IdAtacante - 1].tropas) {
                    printf("Numero de tropas para atacar invalido. Deve ser no minimo 1 e menor que o total de tropas do territorio.\n");
                    break;
                }

                printf("Escolha o territorio defensor (numero), ou 0 para sair\n");
                scanf("%d", &IdDefensor);
                limparBufferEntrada();
                
                if (IdDefensor == 0) {
                    printf("Saindo da simulacao de combate.\n");
                    break;
                }

                if (IdDefensor < 1 || IdDefensor > totalTerritorios || IdAtacante == IdDefensor) {
                    printf("ID de defensor invalido ou igual ao atacante.\n");
                    break;
                }
                
                printf("Escolha o numero de tropas para defender:\n");
                int tropasDefensor;
                scanf("%d", &tropasDefensor);
                limparBufferEntrada();
                
                if (tropasDefensor > mapa[IdDefensor - 1].tropas) {
                    printf("O numero de tropas para defender nao pode ser maior que o total de tropas do territorio.\n");
                    break;
                }
                
                printf("===============================\n");
                printf("Iniciando combate entre %s (Atacante) e %s (Defensor)\n", mapa[IdAtacante - 1].nome, mapa[IdDefensor - 1].nome);
                
                srand(time(NULL));
                int sorteioAtacante = rand() % 6 + 1;
                int sorteioDefensor = rand() % 6 + 1;
                printf("Atacante tirou: %d\n", sorteioAtacante);
                printf("Defensor tirou: %d\n", sorteioDefensor);
                
                if (sorteioAtacante > sorteioDefensor) {
                    mapa[IdDefensor - 1].tropas -= tropasAtacante;
                    printf("Defensor perde %d tropa(s)! Tropas restantes: %d\n", tropasAtacante, mapa[IdDefensor - 1].tropas);
                } else {
                    mapa[IdAtacante - 1].tropas -= tropasDefensor;
                    printf("Atacante perde %d tropa(s)! Tropas restantes: %d\n", tropasDefensor, mapa[IdAtacante - 1].tropas);
                }
                
                if (mapa[IdDefensor - 1].tropas <= 0) {
                    printf("O territorio %s foi conquistado pelo exercito %s!\n", mapa[IdDefensor - 1].nome, mapa[IdAtacante - 1].cor);
                    
                    strcpy(mapa[IdDefensor - 1].cor, mapa[IdAtacante - 1].cor);
                    mapa[IdDefensor - 1].tropas = tropasAtacante;
                    mapa[IdAtacante - 1].tropas -= tropasAtacante;
                }
                break;
            }

            case 0: // Sair
                printf("\nLiberando memoria e saindo do sistema. Ate mais!\n");
                free(mapa);
                break;
        }
    } while (opcao != 0);
    return 0;
}