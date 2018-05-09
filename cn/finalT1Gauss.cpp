/*
Matheus Vinicius G de Godoi nUSPº 10295217
Hugo de Azevedo Vitulli nUSPº 10295221
Reinaldo Mizutani nUSPº 7062145
*/
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <math.h>

#define MAX 50

using namespace std;

void leTabela(float matriz[][MAX], int* lin, int* col){
	FILE *file;
	file = fopen("matriz.txt", "r");
	int i, j, linhas, colunas;
  	float aux;
		

	if(file){
		fscanf(file, "%d %d", &linhas, &colunas);
		for(i=0 ; i<linhas ; i++){
			for(j=0 ; j<colunas ; j++){
				fscanf(file, "%f", &aux);
				matriz[i][j] = aux;
			}
        }

        fclose(file);
	}else{
		printf("\nErro ao abrir arquivo!\nNome do arquivo necessario:\n\"matriz.txt\"");
        exit(0);
	}
  
  	*lin = linhas;
  	*col = colunas;
	return;
}

//Imprime o sistema
void imprimeSistema(float matriz[][MAX], int linhas, int colunas){
  for(int i = 0; i < linhas; i++){
  	for(int j = 0; j < colunas-1; j++){
      if(matriz[i][j] != 0)
    	printf("%.1f[x%d] ",matriz[i][j],j+1);
      if((matriz[i][j+1] > 0)&&(j+1 < colunas-1))
        printf("+");
    }
    printf(" = %.1f\n",matriz[i][colunas-1]);
  } 
}

//Imprime a matriz
void imprimeMatriz(float matriz[][MAX], int linhas, int colunas){
	for (int i = 0; i < linhas; i++){
		for (int j = 0; j < colunas; j++){
			printf("[%.2f]", matriz[i][j]);
		}
		printf("\n");
	}
}

//Realiza o pivotamento parcial
void pivoteamento(float matriz[][MAX], int linhas, int colunas, int iteracao){
	float maior, aux;
	int linhaTrocar = -1;
	
	//Procura o maior na coluna
	maior = fabs(matriz[iteracao][iteracao]);
	for (int i = iteracao; i < linhas; i++){
		if (fabs(matriz[i][iteracao]) > maior){
			maior = fabs(matriz[i][iteracao]);
			linhaTrocar = i;
		}
	}

	if(linhaTrocar == -1){
		return;
	}

	//Realiza a troca de linhas
	for (int i = 0; i < colunas; i++){
		aux = matriz[iteracao][i];
		matriz[iteracao][i] = matriz[linhaTrocar][i];
		matriz[linhaTrocar][i] = aux;
	}
}

//Calculo da Eliminacao
void eliminacaoGauss(float matriz[][MAX], int linhas, int colunas){
	float multiplicador, aux;
	int iteracao = 0;

	//Inicio dos calculos	
	pivoteamento(matriz, linhas, colunas, iteracao);

	while(iteracao != colunas){
		for (int i = iteracao+1; i < linhas; i++){
			//Calcula multiplicador
			multiplicador = matriz[i][iteracao] / matriz[iteracao][iteracao];

			//Realiza as autualizações
			for (int j = iteracao; j < colunas; j++){
				aux = matriz[iteracao][j]*multiplicador;
				matriz[i][j] = matriz[i][j] - aux;
			}
		}

		iteracao += 1;
		if(iteracao == colunas-1){
			break;
		}
		pivoteamento(matriz, linhas, colunas, iteracao);
	}
}

int main(){
	int linhas, colunas;
	int k;
	float sum = 0;
	float vetorRespostas[MAX];
	float matriz[MAX][MAX];
	leTabela(matriz,&linhas,&colunas);
	
	for (int i = 0; i < MAX; i++){
		vetorRespostas[i] = 0;
	}
	//Impressão da matriz original e vetor com as respostas
	printf("\n\nMatriz Original:\n");
	imprimeMatriz(matriz, linhas, colunas);

	//Imprime o sistema linear
	printf("\n\nSistema Linear:\n");
	imprimeSistema(matriz, linhas, colunas);

	//Eliminacao de Gauss
	eliminacaoGauss(matriz, linhas, colunas);
  
	printf("\n\nMatriz com Eliminacao de Gauss:\n");
	imprimeMatriz(matriz, linhas, colunas);

  	//Resolução do sistema linear a partir da eliminação de gauss
	k = 2;
	for(int i = linhas-1; i>=0 ;i--){
		vetorRespostas[i] = (matriz[i][colunas-1] - sum)/matriz[i][colunas-k];
		sum = 0;
		for(int j = linhas-1; j>=0 ; j--){
			sum += vetorRespostas[j] * matriz[i-1][j];
		}
		k++;
	}
	//Impressão do vetor de respostas
	printf("\n");
  	printf("Vetor de Respostas:\n");
	for (int i = 0; i < linhas; ++i){
		printf("x%d = %.3f\n",i+1, vetorRespostas[i]);
	}

	return 0;
}
