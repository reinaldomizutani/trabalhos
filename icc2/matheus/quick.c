#include "quick.h"

//=========================================================================================//
//Ordenação do Quicksort pelo meio, aleatório, mediana de 3
//POPULACO=============//
void quickSortPivoMeioPop( no* paises ,int ini,int fim ){
   int pivo;
   if (ini<fim) {
      pivo = particionaPivoMeioPop(paises, ini, fim);
      quickSortPivoMeioPop(paises, ini, pivo);
      quickSortPivoMeioPop(paises, pivo+1, fim);
   }
}
int particionaPivoMeioPop( no *paises, int ini, int fim ){
   long aux, troca;
   int i,j;
   
   aux = paises[ini].pop;
   i = ini - 1;
   j = fim + 1;
   
	for(;;){
		do{ 
		  	j--; 
		}while( paises[j].pop > aux );
   		do{
			i++;
		} while( paises[i].pop < aux );
      
      if (i < j)  {
         troca = paises[i].pop;
         paises[i].pop = paises[j].pop;
         paises[j].pop = troca;
   		}else{
			return j;
  		}
	}
}	

void quickSortPivoAleatorioPop( no* paises ,int ini,int fim ){
   int pivo;
   if (ini<fim) {
      pivo = particionaPivoAleatorioPop(paises, ini, fim);
      quickSortPivoAleatorioPop(paises, ini, pivo);
      quickSortPivoAleatorioPop(paises, pivo+1, fim);
   }
}
int particionaPivoAleatorioPop( no *paises, int ini, int fim ){
   long aux, troca;
   int i,j;
   
   aux = paises[ini+rand()%(fim-ini)].pop;
   i = ini - 1;
   j = fim + 1;
   
	for(;;){
		do{ 
		  	j--; 
		}while( paises[j].pop > aux );
   		do{
			i++;
		} while( paises[i].pop < aux );
      
      if (i < j)  {
         troca = paises[i].pop;
         paises[i].pop = paises[j].pop;
         paises[j].pop = troca;
   		}else{
			return j;
  		}
	}
}	

void quickSortPivoMedianaPop( no* paises ,int ini,int fim ){
   int pivo;
   if (ini<fim) {
      pivo = particionaPivoMedianaPop(paises, ini, fim);
      quickSortPivoMedianaPop(paises, ini, pivo);
      quickSortPivoMedianaPop(paises, pivo+1, fim);
   }
}
int particionaPivoMedianaPop( no *paises, int ini, int fim ){
   long aux, troca;
   int i,j, indice1, indice2, indice3, indicefinal;
   
   indice1 = ini+rand()%(fim-ini);
   indice2 = ini+rand()%(fim-ini);
   indice3 = ini+rand()%(fim-ini);
   indicefinal = (indice1+indice2+indice3)/3;
   
   aux = paises[indicefinal].pop;
   i = ini - 1;
   j = fim + 1;
   
	for(;;){
		do{ 
		  	j--; 
		}while( paises[j].pop > aux );
   		do{
			i++;
		} while( paises[i].pop < aux );
      
      if (i < j)  {
         troca = paises[i].pop;
         paises[i].pop = paises[j].pop;
         paises[j].pop = troca;
   		}else{
			return j;
  		}
	}
}	

//AREA=============//
void quickSortPivoMeioArea( no* paises ,int ini,int fim ){
   int pivo;
   if (ini<fim) {
      pivo = particionaPivoMeioArea(paises, ini, fim);
      quickSortPivoMeioArea(paises, ini, pivo);
      quickSortPivoMeioArea(paises, pivo+1, fim);
   }
}
int particionaPivoMeioArea( no *paises, int ini, int fim ){
   long aux, troca;
   int i,j;
   
   aux = paises[ini].area;
   i = ini - 1;
   j = fim + 1;
   
	for(;;){
		do{ 
		  	j--; 
		}while( paises[j].area > aux );
   		do{
			i++;
		} while( paises[i].area < aux );
      
      if (i < j)  {
         troca = paises[i].area;
         paises[i].area = paises[j].area;
         paises[j].area = troca;
   		}else{
			return j;
  		}
	}
}	

void quickSortPivoAleatorioArea( no* paises ,int ini,int fim ){
   int pivo;
   if (ini<fim) {
      pivo = particionaPivoAleatorioArea(paises, ini, fim);
      quickSortPivoAleatorioArea(paises, ini, pivo);
      quickSortPivoAleatorioArea(paises, pivo+1, fim);
   }
}
int particionaPivoAleatorioArea( no *paises, int ini, int fim ){
   long aux, troca;
   int i,j;
   
   aux = paises[ini+rand()%(fim-ini)].area;
   i = ini - 1;
   j = fim + 1;
   
	for(;;){
		do{ 
		  	j--; 
		}while( paises[j].area > aux );
   		do{
			i++;
		} while( paises[i].area < aux );
      
      if (i < j)  {
         troca = paises[i].area;
         paises[i].area = paises[j].area;
         paises[j].area = troca;
   		}else{
			return j;
  		}
	}
}	

void quickSortPivoMedianaArea( no* paises ,int ini,int fim ){
   int pivo;
   if (ini<fim) {
      pivo = particionaPivoMedianaArea(paises, ini, fim);
      quickSortPivoMedianaArea(paises, ini, pivo);
      quickSortPivoMedianaArea(paises, pivo+1, fim);
   }
}
int particionaPivoMedianaArea( no *paises, int ini, int fim ){
   long aux, troca;
   int i,j, indice1, indice2, indice3, indicefinal;
   
   indice1 = ini+rand()%(fim-ini);
   indice2 = ini+rand()%(fim-ini);
   indice3 = ini+rand()%(fim-ini);
   indicefinal = (indice1+indice2+indice3)/3;
   
   aux = paises[indicefinal].area;
   i = ini - 1;
   j = fim + 1;
   
	for(;;){
		do{ 
		  	j--; 
		}while( paises[j].area > aux );
   		do{
			i++;
		} while( paises[i].area < aux );
      
      if (i < j)  {
         troca = paises[i].area;
         paises[i].area = paises[j].area;
         paises[j].area = troca;
   		}else{
			return j;
  		}
	}
}	

//NOME=============//
void quickSortPivoMeioNome( no* paises ,int ini,int fim ){
   int pivo;
   if (ini<fim) {
      pivo = particionaPivoMeioNome(paises, ini, fim);
      quickSortPivoMeioNome(paises, ini, pivo);
      quickSortPivoMeioNome(paises, pivo+1, fim);
   }
}
int particionaPivoMeioNome( no *paises, int ini, int fim ){
   char nome[30],aux[30];
   int i,j;
   
   strcpy(aux,paises[ini].pais);
   i = ini - 1;
   j = fim + 1;
   
	for(;;){
		do{ 
		  	j--; 
		}while(strcmp(paises[ini].pais,aux) > 0);
   		do{
			i++;
		} while(strcmp(paises[ini].pais,aux) < 0 );
      
      if (i < j)  {
         strcpy(aux,paises[i].pais);
         strcpy(paises[i].pais,paises[j].pais);
         strcpy(paises[j].pais,aux);
   		}else{
			return j;
  		}
	}
}	

void quickSortPivoAleatorioNome( no* paises ,int ini,int fim ){
   int pivo;
   if (ini<fim) {
      pivo = particionaPivoAleatorioNome(paises, ini, fim);
      quickSortPivoAleatorioNome(paises, ini, pivo);
      quickSortPivoAleatorioNome(paises, pivo+1, fim);
   }
}
int particionaPivoAleatorioNome( no *paises, int ini, int fim ){
   char nome[30],aux[30];
   int i,j, indice;
   
   indice = ini+rand()%(fim-ini);
   strcpy(aux,paises[indice].pais);
   i = ini - 1;
   j = fim + 1;
   
	for(;;){
		do{ 
		  	j--; 
		}while(strcmp(paises[ini].pais,aux) > 0);
   		do{
			i++;
		} while(strcmp(paises[ini].pais,aux) < 0 );
      
      if (i < j)  {
         strcpy(aux,paises[i].pais);
         strcpy(paises[i].pais,paises[j].pais);
         strcpy(paises[j].pais,aux);
   		}else{
			return j;
  		}
	}
}	

void quickSortPivoMedianaNome( no* paises ,int ini,int fim ){
   int pivo;
   if (ini<fim) {
      pivo = particionaPivoMedianaNome(paises, ini, fim);
      quickSortPivoMedianaNome(paises, ini, pivo);
      quickSortPivoMedianaNome(paises, pivo+1, fim);
   }
}
int particionaPivoMedianaNome( no *paises, int ini, int fim ){
   char nome[30],aux[30];
   int i,j;
   int indice1, indice2, indice3, indicefinal;
   
	indice1 = ini+rand()%(fim-ini);
	indice2 = ini+rand()%(fim-ini);
	indice3 = ini+rand()%(fim-ini);
	indicefinal = (indice1+indice2+indice3)/3;
   
   strcpy(aux,paises[indicefinal].pais);
   i = ini - 1;
   j = fim + 1;
   
	for(;;){
		do{ 
		  	j--; 
		}while(strcmp(paises[ini].pais,aux) > 0);
   		do{
			i++;
		} while(strcmp(paises[ini].pais,aux) < 0 );
      
      if (i < j)  {
         strcpy(aux,paises[i].pais);
         strcpy(paises[i].pais,paises[j].pais);
         strcpy(paises[j].pais,aux);
   		}else{
			return j;
  		}
	}
}	

//GDP=============//
void quickSortPivoMeioGdp( no* paises ,int ini,int fim ){
   int pivo;
   if (ini<fim) {
      pivo = particionaPivoMeioGdp(paises, ini, fim);
      quickSortPivoMeioGdp(paises, ini, pivo);
      quickSortPivoMeioGdp(paises, pivo+1, fim);
   }
}
int particionaPivoMeioGdp( no *paises, int ini, int fim ){
   long aux, troca;
   int i,j;
   
   aux = paises[ini].gdp;
   i = ini - 1;
   j = fim + 1;
   
	for(;;){
		do{ 
		  	j--; 
		}while( paises[j].gdp > aux );
   		do{
			i++;
		} while( paises[i].gdp < aux );
      
      if (i < j)  {
         troca = paises[i].gdp;
         paises[i].gdp = paises[j].gdp;
         paises[j].gdp = troca;
   		}else{
			return j;
  		}
	}
}	

