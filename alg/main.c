#include "alg.c"


#include<time.h>



int main(){
    unsigned nusp = 7062145;
    srand((nusp));
    int i=0, size, X, erro=0;
    fila F;
    no *aux=NULL;
    aux = (no*)malloc(sizeof(no));
    
    criaFila(&F);
    scanf("%d", &size);
    for(i=0 ; i<size ; i++){
        X = rand()%5000;
        inserir(&F, &X, &erro);
    }
    imprimeFila(&F);
    return 0;
}