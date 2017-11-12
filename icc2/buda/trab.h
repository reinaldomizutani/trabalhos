#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>



typedef struct{
	char pais[30];
	long area, gdp, pop;
} no;

void heapArea(no *paises, int tam, int *cont);
void heapifyArea(no *paises, int raiz, int fundo, int *cont);

void heapPop(no *paises, int tam, int *cont);
void heapifyPop(no *paises, int raiz, int fundo, int *cont);

void heapGdp(no *paises, int tam, int *cont);
void heapifyGdp(no *paises, int raiz, int fundo, int *cont);
