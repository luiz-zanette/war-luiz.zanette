#ifndef FUNCOES_H
#define FUNCOES_H

#include "estruturas.h"

void limparBufferEntrada();
void cadastrarTerritorio(struct Territorio* mapa, int* totalTerritorios);
void listarTerritorios(const struct Territorio* mapa, int totalTerritorios);
void combate(struct Territorio* mapa, int totalTerritorios);

#endif