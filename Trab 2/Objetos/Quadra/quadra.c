#include "quadra.h"

typedef struct q{
    char cep[100];
    double x, y, w, h;
}Quadra;

Quadra criarQuadra(double x, double y, double w, double h, char *cep){
    Quadra block = (Quadra) malloc(sizeof(Quadra));
    block->x = x;
    block->y = y;
    block->w = w;
    block->h = h;
    strcpy(block->cep, cep);

    return block;
}

double getQuadraX(Quadra block){
    return block->x;
}

double getQuadraY(Quadra block){
    return block->y;
}

double getQuadraW(Quadra block){
    return block->w;
}

double getQuadraH(Quadra block){
    return block->H;
}

char getQuadraCep(Quadra block){
    return block->cep;
}