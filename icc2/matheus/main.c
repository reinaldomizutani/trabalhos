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

	for (j=0 ; j<tam ; j++){
		printf("%s, %ld, %ld, %ld\n", paises[j].pais, paises[j].area, paises[j].pop, paises[j].gdp);
	}

//	printf("\n------------\n");
/*	scanf("%ld",&chavePop);
	aux = buscaSequencialPop(paises,chavePop,tam);
	printf("%d\n",aux);
	scanf("%ld",&chaveArea);
	aux = buscaSequencialArea(paises,chaveArea,tam);
	printf("%d\n",aux);
	scanf("%s",&chaveChar);
	aux = buscaSequencialChar(paises,chaveChar,tam);
	printf("%d\n",aux);*/

//	printf("\n------------\n");
/*	scanf("%ld",&chavePop);
	aux = buscaBinariaPop(paises,chavePop,0,tam);
	printf("%d\n",aux);
	scanf("%ld",&chaveArea);
	aux = buscaBinariaArea(paises,chaveArea,0,tam);
	printf("%d\n",aux);
	scanf("%s",&chaveChar);
	aux = buscaBinariaChar(paises,chaveChar,0,tam);
	printf("%d\n",aux);*/
	
//	printf("\n------------\n");
//	scanf("%ld",&chavePop);
//	aux = buscaInterpolaPop(paises,chavePop,0,tam);
//	printf("%d\n",aux);
//	scanf("%ld",&chaveArea);
//	aux = buscaInterpolaArea(paises,chaveArea,0,tam);
//	printf("%d\n",aux);
//	scanf("%s",&chaveChar);
//	aux = buscaBinariaChar(paises,chaveChar,0,tam);
//	printf("%d\n",aux);
	
//	printf("\n------------\n");
//	quickSortPivoMeioPop(paises,0,tam);
//	quickSortPivoAleatorioPop(paises,0,tam);		
//	quickSortPivoMedianaPop(paises,0,tam);
//	quickSortPivoMeioArea(paises,0,tam);
//	quickSortPivoAleatorioArea(paises,0,tam);		
//	quickSortPivoMedianaArea(paises,0,tam);
//	quickSortPivoMeioNome(paises,0,tam);
//	quickSortPivoAleatorioNome(paises,0,tam);		
//	quickSortPivoMedianaNome(paises,0,tam);
//	quickSortPivoMeioGdp(paises,0,tam);
	
//	printf("\n------------\n");
//	scanf("%ld",&chavePop);
//	aux = buscaInterpolaPop(paises,chavePop,0,tam);
//	printf("%d\n",aux);
//	scanf("%ld",&chaveArea);
//	aux = buscaInterpolaArea(paises,chaveArea,0,tam);
//	printf("%d\n",aux);
//	scanf("%ld",&chaveGdp);
//	aux = buscaInterpolaGdp(paises,chaveGdp,0,tam);
//	printf("%d\n",aux);
//	scanf("%s",&chaveChar);
//	aux = buscaBinariaChar(paises,chaveChar,0,tam);
//	printf("%d\n",aux);
			
	
				
	return 0;
}




