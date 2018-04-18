//LINK to the Problem:
//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1403
//Problem type: Second best Spanning Tree

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct neighbor
{
	int commond_neighbor;
	int rank;
};

typedef neighbor neighbor;

vector<neighbor> neighbors;
int num_disjoint_sets;
int number_neighbors;
vector<int> connectios_used;

int find_commond_neighbor(int n)
{
	if(neighbors[n].commond_neighbor != n)
		neighbors[n].commond_neighbor = find_commond_neighbor(neighbors[n].commond_neighbor);
	return neighbors[n].commond_neighbor;
}

bool same_set(int n1, int n2)
{
	if(find_commond_neighbor(n1) == find_commond_neighbor(n2))
		return true;
	return false;
}

void join_sets(int n1, int n2)
{
	int commond_neighborA, commond_neighborB;

	commond_neighborA = find_commond_neighbor(n1);
	commond_neighborB = find_commond_neighbor(n2);

	num_disjoint_sets--;

	if(neighbors[commond_neighborA].rank > neighbors[commond_neighborB].rank)
		neighbors[commond_neighborB].commond_neighbor = commond_neighborA;

	else
	{
		neighbors[commond_neighborA].commond_neighbor = commond_neighborB;		
		if(neighbors[commond_neighborA].rank == neighbors[commond_neighborB].rank)
			neighbors[commond_neighborB].rank++;
	}
}

pair<int, int> second_way(int dont_use_this_connection, vector<pair<int, pair<int, int> > > &info_connections)
{
	int cost = 0;
	num_disjoint_sets = number_neighbors;
	pair<int, int> ans;
	pair<int, pair<int, int> > aux1;
	
	for(int j = 0; j < neighbors.size(); j++)
	{
		neighbors[j].commond_neighbor = j;
		neighbors[j].rank = 0;
	}

	for(int k = 0; k < info_connections.size(); k++)
	{
		if(num_disjoint_sets == 1)
			break;

		if(k == dont_use_this_connection)
			continue;

		else
		{
			aux1 = info_connections[k];

			if(!same_set(aux1.second.first, aux1.second.second))
			{
				ans.second += aux1.first;
				join_sets(aux1.second.first, aux1.second.second);
			}
		}
	}

	ans.first = num_disjoint_sets;
	return ans;
}

int main()
{
	int t;

	cin >> t;

	for(int i = 0; i < t; i++)
	{
		int num_connections, neighborA, neighborB, cost_network;
		vector<pair<int, pair<int, int> > > info_connections;
		pair<int, pair<int, int> > aux;

		cin >> number_neighbors >> num_connections;

		neighbors.clear();
		connectios_used.clear();
		neighbors.resize(number_neighbors + 1);

		for(int j = 0; j < neighbors.size(); j++)
		{
			neighbors[j].commond_neighbor = j;
			neighbors[j].rank = 0;
		}

		for(int j = 0; j < num_connections; j++)
		{
			cin >> neighborA >> neighborB >> cost_network;
			aux.first = cost_network;
			aux.second.first = neighborA;
			aux.second.second = neighborB;

			info_connections.push_back(aux);
		}

		if(number_neighbors == 1 && num_connections == 0)
		{
			cout << "Case #" << i + 1 << " : No second way\n";
			continue;
		}
		if(num_connections == 0)
		{
			cout << "Case #" << i + 1 << " : No way\n";
			continue;
		}

		sort(info_connections.begin(), info_connections.end());

		num_disjoint_sets = number_neighbors;
		int cost = 0;

		for(int s = 0; s < info_connections.size(); s++)
		{
			aux = info_connections[s];

			if(num_disjoint_sets == 1)
				break;

			if(!same_set(aux.second.first, aux.second.second))
			{
				cost += aux.first;
				join_sets(aux.second.first, aux.second.second);
				connectios_used.push_back(s);
			}
		}

		if(num_disjoint_sets != 1)
		{
			cout << "Case #" << i + 1 << " : No way\n";
			continue;
		}

		
		pair<int, int> second_cost, second_min_cost;


		second_min_cost.first = (1 << 30);
		second_min_cost.second = (1 << 30);


		for(int s = 0; s < connectios_used.size(); s++)
		{
			second_cost = second_way(connectios_used[s], info_connections);

			if(second_cost.first != 1)
				continue;

			else
			{
				if(second_cost.second < second_min_cost.second)
				{
					second_min_cost.second = second_cost.second;
					second_min_cost.first = second_cost.first;
				}
			}
			
		}

		if(second_min_cost.first != 1)
			cout << "Case #" << i + 1 << " : No second way\n";

		else
			cout << "Case #" << i + 1 << " : " << second_min_cost.second << "\n";
	}

	return 0;
}
