//LINK to the Problem:
//https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1989
//Problem type: MST Kruskal

#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std; 

struct city
{
	int commond_city;
	int rank;
};

typedef city city;

vector<city> cities;
int num_disjoint_sets;

int find_common_city(int c1)
{
	if(cities[c1].commond_city != c1)
		cities[c1].commond_city = find_common_city(cities[c1].commond_city);

	return cities[c1].commond_city;
}

bool same_set(int ci1, int ci2)
{
	if(find_common_city(ci1) == find_common_city(ci2))
		return true;
	else
		return false;
}

void join_cities(int city1, int city2)
{
	int commond_cityA, commond_cityB;

	commond_cityA = find_common_city(city1);
	commond_cityB = find_common_city(city2);

	if(cities[commond_cityA].rank > cities[commond_cityB].rank)
	{
		cities[commond_cityB].commond_city = commond_cityA;
		num_disjoint_sets = num_disjoint_sets - 1;
	}

	else
	{
		cities[commond_cityA].commond_city = commond_cityB;
		num_disjoint_sets = num_disjoint_sets - 1;

		if(cities[commond_cityA].rank == cities[commond_cityB].rank)
			cities[commond_cityB].rank = cities[commond_cityB].rank + 1;
	}
}



int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;

	cin >> t;

	for(int i = 0; i < t; i++)
	{
		int num_cities, num_links, cont = 0, cost_network, nodeA, nodeB;
		string cityA, cityB;

		map<string, int> cities_maped;

		cin >> num_cities >> num_links;

		vector<pair<int, pair<int, int> > > info_network;
		pair<int, pair<int, int> > aux, aux2;

		cities.resize(num_cities + 1);
		num_disjoint_sets = num_cities;

		for(int j = 0; j < cities.size(); j++)
		{
			cities[j].commond_city = j;
			cities[j].rank = 0;
		}

		for(int j = 0; j < num_links; j++)
		{
			cin >> cityA;

			if(cities_maped.count(cityA) == 0)
				cities_maped[cityA] = cont++;

			cin >> cityB;

			if(cities_maped.count(cityB) == 0)
				cities_maped[cityB] = cont++;

			nodeA = cities_maped[cityA];
			nodeB = cities_maped[cityB];

			cin >> cost_network;

			aux.first = cost_network;
			aux.second.first = nodeA;
			aux.second.second = nodeB;

			info_network.push_back(aux);

		}

		sort(info_network.begin(), info_network.end());

		int cost = 0;

		for(int s = 0; s < info_network.size(); s++)
		{
			if(num_disjoint_sets == 1)
				break;

			aux2 = info_network[s];

			if(!same_set(aux2.second.first, aux2.second.second))
			{
				cost += aux2.first;

				join_cities(aux2.second.first, aux2.second.second);
			}
		}

		if(i == t-1)
			cout << cost << "\n";
		else
			cout << cost << "\n\n";
		
	}

	return 0; 
}