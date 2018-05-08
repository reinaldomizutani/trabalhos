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