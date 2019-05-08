#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "funcoes.h"

void distCentro (Figura *object, int j, int k, FILE * arqEscreverQryTXT, FILE * arqEscreverQryBb){
    double d, dx, dy, posT; //posT = posição texto

    if(object[j].t[0] == 'r' && object[k].t[0] == 'r'){
        dx = object[j].cx + (object[j].width / 2) - object[k].cx + (object[k].width / 2);
        dy = object[j].cy + (object[j].height / 2) - object[k].cy + (object[k].height / 2);
        d = sqrt((dx*dx) + (dy*dy));

        fprintf(arqEscreverQryBb, "\t<line x1=\"%lf\" y1=\"%lf\" x2=\"%lf\" y2=\"%lf\" style=\"stroke:rgb(0,0,0);stroke-width:2\" />\n", object[j].cx + (object[j].width / 2), object[j].cy + (object[j].height/2), object[k].cx + (object[k].width/2), object[k].cy + (object[k].height/2));

        if((object[j].cx+ (object[j].width)/2) + (object[j].cy+ (object[j].height)/2) < (object[k].cx+ (object[k].width)/2) + (object[k].cy+(object[k].height)/2)){
			fprintf(arqEscreverQryBb, "\n\t<text x=\"%lf\" y=\"%lf\" >%.2lf</text>",object[j].cx+(object[j].width/2)+(d/2),object[j].cy+(object[j].height/2)+(d/2),d);
		}
		else{
			fprintf(arqEscreverQryBb, "\n\t<text x=\"%lf\" y=\"%lf\" >%.2lf</text>",object[k].cx+(object[k].width/2)+(d/2),object[k].cy+(object[k].height/2)+(d/2),d);
		}
    }
    else if(object[j].t[0] == 'r' && object[k].t[0] == 'c'){
        dx = object[j].cx + (object[j].width / 2) - object[k].cx;
        dy = object[j].cy + (object[j].height / 2)- object[k].cy;
        d = sqrt((dx*dx) + (dy*dy));
        
        fprintf(arqEscreverQryBb, "\t<line x1=\"%lf\" y1=\"%lf\" x2=\"%lf\" y2=\"%lf\" style=\"stroke:rgb(0,0,0);stroke-width:2\" />\n", object[j].cx + (object[j].width / 2), object[j].cy + (object[j].height/2), object[k].cx, object[k].cy);

        //Printando distancia no meio da linha
        if(object[k].cx +  object[k].cy < (object[j].cx+ (object[j].width)/2) + (object[j].cy+ (object[j].height)/2)){
			fprintf(arqEscreverQryBb, "\n\t<text x=\"%lf\" y=\"%lf\" >%.2lf</text>",object[k].cx + (d/2),object[k].cy+(d/2),d);
		}
		else{
			fprintf(arqEscreverQryBb, "\n\t<text x=\"%lf\" y=\"%lf\" >%.2lf</text>",(object[j].cx+ (object[j].width)/2)+(d/2),(object[j].cy+ (object[j].height)/2)+(d/2),d);
		}

    }
    else if(object[j].t[0] == 'c' && object[k].t[0] == 'r'){
        dx = object[j].cx - object[k].cx + (object[k].width / 2);
        dy = object[j].cy - object[k].cy + (object[k].height / 2);
        d = sqrt((dx*dx) + (dy*dy));

        fprintf(arqEscreverQryBb, "\t<line x1=\"%lf\" y1=\"%lf\" x2=\"%lf\" y2=\"%lf\" style=\"stroke:rgb(0,0,0);stroke-width:2\" />\n", object[j].cx, object[j].cy, object[k].cx + (object[k].width / 2), object[k].cy + (object[k].height/2) );

        //Printando distancia no meio da linha
        if(object[j].cx +  object[j].cy < (object[k].cx+ (object[k].width)/2) + (object[k].cy+ (object[k].height)/2)){
			fprintf(arqEscreverQryBb, "\n\t<text x=\"%lf\" y=\"%lf\" >%.2lf</text>",object[j].cx + (d/2),object[j].cy+(d/2),d);
		}
		else{
			fprintf(arqEscreverQryBb, "\n\t<text x=\"%lf\" y=\"%lf\" >%.2lf</text>",(object[k].cx+ (object[k].width)/2)+(d/2),(object[k].cy+ (object[k].height)/2)+(d/2),d);
		}

    }
    else{
        dx = object[j].cx - object[k].cx;
        dy = object[j].cy - object[k].cy;
        d = sqrt((dx*dx) + (dy*dy));

        fprintf(arqEscreverQryBb, "\t<line x1=\"%lf\" y1=\"%lf\" x2=\"%lf\" y2=\"%lf\" style=\"stroke:rgb(0,0,0);stroke-width:2\" />\n", object[j].cx, object[j].cy, object[k].cx, object[k].cy);

        //Printando distancia no meio da linha
        if(object[j].cx + object[j].cy < object[k].cx + object[k].cy){
			fprintf(arqEscreverQryBb, "\n\t<text x=\"%lf\" y=\"%lf\" >%.2lf</text>",object[j].cx+(d/2),object[j].cy+(d/2),d);
		}
		else{
			fprintf(arqEscreverQryBb, "\n\t<text x=\"%lf\" y=\"%lf\" >%.2lf</text>",object[k].cx+(d/2),object[k].cy+(d/2),d);
		}
    }

    fprintf(arqEscreverQryTXT, "d? %d %d\n%lf\n",j,k,d);
}