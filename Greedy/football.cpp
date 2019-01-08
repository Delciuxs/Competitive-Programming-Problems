//LINK to the Problem:
//https://icpcarchive.ecs.baylor.edu/index.php?option=onlinejudge&page=show_problem&problem=4541
//Problem type: Greedy

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	int number_matches, goals_buyed;

	while(cin >> number_matches >> goals_buyed)
	{

		int my_team_goals, other_team_goals, diference = 0; 
		int winned = 0, draws = 0, lose = 0, need_to_win, needed_to_draw, max_points = 0;
		vector<int> info;

		for(int i = 0; i < number_matches; i++)
		{
			cin >> my_team_goals >> other_team_goals;
			diference = my_team_goals - other_team_goals;

			if(diference == 0)
			{
				draws++;
				info.push_back(diference);
			}

			else if(diference > 0)
			{
				winned++;
			}

			else if(diference < 0)
			{
				lose++;
				info.push_back(diference);
			}

		}

		sort(info.begin(), info.end());

		for(int i = info.size() - 1; i >= 0; i--)
		{
			if(goals_buyed == 0)
				break;

			if(info[i] == 0)
			{
				winned++;
				draws--;
				goals_buyed--;
			}

			else
			{
				need_to_win = abs(info[i]) + 1;
				needed_to_draw = abs(info[i]);

				if(goals_buyed >= need_to_win)
				{
					winned++;
					lose--;
					goals_buyed -= need_to_win;
				}

				else if(goals_buyed == needed_to_draw)
				{
					draws++;
					lose--;
					goals_buyed -= needed_to_draw;
				}
			}
		}

		max_points = (winned * 3) + (draws * 1);

		cout << max_points << endl;

	}

	return 0;
}