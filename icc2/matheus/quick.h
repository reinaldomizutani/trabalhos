#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

//=========================================================================================//
//Ordenação do Quicksort pelo meio, aleatório, mediana de 3 //POR POPULACAO
void quickSortPivoMeioPop( no* paises ,int ini,int fim,int* cont );
int particionaPivoMeioPop( no *paises, int ini, int fim,int* cont );
void quickSortPivoAleatorioPop( no* paises ,int ini,int fim,int* cont);
int particionaPivoAleatorioPop( no *paises, int ini, int fim,int* cont );
void quickSortPivoMedianaPop( no* paises ,int ini,int fim,int* cont );
int particionaPivoMedianaPop( no *paises, int ini, int fim,int* cont );
				//POR AREA
void quickSortPivoMeioArea( no* paises ,int ini,int fim,int* cont );
int particionaPivoMeioArea( no *paises, int ini, int fim,int* cont );
void quickSortPivoAleatorioArea( no* paises ,int ini,int fim,int* cont );
int particionaPivoAleatorioArea( no *paises, int ini, int fim,int* cont );
void quickSortPivoMedianaArea( no* paises ,int ini,int fim,int* cont );
int particionaPivoMedianaArea( no *paises, int ini, int fim,int* cont );
				//POR NOME
void quickSortPivoMeioNome( no* paises ,int ini,int fim,int* cont );
int particionaPivoMeioNome( no *paises, int ini, int fim,int* cont );
void quickSortPivoAleatorioNome( no* paises ,int ini,int fim,int* cont );
int particionaPivoAleatorioNome( no *paises, int ini, int fim,int* cont );
void quickSortPivoMedianaNome( no* paises ,int ini,int fim,int* cont );
int particionaPivoMedianaNome( no *paises, int ini, int fim,int* cont );
				//POR GDP (para buscar interpolada)
				
void quickSortPivoMeioGdp( no* paises ,int ini,int fim,int* cont );
int particionaPivoMeioGdp( no *paises, int ini, int fim,int* cont );
