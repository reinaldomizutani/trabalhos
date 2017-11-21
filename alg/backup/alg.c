#include "alg.h"

void criaFila(fila *F, int size){
    F->ini = NULL;
    F->fim = NULL;
    F->tam = size;
}

void inserir(fila *F, int *X, int *erro, int *index){
	
	no *p;
	
	p = (no*)malloc(sizeof(no));
	if(p==NULL){
		*erro = 1;
		return;
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
    no *teste = F->ini;
    fila left;
    fila right;
    int tamLeft, tamRight;
    tamLeft = F->tam/2;

    //condição de parada
    if(teste == NULL || teste->prox == NULL){
        return;
    }

    //construindo o tamLeftnho de cada fila secundária
    if(F->tam%2 == 0)
        tamRight = F->tam/2;
    else
        tamRight = (F->tam/2)+1;
    //efetivamente criando as filas secundárias
    criaFila(&left, tamLeft);
    criaFila(&right, tamRight);
    divideFila(F, &left, &right);
    mergeSortC(&left);
    mergeSortC(&right);

 //---------------------------------------------------------------
//      CONTINUAR DAQUI!
 //---------------------------------------------------------------


    *teste = mergeC(left, right);
}

void mergeC(){

}

void divideFila(fila *ini, fila *left, fila *right){
    int i, aux, erro;
    no *temp = NULL;
    temp = ini->ini;
    printf("valor do temp = %d\n", temp->elem);
    for(i=0 ; i<left->tam ; i++){
        inserir(left, &temp->elem, &erro, &i);
        temp = temp->prox;
    }
    
    for(i=0 ; i<right->tam ; i++){
        inserir(right, &temp->elem, &erro, &i);
        temp = temp->prox;
    }

}