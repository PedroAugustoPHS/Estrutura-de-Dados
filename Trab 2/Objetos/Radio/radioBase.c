#include "radioBase.h"

typedef struct radio{
    double x, y;
    int id;
}RadioBase;

RadioBase criarRadio(double x, double y, int id){
    RadioBase cellTower = (RadioBase) malloc(sizeof(RadioBase));
    cellTower->x = x;
    cellTower->y = y;
    cellTower->id = id;

    return cellTower;
}

//GETTERS
double getRadioBaseX(RadioBase cellTower){
    return cellTower->x;
}
double getRadioBaseY(RadioBase cellTower){
    return cellTower->y;
}
int getRadioBaseId(RadioBase cellTower){
    return cellTower->id;
}