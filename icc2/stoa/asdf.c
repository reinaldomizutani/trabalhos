#include "asdf.h"
void crialista(lista *L){
    L->ini = NULL;
    L->fim = NULL;
}

void criaHash(esp *H){
    printf("CHEGOU NO CRIAHASH\n");
    crialista(&H.zero);
    crialista(&H.um);
    crialista(&H.dois);
    crialista(&H.tres);
    crialista(&H.quatro);
    crialista(&H.cinco);
    crialista(&H.seis);
    crialista(&H.sete);
    crialista(&H.oito);
    crialista(&H.nove);

}


void separaHash(int x, esp *H){
    int teste = x;
    int aux = teste%10;
    no *temp;
    temp = (no*)malloc(sizeof(no));
    temp->elem = x;

    switch(aux){
    case 0:
        if(H->zero->ini == NULL){
            H->zero->ini = temp;
            H->zero->fim = temp;
        }
        else{
            H->zero->fim->prox = temp;
            H->zero->fim = temp;
        }
        break;
    case 1:
    if(H->um->ini == NULL){
            H->um->ini = temp;
            H->um->fim = temp;
        }
        else{
            H->um->fim->prox = temp;
            H->um->fim = temp;
        }
        break;
    case 2:
        if(H->dois->ini == NULL){
            H->dois->ini = temp;
            H->dois->fim = temp;
        }
        else{
            H->dois->fim->prox = temp;
            H->dois->fim = temp;
        }
        break;
    case 3:
        if(H->tres->ini == NULL){
            H->tres->ini = temp;
            H->tres->fim = temp;
        }
        else{
            H->tres->fim->prox = temp;
            H->tres->fim = temp;
        }
        break;
    case 4:
        if(H->quatro->ini == NULL){
            H->quatro->ini = temp;
            H->quatro->fim = temp;
        }
        else{
            H->quatro->fim->prox = temp;
            H->quatro->fim = temp;
        }
        break;
    case 5:
        if(H->cinco->ini == NULL){
            H->cinco->ini = temp;
            H->cinco->fim = temp;
        }
        else{
            H->cinco->fim->prox = temp;
            H->cinco->fim = temp;
        }
        break;
    case 6:
        if(H->seis->ini == NULL){
            H->seis->ini = temp;
            H->seis->fim = temp;
        }
        else{
            H->seis->fim->prox = temp;
            H->seis->fim = temp;
        }
        break;
    case 7:
        if(H->sete->ini == NULL){
            H->sete->ini = temp;
            H->sete->fim = temp;
        }
        else{
            H->sete->fim->prox = temp;
            H->sete->fim = temp;
        }
        break;
    case 8:
        if(H->oito->ini == NULL){
            H->oito->ini = temp;
            H->oito->fim = temp;
        }
        else{
            H->oito->fim->prox = temp;
            H->oito->fim = temp;
        }
        break;
    case 9:
        if(H->nove->ini == NULL){
            H->nove->ini = temp;
            H->nove->fim = temp;
        }
        else{
            H->nove->fim->prox = temp;
            H->nove->fim = temp;
        }
        break;
    }
}
