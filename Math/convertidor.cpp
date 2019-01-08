//LINK to the Problem:
//https://omegaup.com/arena/problem/OMI2018-Convertidor#problems
//Problem type: Modular Arithmetic

#include<iostream>
#include<vector>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);	
	cout.tie(0);

	int tipo_convesion;

	cin >> tipo_convesion;

	vector<char> alfabeto(26);

	alfabeto[0] = 'Z';

	char c = 'A';
	
	for(int i = 1; i < 26; i++, c++) 
		alfabeto[i] = c;
	
	if(tipo_convesion == 0)
	{
		long long int numero, coeficiente;
		string respuesta = "";

		cin >> numero;

		if(numero <= 26)
		{
			respuesta += alfabeto[numero % 26];
		}

		else
		{
			if(numero % 26 == 0)
			{
				respuesta += alfabeto[numero % 26];	
				coeficiente = numero / 26;
				coeficiente--;
			}

			else
			{
				respuesta += alfabeto[numero % 26];			
				coeficiente = numero / 26;
			}
			

			while(coeficiente > 26)
			{

				if(coeficiente % 26 == 0)
				{
					respuesta += alfabeto[coeficiente % 26];	
					coeficiente = coeficiente / 26;
					coeficiente--;
				}

				else
				{
					respuesta += alfabeto[coeficiente % 26];			
					coeficiente = coeficiente / 26;
				}
			}

			respuesta+= alfabeto[coeficiente % 26];
		}		

		string invertida = "";

		for(int s = respuesta.size() - 1; s >= 0; s--)
			invertida += respuesta[s];

		cout << invertida << "\n";
	}

	else
	{
		int residuo;
		long long int num;
		string cadena_num;

		cin >> cadena_num;

		if(cadena_num.size() == 1)
		{
			num = cadena_num[0] - 'A';
			num++;
		}

		else
		{
			vector<int> residuos;
			for(int i = 0; i < cadena_num.size(); i++)
			{
				residuo = cadena_num[i] - 'A';
				residuo++;
				residuos.push_back(residuo);
			}

			num = residuos[0];

			for(int i = 0; i < residuos.size() - 1; i++)
			{
				num = (num * 26) + residuos[i + 1];
			}
		}
		
		cout << num << "\n";
	}

	return 0;
}