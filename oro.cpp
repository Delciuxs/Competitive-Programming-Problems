//LINK to the Problem:
//https://omegaup.com/arena/problem/oro#problems
//Problem type: Dynamic Programming

#include <bits/stdc++.h>
using namespace std;

int resuelve(int posicion, int sum_oro, vector<int> &valores_rocas, int oro_req, vector<vector<int> > &memo)
{
	int aux2 = 0, aux1 = 0;

	if(posicion == valores_rocas.size()){
		memo[posicion][sum_oro] = sum_oro;
		return sum_oro;
	}else if(sum_oro >= oro_req){
		memo[posicion][sum_oro] = sum_oro;
		return sum_oro;
	}else if(memo[posicion][sum_oro] == -1){
		aux1 = resuelve(posicion + 1, sum_oro + valores_rocas[posicion], valores_rocas, oro_req, memo);
		aux2 = resuelve(posicion + 1, sum_oro, valores_rocas, oro_req, memo);

		if(aux1 < oro_req)
			aux1 = 1000000;
		if(aux2 < oro_req)
			aux2 = 1000000;

		memo[posicion][sum_oro] = min(aux1, aux2);
	}
	return memo[posicion][sum_oro];
}

int main()
{
	int num_rocas, oro_requerido;
	cin >> num_rocas >> oro_requerido;

	vector<int> valor_oro_rocas(num_rocas);

	for(int i = 0; i < num_rocas; i++)	
		cin >> valor_oro_rocas[i];

	vector<int> columnas(100000,-1);
	vector<vector<int> > memoria(num_rocas + 5,columnas);

	cout << resuelve(0, 0, valor_oro_rocas, oro_requerido, memoria) - oro_requerido;

	return 0;
}