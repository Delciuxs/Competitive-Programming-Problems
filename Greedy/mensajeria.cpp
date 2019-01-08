//LINK to the Problem:
//https://omegaup.com/arena/problem/OMI-2017-Mensajeria#problems
//Problem type: Greedy

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);	
	cout.tie(0);

	int n, k, minimo_costo, suma_parcial_camino = 0;

	cin >> n >> k;

	vector<int> cuarteles(n);

	for(int i = 0; i < n; i++)
		cin >> cuarteles[i];
	

	sort(cuarteles.begin(), cuarteles.end());

	minimo_costo = n * k;

	for(int i = 0; i < cuarteles.size() - 1; i++)
	{
		suma_parcial_camino += cuarteles[i];

		if(((n-1) * k) + suma_parcial_camino <= minimo_costo)
		{
			minimo_costo = ((n-1) * k) + suma_parcial_camino;
			n--;
		}
		else
			break;
	}

	cout << minimo_costo << "\n";

	return 0;
}