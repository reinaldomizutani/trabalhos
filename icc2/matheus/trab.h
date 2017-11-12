#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

typedef struct{
	char pais[30];
	long area, gdp, pop;
} no;

//=========================================================================================//
//Pesquisa População/Area/Nome do pais sequencialmente. Retorna indice caso encontrou ou -1 se nao encontrar.
int buscaSequencialPop(no paises[],long chavePop, int tam, int* cont);
int buscaSequencialArea(no paises[],long chaveArea, int tam, int* cont);
int buscaSequencialNome(no paises[],char chaveNome[], int tam, int* cont);

//=========================================================================================//
//Pesquisa binaria de População/Area/Nome. Retorna indice caso encontrar ou -1 se não encontrar.
int buscaBinariaPop(no paises[],long chavePop, int ini, int fim,int* cont);
int buscaBinariaArea(no paises[],long chaveArea, int ini, int fim,int* cont);
int buscaBinariaNome(no paises[],char chaveNome[], int ini, int fim,int* cont);

//=========================================================================================//
//Pesquisa interpolada de População/Area/Nome. Retorna indice caso encontrar ou -1 se não encontrar.
int buscaInterpolaPop(no paises[],long chavePop, int ini, int fim,int* cont);
int buscaInterpolaArea(no paises[],long chaveArea, int ini, int fim,int* cont);
//int buscaInterpolaNome(no paises[],char chaveNome[], int ini, int fim);
int buscaInterpolaGdp(no paises[],long chaveGdp, int ini, int fim,int* cont);
