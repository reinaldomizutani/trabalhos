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

void criaFila(fila *F);
void inserir(fila *F, int *X, int *erro, int *index);
void imprimeFila(fila *F);


void bubbleSort(fila *F);