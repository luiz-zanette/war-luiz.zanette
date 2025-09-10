#include "funcoes.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

void limparBufferEntrada() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void cadastrarTerritorio(struct Territorio* mapa, int* totalTerritorios) {
    printf("\n--- CADASTRO DE NOVO TERRITORIO ---\n");
    if (*totalTerritorios < MAX_TERRITORIOS) {

        printf("Digite o nome do territorio: ");
        fgets(mapa[*totalTerritorios].nome, MAX_STRING, stdin);

        printf("Digite a cor do exercito: ");
        fgets(mapa[*totalTerritorios].cor, MAX_COR, stdin);

        printf("Digite o numero de tropas no local: ");
        scanf("%d", &mapa[*totalTerritorios].tropas);
        
        mapa[*totalTerritorios].nome[strcspn(mapa[*totalTerritorios].nome, "\n")] = 0;
        mapa[*totalTerritorios].cor[strcspn(mapa[*totalTerritorios].cor, "\n")] = 0;
        
        (*totalTerritorios)++;
        printf("\nTerritorio cadastrado com sucesso!\n");
    } else {
        printf("\nLimite de territorios atingido!\n");
    }
}

void listarTerritorios(const struct Territorio mapa[], int totalTerritorios) {
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
}

void combate(struct Territorio* mapa, int totalTerritorios) {
    printf("\n--- SIMULACAO DE COMBATE ENTRE TERRITORIOS ---\n");
    
    if (totalTerritorios < 2) {
        printf("É necessario ter pelo menos dois territorios cadastrados para simular um combate.\n");
        return;
    }

    printf("===============================\n");
    printf("MAPA DE TERRITORIOS\n");
    printf("===============================\n");
    for (int i = 0; i < totalTerritorios; i++) {
        printf("%d (Nome: %s, Cor: %s, Tropas: %d)\n", i + 1, mapa[i].nome, mapa[i].cor, mapa[i].tropas);
    }
    
    int IdAtacante, tropasAtacante, IdDefensor, tropasDefensor;
    
    printf("Escolha o territorio atacante (numero), ou 0 para sair\n");
    scanf("%d", &IdAtacante); limparBufferEntrada();
    
    if (IdAtacante == 0) {
        printf("Saindo da simulacao de combate.\n");
        return;
    }
    
    if (IdAtacante < 1 || IdAtacante > totalTerritorios || mapa[IdAtacante - 1].tropas <= 1) {
        printf("ID de atacante invalido ou tropas insuficientes (minimo 2 para atacar).\n");
        return;
    }
    
    printf("Escolha o numero de tropas para atacar (maximo %d):\n", mapa[IdAtacante - 1].tropas - 1);
    scanf("%d", &tropasAtacante); limparBufferEntrada();

    if (tropasAtacante < 1 || tropasAtacante >= mapa[IdAtacante - 1].tropas) {
        printf("Numero de tropas para atacar invalido.\n");
        return;
    }

    printf("Escolha o territorio defensor (numero), ou 0 para sair\n");
    scanf("%d", &IdDefensor); limparBufferEntrada();
    
    if (IdDefensor == 0) {
        printf("Saindo da simulacao de combate.\n");
        return;
    }

    if (IdDefensor < 1 || IdDefensor > totalTerritorios || IdAtacante == IdDefensor) {
        printf("ID de defensor invalido ou igual ao atacante.\n");
        return;
    }
    
    printf("Escolha o numero de tropas para defender (maximo %d):\n", mapa[IdDefensor - 1].tropas);
    scanf("%d", &tropasDefensor); limparBufferEntrada();
    
    if (tropasDefensor > mapa[IdDefensor - 1].tropas) {
        printf("O numero de tropas para defender nao pode ser maior que o total de tropas do territorio.\n");
        return;
    }

    printf("===============================\n");
    printf("Iniciando combate entre %s (Atacante) e %s (Defensor)\n", mapa[IdAtacante - 1].nome, mapa[IdDefensor - 1].nome);
    
    int sorteioAtacante = rand() % 6 + 1;
    int sorteioDefensor = rand() % 6 + 1;
    printf("Atacante tirou: %d\n", sorteioAtacante);
    printf("Defensor tirou: %d\n", sorteioDefensor);
    
    if (sorteioAtacante > sorteioDefensor) {
        mapa[IdDefensor - 1].tropas -= 1;
        printf("Defensor perde uma tropa! Tropas restantes: %d\n", mapa[IdDefensor - 1].tropas);
    } else {
        mapa[IdAtacante - 1].tropas -= 1;
        printf("Atacante perde uma tropa! Tropas restantes: %d\n", mapa[IdAtacante - 1].tropas);
    }
    
    if (mapa[IdDefensor - 1].tropas <= 0) {
        printf("O territorio %s foi conquistado pelo exercito %s!\n", mapa[IdDefensor - 1].nome, mapa[IdAtacante - 1].cor);
        
        strcpy(mapa[IdDefensor - 1].cor, mapa[IdAtacante - 1].cor);
        mapa[IdDefensor - 1].tropas = tropasAtacante - 1; 
        mapa[IdAtacante - 1].tropas -= tropasAtacante;
    }
}

void sortearMissao(char* missao, const struct Territorio* mapa, int totalTerritorios) {
    if (totalTerritorios == 0) {
        strcpy(missao, "Nenhum territorio cadastrado para sortear missao.");
        return;
    } 

    int indice = rand() % totalTerritorios;
    int tipoMissao = rand() % 3;
    
    if (tipoMissao == 0) {
        snprintf(missao, MAX_MISSAO_LEN, "Conquistar o territorio: %s", mapa[indice].nome);
    } else if (tipoMissao == 1) {
        snprintf(missao, MAX_MISSAO_LEN, "Eliminar o exercito de cor: %s", mapa[indice].cor);
    } else {
        snprintf(missao, MAX_MISSAO_LEN, "Manter pelo menos %d tropas em %s", mapa[indice].tropas, mapa[indice].nome);
    }  
}

void verificarMissao(const char* missao, const struct Territorio* mapa, int totalTerritorios) {
    if (strlen(missao) == 0) {
        printf("Nenhuma missao foi sorteada ainda.\n");
        return;
    }
    
    if (strstr(missao, "Conquistar o territorio:") != NULL) {
        char nomeTerritorio[MAX_STRING];
        sscanf(missao, "Conquistar o territorio: %s", nomeTerritorio);
        
        for (int i = 0; i < totalTerritorios; i++) {
            if (strcmp(mapa[i].nome, nomeTerritorio) == 0) {
                // Necessário definir a cor do jogador principal para esta verificação
                if (strcmp(mapa[i].cor, "SuaCor") == 0) { 
                    printf("Missao cumprida: %s\n", missao);
                } else {
                    printf("Missao nao cumprida: %s\n", missao);
                }
                return;
            }
        }
    } else if (strstr(missao, "Eliminar o exercito de cor:") != NULL) {
        char corExercito[MAX_COR];
        sscanf(missao, "Eliminar o exercito de cor: %s", corExercito);
        
        int exercitoEliminado = 1;
        for (int i = 0; i < totalTerritorios; i++) {
            if (strcmp(mapa[i].cor, corExercito) == 0 && mapa[i].tropas > 0) {
                exercitoEliminado = 0;
                break;
            }
        }

        if (exercitoEliminado) {
            printf("Missao cumprida: %s\n", missao);
        } else {
            printf("Missao nao cumprida: %s\n", missao);
        }

    } else if (strstr(missao, "Manter pelo menos") != NULL) {
        int tropasNecessarias;
        char nomeTerritorio[MAX_STRING];
        sscanf(missao, "Manter pelo menos %d tropas em %s", &tropasNecessarias, nomeTerritorio);
        
        for (int i = 0; i < totalTerritorios; i++) {
            if (strcmp(mapa[i].nome, nomeTerritorio) == 0) {
                if (mapa[i].tropas >= tropasNecessarias) {
                    printf("Missao cumprida: %s\n", missao);
                } else {
                    printf("Missao nao cumprida: %s\n", missao);
                }
                return;
            }
        }
    }
    printf("Missao de %s incompleta, continue a lutar!\n", missao);
}