#include "quick.h"

//=========================================================================================//
//Ordenação do Quicksort pelo meio, aleatório, mediana de 3
//POPULACO=============//
void quickSortPivoMeioPop( no* paises ,int ini,int fim,int* cont ){
   int pivo;
   *cont++;
   if (ini<fim) {
      *cont+=5;
      pivo = particionaPivoMeioPop(paises, ini, fim,cont);
      quickSortPivoMeioPop(paises, ini, pivo,cont);
      quickSortPivoMeioPop(paises, pivo+1, fim,cont);
   }
   *cont++;
}
int particionaPivoMeioPop( no *paises, int ini, int fim,int* cont ){
   long aux, troca;
   int i,j;
   
   aux = paises[(ini+fim)/2].pop;
   i = ini - 1;
   j = fim + 1;
   *cont+=7;
   
	for(;;){
		do{ 
		  	j--; 
		  	*cont+=2;
		}while( paises[j].pop > aux );
   		do{
			i++;
			*cont+=2;
		} while( paises[i].pop < aux );
      
      if (i < j)  {
         troca = paises[i].pop;
         paises[i].pop = paises[j].pop;
         paises[j].pop = troca;
         *cont+=4;
   		}else{
   			*cont++;
			return j;
  		}
	}
}	

void quickSortPivoAleatorioPop( no* paises ,int ini,int fim,int* cont ){
   int pivo;
   *cont++;
   if (ini<fim) {
      *cont+=5;
      pivo = particionaPivoAleatorioPop(paises, ini, fim, cont);
      quickSortPivoAleatorioPop(paises, ini, pivo,cont);
      quickSortPivoAleatorioPop(paises, pivo+1, fim,cont);
   }
   
   *cont++;
}
int particionaPivoAleatorioPop( no *paises, int ini, int fim,int* cont ){
   long aux, troca;
   int i,j;
   
   aux = paises[ini+rand()%(fim-ini)].pop;
   i = ini - 1;
   j = fim + 1;
      *cont+=9;
      
	for(;;){
		do{ 
		   *cont+=2;
		  	j--; 
		}while( paises[j].pop > aux );
   		do{
   			*cont+=2;
			i++;
		} while( paises[i].pop < aux );
      
      if (i < j)  {
         troca = paises[i].pop;
         paises[i].pop = paises[j].pop;
         paises[j].pop = troca;
   		   *cont+=4;
		}else{
			cont++;
			return j;
  		}
	}
}	

void quickSortPivoMedianaPop( no* paises ,int ini,int fim,int* cont ){
   int pivo;
   	*cont++;
   if (ini<fim) {
      *cont+=5;
	  pivo = particionaPivoMedianaPop(paises, ini, fim,cont);
      quickSortPivoMedianaPop(paises, ini, pivo,cont);
      quickSortPivoMedianaPop(paises, pivo+1, fim,cont);
   }
   
   *cont++;
}
int particionaPivoMedianaPop( no *paises, int ini, int fim,int* cont){
   long aux, troca;
   int i,j, indice1, indice2, indice3, indicefinal;
   
   indice1 = ini+rand()%(fim-ini);
   indice2 = ini+rand()%(fim-ini);
   indice3 = ini+rand()%(fim-ini);
   indicefinal = (indice1+indice2+indice3)/3;
   *cont+=5*3 + 4;
   
   aux = paises[indicefinal].pop;
   i = ini - 1;
   j = fim + 1;
   *cont+=5;
   
	for(;;){
		do{ 
		   *cont+=2;
		  	j--; 
		}while( paises[j].pop > aux );
   		do{
   			*cont+=2;
			i++;
		} while( paises[i].pop < aux );
      
      if (i < j)  {
         troca = paises[i].pop;
         paises[i].pop = paises[j].pop;
         paises[j].pop = troca;
          *cont+=4;
   		}else{
   			 *cont+=1;
			return j;
  		}
	}
}	

//AREA=============//
void quickSortPivoMeioArea( no* paises ,int ini,int fim,int* cont ){
   int pivo;
   *cont++;
   if (ini<fim) {
      *cont+=5;
	  pivo = particionaPivoMeioArea(paises, ini, fim, cont);
      quickSortPivoMeioArea(paises, ini, pivo, cont);
      quickSortPivoMeioArea(paises, pivo+1, fim, cont);
   }
   
   *cont++;
}
int particionaPivoMeioArea( no *paises, int ini, int fim, int* cont ){
  long aux, troca;
   int i,j;
   
   aux = paises[(ini+fim)/2].area;
   i = ini - 1;
   j = fim + 1;
   *cont+=7;
   
	for(;;){
		do{ 
		  	j--; 
		  	*cont+=2;
		}while( paises[j].area > aux );
   		do{
			i++;
			*cont+=2;
		} while( paises[i].area < aux );
      
      if (i < j)  {
         troca = paises[i].area;
         paises[i].area = paises[j].area;
         paises[j].area = troca;
         *cont+=4;
   		}else{
   			*cont++;
			return j;
  		}
	}
}	

void quickSortPivoAleatorioArea( no* paises ,int ini,int fim, int* cont ){
   int pivo;
   *cont++;
   if (ini<fim) {
   		*cont+=5;
      pivo = particionaPivoAleatorioArea(paises, ini, fim, cont);
      quickSortPivoAleatorioArea(paises, ini, pivo, cont);
      quickSortPivoAleatorioArea(paises, pivo+1, fim, cont);
   }
   *cont++;
}
int particionaPivoAleatorioArea( no *paises, int ini, int fim, int* cont ){
 long aux, troca;
   int i,j;
   
   aux = paises[ini+rand()%(fim-ini)].area;
   i = ini - 1;
   j = fim + 1;
      *cont+=9;
      
	for(;;){
		do{ 
		   *cont+=2;
		  	j--; 
		}while( paises[j].area > aux );
   		do{
   			*cont+=2;
			i++;
		} while( paises[i].area < aux );
      
      if (i < j)  {
         troca = paises[i].area;
         paises[i].area = paises[j].area;
         paises[j].area = troca;
   		   *cont+=4;
		}else{
			cont++;
			return j;
  		}
	}
}	


void quickSortPivoMedianaArea( no* paises ,int ini,int fim, int* cont ){
   int pivo;
   *cont++;
   if (ini<fim) {
      *cont+=5;
	  pivo = particionaPivoMedianaArea(paises, ini, fim, cont);
      quickSortPivoMedianaArea(paises, ini, pivo, cont);
      quickSortPivoMedianaArea(paises, pivo+1, fim, cont);
   }
   *cont++;
}
int particionaPivoMedianaArea( no *paises, int ini, int fim, int* cont ){
  long aux, troca;
   int i,j, indice1, indice2, indice3, indicefinal;
   
   indice1 = ini+rand()%(fim-ini);
   indice2 = ini+rand()%(fim-ini);
   indice3 = ini+rand()%(fim-ini);
   indicefinal = (indice1+indice2+indice3)/3;
   *cont+=5*3 + 4;
   
   aux = paises[indicefinal].area;
   i = ini - 1;
   j = fim + 1;
   *cont+=5;
   
	for(;;){
		do{ 
		   *cont+=2;
		  	j--; 
		}while( paises[j].area > aux );
   		do{
   			*cont+=2;
			i++;
		} while( paises[i].area < aux );
      
      if (i < j)  {
         troca = paises[i].area;
         paises[i].area = paises[j].area;
         paises[j].area = troca;
          *cont+=4;
   		}else{
   			 *cont+=1;
			return j;
  		}
	}
}	

//NOME=============//
void quickSortPivoMeioNome( no* paises ,int ini,int fim,int* cont ){
   int pivo;
   *cont++;
   if (ini<fim) {
   	*cont+=5;
      pivo = particionaPivoMeioNome(paises, ini, fim, cont);
      quickSortPivoMeioNome(paises, ini, pivo, cont);
      quickSortPivoMeioNome(paises, pivo+1, fim, cont);
   }
   
   *cont++;
}
int particionaPivoMeioNome( no *paises, int ini, int fim,int* cont ){
   char nome[30],aux[30], troca[30];
   int i,j;
   
   strcpy(aux,paises[(ini+fim)/2].pais);
   i = ini - 1;
   j = fim + 1;
   *cont+=7;
   
	for(;;){
		while((strcmp(paises[ini].pais,aux) > 0)&&(j>fim)){ 
			*cont+=5;
		  	j--; 
		}
   		 while((strcmp(paises[ini].pais,aux) < 0 )&&(i<ini)){
   		 	*cont+=5;
			i++;
		}
      
      if (i <= j)  {
         strcpy(troca,paises[i].pais);
         strcpy(paises[i].pais,paises[j].pais);
         strcpy(paises[j].pais,troca);
         i++;
         j--;
         
		*cont+=6;
   		}else{
   			*cont++;
			return j;
  		}
	}
}	

void quickSortPivoAleatorioNome( no* paises ,int ini,int fim,int* cont ){
   int pivo;
   *cont++;
   if (ini<fim) {
   	*cont+=5;
      pivo = particionaPivoAleatorioNome(paises, ini, fim, cont);
      quickSortPivoAleatorioNome(paises, ini, pivo, cont);
      quickSortPivoAleatorioNome(paises, pivo+1, fim, cont);
   }
   
   *cont++;
}
int particionaPivoAleatorioNome( no *paises, int ini, int fim,int* cont ){
   char nome[30],aux[30],troca[30];
   int i,j, indice;
   
   indice = ini+rand()%(fim-ini);
   strcpy(aux,paises[indice].pais);
   i = ini - 1;
   j = fim + 1;
 	 *cont+=10;
   
	for(;;){
		while((strcmp(paises[ini].pais,aux) > 0)&&(j>fim)){ 
			*cont+=5;
		  	j--; 
		}
   		 while((strcmp(paises[ini].pais,aux) < 0 )&&(i<ini)){
   		 	*cont+=5;
			i++;
		}
      
      if (i <= j)  {
         strcpy(troca,paises[i].pais);
         strcpy(paises[i].pais,paises[j].pais);
         strcpy(paises[j].pais,troca);
         i++;
         j--;
         
		*cont+=6;
   		}else{
   			*cont++;
			return j;
  		}
	}
}	

void quickSortPivoMedianaNome( no* paises ,int ini,int fim,int* cont ){
   int pivo;
   *cont++;
   if (ini<fim) {
      *cont+=5;
	  pivo = particionaPivoMedianaNome(paises, ini, fim, cont);
      quickSortPivoMedianaNome(paises, ini, pivo, cont);
      quickSortPivoMedianaNome(paises, pivo+1, fim,cont);
   }
   
   *cont++;
}
int particionaPivoMedianaNome( no *paises, int ini, int fim,int* cont ){
   char nome[30],aux[30], troca[30];
   int i,j;
   int indice1, indice2, indice3, indicefinal;
   
	indice1 = ini+rand()%(fim-ini);
	indice2 = ini+rand()%(fim-ini);
	indice3 = ini+rand()%(fim-ini);
	indicefinal = (indice1+indice2+indice3)/3;
   
   strcpy(aux,paises[indicefinal].pais);
    i = ini - 1;
   	j = fim + 1;
   	
  *cont+=5*3 + 4 + 1 + 4;
   
	for(;;){
		while((strcmp(paises[ini].pais,aux) > 0)&&(j>fim)){ 
			*cont+=5;
		  	j--; 
		}
   		 while((strcmp(paises[ini].pais,aux) < 0 )&&(i<ini)){
   		 	*cont+=5;
			i++;
		}
      
      if (i <= j)  {
         strcpy(troca,paises[i].pais);
         strcpy(paises[i].pais,paises[j].pais);
         strcpy(paises[j].pais,troca);
         i++;
         j--;
         
		*cont+=6;
   		}else{
   			*cont++;
			return j;
  		}
	}
}	

//GDP=============//
void quickSortPivoMeioGdp( no* paises ,int ini,int fim,int* cont ){
   int pivo;
   *cont++;
   if (ini<fim) {
      *cont+=5;
	  pivo = particionaPivoMeioGdp(paises, ini, fim,cont);
      quickSortPivoMeioGdp(paises, ini, pivo,cont);
      quickSortPivoMeioGdp(paises, pivo+1, fim,cont);
   }
   
   *cont++;
}
int particionaPivoMeioGdp( no *paises, int ini, int fim, int* cont ){
   long aux, troca;
   int i,j;
   
   aux = paises[(ini+fim)/2].gdp;
   i = ini - 1;
   j = fim + 1;
    *cont+=7;
   
	for(;;){
		do{ 
		  	j--; 
		  	*cont+=2;
		}while( paises[j].gdp > aux );
   		do{
			i++;
			*cont+=2;
		} while( paises[i].gdp < aux );
      
      if (i < j)  {
         troca = paises[i].gdp;
         paises[i].gdp = paises[j].gdp;
         paises[j].gdp = troca;
         *cont+=4;
   		}else{
   			*cont++;
			return j;
  		}
	}
} 