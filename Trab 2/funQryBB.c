#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "funcoes.h"


//bb
void boundingBoxCircle(Figura *object, int id, char corBb[], FILE * arqEscreverBbSvg)
{
    // cx e cy vem das informações da forma (struct/lista)
    double rx, ry;
    double width, height;

    ry = object[id].cy - object[id].r; //r = raio do circulo passado por parametro
    rx = object[id].cx - object[id].r;
    width = 2 * object[id].r;
    height = 2 * object[id].r;

    escritaBb(rx,ry,width,height, arqEscreverBbSvg, corBb);
}

//bb
void elipseRect(Figura *object, int id, char corBb[], FILE * arqEscreverBbSvg)
{   
    double rx, ry, cx, cy;

    rx = object[id].width / 2;
    ry = object[id].height / 2;
    cx = object[id].cx + (object[id].width / 2);
    cy = object[id].cy + (object[id].height / 2);

    escritaElipse(cx,cy,rx,ry,arqEscreverBbSvg,corBb);
}

//bb
void verificaBb(Figura *object, int nx, char fillBb[], FILE * arqEscreverBbSvg)
{
	int x=0;

    fprintf(arqEscreverBbSvg,"<svg>");

	while(x<nx){ //Ordem de escrever importa nesse caso, nessa ordem que foi colocada da pra visualizar melhor
		if(object[x].t[0] == 'c'){
			boundingBoxCircle(object, x, fillBb, arqEscreverBbSvg);
            escreverSvgCircle(object, x, arqEscreverBbSvg); //Na funçao o ponteiro de arq sera chamada de outro nome WARNING!!!!
		}
		else if(object[x].t[0] == 'r'){
            escreverSvgRect(object, x, arqEscreverBbSvg);
			elipseRect(object,x, fillBb, arqEscreverBbSvg);

		}
		x++;
	}
    fprintf(arqEscreverBbSvg,"</svg>");
}

//bb
void escritaElipse(double cx, double cy, double rx, double ry, FILE * arqEscreverBbSvg, char corBb[])
{
	fprintf(arqEscreverBbSvg,"\t<ellipse cx=\"%lf\" cy=\"%lf\" rx=\"%lf\" ry=\"%lf\" fill=\"%s\" />\n", cx,cy,rx,ry,corBb);
}

//bb
void escritaBb(double rx, double ry, double width, double height, FILE * arqEscreverBbSvg, char corBb[])
{
	fprintf(arqEscreverBbSvg,"\t<rect x=\"%lf\" y=\"%lf\" width=\"%lf\" height=\"%lf\" fill=\"%s\" />\n", rx,ry,width,height,corBb);
}