#include "arv.c"

int main(){
	char *fraseAux = NULL;	
	char frase[100];
	int i;
	fraseAux = lerstr();
	//printf("%s", fraseAux);
	
	for(i=0 ; i<100 ; i++){
		frase[i] = fraseAux[i];
	}
	frase[100] = '\0';
	//printf("%s", frase);
	
	return 0;
}