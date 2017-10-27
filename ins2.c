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
	if(*raiz == NULL){
		*raiz = (node*) malloc (sizeof(node));
		(*raiz)->elem = *valor;
		(*raiz)->left = NULL;
		(*raiz)->right = NULL;
		return 1;
	}
	else if(*valor < (*raiz)->elem){
		return(instree(&(*raiz)->left, valor));
	}
	else if(*valor >= (*raiz)->elem){
		return(instree(&(*raiz)->right, valor));
		}
	else{
		return 0;
		}
}

void criArvore(tree *bin){
	bin->root = NULL;
}


int main(){
	int N, i, aux, erro=0, *vet;
	
	//criando árvore
	tree arvore;
	criArvore(&arvore);

	
	scanf("%d", &N);
	vet = (int*)malloc(sizeof(int));
	
	for(i=0 ; i<N ; i++){
		scanf("%d", &aux);
		vet[i] = aux;
		erro = instree(&arvore.root, &aux);
		if(erro == 1)
			break;
	}

	for(i=0 ; i<N ; i++){
		printf("%d ", vet[i]);
	}
	printf("\n");

	return 0;
}