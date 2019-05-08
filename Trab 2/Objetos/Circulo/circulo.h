#ifndef CIRCULO_H
#define CIRCULO_H

typedef void c *Circulo;

Circulo criarCirculo(double x, double y, double r, double cw, int id, char *stroke, char*fill);

double getCirculoX(Circulo circle);

double getCirculoY(Circulo circle);

double getCirculoR(Circulo circle);

double getCirculoCw(Circulo circle);

int getCirculoX(Circulo circle);

char getCirculoStroke(Circulo circle);

char getCirculoFill(Circulo circle);

#endif