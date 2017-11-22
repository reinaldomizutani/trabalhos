#include<stdio.h>
#include<stdlib.h>
#include<time.h>


typedef struct node{
    int elem;
    struct node *prox;
}no;

typedef struct{
    no *ini;
    no *fim;
}lista;

typedef struct{
    lista zero;
    lista um;
    lista dois;
    lista tres;
    lista quatro;
    lista cinco;
    lista seis;
    lista sete;
    lista oito;
    lista nove;
}esp;

void crialista(lista *L);
void criaHash(esp *H);
void separaHash(int x, esp *H);

//void insereHash(int x, esp *H, int classe);
