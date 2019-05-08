#ifndef FUNCOES_H
#define FUNCOES_H

//LEITURA
void leituraC();
void leituraR();
void leituraT();
void leituraGeo();
void leituraQuery();
int procuraNx();

//ESCRITA
void escreverSvgCircle();
void escreverSvgRect();
void escreverSvgTexto();
void escreverFigQry();
void escritaElipse();
void escritaBb();

//CRIAR
void abrirSVG();

//DESALOCAR
void freeNosMalloc();

//QRY
void distCentro();
double clamp();
void sobrep();
void pontoIntR();
void pontoIntC();
void creatingFile();
void boundingBoxCircle();
void elipseRect();
void verificaBb();

//Vetor de struct pra armazenar circulos e retangulos
typedef struct{
    char t[1];
    char stroke[10], fill[10];
    double cx, cy, r;
    double width, height;
}Figura;


//Struct com strings com nomes dos arquivos
typedef struct{
    char *inputQuery;
    char *inputFileLimpo; //sem extensão
    char *inputQueryLimpo; //sem extensão p/ concatenar c o strcat(outputPath, inputFileLimpo) **N esquecer do hifen
    char *inputPathFile; //strcat(inputPath, inputFile) -> abrir geo
    char *inputPathQuery;//strcat(inputPath, inputQuery)
    char *outputPathFileLimpo; //strcat(inputPath, inputFileLimpo)
    char *outputPathFileQueryLimpo; // for example: "blabla/arq-arqcons"
    char *outputPath; 
    char *outputPathFileSvg;
    char *outputPathFileQueryTxt;
    char *outputPathFileQuerySuf;
    char *outputPathFileQuerySvg;
}Name;

#endif