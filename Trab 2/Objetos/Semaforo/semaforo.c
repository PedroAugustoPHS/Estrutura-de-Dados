#include "semaforo.h"

typedef struct s{
    double x,y;
    int id;
}Semaforo;

Semaforo criarSemaforo(double x, double y, int id){
    Semaforo trafficLight = (Semaforo) malloc(sizeof(Semaforo));
    trafficLight->x = x;
    trafficLight->y = y;
    trafficLight->id = id;

    return trafficLight;
}

//GETTERS
double getSemaforoX(Semaforo trafficLight){
    return trafficLight->x;
}
double getSemaforoY(Semaforo trafficLight){
    return trafficLight->y;
}
int getSemaforoId(Semaforo trafficLight){
    return trafficLight->id;
}