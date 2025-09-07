#include "funcoes.h"
#include <stdio.h>
#include <string.h>
#include "estruturas.h"

void listarTerritorios(const struct Territorio mapa[], int totalTerritorios) {
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
    getchar(); // Espera o usuário interagir para seguir adiante
}