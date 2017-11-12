#include "trab.h"

//================================================================//
//Pesquisa População/Area/Nome do pais sequencialmente. Retorna indice caso encontrou ou -1 se nao encontrar.
int buscaSequencialPop(no paises[],long chavePop, int tam){
	int i=0;
	for(;i<tam;i++){
		if(paises[i].pop == chavePop){
			return i;
		}
	}
	
return -1;
}
int buscaSequencialArea(no paises[],long chaveArea, int tam){
	int i=0;
	for(;i<tam;i++){
		if(paises[i].area == chaveArea){
			return i;
		}
	}
	
return -1;
}
int buscaSequencialNome(no paises[],char chaveNome[], int tam){
	int i=0;
	for(;i<tam;i++){
		if(strcmp(paises[i].pais,chaveNome)==0){
			return i;
		}
	}
	
return -1;
}

//===================================================================//
//Pesquisa binaria de População/Area/Nome. Retorna indice caso encontrar ou -1 se não encontrar.
int buscaBinariaPop(no paises[],long chavePop, int ini, int fim){
	int i;
	
	i = (ini + fim)/2;
	
	if(paises[i].pop==chavePop){
		return i;
	}else if(ini == fim){
		return -1;
	}
	
	else if(paises[i].pop > chavePop){
		return	buscaBinariaPop(paises,chavePop,ini, i-1);
	}else if(paises[i].pop < chavePop){
		return buscaBinariaPop(paises,chavePop,i+1,fim);
	}
	
	return -1;
}
int buscaBinariaArea(no paises[],long chaveArea, int ini, int fim){
	int i;
	
	i = (ini + fim)/2;
	
	if(paises[i].area==chaveArea){
		return i;
	}else if(ini == fim){
		return -1;
	}
	
	else if(paises[i].area > chaveArea){
		return	buscaBinariaArea(paises,chaveArea,ini, i-1);
	}else if(paises[i].area < chaveArea){
		return buscaBinariaArea(paises,chaveArea,i+1,fim);
	}
	
	return -1;
}
int buscaBinariaNome(no paises[],char chaveNome[], int ini, int fim){
	int i;
	
	i = (ini + fim)/2;
	
	if(strcmp(paises[i].pais,chaveNome)==0){
		return i;
	}else if(ini == fim){
		return -1;
	}
	
	else if(strcmp(paises[i].pais,chaveNome) > 0){
		return	buscaBinariaNome(paises,chaveNome,ini, i-1);
	}else if(strcmp(paises[i].pais,chaveNome) < 0){
		return buscaBinariaNome(paises,chaveNome,i+1,fim);
	}
	
	return -1;
}

//===================================================================//
//Pesquia por interpolação por População/Area/Nome
int buscaInterpolaPop(no paises[],long chavePop, int ini, int fim){
	int meio;
	
	while(ini<=fim){
		meio = ini + ((fim-ini)*(chavePop-paises[ini].pop) / (paises[fim].pop - paises[ini].pop));
		
		if(chavePop < paises[meio].pop){
			fim = meio-1;
		}else if(chavePop > paises[meio].pop){
			ini = meio+1;
		}else{
			return meio;
		}
	}
	return -1;
}
int buscaInterpolaArea(no paises[],long chaveArea, int ini, int fim){
    int meio;
    
    while(ini <= fim){
    	
        meio = ini + ((fim-ini)*((chaveArea-paises[ini].area) / (paises[fim].area - paises[ini].area)));
        
        if(chaveArea < paises[meio].area){		
            fim = meio - 1;
        }else if(chaveArea > paises[meio].area){
            ini = meio + 1;
        }else{
            return meio;
    	}
	}
    return -1;
}
int buscaInterpolaGdp(no paises[],long chaveGdp, int ini, int fim){
    int meio;
    
    while(ini<=fim){
        meio = ini + ((fim-ini)*((chaveGdp-paises[ini].gdp) / (paises[fim].gdp - paises[ini].gdp)));
        if(chaveGdp < paises[meio].gdp){
            fim = meio - 1;
        }else if(chaveGdp > paises[meio].gdp){
            ini = meio + 1;
        }else{
            return meio;
    	}
	}
    return -1;
}

