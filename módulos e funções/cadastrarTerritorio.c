#include "funcoes.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "estruturas.h"

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