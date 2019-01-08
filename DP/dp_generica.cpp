//LINK to the Problem:
//https://omegaup.com/arena/problem/DP-Generica#problems
//Problem type: Dynamic Programming

#include<iostream>
#include<map>
#include<cmath>
using namespace std;

typedef unsigned long long int un_lli;
typedef long long int ll_i;

int most_significante_bit(unsigned long long int num){
	int cont = 0;

	while(num != 0){
		cont++;
		num = (num >> 1ULL);
	}
	return (cont - 1);
}

ll_i DP(un_lli numero, int potencia, map<pair<un_lli, int>, ll_i> &memoria){
	pair<un_lli, int> auxiliar;
	int potencia_num;

	auxiliar.first = numero;
	auxiliar.second = potencia;

	potencia_num = most_significante_bit(numero);

	if(numero == 0)
		return 1;
	if(numero < 0 || potencia == -1)
		return 0;
	if(potencia + 1 >= potencia_num){
		if(memoria.count(auxiliar) == 0){
			if(potencia + 1 == 64)
				memoria[auxiliar] = DP(numero - (1ULL << potencia), potencia - 1, memoria) + DP(numero, potencia - 1, memoria);
			else
				memoria[auxiliar] = DP(numero - (1ULL << (potencia + 1)), potencia - 1, memoria) + DP(numero - (1ULL << potencia), potencia - 1, memoria) + DP(numero, potencia - 1, memoria);
		}
		return memoria[auxiliar];
	}
	else
		return 0;
}

int main(){
	unsigned long long int numero;
	int cuantos_bits;

	ll_i combinaciones;
	cin >> numero;

	cuantos_bits = most_significante_bit(numero);
	map<pair<un_lli, int>, ll_i> memoria;

	combinaciones = DP(numero, cuantos_bits, memoria);
	cout << combinaciones << endl;

	return 0;
}