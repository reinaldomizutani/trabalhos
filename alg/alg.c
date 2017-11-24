#include "alg.h"

void criaFila(fila *F, int size){
    F->ini = NULL;
    F->fim = NULL;
    F->tam = size;
}

void finalizar(fila *F){
	no *aux;
	no *p = F->ini;
	
	while(p != NULL){
		aux = p->prox;
		free(p);
		p = aux;
	}
	
	F->ini = NULL;
	
}

void inserir(fila *F, int *X, int *erro, int *index){
	
	no *p;
	
	p = (no*)malloc(sizeof(no));
	if(p==NULL){
		*erro = 1;
		return;
        printf("ERRO NA CRIAÇÃO DO NO - funcao inserir\n");
	} else *erro = 0;
	
	p->elem = *X;
    p->prox = NULL;
    p->ant = NULL;
    p->index = *index; 
	
	if(F->ini == NULL)
		F->ini = p;
        else {
        p->ant = F->fim;
        F->fim->prox = p;
		}
    F->fim = p;
    
}

void imprimeFila(fila *F){
    no *p;
    p = (no*)malloc(sizeof(no));

    p = F->ini;
    while(p->prox != NULL){
        printf("indice: %d, elem: %d\n", p->index, p->elem);
        p = p->prox;
    }
    printf("indice: %d, elem: %d\n", p->index, p->elem);
}


no* retornaNo(fila *F, int index){
    no *P;
    P = F->ini;
    while(index != P->index){
        P = P->prox;
        
    }
    //printf("no %d = %d", index, P->elem);
    return P;
}

void bubbleSort(fila *F, int size, int ordem){
    no *a= NULL, *b=NULL;
    int i, j, aux;

    if(ordem == 1){ // ordem decrescente
        for(i=0 ; i<size ; i++){
            for(j=0 ; j<size-i-1 ; j++){
                a = retornaNo(F, j);
                b = retornaNo(F, j+1);
                if(b->elem > a->elem){
                    aux = a->elem;
                    a->elem = b->elem;
                    b->elem = aux;
                }
            }
        }
    }else if(ordem == 0){ // ordem crescente
        for(i=0 ; i<size ; i++){
            for(j=0 ; j<size-i-1 ; j++){
                a = retornaNo(F, j);
                b = retornaNo(F, j+1);
                if(b->elem < a->elem){
                    aux = a->elem;
                    a->elem = b->elem;
                    b->elem = aux;
                }
            }
        }
    }
}

void insertionSort(fila *F, int size, int ordem){
    no *key=NULL, *comp=NULL;
    int i, j, aux;

    if(ordem == 0){
        for(i=1 ; i<size ; i++){
            key = retornaNo(F, i);
            j = i-1;
            comp = key->ant;
            aux = key->elem;
            while(j>=0 && comp->elem > aux){
                comp->prox->elem = comp->elem;
                j = j-1;
                if(comp->ant != NULL)
                    comp = comp->ant;
            }
            comp->elem = aux;
        }
    }
    else if(ordem == 1){
        for(i=1 ; i<size ; i++){
            key = retornaNo(F, i);
            j = i-1;
            comp = key->ant;
            aux = key->elem;
            while(j>=0 && comp->elem < aux){
                comp->prox->elem = comp->elem;
                j = j-1;
                if(comp->ant != NULL)
                    comp = comp->ant;
            }
            comp->elem = aux;
        }
    }
}

void mergeSortC(fila *F){
    //dividindo em 2 listas:

    if(F->tam > 1){
        int i=0, erro=0;

        fila esq, dir;
        criaFila(&esq, F->tam/2);
        
        if(F->tam%2 == 0)
            criaFila(&dir, F->tam/2);
        else
            criaFila(&dir, (F->tam/2)+1);

        no *aux;
        aux = (no*)malloc(sizeof(no));
        aux = F->ini;

        while(i < F->tam/2){
            inserir(&esq, &aux->elem, &erro, &i);
            aux = aux->prox;
            i++;
        }
        i=0;
        while(aux != NULL){
            inserir(&dir, &aux->elem, &erro, &i);
            aux = aux->prox;
            i++;
        }

        mergeSortC(&esq);
        mergeSortC(&dir);
        mergeC(F, &esq, &dir);
    }
}

void mergeC(fila *F, fila *esq, fila *dir){
    
    no *aux1, *aux2;
    fila filaux;
    int i=0, erro=0;
    
    aux1 = (no*)malloc(sizeof(no));
    aux2 = (no*)malloc(sizeof(no));

    criaFila(&filaux, esq->tam+dir->tam);

    aux1 = esq->ini;
    aux2 = dir->ini;

	finalizar(F);
	criaFila(F,esq->tam+dir->tam);
		
	while((aux2 != NULL) && (aux1 != NULL)){		
		
        if(aux1->elem <= aux2->elem){
            inserir(F, &aux1->elem, &erro, &i);
            i++;
            aux1 = aux1->prox;
        }
        else{
        	
            inserir(F, &aux2->elem, &erro, &i);
            i++;
            aux2 = aux2->prox;
        }
    }
    
    while(aux1 != NULL){

        inserir(F, &aux1->elem, &erro, &i);
        aux1 = aux1->prox;

    }
    
    while(aux2 != NULL){

        inserir(F, &aux2->elem, &erro, &i);
        aux2 = aux2->prox;
    }
    
    free(aux1);
    free(aux2);
        

}
