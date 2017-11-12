#include "trab.h"
/*
typedef struct{
	char pais[30];
	long area, gdp, pop;
} no;
*/

void heapArea(no *paises, int tam){
	int i;
	no aux;
	for(i = (tam/2) ; i>=0 ; i--){
		heapifyArea(paises, i, tam-1);
	}
	for(i = tam-1 ; i>=1 ; i--){
		aux.pop = paises[0].pop;
		aux.gdp = paises[0].gdp;
		aux.area = paises[0].area;
		strcpy(aux.pais, paises[0].pais);

		paises[0].pop = paises[i].pop;
		paises[0].gdp = paises[i].gdp;
		paises[0].area = paises[i].area;
		strcpy(paises[0].pais, paises[i].pais);

		paises[i].pop = aux.pop;
		paises[i].gdp = aux.gdp;
		paises[i].area = aux.area;
		strcpy(paises[i].pais, aux.pais);

		heapifyArea(paises, 0, i-1);
	}
}

void heapifyArea(no *paises, int raiz, int fundo){
	int rdy, filhoMax;
	no aux;
	rdy = 0;
	while((raiz*2) <= fundo && (!rdy)) {
		if(raiz*2 == fundo){
			filhoMax = raiz*2;
		}
		else if(paises[raiz*2].area > paises[raiz*2+1].area){
			filhoMax = raiz*2;
		}
		else{
			filhoMax = raiz*2 + 1;
		}

		if(paises[raiz].area < paises[filhoMax].area){
			aux.pop = paises[raiz].pop;
			aux.gdp = paises[raiz].gdp;
			aux.area = paises[raiz].area;
			strcpy(aux.pais, paises[raiz].pais);

			paises[raiz].pop = paises[filhoMax].pop;
			paises[raiz].gdp = paises[filhoMax].gdp;
			paises[raiz].area = paises[filhoMax].area;
			strcpy(paises[raiz].pais, paises[filhoMax].pais);
			
			paises[filhoMax].pop = aux.pop;
			paises[filhoMax].gdp = aux.gdp;
			paises[filhoMax].area = aux.area;
			strcpy(paises[filhoMax].pais, paises[raiz].pais);

			raiz = filhoMax;
		}
		else{
			rdy=1;
		}
	}
}