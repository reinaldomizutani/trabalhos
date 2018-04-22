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

void addAresta(Grafo *g, int noV, int noW, char peso){
	g->listaAdj[noV].push_back(make_pair(noW, peso));
}

void printGrafo(Grafo g){
	for(unsigned int i = 0; i < g.listaAdj.size(); i++){
		printf("[%d] -> ",i);
		for(unsigned int j = 0; j < g.listaAdj[i].size(); j++){
			printf("[w=%d, p=%c]",g.listaAdj[i][j].first, g.listaAdj[i][j].second);
		}
		printf("\n");
	}
}

bool checaFrase(Grafo g, int vertAtual, char frase[]){

}

int main(){
	int nVert = 0;
	char vetorTerminais[MAX];
	int estadosIniciais = 0;
	char vetorAceitacao[MAX];
	char fraseTestar[MAX];
	int numArestas = 0;
	int numTestes = 0;
	int noV = 0;
	int noW = 0;
	int vertAtual = 0;
	char peso = 0;
	bool flagFrase = false;
	Grafo g;

	// primeira linha: número de estados
	scanf("%d\n",&nVert);
	g = iniciaGrafo(nVert);
	
	// segunda linha conjunto de símbolos terminais
	scanf("%[^\n]s",vetorTerminais);
	printf("%s\n", vetorTerminais);

	// número de estados iniciais
	scanf("%d\n",&estadosIniciais);

	for(int i = 0; i < estadosIniciais; i++){
		addAresta(&g, i, -1, 'i');
	}
	for(int i = estadosIniciais; i < nVert; i++){
		addAresta(&g, i, -1, '#');
	}

	// conjunto de estados de aceitação
	scanf("%[^\n]s",vetorAceitacao);

	//número de transições
	scanf("%d\n",&numArestas);

	// todas as transições
	for (int i = 0; i < numArestas; i++){
		scanf("%d %c %d\n",&noV, &peso, &noW);
		addAresta(&g, noV, noW, peso);	
	}
	printGrafo(g);

	// número de casos de teste
	scanf("%d\n",&numTestes);

	// verificando se a frase pode ser produzida pelo grafo
	for(int i = 0; i < numTestes; i++){
		scanf("%[^\n]s",fraseTestar);
		flagFrase = false;
		for(int j = 0; j < g.nVert; j++){
			if(g.listaAdj[j][0].first == 'i'){
				vertAtual = j;
				flagFrase = checaFrase(g, vertAtual, fraseTestar);
				if(flagFrase){
					printf("aceita\n");
					break;
				}
			}
		}
		if(!flagFrase){
			printf("rejeita\n");
		}
	}

	return 0;
}