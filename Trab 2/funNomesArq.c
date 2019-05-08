#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "funcoes.h"

void creatingFile(int argc, char *argv[], FILE * arqLerQRY, FILE * arqLerGEO, FILE *arqEscreverTXT, FILE * arqEscreverSVG, Name* nomes, int* verQuery){
    int i = 1;
    int x = 0;
    int y, z = 0;
    char *inputFile = NULL;
    char *inputFileLimpo = NULL;
    char *inputPath = NULL;
	char *inputQuery = NULL;
    char *inputQueryLimpo = NULL;
    char *outputPath = NULL;
	char *outputFileLimpo = NULL;
    char *outputPathFile = NULL;

    while(i<argc){
        if(strcmp("-e", argv[i])==0){
            i++;
            inputPath = (char*)malloc((strlen(argv[i]) + 1)*sizeof(char));
            strcpy(inputPath, argv[i]);
        }
        else if(strcmp("-f", argv[i]) == 0){
            i++;
            inputFile = (char*)malloc((strlen(argv[i]) + 1)*sizeof(char));
            strcpy(inputFile, argv[i]);
        }
        else if(strcmp("-o", argv[i]) == 0){
            i++;
            outputPath = (char*)malloc( (strlen(argv[i]) + 1) * sizeof(char));
            strcpy(outputPath, argv[i]);
        }
        else if(strcmp("-q", argv[i]) == 0){
            i++;
            inputQuery = (char*)malloc((strlen(argv[i])+ 1) * sizeof(char));
            strcpy(inputQuery, argv[i]);
        }
        i++;
    }
    //Nao tem arquivo de consulta
    if(inputQuery == 0){
        (*verQuery)= 0;
		inputQuery = malloc(1*sizeof(char));
		inputQuery[0]='\0';
    }

    if(inputPath != 0){
        if((inputPath[strlen(inputPath)]) == '/'){
            nomes->inputPathFile = (char *) malloc((strlen(inputPath)+strlen(inputFile)+1)*sizeof(char));
            sprintf(nomes->inputPathFile, "%s%s", inputPath, inputFile);
            nomes->inputPathQuery = (char *)malloc((strlen(inputPath)+strlen(inputQuery)+1)*sizeof(char));
            sprintf(nomes->inputPathFile,"%s%s",inputPath,inputQuery);
        }
        else{
            nomes->inputPathFile = (char *) malloc((strlen(inputPath)+strlen(inputFile)+2)*sizeof(char));
            sprintf(nomes->inputPathFile,"%s/%s",inputPath,inputFile);
            nomes->inputPathQuery = (char *)malloc((strlen(inputPath)+strlen(inputQuery)+2)*sizeof(char));
            sprintf(nomes->inputPathQuery,"%s/%s",inputPath,inputQuery);
        }
    }
    else{
        inputPath = malloc(sizeof(char) * 3);
        strcpy(inputPath,"./");
        nomes->inputPathFile = (char *)malloc((strlen(inputPath)+strlen(inputFile)+1)*sizeof(char));
        sprintf(nomes->inputPathFile, "%s%s", inputPath, inputFile);
        nomes->inputPathQuery = (char*) malloc((strlen(inputPath) + strlen(inputQuery)+1)*sizeof(char));
        sprintf(nomes->inputPathQuery, "%s%s", inputPath, inputQuery);
    }

    if((outputPath[strlen(outputPath)])=='/'){
	 	nomes->outputPath = (char *)malloc((strlen(outputPath)+1)*sizeof(char));
	 	sprintf(nomes->outputPath,"%s",outputPath);
	}
	else{
	 	nomes->outputPath = (char *)malloc((strlen(outputPath)+2)*sizeof(char));
	 	sprintf(nomes->outputPath,"%s/",outputPath);
		sprintf(outputPath,"%s/",outputPath);
	}

    //pegando o nome do .geo até o ponto da extensão
    for(y=0; y<= strlen(inputFile); y++){
        if(inputFile[y]== '/'){
            x = y;
            x++;
        }
    }
    y = 0;
    while(inputFile[x+y]!='.'){
		y++;
	}

	inputFileLimpo = (char *) malloc(sizeof(char) *(x+y));

    while(y>0){
        inputFileLimpo[z] = inputFile[x];
        x++;
        z++;
        y--;
    }

    //pegando o nome do query até o ponto da extensão
    x = 0; 
    z = 0;

    for(y=0; y<= strlen(inputQuery); y++){
        if(inputQuery[y]== '/'){
            x = y;
            x++;
        }
    }

    y = 0;

    while(inputQuery[x+y]!='.'){
		y++;
	}

    inputQueryLimpo = (char *)malloc(sizeof(char)*(x+y));

    while(y>0){
        inputQueryLimpo[z] = inputQuery[x];
        x++;
        z++;
        y--;
    }

    nomes->inputFileLimpo = malloc((strlen(inputFileLimpo)+5)*sizeof(char));
	strcpy(nomes->inputFileLimpo,inputFileLimpo);

    nomes->outputPathFileLimpo = (char*) malloc((strlen(inputFileLimpo)+strlen(outputPath)+6)*sizeof(char));
    strcat(nomes->outputPathFileLimpo, outputPath);
    strcat(nomes->outputPathFileLimpo, inputFileLimpo);

    nomes->outputPathFileSvg = (char*) malloc((strlen(inputFileLimpo)+strlen(outputPath)+5) * sizeof(char));
    sprintf(nomes->outputPathFileSvg, "%s%s.svg", outputPath, inputFileLimpo);

    nomes->outputPathFileQueryTxt = (char*) malloc((strlen(inputFileLimpo)+strlen(outputPath)+strlen(inputQueryLimpo)+5)*sizeof(char));
    sprintf(nomes->outputPathFileQueryTxt, "%s%s-%s.txt", outputPath, inputFileLimpo, inputQueryLimpo);

    nomes->inputQueryLimpo = (char *) malloc(strlen(inputQueryLimpo)+1);
    strcat(nomes->inputQueryLimpo, inputQueryLimpo);
    
	nomes->outputPathFileQueryLimpo = malloc((strlen(outputPath)+strlen(inputFileLimpo)+strlen(inputQueryLimpo)+2) *sizeof(char));
	sprintf(nomes->outputPathFileQueryLimpo,"%s%s-%s", outputPath, inputFileLimpo, inputQueryLimpo);

    nomes->outputPathFileQuerySvg = malloc((strlen(outputPath)+strlen(inputFileLimpo)+strlen(inputQueryLimpo)+6)* sizeof(char));
    sprintf(nomes->outputPathFileQuerySvg,"%s%s-%s.svg", outputPath,inputFileLimpo, inputQueryLimpo);

    free(inputPath);
	free(inputFile);
    free(inputFileLimpo);
	free(inputQuery);
    free(inputQueryLimpo);
	free(outputPath);
}