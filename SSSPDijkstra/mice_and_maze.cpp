//LINK to the Problem:
//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3553
//Problem type: SSSP Dijkstra

#include<iostream>
#include<vector>
#include<queue>

using namespace std;

void Dijkstra(vector<int> &distances, vector<vector<pair<int, int> > > adjacency_list, int exit_cell)
{
	int distance, id_cell;
	pair<int, int> aux_pq, aux_adj_list;

	priority_queue<pair<int, int> > pq;
	pq.push(make_pair(0, exit_cell));

	while(pq.size() != 0)
	{
		aux_pq = pq.top();
		pq.pop();

		distance = aux_pq.first;
		id_cell = aux_pq.second;

		if(distance > distances[id_cell])
			continue;

		for(int s = 0; s < adjacency_list[id_cell].size(); s++)
		{
			aux_adj_list = adjacency_list[id_cell][s];

			if(distances[id_cell] + aux_adj_list.second < distances[aux_adj_list.first])
			{
				distances[aux_adj_list.first] = distances[id_cell] + aux_adj_list.second;	
				pq.push(make_pair(distances[aux_adj_list.first], aux_adj_list.first));
			}
		}
	}

}

int main()
{
	int t;

	cin >> t;

	for(int i = 0; i < t; i++)
	{
		int num_cells, exit_cell, time, num_connections, cellA, cellB, time_btw_cells, cont = 0;

		cin >> num_cells >> exit_cell >> time >> num_connections;

		vector<int> distances(num_cells + 1, 1000000);
		distances[exit_cell] = 0;

		vector<pair<int, int> > adjacency_cell;
		vector<vector<pair<int, int> > > adjacency_list(num_cells + 1, adjacency_cell); 

		for(int j = 0; j < num_connections; j++)
		{	
			cin >> cellA >> cellB >> time_btw_cells;
			adjacency_list[cellB].push_back(make_pair(cellA, time_btw_cells));
		}	

		Dijkstra(distances, adjacency_list, exit_cell);

		for(int j = 1; j < distances.size(); j++)
		{
			if(distances[j] <= time)
				cont++;
		}

		if(i == t - 1)
			cout << cont << "\n";
		else
			cout << cont << "\n\n";
		

	}


	return 0;
}