#include "trab.c"
#include "quick.c"

int main(){
	//-----------------------------------------------------
	//1. declaracao de variaveis
	//-----------------------------------------------------

    FILE *fp;
    fp = fopen("paises.txt", "r");
	char pais[30];
	char chaveChar[30];
	long gdp, pop, area;
	long chavePop, chaveArea, chaveGdp;
	int tam, aux=0, contArea=0, contPop=0, contGdp=0;
	int i=0, j;
	clock_t tempoInicial, tempoFinal;
	double tempoTotal;
	no *paises = NULL;
	srand(time(NULL));

	//-----------------------------------------------------
	//2. leitura de dados do arquivo
	//-----------------------------------------------------

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
	//-----------------------------------------------------
	//3. chamadas das funcoes de ordenacao
	//-----------------------------------------------------
	system("cls");
	//3.b - Quick Sort
	//POPULACAO
	printf("2.a.a - Quick Sort - Populacao (pivo meio):\n");
	tempoInicial = clock();
	quickSortPivoMeioPop(paises,0,tam,&aux);
	tempoFinal = clock();
	tempoTotal = (tempoFinal - tempoInicial)/(CLOCKS_PER_SEC);	
	printf("Tempo de ordenacao: %.12f\nnumero de operacoes:%d\n--\n", tempoTotal, aux);
	aux = 0;

	printf("2.a.b -  Quick Sort - Populacao (pivo aleatorio):\n");
	tempoInicial = clock();
	quickSortPivoAleatorioPop(paises,0,tam,&aux);
	tempoFinal = clock();
	tempoTotal = (tempoFinal - tempoInicial)/(CLOCKS_PER_SEC);	
	printf("Tempo de ordenacao: %.12f\nnumero de operacoes:%d\n--\n", tempoTotal, aux);
	aux = 0;

	printf("2.a.c -  Quick Sort - Populacao (pivo mediana):\n");
	tempoInicial = clock();
	quickSortPivoMedianaPop(paises,0,tam,&aux);
	tempoFinal = clock();
	tempoTotal = (tempoFinal - tempoInicial)/(CLOCKS_PER_SEC);	
	printf("Tempo de ordenacao: %.12f\nnumero de operacoes:%d\n--\n", tempoTotal, aux);
	aux = 0;

	//AREA
	printf("2.b.a -  Quick Sort - Area (pivo meio):\n");
	tempoInicial = clock();
	quickSortPivoMeioArea(paises,0,tam,&aux);
	tempoFinal = clock();
	tempoTotal = (tempoFinal - tempoInicial)/(CLOCKS_PER_SEC);	
	printf("Tempo de ordenacao: %.12f\nnumero de operacoes:%d\n--\n", tempoTotal, aux);
	aux = 0;
	
	printf("2.b.b -  Quick Sort - Area (pivo aleatorio):\n");
	tempoInicial = clock();
	quickSortPivoAleatorioArea(paises,0,tam,&aux);
	tempoFinal = clock();
	tempoTotal = (tempoFinal - tempoInicial)/(CLOCKS_PER_SEC);	
	printf("Tempo de ordenacao: %.12f\nnumero de operacoes:%d\n--\n", tempoTotal, aux);
	aux = 0;
		
	printf("2.b.c -  Quick Sort - Area (pivo mediana):\n");
	tempoInicial = clock();
	quickSortPivoMedianaArea(paises,0,tam,&aux);
	tempoFinal = clock();
	tempoTotal = (tempoFinal - tempoInicial)/(CLOCKS_PER_SEC);	
	printf("Tempo de ordenacao: %.12f\nnumero de operacoes:%d\n--\n", tempoTotal, aux);
	aux = 0;

	//NOME
	printf("2.c.a -  Quick Sort - Nome (pivo meio):\n");
	tempoInicial = clock();
	quickSortPivoMeioNome(paises,0,tam,&aux);
	tempoFinal = clock();
	tempoTotal = (tempoFinal - tempoInicial)/(CLOCKS_PER_SEC);	
	printf("Tempo de ordenacao: %.12f\nnumero de operacoes:%d\n--\n", tempoTotal, aux);
	aux = 0;
	
	printf("2.c.b -  Quick Sort - Nome (pivo aleatorio):\n");
	tempoInicial = clock();
	quickSortPivoAleatorioNome(paises,0,tam,&aux);
	tempoFinal = clock();
	tempoTotal = (tempoFinal - tempoInicial)/(CLOCKS_PER_SEC);	
	printf("Tempo de ordenacao: %.12f\nnumero de operacoes:%d\n--\n", tempoTotal, aux);
	aux = 0;
		
	printf("2.c.c -  Quick Sort - Nome (pivo mediana):\n");
	tempoInicial = clock();
	quickSortPivoMedianaNome(paises,0,tam,&aux);
	tempoFinal = clock();
	tempoTotal = (tempoFinal - tempoInicial)/(CLOCKS_PER_SEC);	
	printf("Tempo de ordenacao: %.12f\nnumero de operacoes:%d\n--\n", tempoTotal, aux);
	aux = 0;



	//3.a - Heap Sort:
	printf("1.a. Heap Sort - Area.\n");
	tempoInicial = clock();
	heapArea(paises, i+1, &contArea);
	tempoFinal = clock();
	tempoTotal = (tempoFinal - tempoInicial)/(CLOCKS_PER_SEC);	
	printf("Tempo de ordenacao: %.12f\nnumero de operacoes:%d\n--\n", tempoTotal, contArea);
	contArea = 0;

	printf("1.a. Heap Sort - Populacao.\n");
	tempoInicial = clock();
	heapPop(paises, i+1, &contPop);
	tempoFinal = clock();
	tempoTotal = (tempoFinal - tempoInicial)/(CLOCKS_PER_SEC);	
	printf("Tempo de ordenacao: %.12f\nnumero de operacoes:%d\n--\n", tempoTotal, contPop);
	contPop=0;

	printf("1.a. Heap Sort - GDP.\n");
	tempoInicial = clock();
	heapGdp(paises, i+1, &contGdp);
	tempoFinal = clock();
	tempoTotal = (tempoFinal - tempoInicial)/(CLOCKS_PER_SEC);	
	printf("Tempo de ordenacao: %.12f\nnumero de operacoes:%d\n--\n\n\n", tempoTotal, contGdp);
	contGdp=0;


heapPop(paises, i+1, &contPop);
/*
//Busca Sequencial
printf("BUSCA SEQUENCIAL\nchave pop:\n");
scanf("%ld", &contPop);

tempoInicial = clock();
buscaSequencialPop(paises, contPop, tam, &aux);
tempoFinal = clock();
tempoTotal = (tempoFinal - tempoInicial)/(CLOCKS_PER_SEC);	
printf("Tempo de busca: %.12f\nnumero de operacoes:%d\n--\n\n\n", tempoTotal, aux);
aux = 0;


// BUSCA INTERPOLADA
	printf("\n\n== BUSCAS INTERPOLADAS ==\n");
	printf("Chave GDP: ");
	scanf("%ld",&chaveGdp);

	tempoInicial = clock();
	aux = buscaInterpolaPop(paises,chaveGdp,0,tam,&aux);
	tempoFinal = clock();
	tempoTotal = (tempoFinal - tempoInicial)/(CLOCKS_PER_SEC);	
	printf("Tempo de busca: %.12f\nnumero de operacoes:%d\n--\n\n\n", tempoTotal, aux);
*/

csortGdp(*paises, i+1, contGdp);

	free(paises);
	fclose(fp);
	return 0;
}