//LINK to the Problem:
//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3634
//Problem type: Greedy

#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;

int main()
{
	int number_islands, num_case = 0, flag;
	long double aux_distance, center_radar, left_boundary, right_boundary, left_boundary_aux, right_boundary_aux, radar_distance;

	cin >> number_islands >> radar_distance;

	while(number_islands + radar_distance != 0)
	{
		vector<pair<int, int> >island(number_islands);
		pair<int, int> coordinates_island;

		vector<pair<long double, long double> >ranges(number_islands);	
		pair<long double, long double> boundary;


		flag = 1;
		num_case++;
		int num_radars = 0;

		for(int i = 0; i < number_islands; i++)
		{
			cin >> coordinates_island.first >> coordinates_island.second;
			if(coordinates_island.second > radar_distance)
				flag = 0;
			
			island[i] = coordinates_island;
		}

		if(flag == 1)
		{
			for(int i = 0; i < island.size(); i++)
			{
				aux_distance = sqrt((pow(radar_distance, 2)) - (pow(island[i].second, 2)));
				
				left_boundary = island[i].first - aux_distance;
				right_boundary = island[i].first + aux_distance;
			
				boundary.first = left_boundary;
				boundary.second = right_boundary;

				ranges[i] = boundary;
			}

			sort(ranges.begin(), ranges.end());

			left_boundary_aux = ranges[0].first;
			right_boundary_aux = ranges[0].second;

			int i = 0;

			while(i < ranges.size())
			{
				if(left_boundary_aux <= right_boundary_aux)
				{
					i++;
					left_boundary_aux = ranges[i].first;
					if(ranges[i].second < right_boundary_aux)
						right_boundary_aux = ranges[i].second;
				}
				
				else
				{
					num_radars++;
					right_boundary_aux = ranges[i].second;
				}


			}
			cout << "Case " << num_case << ": " << num_radars + 1 <<endl;
		}

		else
			cout << "Case " << num_case << ": " << "-1" <<endl;
		
		cin >> number_islands >> radar_distance;
	}
	return 0;
}