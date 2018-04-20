//LINK to the Problem:
//https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2139
//Problem type: MST / Kruskal

#include<bits/stdc++.h>
using namespace std;

vector<int> difference = {0,1,2,3,4,5,4,3,2,1};

int num_rolls(string s1, string s2)
{
	int c1 = 0, c2 = 0, sum = 0;

	for(int i = 0; i < s1.size(); i++)
	{
		c1 = s1[i] - '0';
		c2 = s2[i] - '0';

		sum += difference[abs(c1 - c2)];
	}

	return sum;
}

struct key
{
	int common_key;
	int rank;
};

vector<key> keys;
int num_disjoint_sets;

int find_common_key(int k)
{
	if(keys[k].common_key != k)
		keys[k].common_key = find_common_key(keys[k].common_key);
	return keys[k].common_key ;
}

bool same_set(int k1, int k2)
{
	return find_common_key(k1) == find_common_key(k2);
}

void join_sets(int k1, int k2)
{
	int common_key1, common_key2;

	common_key1 = find_common_key(k1);
	common_key2 = find_common_key(k2);

	num_disjoint_sets--;

	if(keys[common_key1].rank > keys[common_key2].rank)
		keys[common_key2].common_key = common_key1;

	else
	{
		keys[common_key1].common_key = common_key2;		
		if(keys[common_key1].rank == keys[common_key2].rank)
			keys[common_key2].rank++;
	}
}

int main()
{
	int t; 

	cin >> t;

	for(int i = 0; i < t; i++)
	{
		int num_keys, first_key_unlocked, minimum_rolls = (1 << 30), rolls = 0;
		string solution;

		cin >> num_keys;

		vector<string> solution_keys(num_keys + 1);
		solution_keys[0] = "0000";

		vector<pair<int, pair<int, int> > > info_keys;
		pair<int, pair<int, int> > aux;

		keys.resize(num_keys + 1);
		num_disjoint_sets = num_keys + 1;

		for(int s = 0; s < keys.size(); s++)
		{
			keys[s].common_key = s;
			keys[s].rank = 0;
		}

		for(int j = 1; j < solution_keys.size(); j++)
		{
			cin >> solution;

			solution_keys[j] = solution;
		}

		for(int j = 0; j < solution_keys.size() - 1; j++)
		{
			for(int k = j + 1; k < solution_keys.size(); k++)
			{
				if(j == 0)
				{
					rolls = num_rolls(solution_keys[j], solution_keys[k]);
					if(rolls < minimum_rolls)
					{
						minimum_rolls = rolls;
						first_key_unlocked = k;
					}
				}

				else
				{
					rolls = num_rolls(solution_keys[j], solution_keys[k]);
					aux.first = rolls;
					aux.second.first = j;
					aux.second.second = k;

					info_keys.push_back(aux);
				}
			}
		}

		int cost_rolls = 0;

		join_sets(0, first_key_unlocked);

		sort(info_keys.begin(), info_keys.end());

		for(int j = 0; j < info_keys.size(); j++)
		{
			if(num_disjoint_sets == 1)
				break;

			aux = info_keys[j];

			if(!same_set(aux.second.first, aux.second.second))
			{
				cost_rolls += aux.first;

				join_sets(aux.second.first, aux.second.second);
			}
		}

		cout << minimum_rolls + cost_rolls << endl;

	}

	return 0;
}