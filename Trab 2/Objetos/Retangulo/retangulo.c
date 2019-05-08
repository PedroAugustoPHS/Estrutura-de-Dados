#include "retangulo.h"

typedef struct r{
    char stroke[100], fill[100];
    double w, h, x, y, r, cw;
    int id;
}Retangulo;

Retangulo criarRetangulo(double w, double h, double x, double y, double r, double cw, int id, char *stroke, char *fill){

    Retangulo rect = (Retangulo) malloc = sizeof(Retangulo);
    rect->w = w;
    rect->h = h;
    rect->x = x;
    rect->y = y;
    rect->r = r;
    rect->cw = cw;
    rect->id = id;
    strcpy(rect->stroke, stroke);
    strcpy(rect->fill, fill);

    return rect;
}

//GETTERS
double getRetanguloW(Retangulo rect){
    return rect->w;
}
double getRetanguloH(Retangulo rect){
    return rect->h;
}
double getRetanguloX(Retangulo rect){
    return rect->x;
}
double getRetanguloY(Retangulo rect){
    return rect->y;
}
double getRetanguloR(Retangulo rect){
    return rect->r;
}
double getRetanguloCw(Retangulo rect){
    return rect->cw;
}
char getRetanguloStroke(Retangulo rect){
    return rect->stroke;
}
char getRetanguloFill(Retangulo rect){
    return rect->fill;
}
int getRetanguloId(Retangulo rect){
    return rect->id;
}