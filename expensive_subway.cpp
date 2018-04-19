//LINK to the Problem:
//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2757
//Problem type: MST / Kruskal

#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

struct station
{
	int commond_station;
	int rank;
};
 

typedef station station;

vector<station> stations;
int num_disjoint_sets;

int find_commond_station(int s)
{
	if(stations[s].commond_station != s)
		stations[s].commond_station = find_commond_station(stations[s].commond_station);
	return stations[s].commond_station;
}

bool same_set(int s1, int s2)
{
	if(find_commond_station(s1) == find_commond_station(s2))
		return true;
	return false;
}


void joins_sets(int st1, int st2)
{
	int commond_st1, commond_st2;

	commond_st1 = find_commond_station(st1);
	commond_st2 = find_commond_station(st2);

	num_disjoint_sets--;

	if(stations[commond_st1].rank > stations[commond_st2].rank)
		stations[commond_st2].commond_station = commond_st1;

	else
	{
		stations[commond_st1].commond_station = commond_st2;			
		if(stations[commond_st1].rank == stations[commond_st2].rank)
			stations[commond_st2].rank++;
	}
}


int main()
{
	int num_stations, num_conections;
	
	cin >> num_stations >> num_conections;

	while(num_stations + num_conections != 0)
	{
		unordered_map<string, int> id_station;
		int id_stationA, id_stationB, cont = 0, cost;
		string name_station,stationA, stationB ,station_origin;

		vector<pair<int, pair<int, int> > > info_subway;
		pair<int, pair<int, int> > aux;


		for(int i = 0; i < num_stations; i++)
		{
			cin >> name_station;

			if(id_station.count(name_station) == 0)
				id_station[name_station] = cont++;
		}

		stations.resize(cont + 1);
		num_disjoint_sets = cont;

		for(int i = 0; i < stations.size(); i++)
		{
			stations[i].commond_station = i;
			stations[i].rank = 0;
		}


		for(int j = 0; j < num_conections; j++)
		{
			cin >> stationA >> stationB >> cost;

			id_stationA = id_station[stationA];
			id_stationB = id_station[stationB];

			aux.first = cost;
			aux.second.first = id_stationA;
			aux.second.second = id_stationB;

			info_subway.push_back(aux);

		}

		cin >> station_origin;


		sort(info_subway.begin(), info_subway.end());

		int money_needed = 0;

		for(int s = 0; s < info_subway.size(); s++)
		{
			aux = info_subway[s];

			if(num_disjoint_sets == 1)
				break;

			if(!same_set(aux.second.first, aux.second.second))
			{
				money_needed += aux.first;
				joins_sets(aux.second.first, aux.second.second);
			}
		}


		if(num_disjoint_sets != 1)
			cout << "Impossible" << endl;

		else
			cout << money_needed << endl;

		cin >> num_stations >> num_conections;
	}

	return 0;	
}