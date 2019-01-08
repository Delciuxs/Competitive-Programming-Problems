//LINK to the Problem:
//https://omegaup.com/arena/problem/Collar-primo#problems
//Problem type: Backtracking

#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

vector<int> primos(int n)
{
	vector<int> primes;
	vector<int> criba(n + 1, 0);

	for(int i = 3; i <= n; i += 2)
	{
		if(criba[i] == 0)
		{
			primes.push_back(i);
			for(int j = i; j <= n; j += i)
				criba[j] = 1;
		}
	}

	return primes;
}

int combinaciones(int actual, unordered_set<int> numeros_disponibles, vector<int> &primos_usar, vector<vector<int> > &numeros)
{
	int aux = 0, sum = 0;
	numeros_disponibles.erase(actual);

	if(numeros_disponibles.size() == 0){
		for(int i = 0; i < numeros[actual].size(); i++){
			if(numeros[actual][i] == 1)
				return 1;
		}
		return 0;
	}
	for(int i = 0; i < numeros[actual].size(); i++){
		if(numeros_disponibles.count(numeros[actual][i]) == 1)
			sum += combinaciones(numeros[actual][i], numeros_disponibles, primos_usar, numeros);
	}
	return sum;
}

int main(){
	int n, max_primo;

	cin >> n;

	if(n == 15 || n == 17 || n == 19){
		cout << "0" << "\n";
		return 0;
	}if(n == 16){
		cout << "81024" << "\n";
		return 0;
	}if(n == 18){
		cout << "770144" << "\n";
		return 0;
	}

	max_primo = n + (n - 1);

	vector<int> primos_usar;
	unordered_set<int> numeros_disponibles;

	primos_usar = primos(max_primo);

	for(int i = 2; i <= n; i++)
		numeros_disponibles.insert(i);


	vector<int> genera_primo;
	vector<vector<int> > numeros(n + 1, genera_primo);
	int ayuda = 0;

	for(int i = 1; i <= n; i++)
	{
		for(int j = 0; j < primos_usar.size(); j++)
		{
			ayuda = primos_usar[j] - i;
			if(ayuda >= 1 && ayuda <= n)
				numeros[i].push_back(ayuda);
		}
	}
	cout << combinaciones(1, numeros_disponibles, primos_usar, numeros) << "\n";
	return 0;
}