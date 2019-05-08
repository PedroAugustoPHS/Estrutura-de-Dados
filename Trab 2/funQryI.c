#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "funcoes.h"

void pontoIntR(Figura *object, int j, double cx, double cy, FILE * arqEscreverQryTXT, FILE * arqEscreverQrySvg)
{
    if(cx >= object[j].cx && cx<=(object[j].cx + object[j].width)){
        if(cy>=object[j].cy && cy<=(object[j].cy + object[j].height)){
            fprintf(arqEscreverQryTXT, "i? %d %lf %lf\nINTERNO\n", j, cx, cy);
            //escrevendo ponto e linha no svg
            fprintf(arqEscreverQrySvg, "\t<circle cx=\"%lf\" cy=\"%lf\" r=\"5\" stroke=\"green\" fill=\"green\" />\n", cx, cy);
            fprintf(arqEscreverQrySvg, "\t<line x1=\"%lf\" y1=\"%lf\" x2=\"%lf\" y2=\"%lf\" style=\"stroke:rgb(0,255,0);stroke-width:2\" />\n", cx, cy, object[j].cx + (object[j].width/2), object[j].cy + (object[j].height/2));
        }
    }
    else{
        fprintf(arqEscreverQryTXT, "i? %d %lf %lf\nNAO INTERNO\n", j, cx, cy);    
        //escrevendo ponto e linha no svg
        fprintf(arqEscreverQrySvg, "\t<circle cx=\"%lf\" cy=\"%lf\" r=\"5\" stroke=\"red\" fill=\"red\" />\n", object[j].cx, object[j].cx);
        fprintf(arqEscreverQrySvg, "\t<line x1=\"%lf\" y1=\"%lf\" x2=\"%lf\" y2=\"%lf\" style=\"stroke:rgb(255,0,0);stroke-width:2\" />\n", object[j].cx, object[j].cy, object[j].cx + (object[j].width/2), object[j].cy + (object[j].height/2));
    }
}
//i?
void pontoIntC(Figura *object, int j, double cx, double cy, FILE * arqEscreverQryTXT, FILE * arqEscreverQrySvg)
{
    double d;
    
    d = sqrt(pow(((object[j].cx) - cx),2) + pow(((object[j].cy) - cy),2));

    if(d < object[j].r){
        fprintf(arqEscreverQryTXT, "i? %d %lf %lf\nINTERNO\n", j, cx, cy);
        //escrevendo ponto e linha no svg
        fprintf(arqEscreverQrySvg, "\t<circle cx=\"%lf\" cy=\"%lf\" r=\"5\" stroke=\"green\" fill=\"green\" />\n", cx, cy);
        fprintf(arqEscreverQrySvg, "\t<line x1=\"%lf\" y1=\"%lf\" x2=\"%lf\" y2=\"%lf\" style=\"stroke:rgb(0,255,0);stroke-width:2\" />\n", cx, cy, object[j].cx, object[j].cy);
    }
    else{
        fprintf(arqEscreverQryTXT, "i? %d %lf %lf\nNAO INTERNO\n", j, cx, cy);
        //escrevendo ponto e linha no svg
        fprintf(arqEscreverQrySvg, "\t<circle cx=\"%lf\" cy=\"%lf\" r=\"5\" stroke=\"red\" fill=\"red\" />\n", cx, cy);
        fprintf(arqEscreverQrySvg, "\t<line x1=\"%lf\" y1=\"%lf\" x2=\"%lf\" y2=\"%lf\" style=\"stroke:rgb(255,0,0);stroke-width:2\" />\n", cx, cy, object[j].cx, object[j].cy);
    }
}