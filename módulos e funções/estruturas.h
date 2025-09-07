#ifndef ESTRUTURAS_H
#define ESTRUTURAS_H

#define MAX_STRING 30
#define MAX_COR 10
#define MAX_TERRITORIOS 5

struct Territorio {
    char nome[MAX_STRING];
    char cor[MAX_COR];
    int tropas;
};

#endif