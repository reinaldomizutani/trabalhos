#include<stdio.h>
#include<stdlib.h>
#include<string.h>



typedef struct{
	char pais[30];
	long area, gdp, pop;
} no;

void heapArea(no *paises, int tam);
void heapifyArea(no *paises, int raiz, int fundo);