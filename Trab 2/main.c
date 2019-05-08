#include <stdio.h>
#include <stdlib.h>
#include "funcoes.h"

int main(int argc, char *argv[])
{
	FILE * arqLerGEO = NULL;
	FILE * arqEscreverSVG = NULL;
	FILE * arqLerQRY = NULL;
	FILE * arqEscreverQryTXT = NULL;

	int verQuery = 1;
	int numMax=1000;

	Name nomes;

	creatingFile(argc, argv, arqLerQRY, arqLerGEO, arqEscreverQryTXT, arqEscreverSVG, &nomes, &verQuery);
	
	if(verQuery == 1){
		arqLerQRY = fopen(nomes.inputPathQuery,"r");
	}
	

	arqLerGEO = fopen(nomes.inputPathFile,"r");

	if(arqLerGEO == NULL){
		printf("ERRO AO ABRIR O ARQUIVO!\n");
		system("pause");
		exit(1);
	}
	numMax = procuraNx(arqLerGEO);

	arqEscreverSVG = fopen(nomes.outputPathFileSvg, "w");

	if(arqEscreverSVG == NULL){
		printf("ERRO AO ABRIR O ARQUIVO!\n");
		system("pause");
		exit(1);
	}

	if(verQuery == 1){
		arqEscreverQryTXT = fopen(nomes.outputPathFileQueryTxt, "w");
	}
	
	abrirSVG(arqEscreverSVG);

	Figura *object;
	object = (Figura*) malloc(numMax * sizeof(Figura));
	
	//Pra voltar o cursor
	fclose(arqLerGEO);
	arqLerGEO = fopen(nomes.inputPathFile,"r");

	leituraGeo(object, arqLerGEO, &numMax, arqEscreverSVG);
		
	fclose(arqLerGEO);
	
	if(verQuery == 1){
		leituraQuery(object, arqLerQRY, arqEscreverQryTXT, arqEscreverSVG, numMax, &nomes);
	}
	
	fprintf(arqEscreverSVG, "</svg>");
	
	fclose(arqEscreverSVG);

	if(verQuery == 1){
		fclose(arqEscreverQryTXT);
		fclose(arqLerQRY);
	}

	freeNosMalloc(object, nomes);
	
	return 0;
}