//LINK to the Problem:
//https://www.hackerearth.com/practice/algorithms/graphs/breadth-first-search/practice-problems/algorithm/bfs/
//Problem type: BFS

#include<iostream>
#include<vector>
#include<unordered_set>
#include<queue>
using namespace std;

struct node
{
	int id_node;
	int distance;
};
typedef node node;

int how_many_nodes(vector<vector<node> > &graph, int level)
{
	int cont = 0;

	node aux, root;

	unordered_set<int> nodes_already_visited;

	queue<node> nodes_to_be_search;

	root.id_node = 1;
	root.distance = 0;

	nodes_to_be_search.push(root);

	nodes_already_visited.insert(1);

	if(level == 1)
		return 1;

	while(nodes_to_be_search.size() != 0)
	{
		aux = nodes_to_be_search.front();
		
		nodes_to_be_search.pop();

		for(int j = 0; j < graph[aux.id_node].size(); j++)
		{
			if(nodes_already_visited.count(graph[aux.id_node][j].id_node) == 0)
			{
		
				nodes_already_visited.insert(graph[aux.id_node][j].id_node);

				graph[aux.id_node][j].distance = aux.distance + 1;

				if(graph[aux.id_node][j].distance > level - 1)
					return cont;
				

				if(graph[aux.id_node][j].distance == level - 1)
					cont++;
				
				nodes_to_be_search.push(graph[aux.id_node][j]);
				
			}

		}

	}

	return cont;



}


int main()
{

	int num_nodes, level;

	node node_a, node_b;

	cin >> num_nodes;

	vector<node> adjacency_nodes;

	vector<vector<node> > adjacency_list(num_nodes + 1, adjacency_nodes);

	for(int i = 0; i < num_nodes - 1; i++)
	{
		cin >> node_a.id_node >> node_b.id_node;

		node_a.distance = 0;
		node_b.distance = 0;


		(adjacency_list[node_a.id_node]).push_back(node_b);
		(adjacency_list[node_b.id_node]).push_back(node_a);
	}

	

	cin >> level;

	cout << how_many_nodes(adjacency_list, level) << endl;

	return 0;
}

/*






















*/