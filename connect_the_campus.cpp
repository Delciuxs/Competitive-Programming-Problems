//LINK to the Problem:
//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1338
//Problem type: "Minimum" spanning subgraph

#include<iostream>
#include<vector>
#include<cmath>
#include<iomanip>
#include<algorithm>
using namespace std;

double distance_between_buildings(int x1, int y1, int x2, int y2)
{
	double distance;
	distance = sqrt(pow(x2 - x1 , 2) + pow(y2 - y1, 2));
	return distance;
}

struct building
{
	int common_building;
	int rank;
};

typedef building building;

vector<building> buildings;
int num_disjoint_set;

int find_common_building(int b)
{
	if(buildings[b].common_building != b)
		buildings[b].common_building = find_common_building(buildings[b].common_building);
	return buildings[b].common_building;
}

bool same_set(int b1, int b2)
{
	if(find_common_building(b1) == find_common_building(b2))
		return true;
	return false;
}

void join_set(int bu1, int bu2)
{
	int common_buildingA, common_buildingB;

	common_buildingA = find_common_building(bu1);
	common_buildingB = find_common_building(bu2);

	
	if(common_buildingA == common_buildingB)
		return;

	if(buildings[common_buildingA].rank > buildings[common_buildingB].rank)
	{
		num_disjoint_set--;
		buildings[common_buildingB].common_building = common_buildingA;
	}

	else
	{
		buildings[common_buildingA].common_building = common_buildingB;
		num_disjoint_set--;
		if(buildings[common_buildingA].rank == buildings[common_buildingB].rank)		
		{
			buildings[common_buildingB].rank++;
		}
	}
}

int main()
{
	int num_buildings;

	while(cin >> num_buildings)
	{
		int coorX, coorY;
		
		vector<pair<double, pair<int, int> > > info_connections;
		vector<pair<int, int> > coordinates_building(num_buildings + 1);
		
		pair<int, int> aux;
		pair<double, pair<int, int> > auxiliar;
		
		aux.first = -1;
		aux.second = -1;
		coordinates_building[0] = aux;

		buildings.resize(num_buildings + 1);
		num_disjoint_set = num_buildings;

		for(int i = 0; i < buildings.size(); i++)
		{
			buildings[i].common_building = i;
			buildings[i].rank = 0;
		}


		for(int i = 0; i < num_buildings; i++)
		{
			cin >> coorX >> coorY;

			aux.first = coorX;
			aux.second = coorY;

			coordinates_building[i + 1] = aux;

		}

		// cout << "num de coordinates_building " << coordinates_building.size() << endl;

		double distance;

		for(int i = 1; i < coordinates_building.size() - 1 ; i++)
			for(int j = i + 1; j < coordinates_building.size(); j++)
			{	
				distance = distance_between_buildings(coordinates_building[i].first, coordinates_building[i].second,
					coordinates_building[j].first, coordinates_building[j].second);

				// cout << distance << endl;
				auxiliar.first = distance;
				auxiliar.second.first = i;
				auxiliar.second.second = j;

				info_connections.push_back(auxiliar);
			}


		sort(info_connections.begin(), info_connections.end());

		int num_existing_cables, buildingA, buildingB;

		cin >> num_existing_cables;

		for(int i = 0; i < num_existing_cables; i++)
		{
			cin >> buildingA >> buildingB;

			join_set(buildingA, buildingB);
		}

		double cable_required = 0;

		for(int i = 0; i < info_connections.size(); i++)
		{
			if(num_disjoint_set == 1)
				break;

			auxiliar = info_connections[i];

			if(!same_set(auxiliar.second.first, auxiliar.second.second))
			{
				cable_required += auxiliar.first;				
				join_set(auxiliar.second.first, auxiliar.second.second);
			}
		}

		cout << setprecision(2) << fixed << cable_required << endl;

	}


	return 0; 
}
