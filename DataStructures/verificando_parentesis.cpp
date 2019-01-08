//LINK to the Problem:
//https://omegaup.com/arena/problem/Check-brackets-in-the-code#problems
//Problem type: Data Structures

#include<iostream>
#include<stack>
using namespace std;

int main()
{
	string cadena;
	stack<pair<char, int> > pila;
	pair<char, int> aux;

	cin >> cadena;

	for(int i = 0 ; i < cadena.size(); i++)
	{
		if(cadena[i] == '{' || cadena[i] == '[' || cadena[i] == '(')
			pila.push(make_pair(cadena[i], i));

		if(cadena[i] == '}')
		{
			
			if(pila.size() == 0)
			{
				cout << i + 1 << endl;
				return 0;
			}
			else
			{
				aux = pila.top();
				if(aux.first == '{')
					pila.pop();
				else
				{
					cout << i + 1 << endl;
					return 0;
				}
			}
		}

		if(cadena[i] == ']')
		{
			
			if(pila.size() == 0)
			{
				cout << i + 1 << endl;
				return 0;
			}
			else
			{
				aux = pila.top();
				if(aux.first == '[')
					pila.pop();
				else
				{
					cout << i + 1 << endl;
					return 0;
				}
			}
		}

		if(cadena[i] == ')')
		{

			if(pila.size() == 0)
			{
				cout << i + 1 << endl;
				return 0;
			}
			else
			{
				aux = pila.top();
				if(aux.first == '(')
					pila.pop();
				else
				{
					cout << i + 1 << endl;
					return 0;
				}
			}
		}
	}

	if(pila.size() != 0)
	{
		aux = pila.top();
		cout << aux.second + 1 << endl;
	}

	else
		cout << "Success" << endl;

	return 0;
}