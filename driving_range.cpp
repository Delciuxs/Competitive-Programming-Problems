//LINK to the Problem:
//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2957
//Problem type: MST Kruskal

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct city
{
	int commond_city;
	int rank;
};

typedef city city;
vector<city> cities;
int num_disjoint_sets;

int find_commond_city(int c)
{
	if(cities[c].commond_city != c)
		cities[c].commond_city = find_commond_city(cities[c].commond_city);

	return cities[c].commond_city;
}

bool same_set(int c1, int c2)
{
	if(find_commond_city(c1) == find_commond_city(c2))
		return true;
	return false;
}

void join_sets(int city1, int city2)
{
	int commond_cityB, commond_cityA;
	commond_cityA = find_commond_city(city1);
	commond_cityB = find_commond_city(city2);

	num_disjoint_sets--;

	if(cities[commond_cityA].rank > cities[commond_cityB].rank)
		cities[commond_cityB].commond_city = commond_cityA;
	else
	{
		cities[commond_cityA].commond_city = commond_cityB;
		if(cities[commond_cityA].rank == cities[commond_cityB].rank)
			cities[commond_cityB].rank++;
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
			cities[s].commond_city = s;
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