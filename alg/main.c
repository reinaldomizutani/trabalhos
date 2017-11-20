#include "alg.c"


#include<time.h>



int main(){
    unsigned nusp = 7062145;
    srand((nusp));
    int i=0, size, X, erro=0;
    fila F;
    no *aux=NULL;
    aux = (no*)malloc(sizeof(no));
    
    scanf("%d", &size);
    criaFila(&F, size);
    for(i=0 ; i<size ; i++){
        X = rand()%500;
        inserir(&F, &X, &erro, &i);
    }
    bubbleSort(&F, size, 0);
    imprimeFila(&F);
    printf("SIZE = %d", F.tam);
    
    return 0;
}