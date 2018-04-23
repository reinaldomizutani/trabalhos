/*
Introdução a Teoria da Computação - turma 2018
Alunos:
Hugo de Azevedo Vitulli  			10295221
Matheus Vinicius Gouvea de Godoi  	10295217
Reinaldo Mizutani					7062145
*/

#include <vector>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define MAX 100

using namespace std;

typedef pair<int,char> parIntChar;
typedef vector<parIntChar> vetorParIntChar;
typedef vector<int> vetorInt;

typedef struct{
	int nVert;
	int nEdge;
	vector<vetorParIntChar> listaAdj;
}Grafo;

Grafo iniciaGrafo(int nVert){
	Grafo g;
	g.nVert = nVert;
	g.listaAdj.resize(nVert);
	return g;
}

//Adcionar aresta no grafo
void addAresta(Grafo *g, int noV, int noW, char peso){
	g->listaAdj[noV].push_back(make_pair(noW, peso));
}

//Função para imprimir grafo 
void printGrafo(Grafo g){
	for(unsigned int i = 0; i < g.listaAdj.size(); i++){
		printf("[%d]\n",i);
		for(unsigned int j = 0; j < g.listaAdj[i].size(); j++){
			printf("%d %c\n",g.listaAdj[i][j].first, g.listaAdj[i][j].second);
		}
	}
}

bool checaFrase(Grafo g, int vertAtual, char frase[], char terminal[], char aceitacao[]){
	
	//checar se a cadeia tem terminais válidos somente
	for (unsigned int i = 0; i < strlen(frase); i++){				//Pra todo caracter da cadeia
		int flagTerminalExiste = 0;
		for(unsigned int j = 0; j < strlen(terminal); j++){				//Pra todo terminal
			if(frase[i]==terminal[j]){								//Se encontrar um terminal igual, ele existe
				flagTerminalExiste = 1;
				break;
			}
		}
		if(!flagTerminalExiste){							//Caso não encontre, já não é possivel aceitar
			return false;
		}
	}


	//checa a cadeia no automato
	for (unsigned int i = 0; i < strlen(frase); i++)	{				//Pra todo caracter da cadeia
		int flagEncontrouPeso = 0;
		for (unsigned int j = 0; j < g.listaAdj[vertAtual].size(); j++){			//Pra toda ligação de cada estado
			if(g.listaAdj[vertAtual][j].second == '#'){						//Remove auxiliares
				continue;
			}
			if(g.listaAdj[vertAtual][j].second == frase[i]){			//Se encontrar uma ligacao
				vertAtual = g.listaAdj[vertAtual][j].first;					//Usa essa ligacao como qX atual para continuar processando
				flagEncontrouPeso = 1;
				break;
			}
		}
		if(!flagEncontrouPeso){								//Caso não encontre, cadeia é inválida
			return false;
		}
	}

	//checa estados de aceitacao
	for(unsigned int j = 0; j < strlen(aceitacao); j++){			//Para todo estado de aceitação
		if(aceitacao[j] == ' '){							//Ignora o espaço no meio do vetor
			continue;
		}
		if(vertAtual == (aceitacao[j] - 48)){				//Caso o vertice que parou seja existente na aceitação, a cadeia é válida
			return true;
		}
	}
	return false;
}

int main(){
	//Todas variaveis utilizadas
	int nVert = 0;
	char vetorTerminais[MAX];
	char estadosIniciais[MAX];
	char vetorAceitacao[MAX];
	char fraseTestar[MAX];
	int numArestas = 0;
	int numTestes = 0;
	int noV = 0;
	int noW = 0;
	int vertAtual = 0;
	char peso = 0;
	bool flagFrase = false;
	int contadorSaida = 1;
	Grafo g;

	//Número de estados do grafo
	scanf("%d\n",&nVert);
	g = iniciaGrafo(nVert);

	//Vetor de caracteres terminais
	scanf("%[^\n]s",vetorTerminais);
	getchar();

	//Vetor dos estados Iniciais
	scanf("%[^\n]s",estadosIniciais);
	getchar();
	//Para todos iniciais, inicia o estado com uma ligação para o estado -1, de peso 'i', para sabermos que é inicial
	for(unsigned int i = 0; i < strlen(estadosIniciais); i++){
		if(estadosIniciais[i] == ' '){
			continue;
		}
		addAresta(&g, estadosIniciais[i]-48, -1, 'i');
	}
	//Os que não são iniciais, recebem uma auxiliar -1, '#', para completar as primeiras ligações de cada estado
	for(int i = strlen(estadosIniciais); i < nVert; i++){
		addAresta(&g, i, -1, '#');
	}

	//Vetor de aceitação
	scanf("%[^\n]s",vetorAceitacao);
	getchar();

	//Número de ligações entre estados
	scanf("%d\n",&numArestas);

	for (int i = 0; i < numArestas; i++){			//Cada ligação entre estados é uma nova aresta no grafo
		scanf("%d %c %d\n",&noV, &peso, &noW);
		addAresta(&g, noV, noW, peso);	
	}

	//Número de frases para testar
	scanf("%d\n",&numTestes);
	for(int i = 0; i < numTestes; i++){			//Para cada frase de teste
		scanf("%[^\n]s",fraseTestar);				//Pegar a frase
		getchar();
		flagFrase = false;
		for(int j = 0; j < g.nVert; j++){		//Para todo nó no grafo
			if(g.listaAdj[j][0].second == 'i'){		//Checar os iniciais, e chamar a função com TODOS iniciais
				vertAtual = j;
				flagFrase = checaFrase(g, vertAtual, fraseTestar, vetorTerminais, vetorAceitacao);
				if(flagFrase){
					printf("%d. aceita\n",contadorSaida);				//Caso um inicial tenha resposta 'aceita', não é presciso checar os outros
					contadorSaida++;
					break;
				}
			}
		}
		if(!flagFrase){							//Caso nenhum inicial tenha tido 'aceita', então a frase é rejeitada
			printf("%d. rejeita\n",contadorSaida);
			contadorSaida++;
		}
	}

	return 0;
}
