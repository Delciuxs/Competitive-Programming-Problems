//LINK to the Problem:
//https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=216
//Problem type: DFS

#include<iostream>
#include<vector>
#include<set>

using namespace std;

void DFS(vector<vector<int> > &adjacency_list, int node_to_be_search, set<int> &already_visited)
{
	
	for(int i = 0; i < adjacency_list[node_to_be_search].size(); i++)
	{
		if(already_visited.count(adjacency_list[node_to_be_search][i]) == 0)
		{
			already_visited.insert(adjacency_list[node_to_be_search][i]);
			DFS(adjacency_list, adjacency_list[node_to_be_search][i], already_visited);
		}
	}
}

int main()
{
	int num_vertices, starting_vertex, node, how_many_searches;

	cin >> num_vertices;

	while(num_vertices != 0)
	{
		vector<int> adjacency_nodes;
		vector<vector<int> > adjacency_list(num_vertices + 1, adjacency_nodes);

		cin >> starting_vertex;

		while(starting_vertex != 0)
		{
			cin >> node;

			while(node != 0)
			{
				adjacency_list[starting_vertex].push_back(node);
				cin >> node;	
			}
			
			cin >> starting_vertex;
				
		}

		cin >> how_many_searches;

		vector<int> vertex_to_be_investigated(how_many_searches);

		for(int i = 0; i < how_many_searches; i++)
			cin >> vertex_to_be_investigated[i];

		for(int i = 0; i < how_many_searches; i++)
		{
			set<int> already_visited;
			vector<int> solution;

			DFS(adjacency_list, vertex_to_be_investigated[i], already_visited);

			for(int i = 1; i <= num_vertices; i++)
			{
				if(already_visited.count(i) == 0)
					solution.push_back(i);
			}

			cout << solution.size();

			for(int i = 0; i < solution.size(); i++)
				cout << " " << solution[i];

			cout << endl;

		}
	
		cin >> num_vertices;
	}

	return 0;
}