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
/*
void insertionSort(fila *F, int size, int ordem){
    int i, j, aux;
    no *a, *b;
    for(i=1 ; i<size ; i++){
        a = retornaNo(F, i); // key
        aux = a->elem;
        j = i-1;

        b = retornaNo(F, i-1); // vet[j]

        while(j>=0 && b->elem > aux){
            a->elem = b->elem;
            j = j+1;
        }
        b = b->prox;
        b->elem = 
    }
}*/


/*
void insertionSort(int arr[], int n)
{
   int i, key, j;
   for (i = 1; i < n; i++)
   {
       key = arr[i];
       j = i-1;

       while (j >= 0 && arr[j] > key)
       {
           arr[j+1] = arr[j];
           j = j-1;
       }
       arr[j+1] = key;
   }
}*/