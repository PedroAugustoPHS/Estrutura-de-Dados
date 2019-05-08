#include "circulo.h"

typedef struct c{
    char stroke[100], fill[100];
    double x, y, r, cw;
    int id;
}Circulo;

Circulo criarCirculo(double x, double y, double r, double cw, int id, char *stroke, char*fill){

    Circulo circle = (Circulo) malloc(sizeof(Circulo));
    circle->x = x;
    circle->y = y;
    circle->r = r;
    circle->cw = cw;
    circle->id = id;
    strcpy(circle->stroke, stroke);
    strcpy(circle->fill, fill);

    return circle;
}

//GETTERS
double getCirculoX(Circulo circle){
    return circle->x;
}

double getCirculoY(Circulo circle){
    return circle->y;
}

double getCirculoR(Circulo circle){
    return circle->r;
}

double getCirculoCw(Circulo circle){
    return circle->cw;
}

int getCirculoX(Circulo circle){
    return circle->id;
}

char getCirculoStroke(Circulo circle){
    return circle->stroke;
}

char getCirculoFill(Circulo circle){
    return circle->fill;
}