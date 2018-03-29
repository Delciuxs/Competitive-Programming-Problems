//LINK to the Problem:
//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=4027
//Problem type: DFS properties

#include<iostream>
#include<stack>
#include<map>

using namespace std;

int main()
{
	int t;
	pair<char, int> aux;
	string secuence_travel;
	char entrance;

	cin >> t;

	for(int i = 0; i < t; i++)
	{
		stack<int> trails;
		map<char, int> sprinklers;

		cin >> secuence_travel;	

		entrance = secuence_travel[0];
		
		trails.push(secuence_travel[0]);

		aux.first = entrance;
		aux.second = 0;

		sprinklers.insert(aux);

		for(int j = 1; j < secuence_travel.size(); j++)
		{
			if(sprinklers.count(secuence_travel[j]) == 0)
			{
				sprinklers[trails.top()]++;

				aux.first = secuence_travel[j];
				aux.second = 0;

				sprinklers.insert(aux);

				trails.push(secuence_travel[j]);

			}
			else
			{
				sprinklers[secuence_travel[j]]++;

				trails.pop();
			}
		}

		sprinklers[entrance]--;

		cout << "Case " << i + 1 << endl;

		for(auto x : sprinklers)
			cout << x.first << " = " << x.second << endl;
	}
	


	return 0;
}