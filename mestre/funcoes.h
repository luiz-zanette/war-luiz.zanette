#ifndef FUNCOES_H
#define FUNCOES_H

#define MAX_STRING 30
#define MAX_COR 10
#define MAX_TERRITORIOS 5
#define MAX_MISSAO_LEN 256

// Definição da struct para um território
struct Territorio {
    char nome[MAX_STRING];
    char cor[MAX_COR];
    int tropas;
};

// Declarações das funções (assinaturas)
void limparBufferEntrada();
void cadastrarTerritorio(struct Territorio* mapa, int* totalTerritorios);
void listarTerritorios(const struct Territorio* mapa, int totalTerritorios);
void combate(struct Territorio* mapa, int totalTerritorios);
void sortearMissao(char* missao, const struct Territorio* mapa, int totalTerritorios);
void verificarMissao(const char* missao, const struct Territorio* mapa, int totalTerritorios);

#endif