//LINK to the Problem:
//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=945
//Problem type: Bipartite

#include<iostream>
#include<vector>
#include<set>
#include<queue>
using namespace std;

vector<int> colors;

bool Bipartite_Check(int node, vector<vector<int> > &adjacency_list)
{
	int red = 1, blue = -1, node_aux;

	queue<int> aux;
	set<int> visited;

	aux.push(node);
	colors[node] = red;
	visited.insert(node);

	while(aux.size() != 0)
	{
		node_aux = aux.front();
		aux.pop();

		for(int i = 0; i < adjacency_list[node_aux].size(); i++)
		{
			if(visited.count(adjacency_list[node_aux][i]) == 0)
			{
				visited.insert(adjacency_list[node_aux][i]);
				
				colors[adjacency_list[node_aux][i]] = colors[node_aux] * -1;
				
				aux.push(adjacency_list[node_aux][i]);
			}

			else
			{
				if(colors[node_aux] == colors[adjacency_list[node_aux][i]])
					return false;
			}
		}
	}

	return true;
}


int main()
{
	int number_nodes, number_edges;

	cin >> number_nodes;

	while(number_nodes != 0)
	{
		int u, v;

		cin >> number_edges;

		colors.resize(number_nodes);
		vector<int> adjacency_nodes;
		vector<vector<int> > adjacency_list(number_nodes, adjacency_nodes);

		for(int i = 0; i < number_edges; i++)
		{
			cin >> u >> v;

			adjacency_list[u].push_back(v);
			adjacency_list[v].push_back(u);
		}

		if(Bipartite_Check(0, adjacency_list))
			cout << "BICOLORABLE." << endl;
		else
			cout << "NOT BICOLORABLE." << endl;


		cin >> number_nodes;
	}

	

	return 0;
}