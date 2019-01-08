//LINK to the Problem:
//https://omegaup.com/arena/problem/Maximo-Elemento-en-la-Pila#problems
//Problem type: Data Structures

#include<iostream>
#include<vector>
#include<map>
#include<queue>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);	
	cout.tie(0);

	int n, tipo, tam;
	long long int num;
	vector<pair<long long int, long long int> > pila;
	priority_queue<pair<long long int, long long int> > pq;
	pair<long long int, long long int> aux, aux2;
	map<pair<long long int, long long int>, bool> borrados;

	cin >> n;

	for(int i = 0; i < n; i++)
	{
		cin >> tipo;

		if(tipo == 1)
		{
			cin >> num;

			pila.push_back(make_pair(num, i));
			pq.push(make_pair(num, i));
		}

		else if(tipo == 2)
		{
			tam = pila.size() - 1;
			aux = pila[tam];
			pila.pop_back();

			borrados[aux] = false;
		}

		else if(tipo == 3)
		{
			while(true)
			{
				aux2 = pq.top();

				if(borrados.count(aux2) == 1)
				{
					pq.pop();
					continue;
				}
				else
				{
					cout << aux2.first << "\n";
					break;
				}
			}
		}
	}	

	return 0;
}
