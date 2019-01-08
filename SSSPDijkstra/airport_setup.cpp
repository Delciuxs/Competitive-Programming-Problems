//LINK to the Problem:
//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2372
//Problem type: SSSP Dijkstra

#include<iostream>
#include<vector>
#include<unordered_set>
#include<algorithm>
#include<queue>
using namespace std;


void Dijkstra(vector<int> &airports_needed, vector<vector<pair<int, int> > > &adjacency_list, int source)
{
	int airports, id_city;
	pair<int, int> aux_pq, aux_adj_list;

	priority_queue<pair<int, int> > pq;

	pq.push(make_pair(0, source));

	while(pq.size() != 0)
	{
		aux_pq = pq.top();
		pq.pop();

		airports = -1 * aux_pq.first;
		id_city = aux_pq.second;

		if(airports > airports_needed[id_city])
			continue;
		for(int s = 0; s < adjacency_list[id_city].size(); s++)
		{
			aux_adj_list = adjacency_list[id_city][s];

			if(airports_needed[id_city] + aux_adj_list.second < airports_needed[aux_adj_list.first])
			{
				airports_needed[aux_adj_list.first] = airports_needed[id_city] + aux_adj_list.second;
				pq.push(make_pair(-1 * airports_needed[aux_adj_list.first], aux_adj_list.first));
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);	
	cout.tie(0);

	int t;

	cin >> t;

	for (int i = 0; i < t; ++i)
	{
		int num_cities, num_connections, num_cities_with_airports, airport, cityA, cityB;

		cin >> num_cities >> num_connections >> num_cities_with_airports;

		unordered_set<int> cities_with_airports;

		for(int j = 0 ; j < num_cities_with_airports; j++)
		{
			cin >> airport;
			cities_with_airports.insert(airport);
		}

		vector<pair<int, int> > adjacency_city;
		vector<vector<pair<int, int> > > adjacency_list(num_cities + 1, adjacency_city);

		for(int j = 0; j < num_connections; j++)
		{
			cin >> cityA >> cityB;

			if(cities_with_airports.count(cityA) == 1)
			{
				if(cities_with_airports.count(cityB) == 1)
				{
					adjacency_list[cityA].push_back(make_pair(cityB, 0));
					adjacency_list[cityB].push_back(make_pair(cityA, 0));
				}

				else
				{
					adjacency_list[cityA].push_back(make_pair(cityB, 1));
					adjacency_list[cityB].push_back(make_pair(cityA, 0));
				}

			}

			else
			{
				if(cities_with_airports.count(cityB) == 1)
				{
					adjacency_list[cityA].push_back(make_pair(cityB, 0));
					adjacency_list[cityB].push_back(make_pair(cityA, 1));
				}

				else
				{
					adjacency_list[cityA].push_back(make_pair(cityB, 1));
					adjacency_list[cityB].push_back(make_pair(cityA, 1));
				}
			}


		}

		int num_demands;
		cin >> num_demands;

		cout << "Case " << i + 1 << ":" << endl;
		
		for(int j = 0; j < num_demands; j++)
		{	
			cin >> cityA >> cityB;

			vector<int> airports_needed(num_cities + 1, 1000000);
			airports_needed[cityA] = 0;

			Dijkstra(airports_needed, adjacency_list, cityA);

			if(airports_needed[cityB] == 1000000)	
				cout << "-1\n";
			else
			{
				if(cities_with_airports.count(cityA) == 0)
				{
					if(cityA == cityB)
						cout << "0\n";
					else
						cout << airports_needed[cityB] + 1 << "\n";									
				}
				else
					cout << airports_needed[cityB] << "\n";	
			} 
			
		}
		cout << "\n";

		



	}

	return 0; 
}