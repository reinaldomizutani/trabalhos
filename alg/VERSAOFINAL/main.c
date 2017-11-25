/*
Reinaldo Mizutani - 7062145
*/

#include "ab.h"
//#include "ab.c"

int main()
{
//tratamento de variaveis iniciais
	int i=0 , j=0 , erro, alt1, alt2, folha=0, teste, ordem, tamfrase, verif;
	char *frase, pai;

	Arvore arv;
	criArvore(&arv);
	AVL avltree;	
	createAvl(&avltree);
	system("cls");
	frase = lerstr();

// ------------------------------------------------------------
// INSERCAO POR LARGURA
// ------------------------------------------------------------
	pai = -1;
    insR(&arv, &frase[0], &pai, &erro);
    pai = frase[i];

    while(i < strlen(frase+1))
    {
        if(frase[i+1] != ' ')
            insL(&arv, &frase[i+1], &pai, &erro);
        if(frase[i+2] != ' ')
            insR(&arv, &frase[i+2], &pai, &erro);
        j = j+1;
        pai = frase[j];
        i = i+2;
    }

    i=0;
// ------------------------------------------------------------
// INSERCAO NA AVL
// ------------------------------------------------------------
    while(i<strlen(frase))
    {
    	inserir_avl(&avltree.raiz, &frase[i]);
    	i++;
    }

// ------------------------------------------------------------
// respondendo perguntas:
// ------------------------------------------------------------
	
	
    printf("\n\n--------------------------------------------------\n");
	printf("1 - ARVORE (insercao por largura)\n");
	printf("--------------------------------------------------\n\n");
	imprimir(arv.raiz);
	printf("\n");
	//1. Verificacao da altura da ab
	alt1 = altura(arv.raiz);
	printf("Altura: \t\t%d\n", alt1);
	//2. Contando a quantidade de nos folha
	printf("Numero de nos folhas: \t%d\n", nosfolhas(arv.raiz));
	//3. Verificacao se a arvore e cheia
	if(nosfolhas(arv.raiz) == pow(2,alt1-1))
		printf("Arvore Cheia?:\t\tsim\n");
	else printf("Arvore Cheia?:\t\tnao\n");
	//4. Verificacao se a arvore e ABB
	abb(arv.raiz, &erro);
	if(erro)
		printf("Arvore e ABB?: \t\tnao\n");
	else printf("Arvore e ABB?: \t\tsim\n");
	//5. Verificacao se é AVL
	teste = avl(arv.raiz, &erro);
	if(!teste)
		printf("Arvore e AVL?: \t\tsim\n");
	else printf("Arvore e AVL?: \t\tnao\n");

//6. Verificacao: percurso pre-ordem 
	tamfrase = strlen(frase);
	char fraseAux[tamfrase];
	i=0;
	preOrdemVet(arv.raiz, fraseAux, &i);
	verif = verificaOrdem(fraseAux);
	if(verif == 1)
		printf("preordem e ordenado?\tnao\n");
	else
		printf("preordem e ordenado?\tsim\n");

//7. Verificacao: percurso ordem 
	i=0;
	OrdemVet(arv.raiz, fraseAux, &i);
	verif = verificaOrdem(fraseAux);
	if(verif == 1)
		printf("Ordem e ordenado?\tnao\n");
	else
		printf("Ordem e ordenado?\tsim\n");

//8. Verificacao: percurso em pos-ordem 
	i=0;
	posOrdemVet(arv.raiz, fraseAux, &i);
	verif = verificaOrdem(fraseAux);
	if(verif == 1)
		printf("Pos-ordem e ordenado?\tnao\n");
	else
		printf("Pos-ordem e ordenado?\tsim\n");

	
	printf("\n");

    printf("--------------------------------------------------\n");
	printf("2 - ARVORE AVL\n");
	printf("--------------------------------------------------\n\n");
	imprimir_avl(&avltree.raiz);
	printf("\n");
	//1. Verificacao da altura da avl
	alt2 = altura_avl(avltree.raiz);
	printf("Altura: \t\t%d\n", alt1);
	//2. Contando a quantidade de nos folha
	printf("Numero de nos folhas: \t%d\n", nosfolhas(arv.raiz));
	//verifica se avl é do tipo cheia
	if(nosfolhas_avl(avltree.raiz) == pow(2,alt1-1))
		printf("Arvore Cheia?:\t\tsim\n");
	else printf("Arvore Cheia?:\t\tnao\n");
	//4. Verificacao se a arvore e ABB
	abb_avl(avltree.raiz, &erro);
	if(erro)
		printf("Arvore e ABB?: \t\tnao\n");
	else printf("Arvore e ABB?: \t\tsim\n");
	
	avlAVL(avltree.raiz, &erro);
	if(!erro)
		printf("Arvore e AVL?: \t\tsim\n");
	else printf("Arvore e AVL?: \t\tnao\n");


//6. Verificacao: percurso pre-ordem 

	i=0;
	preOrdemVetAVL(avltree.raiz, fraseAux, &i);
	verif = verificaOrdem(fraseAux);
	if(verif == 1)
		printf("preordem e ordenado?\tnao\n");
	else
		printf("preordem e ordenado?\tsim\n");

//7. Verificacao: percurso ordem 
	i=0;
	OrdemVetAVL(avltree.raiz, fraseAux, &i);
	verif = verificaOrdem(fraseAux);
	if(verif == 1)
		printf("Ordem e ordenado?\tnao\n");
	else
		printf("Ordem e ordenado?\tsim\n");

//8. Verificacao: percurso em pos-ordem 
	i=0;
	posOrdemVetAVL(avltree.raiz, fraseAux, &i);
	verif = verificaOrdem(fraseAux);
	if(verif == 1)
		printf("Pos-ordem e ordenado?\tnao\n");
	else
		printf("Pos-ordem e ordenado?\tsim\n");
		
	printf("\n");
	printf("\n");

	return 0;
}
