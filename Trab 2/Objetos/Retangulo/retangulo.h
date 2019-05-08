#ifndef RETANGULO_H
#define RETANGULO_H

Retangulo criarRetangulo(double w, double h, double x, double y, double r, double cw, int id, char *stroke, char *fill);

double getRetanguloW(Retangulo rect);

double getRetanguloH(Retangulo rect);

double getRetanguloX(Retangulo rect);

double getRetanguloY(Retangulo rect);

double getRetanguloR(Retangulo rect);

double getRetanguloCw(Retangulo rect);

char getRetanguloStroke(Retangulo rect);

char getRetanguloFill(Retangulo rect);

int getRetanguloId(Retangulo rect);



#endif