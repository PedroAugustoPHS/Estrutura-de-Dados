#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcoes.h"

void escreverSvgCircle(Figura *object, int id, FILE *arqEscreverSVG)
{
	fprintf(arqEscreverSVG, "\t<circle id=\"%d\" cx=\"%lf\" cy=\"%lf\" r=\"%lf\" stroke=\"%s\" fill=\"%s\"/>\n", id, object[id].cx, object[id].cy, object[id].r, object[id].stroke, object[id].fill);
}

void escreverSvgRect(Figura *object, int id, FILE * arqEscreverSVG)
{
	fprintf(arqEscreverSVG, "\t<rect id=\"%d\" x=\"%lf\" y=\"%lf\" width=\"%lf\" height=\"%lf\" stroke=\"%s\" fill=\"%s\"/>\n\t", id, object[id].cx, object[id].cy, object[id].width, object[id].height, object[id].stroke, object[id].fill);
}

void escreverSvgTexto(FILE *arqEscreverSVG, double cx, double cy, char texto[])
{
	fprintf(arqEscreverSVG, "\t<text x=\"%lf\" y=\"%lf\">%s</text>\n", cx, cy, texto);
}

void leituraC(Figura *object, FILE *arqLerGEO, FILE *arqEscreverSVG)
{
	int id;

	fscanf(arqLerGEO, "%d", &id);
	strcpy(object[id].t, "c");
	fscanf(arqLerGEO,"%lf %lf %lf %s %s", &object[id].r, &object[id].cx, &object[id].cy, object[id].stroke, object[id].fill);
	escreverSvgCircle(object, id, arqEscreverSVG);
}

void leituraR(Figura *object, FILE *arqLerGEO, FILE *arqEscreverSVG)
{
	int id;

	fscanf(arqLerGEO, "%d", &id);
	strcpy(object[id].t, "r");
	fscanf(arqLerGEO,"%lf %lf %lf %lf %s %s", &object[id].width, &object[id].height, &object[id].cx, &object[id].cy, object[id].stroke, object[id].fill);
	escreverSvgRect(object, id, arqEscreverSVG);
}

void leituraT(FILE * arqLerGEO, FILE * arqEscreverSVG)
{
	double cx, cy;
	char texto[300];

	fscanf(arqLerGEO, "%lf %lf", &cx, &cy);
	fscanf(arqLerGEO, " %[^\n]", texto);

	escreverSvgTexto(arqEscreverSVG, cx, cy, texto);
}

void leituraGeo(Figura *object, FILE * arqLerGEO, int *numMax, FILE *arqEscreverSVG)
{
	char t[2];
	int contMax = 0, nx;
	
    while( fscanf(arqLerGEO, "%s", t) != EOF){
		if(contMax >= *numMax){
			printf("Numero maximo de circulos e retangulos atingido!\n");
			break;
		}
		else if(t[0] == 'c' && t[1] == 'q'){

		}
		else if(t[0] == 'c' && t[1] == 'h'){
			
		}
		else if(t[0] == 'c' && t[1] == 'r'){
			
		}
		else if(t[0] == 'c' && t[1] == 's'){
			
		}
		else if(t[0] == 'c'){
			leituraC(object, arqLerGEO, arqEscreverSVG);
			contMax++;	
		}
		else if(t[0] == 'r' && t[1] == 'b'){
			
		}
		else if(t[0] == 'r'){
			leituraR(object, arqLerGEO, arqEscreverSVG);
			contMax++;
		}
		else if(t[0] == 't'){
			leituraT(arqLerGEO, arqEscreverSVG);
		}
		else if(t[0] == 'n'){
			fscanf(arqLerGEO, "%d", &nx); //ler o numero e continuar
		}
		else if(t[0] == 'q'){

		}
		else if(t[0] == 'h'){

		}
		else if(t[0] == 's' && t[1] == 'w' ){

		}
		else if(t[0] == 's'){

		}

	}
}

void abrirSVG(FILE *arqEscreverSVG)
{
	fprintf(arqEscreverSVG, "<svg > \n");
}

void leituraQuery(Figura *object, FILE * arqLerQRY, FILE * arqEscreverQryTXT, FILE * arqEscreverSVG, int nx, Name *nomes)
{
    char t[5];
	char fillBb[25];
	char sufixo[30];
    int j, k;
	double cx,cy;

	FILE * arqEscreverBbSvg;
	FILE * arqEscreverQrySvg = fopen(nomes->outputPathFileQuerySvg, "w");

	fprintf(arqEscreverQrySvg, "<svg >\n");
	escreverFigQry(object, nx, arqEscreverQrySvg);
	
    while((fscanf(arqLerQRY,"%s", t))!= EOF){
        if(t[0] == 'o' && t[1] == '?'){
            fscanf(arqLerQRY,"%d %d", &j, &k); 	
            sobrep(object, j, k, arqEscreverQryTXT, arqEscreverQrySvg);
        }
        else if(t[0] == 'i' && t[1] == '?'){
			fscanf(arqLerQRY, "%d %lf %lf", &j, &cx, &cy);
			if(object[j].t[0] == 'c'){
				pontoIntC(object, j, cx, cy, arqEscreverQryTXT, arqEscreverQrySvg);
			}
			else{
				pontoIntR(object, j, cx, cy, arqEscreverQryTXT, arqEscreverQrySvg);
			}
        }
        else if(t[0] == 'd' && t[1] == '?'){
            fscanf(arqLerQRY,"%d %d", &j, &k);
            distCentro(object, j, k, arqEscreverQryTXT, arqEscreverQrySvg);
        }	
        else if(t[0] == 'b' && t[1] == 'b'){
			fscanf(arqLerQRY, "%s %s", sufixo, fillBb);
			nomes->outputPathFileQuerySuf = (char*) malloc((strlen(nomes->outputPathFileQueryLimpo)+strlen(sufixo)+6) *sizeof(char));
			sprintf(nomes->outputPathFileQuerySuf, "%s-%s.svg", nomes->outputPathFileQueryLimpo, sufixo);
			arqEscreverBbSvg = fopen(nomes->outputPathFileQuerySuf, "w");
			verificaBb(object, nx, fillBb, arqEscreverBbSvg);
			fclose(arqEscreverBbSvg);
			free(nomes->outputPathFileQuerySuf);
        }
		else if(strcmp())

    }
	fprintf(arqEscreverQrySvg, "</svg>");
	fclose(arqEscreverQrySvg);
}

void escreverFigQry(Figura *object, int nx, FILE * arqEscreverQrySvg)
{
	int x=0;
	while(x<nx){
		if(object[x].t[0] == 'c'){
			escreverSvgCircle(object, x, arqEscreverQrySvg);
		}
		else if(object[x].t[0] == 'r'){
			escreverSvgRect(object, x, arqEscreverQrySvg);
		}
		x++;
	}
}


void freeNosMalloc(Figura *object, Name nomes)
{
    free(object);
    free(nomes.inputFileLimpo);
    free(nomes.inputQueryLimpo);
    free(nomes.inputPathFile);
    free(nomes.inputPathQuery);
    free(nomes.outputPathFileLimpo);
    free(nomes.outputPathFileQueryLimpo);
    free(nomes.outputPath);
    free(nomes.outputPathFileSvg);
    free(nomes.outputPathFileQueryTxt);
    free(nomes.outputPathFileQuerySvg);
}

int procuraNx(FILE * arqLerGEO) // Pegar o maior numero do nx de todo arquivo .geo
{	
	char c;
	int nx, maior = 0;

	while(1){
		c = fgetc(arqLerGEO);

		if(c == 'n'){
			c = fgetc(arqLerGEO);
			if( c == 'x'){
				fscanf(arqLerGEO, "%d", &nx);
				if(nx > maior){
					maior = nx;
				}
			}
		}
		else if( c == EOF){
			if(maior == 0){
				return 1000;
			}
			else{
				return maior;
			}
		}
	}
}