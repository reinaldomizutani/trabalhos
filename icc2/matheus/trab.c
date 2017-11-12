#include "trab.h"

//================================================================//
//Pesquisa População/Area/Nome do pais sequencialmente. Retorna indice caso encontrou ou -1 se nao encontrar.
int buscaSequencialPop(no paises[],long chavePop, int tam, int* cont){
	int i=0;
	*cont++;
	
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
	*cont++;
	
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
	*cont++;
	for(;i<tam;i++){
		if(strcmp(paises[i].pais,chaveNome)==0){
			*cont += i*3+1;	
			return i;
		}
	}
	*cont += i*3+1;	
return -1;
}

//===================================================================//
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
		*cont+=3;
		return	buscaBinariaPop(paises,chavePop,ini, i-1,cont);
	}else if(paises[i].pop < chavePop){
		*cont+=3;
		return buscaBinariaPop(paises,chavePop,i+1,fim,cont);
	}
	*cont++;
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
		*cont+=3;
		return	buscaBinariaArea(paises,chaveArea,ini, i-1,cont);
	}else if(paises[i].area < chaveArea){
		*cont+=3;
		return buscaBinariaArea(paises,chaveArea,i+1,fim,cont);
	}
	
	*cont++;
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
		*cont+=3;
		return	buscaBinariaNome(paises,chaveNome,ini, i-1,cont);
	}else if(strcmp(paises[i].pais,chaveNome) < 0){
		*cont+=3;
		return buscaBinariaNome(paises,chaveNome,i+1,fim,cont);
	}
	
	*cont++;
	return -1;
}

//===================================================================//
//Pesquia por interpolação por População/Area/Nome
int buscaInterpolaPop(no paises[],long chavePop, int ini, int fim,int* cont){
	int meio;
	
	while(ini<=fim){
		meio = ini + ((fim-ini)*(chavePop-paises[ini].pop) / (paises[fim].pop - paises[ini].pop));
		*cont+=8;
			
		if(chavePop < paises[meio].pop){
			*cont+=3;
			fim = meio-1;
		}else if(chavePop > paises[meio].pop){
			*cont+=3;			
			ini = meio+1;
		}else{
			*cont++;
			return meio;
		}
	}
	*cont++;
	return -1;
}
int buscaInterpolaArea(no paises[],long chaveArea, int ini, int fim,int* cont){
    int meio;
    
    while(ini <= fim){
    	
        meio = ini + ((fim-ini)*((chaveArea-paises[ini].area) / (paises[fim].area - paises[ini].area)));
        *cont+=8;
        
        if(chaveArea < paises[meio].area){
			*cont+=3;		
            fim = meio - 1;
        }else if(chaveArea > paises[meio].area){
        	*cont+=3;
            ini = meio + 1;
        }else{
        	*cont++;
            return meio;
    	}
	}
	
	*cont++;
    return -1;
}
int buscaInterpolaGdp(no paises[],long chaveGdp, int ini, int fim,int* cont){
    int meio;
    
    while(ini<=fim){
    	
        meio = ini + ((fim-ini)*((chaveGdp-paises[ini].gdp) / (paises[fim].gdp - paises[ini].gdp)));
        *cont+=8;
        
        if(chaveGdp < paises[meio].gdp){
        	*cont+=3;
            fim = meio - 1;
        }else if(chaveGdp > paises[meio].gdp){
        	*cont+=3;
            ini = meio + 1;
        }else{
        	*cont++;
            return meio;
    	}
	}
	
	*cont++;
    return -1;
}

