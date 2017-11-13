#include "couting.h"
#define TAM 50

int procuramaiorGdp(no *paises)
{
	int i, max=0;

	for (i=0; i<TAM; i++)
	{
		if (paises[i].gdp > max)
		{
			max = paises[i].gdp;
		}
	}
	return max;
}

void countingSortgdp(no *paises)
{
	int	i, n=0;
	int max = procuramaior(paises);
	int*Vetor2 =(int*)calloc(max,sizeof(int));

	for(i=0; i<TAM; i++)
	{
		Vetor2[paises[i].gdp]++;
	}

	i=0;

	while(i<TAM)
	{
		while(Vetor2[n]>0)
		{
			paises[i].gdp = n;
			Vetor2[n]--;
			i++;

			if(i>TAM)
			{
				break;
			}
		}
		n++;
	}
}
