#include "trab.c"


int main(){
    FILE *fp;
    fp = fopen("paises.txt", "r");
	char pais[30];
	long gdp, pop, area;
	
	int i=0, j, cont, op;
	
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
	
	for (j=0 ; j<i ; j++){
		printf("%s, %ld, %ld, %ld\n", paises[j].pais, paises[j].area, paises[j].pop, paises[j].gdp);
	}
	cont = i+1;
	
	heapArea(paises, cont);

	for (j=0 ; j<i ; j++){
		printf("%ld\n", paises[j].area);
	}
	cont = i+1;
	
	return 0;
}