//LINK to the Problem:
//https://omegaup.com/arena/problem/Buscador#problems
//Problem type: Dynamic Programming

#include<iostream>
#include<vector>
using namespace std;

int lcs(string palabra_ingresada, string diccionario, int m, int n, vector<vector<int> > &memo)
{
	int aux1, aux2, num_coincidencias = 0;

	if(memo[m][n] != -1)
		return memo[m][n];

	if(m == 0 || n == 0)
		num_coincidencias = 0;

	else if(palabra_ingresada[m - 1] == diccionario[n - 1])
		num_coincidencias = 1 + lcs(palabra_ingresada, diccionario, m - 1, n - 1, memo);

	else
	{
		aux1 = lcs(palabra_ingresada, diccionario, m, n - 1, memo);
		aux2 = lcs(palabra_ingresada, diccionario, m - 1, n, memo);

		num_coincidencias = max(aux1, aux2);
	}

	memo[m][n] = num_coincidencias;
	return num_coincidencias;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	string palabra_ingresada, palabra_mas_parecida;
	int num_palabras, tam_palabra_ingresada, coincidencias;
	int mayor_coincidencia = -1;

	cin >> palabra_ingresada ;
	cin >> num_palabras;

	vector<string> palabras(num_palabras);

	tam_palabra_ingresada = palabra_ingresada.size();


	for(int i = 0; i < num_palabras; i++)
		cin >> palabras[i];

	for(int i = 0; i < palabras.size(); i++)
	{
		vector<int> horizontal(palabras[i].size() + 3, -1);
		vector<vector<int> > memoria(tam_palabra_ingresada + 3, horizontal);

		coincidencias = lcs(palabra_ingresada, palabras[i], tam_palabra_ingresada, palabras[i].size(), memoria);

		if(coincidencias > mayor_coincidencia)
		{
			mayor_coincidencia = coincidencias;
			palabra_mas_parecida = palabras[i];
		}

		else if(coincidencias == mayor_coincidencia)
		{
			if(palabras[i].size() < palabra_mas_parecida.size())
				palabra_mas_parecida = palabras[i];
		}

	}

	cout << palabra_mas_parecida << "\n";

	return 0;
}