//LINK to the Problem:
//https://omegaup.com/arena/problem/L-OMI2011-La-guardia-negra#problems
//Problem type: Greedy
	
#include<stdio.h>

int main()
{
	long long int filas, columnas, suma_parcial, valor, num_proyectiles, f, c, d;

	scanf("%lli", &filas);
	scanf("%lli", &columnas);

	long long int mapa[filas][columnas];
	long long int acarreos[filas][columnas];

	long long int i, j, s;

	for(i = 0; i < filas; i++)
	{
		suma_parcial = 0;
		for(j = 0; j < columnas; j++)
		{
			scanf("%lli", &valor);
			suma_parcial += valor;
			mapa[i][j] = valor;
			acarreos[i][j] = suma_parcial;
		}
	}

	long long int FA, FB, izq, der, total;

	scanf("%lli", &num_proyectiles);
	
	for(i = 0; i < num_proyectiles; i++)
	{
		total = 0;

		scanf("%lli", &f);
		scanf("%lli", &c);
		scanf("%lli", &d);

		FA = f - d;
		FB = f + d;

		izq = c;
		der = c;

		for(s = 0; s < d; s++)
		{
			total = total + acarreos[FA + s][der] - acarreos[FA + s][izq] + mapa[FA + s][izq] + acarreos[FB - s][der] - acarreos[FB - s][izq] + mapa[FB - s][izq];
			der++;
			izq--;			

		}

		total = total + acarreos[f][der] - acarreos[f][izq] + mapa[f][izq];

		printf("%lli\n", total);

	}

	return 0;
}