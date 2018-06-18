//LINK to the Problem:
//https://omegaup.com/arena/problem/Hasta-cero#problems
//Problem type: BFS

#include<iostream>
#include<queue>
#include<cmath>
using namespace std;

int BFS(int num)
{
	int raiz, res = 0;
	pair<int, int> aux;

	queue<pair<int, int> > q;

	q.push(make_pair(num, 0));

	while(q.size() != 0)
	{
		aux = q.front();
		q.pop();

		if(aux.first <= 4)
        {
            if(aux.first == 4)
            	res = aux.second + 3;
            else
            	res = aux.second + aux.first;
            break;
        }

		raiz = sqrt(aux.first);

		for(int j = raiz; j >= 2; j--)
		{
			if(aux.first % j == 0)
				q.push(make_pair(aux.first / j, aux.second + 1));
		}

		q.push(make_pair(aux.first - 1, aux.second + 1));
	}
	return res;
}

int main()
{
	int querys;
	cin >> querys;

	for(int i = 0; i < querys; i++)
	{
		int  num;
		cin >> num;
		cout << BFS(num) << "\n";
	}

	return 0;
}