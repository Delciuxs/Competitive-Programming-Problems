//LINK to the Problem:
//http://www.spoj.com/problems/TOPOSORT/
//Problem type: Topological Sort

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main()
{
	int num_sticks, num_contact_points, a, b;

	cin >> num_sticks >> num_contact_points;

	vector<int> adjacency_nodes;
	vector<vector<int> > adjacency_list(num_sticks + 1, adjacency_nodes);
	vector<int> in_degree(num_sticks + 1, 0);
	vector<int> topological_sort;
	priority_queue<int> aux_for_topo_sort;
	int cont = 0, aux_vertex;

	for(int i = 0; i < num_contact_points; i++)
	{
		cin >> a >> b;
		adjacency_list[a].push_back(b);
		in_degree[b]++;
	}	

	for(int i = 1; i < in_degree.size(); i++)
		if(in_degree[i] == 0)
			aux_for_topo_sort.push(i * -1);

	while(aux_for_topo_sort.size() != 0)
	{
		aux_vertex = aux_for_topo_sort.top() * -1;
		topological_sort.push_back(aux_vertex);
		aux_for_topo_sort.pop();

		cont++;

		for(int i = 0; i < adjacency_list[aux_vertex].size(); i++)
		{
			in_degree[adjacency_list[aux_vertex][i]]--;
			if(in_degree[adjacency_list[aux_vertex][i]] == 0)
				aux_for_topo_sort.push(adjacency_list[aux_vertex][i] * -1);
		}

	}

	if(cont != num_sticks)
		cout << "Sandro fails." << endl;

	else
	{
		for(int i = 0; i < topological_sort.size(); i++)
			cout << topological_sort[i] << " ";
		cout << endl;
	}

	
	return 0;
}

