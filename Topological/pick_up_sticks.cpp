//LINK to the Problem:
//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2733
//Problem type: Topological Sort

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main()
{
	int num_sticks, num_contact_points, a, b;

	cin >> num_sticks >> num_contact_points;

	while(num_sticks + num_contact_points != 0)
	{
		vector<int> adjacency_nodes;
		vector<vector<int> > adjacency_list(num_sticks + 1, adjacency_nodes);
		vector<int> in_degree(num_sticks + 1, 0);
		vector<int> topological_sort;
		queue<int> aux_for_topo_sort;
		int cont = 0, aux_vertex;

		for(int i = 0; i < num_contact_points; i++)
		{
			cin >> a >> b;
			adjacency_list[a].push_back(b);
			in_degree[b]++;
		}	

		for(int i = 1; i < in_degree.size(); i++)
			if(in_degree[i] == 0)
				aux_for_topo_sort.push(i);

		while(aux_for_topo_sort.size() != 0)
		{
			aux_vertex = aux_for_topo_sort.front();
			topological_sort.push_back(aux_vertex);
			aux_for_topo_sort.pop();

			cont++;

			for(int i = 0; i < adjacency_list[aux_vertex].size(); i++)
			{
				in_degree[adjacency_list[aux_vertex][i]]--;
				if(in_degree[adjacency_list[aux_vertex][i]] == 0)
					aux_for_topo_sort.push(adjacency_list[aux_vertex][i]);
			}

		}

		if(cont != num_sticks)
			cout << "IMPOSSIBLE" << endl;

		else
		{
			for(int i = 0; i < topological_sort.size(); i++)
				cout << topological_sort[i] << endl;
		}

		cin >> num_sticks >> num_contact_points;
	}

	return 0;
}

