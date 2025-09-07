#include "funcoes.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "estruturas.h"

void limparBufferEntrada() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void simularAtaque(struct Territorio* mapa, int totalTerritorios) {
    printf("\n--- SIMULACAO DE COMBATE ENTRE TERRITORIOS ---\n");
    if (totalTerritorios < 2) {
        printf("É necessario ter pelo menos dois territorios cadastrados para simular um combate.\n");
        return; // Use 'return' para sair da função
    }
    
    printf("===============================\n");
    printf("MAPA DE TERRITÓRIOS\n");
    printf("===============================\n");
    for (int i = 0; i < totalTerritorios; i++) {
        printf("%d (Nome: %s, Cor: %s, Tropas: %d)\n", i + 1, mapa[i].nome, mapa[i].cor, mapa[i].tropas);
    }
    
    printf("Escolha o territorio atacante (numero), ou 0 para sair\n");
    int IdAtacante; scanf("%d", &IdAtacante); limparBufferEntrada();
    
    // ... e o restante do seu código de combate
    
    printf("Escolha o numero de tropas para atacar:\n");
    int tropasAtacante; scanf("%d", &tropasAtacante); limparBufferEntrada();
    
    printf("Escolha o territorio defensor (numero), ou 0 para sair\n");
    int IdDefensor; scanf("%d", &IdDefensor); limparBufferEntrada();
    
    printf("Escolha o numero de tropas para defender:\n");
    int tropasDefensor; scanf("%d", &tropasDefensor); limparBufferEntrada();
    
    if (IdAtacante == 0 || IdDefensor == 0) {
        printf("Saindo da simulação de combate.\n");
        return;
    }
    
    printf("===============================\n");
    printf("Iniciando combate entre %s (Atacante) e %s (Defensor)\n", mapa[IdAtacante - 1].nome, mapa[IdDefensor - 1].nome);
    
    srand(time(NULL));
    int sorteioAtacante = rand() % 6 + 1;
    int sorteioDefensor = rand() % 6 + 1;
    printf("Atacante tirou: %d\n", sorteioAtacante);
    printf("Defensor tirou: %d\n", sorteioDefensor);
    
    if (sorteioAtacante > sorteioDefensor) {
        mapa[IdDefensor - 1].tropas--;
        printf("Defensor perde uma tropa! Tropas restantes: %d\n", mapa[IdDefensor - 1].tropas);
    } else {
        mapa[IdAtacante - 1].tropas--;
        printf("Atacante perde uma tropa! Tropas restantes: %d\n", mapa[IdAtacante - 1].tropas);
    }
    
    if (mapa[IdDefensor - 1].tropas <= 0) {
        printf("O territorio %s foi conquistado pelo exercito %s!\n", mapa[IdDefensor - 1].nome, mapa[IdAtacante - 1].cor);
        
        strcpy(mapa[IdDefensor - 1].cor, mapa[IdAtacante - 1].cor);
        mapa[IdDefensor - 1].tropas = mapa[IdAtacante - 1].tropas / 2;
        mapa[IdAtacante - 1].tropas = mapa[IdAtacante - 1].tropas / 2;
    }
}