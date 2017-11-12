#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

//=========================================================================================//
//Ordenação do Quicksort pelo meio, aleatório, mediana de 3 //POR POPULACAO
void quickSortPivoMeioPop( no* paises ,int ini,int fim );
int particionaPivoMeioPop( no *paises, int ini, int fim );
void quickSortPivoAleatorioPop( no* paises ,int ini,int fim );
int particionaPivoAleatorioPop( no *paises, int ini, int fim );
void quickSortPivoMedianaPop( no* paises ,int ini,int fim );
int particionaPivoMedianaPop( no *paises, int ini, int fim );
				//POR AREA
void quickSortPivoMeioArea( no* paises ,int ini,int fim );
int particionaPivoMeioArea( no *paises, int ini, int fim );
void quickSortPivoAleatorioArea( no* paises ,int ini,int fim );
int particionaPivoAleatorioArea( no *paises, int ini, int fim );
void quickSortPivoMedianaArea( no* paises ,int ini,int fim );
int particionaPivoMedianaArea( no *paises, int ini, int fim );
				//POR NOME
void quickSortPivoMeioNome( no* paises ,int ini,int fim );
int particionaPivoMeioNome( no *paises, int ini, int fim );
void quickSortPivoAleatorioNome( no* paises ,int ini,int fim );
int particionaPivoAleatorioNome( no *paises, int ini, int fim );
void quickSortPivoMedianaNome( no* paises ,int ini,int fim );
int particionaPivoMedianaNome( no *paises, int ini, int fim );
				//POR GDP (para buscar interpolada)
				
void quickSortPivoMeioGdp( no* paises ,int ini,int fim );
int particionaPivoMeioGdp( no *paises, int ini, int fim );
