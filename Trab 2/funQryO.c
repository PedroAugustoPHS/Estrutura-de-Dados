#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "funcoes.h"

double clamp(double coord, double min, double max)
{
    if(coord > max){
        return max;
    }
    else if(coord < min){
        return min;
    }
    else{
        return coord;
    }
}

void sobrep(Figura *object, int j, int k, FILE * arqEscreverQryTXT, FILE * arqEscreverQrySvg)
{
    double menorX=0, maiorX=0, menorY=0, maiorY=0;

	if(object[j].t[0] == 'c' && object[k].t[0] == 'r'){
        if(object[j].cx - object[j].r < object[k].cx){
            menorX = object[j].cx - object[j].r;
        }
		else{
			menorX=object[k].cx;
		}
        if(object[j].cy - object[j].r < object[k].cy){
            menorY = object[j].cy - object[j].r;
        }
        else{
            menorY = object[k].cy;
        }
        if(object[j].cx + object[j].r > object[k].cx + object[k].width){
            maiorX = object[j].cx + object[j].r;
        }
        else{
            maiorX= object[k].cx + object[k].width;
        }
        if(object[j].cy + object[j].r > object[k].cy + object[k].height){
            maiorY= object[j].cy + object[j].r;
        }
        else{
            maiorY= object[k].cy + object[k].height;
        }
		if(sqrt(pow(clamp(object[j].cx, object[k].cx, (object[k].cx + object[k].width))- object[j].cx,2) + pow(clamp(object[j].cy, object[k].cy, object[k].cy + object[k].height)- object[j].cy,2)) <= object[j].r){
            fprintf(arqEscreverQryTXT,"o? %d %d\nSIM\n", j, k);
            fprintf(arqEscreverQrySvg, "\t<rect width=\"%lf\" height=\"%lf\" x=\"%lf\" y=\"%lf\" fill=\"none\" stroke=\"black\" />\n",maiorX-menorX, maiorY-menorY,menorX,menorY);
		}
		else{
            fprintf(arqEscreverQryTXT,"o? %d %d\nNAO\n", j, k);
            fprintf(arqEscreverQrySvg, "\t<rect width=\"%lf\" height=\"%lf\" x=\"%lf\" y=\"%lf\" fill=\"none\" stroke=\"black\" stroke-dasharray= \"5\" />\n", maiorX-menorX, maiorY-menorY,menorX,menorY);
		}
	}

    else if(object[j].t[0] == 'r' && object[k].t[0] == 'c'){
        if(object[k].cx - object[k].r < object[j].cx){
            menorX = object[k].cx - object[k].r; //menor X
        }
		else{
			menorX=object[j].cx;
		}
        if(object[k].cy - object[k].r < object[j].cy){
            menorY = object[k].cy - object[k].r; //menor Y
        }
        else{
            menorY = object[j].cy;
        }
        if(object[j].cx + object[j].width < object[k].cx + object[k].r ){
            maiorX = object[k].cx + object[k].r; // maior X
        }
        else{
            maiorX= object[j].cx + object[j].width;
        }
        if(object[j].cy + object[j].height < object[k].cy + object[k].r){
            maiorY= object[k].cy + object[k].r; // maior Y
        }
        else{
            maiorY= object[j].cy + object[j].height;
        }
		if(sqrt(pow(clamp(object[k].cx, object[j].cx, (object[j].cx + object[j].width))- object[k].cx,2) + pow(clamp(object[k].cy, object[j].cy, object[j].cy + object[j].height)- object[k].cy,2)) <= object[k].r){
            fprintf(arqEscreverQryTXT,"o? %d %d\nSIM\n", j, k);
            fprintf(arqEscreverQrySvg, "\t<rect width=\"%lf\" height=\"%lf\" x=\"%lf\" y=\"%lf\" fill=\"none\" stroke=\"black\" />\n",maiorX-menorX, maiorY-menorY,menorX,menorY);
		}
		else{
            fprintf(arqEscreverQryTXT,"o? %d %d\nNAO\n", j, k);
            fprintf(arqEscreverQrySvg, "\t<rect width=\"%lf\" height=\"%lf\" x=\"%lf\" y=\"%lf\" fill=\"none\" stroke=\"black\" stroke-dasharray= \"5\" />\n", maiorX-menorX, maiorY-menorY,menorX,menorY);
		}
	}
    else if(object[j].t[0] == 'r' && object[k].t[0] == 'r'){
        if(object[j].cx < object[k].cx){
            menorX = object[j].cx;
        }
        else{
            menorX = object[k].cx;
        }
        if( object[j].cy < object[k].cy){
            menorY = object[j].cy;   
        }
        else{
            menorY = object[k].cy;
        }
        if( object[j].cx + object[j].width < object[k].cx + object[k].width){
            maiorX = object[k].cx + object[k].width;
        }
        else{
            maiorX = object[j].cx + object[j].width;
        }
        if(object[j].cy + object[j].height < object[k].cy + object[k].height){
            maiorY = object[k].cy + object[k].height;
        }
        else{
            maiorY = object[j].cy + object[j].height;
        }
        if(object[k].cx >= object[j].cx && object[k].cx <= object[j].cx + object[j].width){
            if(object[k].cy >= object[j].cy && object[k].cy <= object[j].cy + object[j].height){
                fprintf(arqEscreverQryTXT,"o? %d %d\nSIM\n", j, k);
                fprintf(arqEscreverQrySvg, "\t<rect width=\"%lf\" height=\"%lf\" x=\"%lf\" y=\"%lf\" fill=\"none\" stroke=\"black\" />\n", maiorX-menorX, maiorY-menorY, menorX, menorY);
            }
        }
        else if(object[k].cx + object[k].width >= object[j].cx && object[k].cx + object[k].cx <= object[j].cx + object[j].width){
            if(object[k].cy >= object[j].cy && object[k].cy <= object[j].cy + object[j].height){
                fprintf(arqEscreverQryTXT,"o? %d %d\nSIM\n", j, k);
                fprintf(arqEscreverQrySvg, "\t<rect width=\"%lf\" height=\"%lf\" x=\"%lf\" y=\"%lf\" fill=\"none\" stroke=\"black\" />\n", maiorX-menorX, maiorY-menorY, menorX, menorY);
            }
        }
        else if(object[k].cx >= object[j].cx && object[k].cx <= object[j].cx + object[j].width){
            if(object[k].cy + object[k].height >= object[j].cy && object[k].cy + object[k].height <= object[j].cy + object[j].height){
                fprintf(arqEscreverQryTXT,"o? %d %d\nSIM\n", j, k);
                fprintf(arqEscreverQrySvg, "\t<rect width=\"%lf\" height=\"%lf\" x=\"%lf\" y=\"%lf\" fill=\"none\" stroke=\"black\" />\n", maiorX-menorX, maiorY-menorY, menorX, menorY);
            }
        }
        else if(object[k].cx + object[k].width >= object[j].cx && object[k].cx + object[k].width <= object[j].cx + object[j].width){
            if(object[k].cy + object[k].height >= object[j].cy && object[k].cy + object[k].height <= object[j].cy + object[j].height){
                fprintf(arqEscreverQryTXT,"o? %d %d\nSIM\n", j, k);
                fprintf(arqEscreverQrySvg, "\t<rect width=\"%lf\" height=\"%lf\" x=\"%lf\" y=\"%lf\" fill=\"none\" stroke=\"black\" />\n", maiorX-menorX, maiorY-menorY, menorX, menorY);
            }
        }
        else{
            fprintf(arqEscreverQryTXT,"o? %d %d\nNAO\n", j, k);
            fprintf(arqEscreverQrySvg, "\t<rect width=\"%lf\" height=\"%lf\" x=\"%lf\" y=\"%lf\" fill=\"none\" stroke=\"black\" stroke-dasharray=\"5\" />\n", maiorX-menorX, maiorY-menorY, menorX, menorY);
        }
	}
	else{
        if(object[j].cx - object[j].r < object[k].cx - object[k].r){
            menorX = object[j].cx - object[j].r;
        }
        else{
            menorX = object[k].cx - object[j].r;
        }
        if(object[j].cy - object[j].r < object[k].cy - object[k].r){
            menorY = object[j].cy - object[j].r;
        }
        else{
            menorY = object[k].cy - object[k].r;
        }
        if(object[j].cx + object[j].r < object[k].cx + object[k].r){
            maiorX = object[k].cx + object[k].r;
        }
        else{
            maiorX = object[j].cx + object[j].r;
        }
        if(object[j].cy + object[j].r < object[k].cy + object[k].r ){
            maiorY = object[k].cy + object[k].r;
        }
        else{
            maiorY = object[j].cy + object[j].r;
        }
        if(sqrt(pow((object[j].cx - object[k].cx),2) + pow((object[j].cy - object[k].cy),2)) <= (object[j].r + object[k].r)){
            fprintf(arqEscreverQryTXT,"o? %d %d\nSIM\n", j, k);
			fprintf(arqEscreverQrySvg, "\n\t<rect width=\"%lf\" height=\"%lf\" x=\"%lf\" y=\"%lf\" fill=\"none\" stroke=\"black\" />",maiorX-menorX,maiorY-menorY,menorX,menorY);
		}
		else{
            fprintf(arqEscreverQryTXT,"o? %d %d\nNAO\n", j, k);
			fprintf(arqEscreverQrySvg, "\n\t<rect width=\"%lf\" height=\"%lf\" x=\"%lf\" y=\"%lf\" fill=\"none\" stroke=\"black\" stroke-dasharray=\"5\" />",maiorX-menorX,maiorY-menorY,menorX,menorY);
		}
	}
}