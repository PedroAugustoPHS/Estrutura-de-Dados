//#include "quadras.h"
#include <stdio.h>
#include <stdlib.h>
 
typedef struct Quadras{
    char cep[20];
    double x, y, width, height;
    char stroke[20], fill[20];
    double strokeWidth;
    struct Quadras* ant;
    struct Quadras* prox;
}QList;
 
typedef struct ListQ{
    QList* inicio;
    QList* fim;
}ListaQ;
 
QList* qlist;
ListaQ* listq;
listq->inicio = listq->fim = NULL;

void* inserirQuadraDefault(char cep[20], double x, double y, double width, double height){
    ListaQ *aux1, *aux2;
    
    if (listq->inicio == NULL){
        
    }
    else{

        aux = listq->fim;


         
    }
}