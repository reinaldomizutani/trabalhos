#include "trab.h"


//--------------------------------------------------------------------
// FUNCOES HEAP SORT
//--------------------------------------------------------------------

void heapArea(no *paises, int tam, int *cont){
	int i;
	no aux;
	for(i = (tam/2) ; i>=0 ; i--){
		heapifyArea(paises, i, tam-1, cont);
		*cont = *cont+1;
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

		*cont = *cont+13;

		heapifyArea(paises, 0, i-1, cont);
	}
}
void heapifyArea(no *paises, int raiz, int fundo, int *cont){
	int rdy, filhoMax;
	no aux;
	rdy = 0;
	while((raiz*2) <= fundo && (!rdy)) {
		if(raiz*2 == fundo){
			filhoMax = raiz*2;
			*cont = *cont + 1;
		}
		else if(paises[raiz*2].area > paises[raiz*2+1].area){
			filhoMax = raiz*2;
			*cont = *cont + 1;
		}
		else{
			filhoMax = raiz*2 + 1;
			*cont = *cont + 1;
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
			
			*cont = *cont + 13;

			raiz = filhoMax;
		}
		else{
			*cont = *cont + 1;
			rdy=1;
		}
	}
}
void heapPop(no *paises, int tam, int *cont){
	int i;
	no aux;
	for(i = (tam/2) ; i>=0 ; i--){
		heapifyPop(paises, i, tam-1, cont);
		*cont = *cont+1;
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

		*cont = *cont+13;

		heapifyPop(paises, 0, i-1, cont);
	}
}
void heapifyPop(no *paises, int raiz, int fundo, int *cont){
	int rdy, filhoMax;
	no aux;
	rdy = 0;
	while((raiz*2) <= fundo && (!rdy)) {
		if(raiz*2 == fundo){
			filhoMax = raiz*2;
			*cont = *cont + 1;
		}
		else if(paises[raiz*2].pop > paises[raiz*2+1].pop){
			filhoMax = raiz*2;
			*cont = *cont + 1;
		}
		else{
			filhoMax = raiz*2 + 1;
			*cont = *cont + 1;
		}

		if(paises[raiz].pop < paises[filhoMax].pop){
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
			
			*cont = *cont + 13;

			raiz = filhoMax;
		}
		else{
			*cont = *cont + 1;
			rdy=1;
		}
	}
}
void heapGdp(no *paises, int tam, int *cont){
	int i;
	no aux;
	for(i = (tam/2) ; i>=0 ; i--){
		heapifyGdp(paises, i, tam-1, cont);
		*cont = *cont+1;
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

		*cont = *cont+13;

		heapifyGdp(paises, 0, i-1, cont);
	}
}
void heapifyGdp(no *paises, int raiz, int fundo, int *cont){
	int rdy, filhoMax;
	no aux;
	rdy = 0;
	while((raiz*2) <= fundo && (!rdy)) {
		if(raiz*2 == fundo){
			filhoMax = raiz*2;
			*cont = *cont + 1;
		}
		else if(paises[raiz*2].gdp > paises[raiz*2+1].gdp){
			filhoMax = raiz*2;
			*cont = *cont + 1;
		}
		else{
			filhoMax = raiz*2 + 1;
			*cont = *cont + 1;
		}

		if(paises[raiz].gdp < paises[filhoMax].gdp){
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
			
			*cont = *cont + 13;

			raiz = filhoMax;
		}
		else{
			*cont = *cont + 1;
			rdy=1;
		}
	}
}
void heapNome(no *paises, int tam, int *cont){
	int i;
	no aux;
	for(i = (tam/2) ; i>=0 ; i--){
		heapifyNome(paises, i, tam-1, cont);
		*cont = *cont+1;
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

		*cont = *cont+13;

		heapifyNome(paises, 0, i-1, cont);
	}
}
void heapifyNome(no *paises, int raiz, int fundo, int *cont){
	int rdy, filhoMax;
	no aux;
	rdy = 0;
	while((raiz*2) <= fundo && (!rdy)) {
		if(raiz*2 == fundo){
			filhoMax = raiz*2;
			*cont = *cont + 1;
		}//		paises[raiz*2].pais							       > 		paises[raiz*2+1].pais
		else if(strcmp(paises[raiz*2].pais, paises[raiz*2+1].pais) > strcmp(paises[raiz*2+1].pais, paises[raiz*2].pais)){
			filhoMax = raiz*2;
			*cont = *cont + 1;
		}
		else{
			filhoMax = raiz*2 + 1;
			*cont = *cont + 1;
		}
		//				paises[raiz].pais 				   <                   paises[filhoMax].pais)
		if(strcmp(paises[raiz].pais, paises[filhoMax].pais) < strcmp(paises[filhoMax].pais, paises[raiz].pais)){
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
			
			*cont = *cont + 13;

			raiz = filhoMax;
		}
		else{
			*cont = *cont + 1;
			rdy=1;
		}
	}
}

//--------------------------------------------------------------------
// FUNCOES BUSCA SEQUENCIAL
//--------------------------------------------------------------------
//Pesquisa População/Area/Nome do pais sequencialmente. Retorna indice caso encontrou ou -1 se nao encontrar.
int buscaSequencialPop(no paises[],long chavePop, int tam, int* cont){
	int i=0;
	*cont = *cont+1;
	
	for(;i<tam;i++){
		if(paises[i].pop == chavePop){
			*cont += i*3+1;
			return i;
		}
	}
	*cont += i*3+1;	
return -1;
}
int buscaSequencialArea(no paises[],long chaveArea, int tam, int* cont){
	int i=0;
	*cont = *cont+1;
	
	for(;i<tam;i++){
		if(paises[i].area == chaveArea){
			*cont += i*3+1;	
			return i;
		}
	}
	*cont += i*3+1;		
return -1;
}
int buscaSequencialNome(no paises[],char chaveNome[], int tam,int* cont){
	int i=0;
	*cont = *cont+1;
	for(;i<tam;i++){
		if(strcmp(paises[i].pais,chaveNome)==0){
			*cont += i*3+1;	
			return i;
		}
	}
	*cont += i*3+1;	
return -1;
}

//--------------------------------------------------------------------
// FUNCOES BUSCA BINARIA
//--------------------------------------------------------------------
//Pesquisa binaria de População/Area/Nome. Retorna indice caso encontrar ou -1 se não encontrar.
int buscaBinariaPop(no paises[],long chavePop, int ini, int fim,int* cont){
	int i;
	*cont+=2;
	i = (ini + fim)/2;
	
	if(paises[i].pop==chavePop){
		*cont+=2;
		return i;
	}else if(ini == fim){
		*cont+=2;
		return -1;
	}
	
	else if(paises[i].pop > chavePop){
		*cont = *cont+3;
		return	buscaBinariaPop(paises,chavePop,ini, i-1,cont);
	}else if(paises[i].pop < chavePop){
		*cont = *cont+3;
		return buscaBinariaPop(paises,chavePop,i+1,fim,cont);
	}
	*cont = *cont+1;
	return -1;
}
int buscaBinariaArea(no paises[],long chaveArea, int ini, int fim,int* cont){
	int i;
	*cont+=2;
	i = (ini + fim)/2;
	
	if(paises[i].area==chaveArea){
		*cont+=2;
		return i;
	}else if(ini == fim){
		*cont+=2;
		return -1;
	}
	
	else if(paises[i].area > chaveArea){
		*cont = *cont+3;
		return	buscaBinariaArea(paises,chaveArea,ini, i-1,cont);
	}else if(paises[i].area < chaveArea){
		*cont = *cont+3;
		return buscaBinariaArea(paises,chaveArea,i+1,fim,cont);
	}
	
	*cont = *cont+1;
	return -1;
}
int buscaBinariaNome(no paises[],char chaveNome[], int ini, int fim,int* cont){
	int i;
	
	i = (ini + fim)/2;
	*cont+=2;
	
	if(strcmp(paises[i].pais,chaveNome)==0){
		*cont+=2;
		return i;
	}else if(ini == fim){
		*cont+=2;
		return -1;
	}
	
	else if(strcmp(paises[i].pais,chaveNome) > 0){
		*cont = *cont+3;
		return	buscaBinariaNome(paises,chaveNome,ini, i-1,cont);
	}else if(strcmp(paises[i].pais,chaveNome) < 0){
		*cont = *cont+3;
		return buscaBinariaNome(paises,chaveNome,i+1,fim,cont);
	}
	
	*cont = *cont+1;
	return -1;
}

//--------------------------------------------------------------------
// FUNCOES BUSCA POR INTERPOLACAO
//--------------------------------------------------------------------
//Pesquia por interpolação por População/Area/Nome
int buscaInterpolaPop(no *paises,long chavePop, int ini, int fim,int* cont){
	int meio;
	
	while(ini<=fim){

		meio = ini + ((fim-ini)*(chavePop-paises[ini].pop) / (paises[fim].pop - paises[ini].pop));
		*cont = *cont+8;
			
		if(chavePop < paises[meio].pop){
			*cont = *cont+3;
			fim = meio-1;
		}else if(chavePop > paises[meio].pop){
			*cont = *cont+3;			
			ini = meio+1;
		}else{
			*cont = *cont+1;
			return meio;
		}
	}
	*cont = *cont+1;
	return -1;
}
int buscaInterpolaArea(no *paises,long chaveArea, int ini, int fim,int* cont){
    int meio;
    
    while(ini <= fim){
    	
        meio = ini + ((fim-ini)*((chaveArea-paises[ini].area) / (paises[fim].area - paises[ini].area)));
        *cont = *cont+8;
        
        if(chaveArea < paises[meio].area){
			*cont = *cont+3;		
            fim = meio - 1;
        }else if(chaveArea > paises[meio].area){
        	*cont = *cont+3;
            ini = meio + 1;
        }else{
        	*cont = *cont+1;
            return meio;
    	}
	}
	
	*cont = *cont+1;
    return -1;
}
int buscaInterpolaGdp(no *paises,long chaveGdp, int ini, int fim,int* cont){
    int meio;
    
    while(ini<=fim){
    	
        meio = ini + ((fim-ini)*((chaveGdp-paises[ini].gdp) / (paises[fim].gdp - paises[ini].gdp)));
        *cont = *cont+8;
        
        if(chaveGdp < paises[meio].gdp){
        	*cont = *cont+3;
            fim = meio - 1;
        }else if(chaveGdp > paises[meio].gdp){
        	*cont = *cont+3;
            ini = meio + 1;
        }else{
        	*cont = *cont+1;
            return meio;
    	}
	}
	
	*cont = *cont+1;
    return -1;
}






void csortGdp(no *paises, int tam, int *cont){
    long maior=0, i;
    no aux;

    for(i=0 ; i<tam; i++){
        if(maior < paises[i].gdp)
        maior = paises[i].gdp;
    }
    no *vet2, *vet3;
    
    vet3 = (no*) calloc (tam, sizeof(no));
    vet2 = (no*) calloc (maior+1, sizeof(no));

    for(i=0 ; i<tam; i++){
        vet2[paises[i].gdp] = vet2[paises[i].gdp].gdp + 1;
    }
    //POSSIVEIS CAGOS
    for(i=0 ; i<maior+1 ; i++){
        aux.gdp = aux.gdp + vet2[i]gdp;
        vet2[i].gdp = aux.gdp;
    }
    //LOTSA CAGOS
    for(i=tam-1 ; i>=0 ; i--){
        vet3[vet2[paises[i]]-1].gdp = paises[i].gdp;
        --vet2[paises[i]];
    }
    for(i=0 ; i<N ; i++){
        printf("%d ", vet3[i].gdp);
    }


}