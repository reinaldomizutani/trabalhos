/*
formato de entrada:
primeira linha: tem 2 ints, o primeiro é o número de linhas, o segundo é o número de colunas
segunda linha em diante tem a matriz, dividida por espaços.

exemplo:

4 4
1 2 3 4
5 6 7 8
9 10 11 12
13 14 15 6

*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int **leTabela(int **matriz){
	FILE *file;
	file = fopen("tabela.txt", "r");
	int i, j, linhas, colunas, asdf;
		

	if(file){
		fscanf(file, "%d %d", &linhas, &colunas);
		matriz = (int**) malloc(linhas*sizeof(int*));
		for(i=0 ; i<colunas ; i++){
			matriz[i] = (int*) malloc(colunas*sizeof(int));
		}

		for(i=0 ; i<linhas ; i++){
			for(j=0 ; j<colunas ; j++){
				fscanf(file, "%d", &asdf);
				matriz[i][j] = asdf;
			}
        }

        fclose(file);
	}	
	return matriz;
}




int main(){
	int **matriz = NULL;
	matriz = leTabela(matriz);
	

	printf("%d", matriz[1][1]);
	return 0;
}
