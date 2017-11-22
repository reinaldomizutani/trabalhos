#include "asdf.c"


int main(){
    int tam, i, temp;
    scanf("%d", &tam);
    srand(time(NULL));
    esp H;
    criaHash(&H);

    for(i=0 ; i<tam ; i++){
        temp = rand()%100;
        separaHash(temp, &H);
    }
    return 0;
}
