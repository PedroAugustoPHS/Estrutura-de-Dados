#include "hidrante.h"

typedef struct h{
    double x, y;
    int id;
}Hidrante;

Hidrante criarHidrante(double x, double y, int id){
    Hidrante hydrant = (Hidrante) malloc(sizeof(Hidrante));
    hydrant->x = x;
    hydrant->y = y;
    hydrant->id = id;

    return hydrant;
}

//GETTERS
double getHidranteX(Hidrande hydrant){
    return hydrant->x;
}
double getHidranteY(Hidrande hydrant){
    return hydrant->y;
}
int getHidranteId(Hidrande hydrant){
    return hydrant->id;
}