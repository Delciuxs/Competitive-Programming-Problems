//LINK to the Problem:
//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2391
//Problem type: Bipartite

#include<iostream>
#include<vector>
#include<queue>
#include<set>
using namespace std;

vector<int> colors;

bool claw_decomposition(int node, vector<vector<int> > &adjacency_list)
{
	int aux_node;

	queue<int> nodes;
	set<int> visited;

	nodes.push(node);
	visited.insert(node);
	colors[node] = -1;

	while(nodes.size() != 0)
	{
		aux_node = nodes.front();
		nodes.pop();

		for(int i = 0; i < adjacency_list[aux_node].size(); i++)
		{
			if(visited.count(adjacency_list[aux_node][i]) == 0)
			{
				visited.insert(adjacency_list[aux_node][i]);
				colors[adjacency_list[aux_node][i]] = colors[aux_node] * -1;
				nodes.push(adjacency_list[aux_node][i]);
			}

			else if(colors[adjacency_list[aux_node][i]] == colors[aux_node])
				return false;
		}
	}

	return true;
}

int main()
{
	int num_nodes, num_edges, u, v;

	cin >> num_nodes;

	while(num_nodes != 0)
	{
		colors.resize(num_nodes + 1);
		vector<int> adjacency_nodes;
		vector<vector<int> > adjacency_list(num_nodes + 1, adjacency_nodes);
		bool can_be_decomposed = true;

		cin >> u >> v;

		while(u + v != 0)
		{
			adjacency_list[u].push_back(v);
			adjacency_list[v].push_back(u);

			cin >> u >> v;
		}

		for(int i = 1; i < num_nodes + 1; i++)
		{	
			if(claw_decomposition(i, adjacency_list) == false)
			{
				can_be_decomposed = false;
				break;
			}

		}

		if(can_be_decomposed)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;

		cin >> num_nodes;
	}


	return 0;
}