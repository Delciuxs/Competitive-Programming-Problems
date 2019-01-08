//LINK to the Problem:
//http://www.spoj.com/problems/ULM09/
//Problem type: MST Kruskal

#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std; 

struct city
{
	int common_city;
	int rank;
};

typedef city city;

vector<city> cities;
int num_disjoint_sets;

int find_common_city(int c1)
{
	if(cities[c1].common_city != c1)
		cities[c1].common_city = find_common_city(cities[c1].common_city);

	return cities[c1].common_city;
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
	int common_cityA, common_cityB;

	common_cityA = find_common_city(city1);
	common_cityB = find_common_city(city2);

	if(cities[common_cityA].rank > cities[common_cityB].rank)
	{
		cities[common_cityB].common_city = common_cityA;
		num_disjoint_sets = num_disjoint_sets - 1;
	}

	else
	{
		cities[common_cityA].common_city = common_cityB;
		num_disjoint_sets = num_disjoint_sets - 1;

		if(cities[common_cityA].rank == cities[common_cityB].rank)
			cities[common_cityB].rank = cities[common_cityB].rank + 1;
	}
}



int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int num_cities, num_roads;

	cin >> num_cities >> num_roads;

	while(num_cities + num_roads != 0)
	{
		int cityA, cityB, cost_between_cities, cost_having_all_light_on = 0;

		vector<pair<int, pair<int, int> > > info_road;
		pair<int, pair<int, int> > aux, aux2;

		cities.resize(num_cities);
		num_disjoint_sets = num_cities;

		for(int j = 0; j < cities.size(); j++)
		{
			cities[j].common_city = j;
			cities[j].rank = 0;
		}

		for(int i = 0; i < num_roads; i++)
		{	
			cin >> cityA >> cityB >> cost_between_cities;

			cost_having_all_light_on += cost_between_cities;

			aux.first = cost_between_cities;
			aux.second.first = cityA;
			aux.second.second = cityB;

			info_road.push_back(aux);

		}

		sort(info_road.begin(), info_road.end());

		int cost = 0;

		for(int s = 0; s < info_road.size() ; s++)
		{
			if(num_disjoint_sets == 1)
				break;

			aux2 = info_road[s];

			if(!same_set(aux2.second.first, aux2.second.second))
			{
				cost += aux2.first;

				join_cities(aux2.second.first, aux2.second.second);
			}
		}

		cout << cost_having_all_light_on - cost << endl;

		cin >> num_cities >> num_roads;
	}

	return 0; 
}
