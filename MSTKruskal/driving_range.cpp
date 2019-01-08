//LINK to the Problem:
//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2957
//Problem type: MST Kruskal

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct city
{
	int common_city;
	int rank;
};

typedef city city;
vector<city> cities;
int num_disjoint_sets;

int find_common_city(int c)
{
	if(cities[c].common_city != c)
		cities[c].common_city = find_common_city(cities[c].common_city);

	return cities[c].common_city;
}

bool same_set(int c1, int c2)
{
	if(find_common_city(c1) == find_common_city(c2))
		return true;
	return false;
}

void join_sets(int city1, int city2)
{
	int common_cityB, common_cityA;
	common_cityA = find_common_city(city1);
	common_cityB = find_common_city(city2);

	num_disjoint_sets--;

	if(cities[common_cityA].rank > cities[common_cityB].rank)
		cities[common_cityB].common_city = common_cityA;
	else
	{
		cities[common_cityA].common_city = common_cityB;
		if(cities[common_cityA].rank == cities[common_cityB].rank)
			cities[common_cityB].rank++;
	}

}

int main()
{
	int num_cities, num_roads;

	cin >> num_cities >> num_roads;

	while(num_cities + num_roads != 0)
	{
		int cityA, cityB, cost_between_cities;
		vector<pair<int, pair<int,int> > > info_roads;
		pair<int, pair<int, int> > aux;

		cities.resize(num_cities);
		num_disjoint_sets = num_cities;

		for(int s = 0; s < cities.size(); s++)
		{
			cities[s].common_city = s;
			cities[s].rank = 0;
		}

		for(int i = 0; i < num_roads; i++)
		{
			cin >> cityA >> cityB >> cost_between_cities;

			aux.first = cost_between_cities;
			aux.second.first = cityA;
			aux.second.second = cityB;

			info_roads.push_back(aux);
		}

		if(num_roads == 0)
			cout << "IMPOSSIBLE\n";


		else
		{
			sort(info_roads.begin(), info_roads.end());
			int max_cost = 0;

			for(int j = 0; j < info_roads.size(); j++)
			{
				if(num_disjoint_sets == 1)
					break;

				aux = info_roads[j];

				if(!same_set(aux.second.first, aux.second.second))
				{
					max_cost = max(max_cost, aux.first);
					join_sets(aux.second.first, aux.second.second);
				}
			}

			if(num_disjoint_sets != 1)
				cout << "IMPOSSIBLE\n";

			else
				cout << max_cost << "\n";
			
		}
		

		cin >> num_cities >> num_roads;
	}

	return 0;
}
