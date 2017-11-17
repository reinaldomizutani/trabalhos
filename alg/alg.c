#include "alg.h"


//bubble sort

/*
void bubbleSort(int arr[], int n)
{
   int i, j;
   for (i = 0; i < n-1; i++)      
 
       // Last i elements are already in place   
       for (j = 0; j < n-i-1; j++) 
           if (arr[j] > arr[j+1])
              swap(&arr[j], &arr[j+1]);
            }*/
            


void criaFila(fila *F){
    F->ini = NULL;
    F->fim = NULL;
    F->tam = 0;
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
		else F->fim->prox = p;
		
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
}

void bubbleSort(fila *F){

}