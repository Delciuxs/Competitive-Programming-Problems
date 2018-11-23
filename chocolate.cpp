//LINK to the Problem:
//https://omegaup.com/arena/problem/chocolate#problems
//Problem type: Greedy

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	int m, n;
	int sum1 = 0, sum2 = 0;
	pair<int, char> aux1;

	cin >> m >> n;

	vector<pair<int, char> > arr;

	int cortes_filas = 1;
	int cortes_columnas = 1;

	for (int i = 0; i < m - 1; ++i)
	{
		cin >> aux1.first;
		aux1.second = 'c'; 
		arr.push_back(aux1);
	}

	for (int i = 0; i < n - 1; ++i)
	{
		cin >> aux1.first;
		aux1.second = 'f';
		arr.push_back(aux1);
	}

	sort(arr.begin(), arr.end());

	for(int i = arr.size() - 1; i >= 0; i--)
	{
		if(arr[i].second == 'c')
		{
			sum1 += arr[i].first * cortes_filas;
			cortes_columnas++;
		}
		if(arr[i].second == 'f')
		{
			sum2 += arr[i].first * cortes_columnas;
			cortes_filas++;
		}
	}

	cout << sum1 + sum2 << endl;

	return 0;
}