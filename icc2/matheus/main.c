#include "trab.c"
#include "quick.c"

int main(){
    FILE *fp;
    fp = fopen("paises.txt", "r");
	char pais[30];
	char chaveChar[30];
	long gdp, pop, area;
	long chavePop, chaveArea, chaveGdp;
	int tam, aux;
	int i=0, j;
	
	//variaveis para contar o tempo
	clock_t tempoInicial, tempoFinal;
	double tempoTotal;
	
	srand(time(NULL));

	no *paises = NULL;

	while(!feof(fp)){
		fscanf(fp, "%s %ld %ld %ld", pais, &area, &pop, &gdp);

		paises = (no*)realloc(paises, (i+1)*sizeof(no));
		strcpy(paises[i].pais, pais);
		paises[i].area = area;
		paises[i].pop = pop;
		paises[i].gdp = gdp;
		i++;
	}

	tam = i;


//====================================================================================================//
/*		BUSCAS SEQUENCIAIS		*//*
printf("== BUSCAS SEQUENCIAIS ==\n");	
	printf("Chave pop: ");	
	scanf("%ld",&chavePop);
	printf("Chave area: ");
	scanf("%ld",&chaveArea);
	printf("Chave nome: ");
	scanf("%s",&chaveChar);
	
	
		tempoInicial = clock();
	aux = buscaSequencialPop(paises,chavePop,tam);
		tempoFinal = clock();
		tempoTotal = (double)(tempoFinal - tempoInicial)/(double)(CLOCKS_PER_SEC);	
		printf("\nTempo Busca Popu: %.12f\n", tempoTotal);
		
		tempoInicial = clock();				
	aux = buscaSequencialArea(paises,chaveArea,tam);
		tempoFinal = clock();
		tempoTotal = (tempoFinal - tempoInicial)/(CLOCKS_PER_SEC);	
		printf("Tempo Busca Area: %.12f\n", tempoTotal);
		
		tempoInicial = clock();
	aux = buscaSequencialNome(paises,chaveChar,tam);
		tempoFinal = clock();
		tempoTotal = (tempoFinal - tempoInicial)/(CLOCKS_PER_SEC);	
		printf("Tempo Busca Nome: %.12f\n", tempoTotal);		

//	printf("Indice: %d\n",aux);	

//====================================================================================================//			
/*		QUICKSORTS		*/	/*
	printf("\n== QUICKSORTS ==\n");
	
	/* POR POPULACAO *//*
	printf("Por Populacao:\n");
		tempoInicial = clock();
	quickSortPivoMeioPop(paises,0,tam);
		tempoFinal = clock();
		tempoTotal = (tempoFinal - tempoInicial)/(CLOCKS_PER_SEC);	
		printf("\nTempo Orde Meio: %.12f", tempoTotal);
		
		tempoInicial = clock();
	quickSortPivoAleatorioPop(paises,0,tam);
		tempoFinal = clock();
		tempoTotal = (tempoFinal - tempoInicial)/(CLOCKS_PER_SEC);	
		printf("\nTempo Orde Alea: %.12f", tempoTotal);
		
				tempoInicial = clock();
	quickSortPivoMedianaPop(paises,0,tam);
		tempoFinal = clock();
		tempoTotal = (tempoFinal - tempoInicial)/(CLOCKS_PER_SEC);	
		printf("\nTempo Orde Medi: %.12f", tempoTotal);

	/* POR AREA *//*
	printf("\n\nPor Area:\n");
		tempoInicial = clock();
	quickSortPivoMeioArea(paises,0,tam);
		tempoFinal = clock();
		tempoTotal = (tempoFinal - tempoInicial)/(CLOCKS_PER_SEC);	
		printf("\nTempo Orde Meio: %.12f", tempoTotal);
		
		tempoInicial = clock();
	quickSortPivoAleatorioArea(paises,0,tam);
		tempoFinal = clock();
		tempoTotal = (tempoFinal - tempoInicial)/(CLOCKS_PER_SEC);	
		printf("\nTempo Orde Alea: %.12f", tempoTotal);
		
		tempoInicial = clock();
	quickSortPivoMedianaArea(paises,0,tam);
		tempoFinal = clock();
		tempoTotal = (tempoFinal - tempoInicial)/(CLOCKS_PER_SEC);	
		printf("\nTempo Orde Medi: %.12f", tempoTotal);
			
			
		/* POR NOME *//*
		printf("\n\nPor Nome:\n");
	
		tempoInicial = clock();
	quickSortPivoMeioNome(paises,0,tam);
		tempoFinal = clock();
		tempoTotal = (tempoFinal - tempoInicial)/(CLOCKS_PER_SEC);	
		printf("\nTempo Orde Meio: %.12f", tempoTotal);
		
		tempoInicial = clock();
	quickSortPivoAleatorioNome(paises,0,tam);
		tempoFinal = clock();
		tempoTotal = (tempoFinal - tempoInicial)/(CLOCKS_PER_SEC);	
		printf("\nTempo Orde Alea: %.12f", tempoTotal);
		
		tempoInicial = clock();
	quickSortPivoMedianaNome(paises,0,tam);
		tempoFinal = clock();
		tempoTotal = (tempoFinal - tempoInicial)/(CLOCKS_PER_SEC);	
		printf("\nTempo Orde Medi: %.12f", tempoTotal);

		/* POR GDP */
		printf("\n\nPor GDP:\n");
		tempoInicial = clock();
	quickSortPivoMeioGdp(paises,0,tam,&aux);
		tempoFinal = clock();
		tempoTotal = (tempoFinal - tempoInicial)/(CLOCKS_PER_SEC);	
		printf("\nTempo Orde Meio: %.12f", tempoTotal);

//====================================================================================================//
/* BUSCA BINARIA *//*
	printf("\n\n== BUSCAS BINARIAS ==\n");
	printf("Chave pop: ");	
	scanf("%ld",&chavePop);
	printf("Chave area: ");
	scanf("%ld",&chaveArea);
	printf("Chave nome: ");
	scanf("%s",&chaveChar);
	
		tempoInicial = clock();
	aux = buscaBinariaPop(paises,chavePop,0,tam);
		tempoFinal = clock();
		tempoTotal = (tempoFinal - tempoInicial)/(CLOCKS_PER_SEC);	
		printf("\nTempo em segundos: %.12f\n", tempoTotal);

		tempoInicial = clock();
	aux = buscaBinariaArea(paises,chaveArea,0,tam);
		tempoFinal = clock();
		tempoTotal = (tempoFinal - tempoInicial)/(CLOCKS_PER_SEC);	
		printf("Tempo em segundos: %.12f\n", tempoTotal);
		
		tempoInicial = clock();
	aux = buscaBinariaNome(paises,chaveChar,0,tam);
		tempoFinal = clock();
		tempoTotal = (tempoFinal - tempoInicial)/(CLOCKS_PER_SEC);	
		printf("Tempo em segundos: %.12f\n", tempoTotal);

	
//	printf("Indice: %d\n",aux);

//====================================================================================================//
/* BUSCA INTERPOLADA */	
	printf("\n\n== BUSCAS INTERPOLADAS ==\n");
//	printf("Chave pop: ");	
//	scanf("%ld",&chavePop);
//	printf("Chave area: ");
//	scanf("%ld",&chaveArea);
	printf("Chave GDP: ");
	scanf("%s",&chaveGdp);
/*	
		tempoInicial = clock();
	aux = buscaInterpolaPop(paises,chavePop,0,tam);
		tempoFinal = clock();
		tempoTotal = (tempoFinal - tempoInicial)/(CLOCKS_PER_SEC);	
		printf("\nTempo em segundos: %.12f\n", tempoTotal);

		tempoInicial = clock();
	aux = buscaInterpolaArea(paises,chaveArea,0,tam);
		tempoFinal = clock();
		tempoTotal = (tempoFinal - tempoInicial)/(CLOCKS_PER_SEC);	
		printf("Tempo em segundos: %.12f\n", tempoTotal);
*/
		tempoInicial = clock();
	aux = buscaInterpolaGdp(paises,chaveGdp,0,tam,&aux);
		tempoFinal = clock();
		tempoTotal = (tempoFinal - tempoInicial)/(CLOCKS_PER_SEC);	
		printf("Tempo em segundos: %.12f\n", tempoTotal);

//	aux = buscaBinariaChar(paises,chaveChar,0,tam);

//====================================================================================================//
//	printf("Indice: %d\n",aux);
			
	/*for (j=0 ; j<tam ; j++){
		printf("%s, %ld, %ld, %ld\n", paises[j].pais, paises[j].area, paises[j].pop, paises[j].gdp);
	}*/

				
	return 0;
}




