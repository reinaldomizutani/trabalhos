#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

typedef struct{
	char pais[30];
	long area, gdp, pop;
} no;

//=========================================================================================//
//Pesquisa Popula��o/Area/Nome do pais sequencialmente. Retorna indice caso encontrou ou -1 se nao encontrar.
int buscaSequencialPop(no paises[],long chavePop, int tam);
int buscaSequencialArea(no paises[],long chaveArea, int tam);
int buscaSequencialNome(no paises[],char chaveNome[], int tam);

//=========================================================================================//
//Pesquisa binaria de Popula��o/Area/Nome. Retorna indice caso encontrar ou -1 se n�o encontrar.
int buscaBinariaPop(no paises[],long chavePop, int ini, int fim);
int buscaBinariaArea(no paises[],long chaveArea, int ini, int fim);
int buscaBinariaNome(no paises[],char chaveNome[], int ini, int fim);

//=========================================================================================//
//Pesquisa interpolada de Popula��o/Area/Nome. Retorna indice caso encontrar ou -1 se n�o encontrar.
int buscaInterpolaPop(no paises[],long chavePop, int ini, int fim);
int buscaInterpolaArea(no paises[],long chaveArea, int ini, int fim);
//int buscaInterpolaNome(no paises[],char chaveNome[], int ini, int fim);

