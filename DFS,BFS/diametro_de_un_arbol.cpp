//LINK to the Problem:
//https://omegaup.com/arena/problem/diametroarbol#problems
//Problem type: BFS

#include<iostream>
#include<vector>
#include<unordered_set>
#include<queue>

using namespace std;

struct vertice
{
	int id_node;
	int distance;
};

typedef vertice vertice;


vertice furthest_node(vertice node_source, vector<vector<vertice> > &adjacency_list)
{
	vertice node_aux;

	unordered_set<int> visited;

	queue<vertice> nodes;

	nodes.push(node_source);

	visited.insert(node_source.id_node);

	while(nodes.size() != 0)
	{
		node_aux = nodes.front();

		nodes.pop();

		for(int s = 0; s < adjacency_list[node_aux.id_node].size(); s++)
		{
			if(visited.count(adjacency_list[node_aux.id_node][s].id_node) == 0)
			{
				adjacency_list[node_aux.id_node][s].distance = node_aux.distance + 1;

				visited.insert(adjacency_list[node_aux.id_node][s].id_node);

				nodes.push(adjacency_list[node_aux.id_node][s]);
			}
		}
	}

	return node_aux;
}

int main()
{
	int num_vertices;
	
	vertice u, v, aux1, first_further_vertice, furthest_vertice;

	cin >> num_vertices;

	vector<vertice> adjacency_nodes;

	vector<vector<vertice> > adjacency_list(num_vertices + 1, adjacency_nodes);

	for(int i = 0; i < num_vertices - 1; i++)
	{
		cin >> u.id_node >> v.id_node;
		
		u.distance = 0;
		v.distance = 0;

		adjacency_list[u.id_node].push_back(v);
		adjacency_list[v.id_node].push_back(u);
	}

	aux1.id_node = 1;
	aux1.distance = 0;

	first_further_vertice = furthest_node(aux1, adjacency_list);

	first_further_vertice.distance = 0;

	furthest_vertice = furthest_node(first_further_vertice, adjacency_list);

	cout << furthest_vertice.distance << endl;

	return 0;
}