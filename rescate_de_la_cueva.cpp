//LINK to the Problem:
//https://omegaup.com/arena/problem/cueva#problems
//Problem type: Iterative DFS

#include<iostream>
#include<vector>
#include<stack>

using namespace std;

void iterative_DFS(int actual_node, vector<vector<int> > &adjacency_list, vector<int> &times_arrival, vector<int> &times_exit, vector<bool> &visited)
{
	int t = 1, aux;
	stack<int> s;

	s.push(actual_node);
	visited[actual_node] = true;

	while(s.size() != 0)
	{
		
		aux = s.top(); 

		if(times_arrival[aux] == -1)
			times_arrival[aux] = t;		

		for(int sa = 0; sa < adjacency_list[aux].size(); sa++)
		{
			if(visited[adjacency_list[aux][sa]] == true)
				continue;

			else
			{
				t++;
				visited[adjacency_list[aux][sa]] = true;
				s.push(adjacency_list[aux][sa]);
			}
			
		}

		if(s.top() == aux)
		{
			t++;
			times_exit[s.top()] = t;
			s.pop();
			t++;
		}
	}
}


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);	
	cout.tie(0);

	int n, querys, u, v;

	cin >> n >> querys;

	vector<int> adjacency_nodes;
	vector<vector<int> > adjacency_list(n + 1, adjacency_nodes);

	vector<int> times_arrival(n + 1, -1);
	vector<int> times_exit(n + 1);
	vector<bool> visited(n + 1, false);

	for(int i = 0; i < (n - 1); i++)
	{
		cin >> u >> v;

		adjacency_list[u].push_back(v);
		adjacency_list[v].push_back(u);
	}	


	iterative_DFS(1, adjacency_list, times_arrival, times_exit, visited);

	int origin, landslice;

	for(int sa = 0; sa < querys; sa++)
	{
		cin >> landslice >> origin;

		if(landslice == origin)
			cout << "0\n";

		else
		{
			if((times_arrival[landslice] < times_arrival[origin]) && (times_exit[origin] < times_exit[landslice]))
				cout << "0\n";
			else
				cout << "1\n";
		}
	}

	return 0;
}