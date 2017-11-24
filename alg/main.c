#include "alg.c"




int main(){
    unsigned nusp = 7062145;
    int i=0, size, X, erro=0;
    fila F;
    no *aux=NULL;
    
	aux = (no*)malloc(sizeof(no));
        
    srand((nusp));
    
	scanf("%d", &size);
    criaFila(&F, size);
    
	for(i=0 ; i<size ; i++){
        X = rand()%500;
        inserir(&F, &X, &erro, &i);
    }
    
    //insertionSort(&F, size, 1);

	
    mergeSortC(&F);
    imprimeFila(&F);


    return 0;
}
