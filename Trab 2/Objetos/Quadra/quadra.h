#ifndef QUADRA_H
#define QUADRA_H

Quadra criarQuadra(double x, double y, double w, double h, char *cep);

double getQuadraX(Quadra block);

double getQuadraY(Quadra block);

double getQuadraW(Quadra block);

double getQuadraH(Quadra block);

char getQuadraCep(Quadra block);

#endif