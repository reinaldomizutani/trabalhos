#include<stdio.h>
#include<stdlib.h>


typedef struct no{
	int elem;
	struct no *left, *right;
	
} node;

typedef struct{
	node *root;
} tree;

int instree(node **raiz, int *valor){
	if(*raiz == NULL){// ESTA PORRA TA DANDO ERRADO COROLHO
		*raiz = (node*) malloc (sizeof(node));
		(*raiz)->elem = *valor;
		(*raiz)->left = NULL;
		(*raiz)->right = NULL;
		printf("TESTE IF RAIZ = NULL\n");
		return 1;
	}
	else if(*valor < (*raiz)->elem){
		return(instree(&(*raiz)->left, valor));
		printf("TESTE INSERÇÃO ESQUERDA\n");
		}
	else if(*valor >= (*raiz)->elem){
		return(instree(&(*raiz)->right, valor));
		printf("TESTE INSERÇÃO DIREITA\n");
		}
	else{
		printf("TESTE DEU MERDA\n");
		return 0;
		}
}

void criArvore(tree *bin){
	bin->root = NULL;
}


int main(){
	int N, i, aux, erro=0;
	
	//criando árvore
	tree arvore;
	criArvore(&arvore);

	
	scanf("%d", &N);
	
	for(i=0 ; i<N ; i++){
		scanf("%d", &aux);
		erro = instree(&arvore.root, &aux);
	}


	return 0;
}