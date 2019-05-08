#ifndef SEMAFORO_H
#define SEMAFORO_H

Semaforo criarSemaforo(double x, double y, int id);

double getSemaforoX(Semaforo trafficLight);

double getSemaforoY(Semaforo trafficLight);

int getSemaforoId(Semaforo trafficLight);

#endif