//LINK to the Problem:
//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=961
//Problem type: Greedy

#include<iostream>
#include<vector>
using namespace std;

int main()
{
	int t, distant_to_cover, left_boundary, right_boundary;

	cin >> t;

	for(int i = 0; i < t; i++)
	{
		vector<pair<int, int> > ranges;
		vector<pair<int, int> > solutions;
		pair<int, int> aux1, aux2;
		int minimun_lines = 0, actual_mark = 0, flag = 0, best_range_taken = 0, complete, flag_modify = 0;

		cin >> distant_to_cover;

		cin >> left_boundary >> right_boundary;

		while(left_boundary + right_boundary != 0)
		{
			aux1.first = left_boundary;
			aux1.second = right_boundary;

			ranges.push_back(aux1);

			cin >> left_boundary >> right_boundary;			
		}

		while(actual_mark < distant_to_cover)
		{
			
			flag = 0;
			complete = 1;
			flag_modify = 0;

			for(int j = 0; j < ranges.size(); j++)
			{
				
				if(ranges[j].first <= actual_mark)
				{
					if(ranges[j].second > actual_mark)
					{
						flag = 1;
						if((ranges[j].second - actual_mark) > best_range_taken)
						{
							// cout << "ando muy adentro del codigo men" << endl;
							aux2.first = ranges[j].first;
							aux2.second = ranges[j].second;
							
							best_range_taken = ranges[j].second - actual_mark;
							flag_modify = 1;
						}
					}
					
				}
			}

			if(flag == 0)
			{
				cout << "0" << endl;
				complete = 0;
				break;
			}

			if(flag_modify == 1)
			{
				minimun_lines++;
				solutions.push_back(aux2);
				actual_mark = actual_mark + best_range_taken;
				best_range_taken = 0;
			}
			
		}

		if(complete == 1)
		{
			cout << minimun_lines << endl;
			for(int k = 0; k < solutions.size(); k++)
				cout << solutions[k].first << " " << solutions[k].second << endl;
		}

		cout << endl;

	}



	return 0;
}

/*
Example
20
-5 0
-3 4
-1 7
-5 7
-1 4
1 13
4 8
5 10
6 11
9 15
12 16
14 23
0 0
*/