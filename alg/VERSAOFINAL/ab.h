#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

//STRUCTS 
//1 - arvore binaria
typedef char elem;
typedef struct bloco {
        elem info;
        struct bloco *esq, *dir;
} no;

typedef struct {
        no *raiz;
} Arvore;

//2 - AVL
typedef char elem;
typedef struct blocoAvl {
        elem info;
        int fb;
        struct blocoAvl *esq, *dir;
} no_avl;

typedef struct {
        no_avl *raiz;
} AVL;

//FUNCOES:
//AUXILIARES:
char *lerstr();
void imprimir_avl(no_avl**);
void imprimir(no*);

//Arvore Binaria
void criArvore(Arvore*);
int IsEmpty(Arvore*);
no* busca(no*,elem*);
no* busca_pai(no*,elem*);
void insL(Arvore*,elem*,elem*,int*);
void insR(Arvore*,elem*,elem*,int*);
int altura(no*);
void finaliza(no*);
void remover(Arvore*,elem*,int*);
void percurso_pre_ordem(no*);
void percurso_em_ordem(no*);
void percurso_pos_ordem(no*);
int espelho_similares(no*,no*);
int nosfolhas(no*);
void abb(no*, int*);
int avl(no*, int*);
void preOrdemVet(no *p, char *frase, int *i);

//AVL
void createAvl(AVL*);
void finalizar_avl(no_avl**);
int inserir_avl(no_avl**,char*);
int buscar_avl(no_avl**,int*);
int altura_avl(no_avl*);
int nosfolhas_avl(no_avl*);
void abb_avl(no_avl*, int*);
int avlAVL(no_avl *p, int *erro);