#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

typedef struct{
	char pais[30];
	long area, gdp, pop;
} no;

//FUNÇÕES HEAPSORT
void heapArea(no *paises, int tam, int *cont);
void heapifyArea(no *paises, int raiz, int fundo, int *cont);
void heapPop(no *paises, int tam, int *cont);
void heapifyPop(no *paises, int raiz, int fundo, int *cont);
void heapGdp(no *paises, int tam, int *cont);
void heapifyGdp(no *paises, int raiz, int fundo, int *cont);
void heapNome(no *paises, int tam, int *cont);
void heapifyNome(no *paises, int raiz, int fundo, int *cont);

//FUNCOES BUSCA SEQUENCIAL
int buscaSequencialPop(no paises[],long chavePop, int tam, int* cont);
int buscaSequencialArea(no paises[],long chaveArea, int tam, int* cont);
int buscaSequencialNome(no paises[],char chaveNome[], int tam, int* cont);

//FUNCOES BUSCA BINARIA
int buscaBinariaPop(no paises[],long chavePop, int ini, int fim,int* cont);
int buscaBinariaArea(no paises[],long chaveArea, int ini, int fim,int* cont);
int buscaBinariaNome(no paises[],char chaveNome[], int ini, int fim,int* cont);

//FUNCOES BUSCA POR INTERPOLACAO
int buscaInterpolaPop(no paises[],long chavePop, int ini, int fim,int* cont);
int buscaInterpolaArea(no paises[],long chaveArea, int ini, int fim,int* cont);
//int buscaInterpolaNome(no paises[],char chaveNome[], int ini, int fim);
int buscaInterpolaGdp(no paises[],long chaveGdp, int ini, int fim,int* cont);




void csortGdp(no *paises, int tam, int *cont);