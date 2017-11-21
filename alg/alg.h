#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

typedef struct node{
    int elem, index;
    struct node *prox, *ant;
} no;

typedef struct{
    no *ini, *fim;
    int tam;
} fila;

void criaFila(fila *F, int size);
void inserir(fila *F, int *X, int *erro, int *index);
void imprimeFila(fila *F);
no* retornaNo(fila *F, int index);

void bubbleSort(fila *F, int size, int ordem);//0 = crescente ; 1 = decrescente
void insertionSort(fila *F, int size, int ordem);
