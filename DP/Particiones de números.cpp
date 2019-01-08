//LINK to the Problem:
//https://omegaup.com/arena/problem/Particiones-de-numeros#problems
//Problem type: DP

#include<iostream>
#include<vector>
using namespace std;

int n;

int DP(int suma_actual, int iterador, vector<vector<int> > &memoria)
{
	int aux = 0;

	if(suma_actual > n)
		return 0;

	else if(suma_actual == n)
		return 1;

	else if(memoria[suma_actual][iterador] == -1)
	{
		for(int i = iterador; i <= n; i++)
			aux += DP(suma_actual + i, i, memoria);

		memoria[suma_actual][iterador] = aux;
	}

	return memoria[suma_actual][iterador];
}

int main()
{
	cin >> n;

	vector<int> horizontal(n+10, -1);
	vector<vector<int> > memo(n+10, horizontal);

	cout << DP(0, 1, memo) << "\n";

	return 0;
}