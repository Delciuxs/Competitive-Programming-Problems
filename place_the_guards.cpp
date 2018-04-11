//LINK to the Problem:
//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2021
//Problem type: Bipartite

#include<iostream>
#include<vector>
#include<set>
#include<queue>
#include<algorithm>
using namespace std;

vector<int> colors;

bool place_guards(int junction, vector<vector<int> > &streets, set<int> &red, set<int> &blue, set<int> &visited)
{
	int junction_aux, type_color;
	queue<int> junctions_being_processed;

	visited.insert(junction);
	red.insert(junction);
	colors[junction] = -1;

	junctions_being_processed.push(junction);

	while(junctions_being_processed.size() != 0)
	{
		junction_aux = junctions_being_processed.front();
		junctions_being_processed.pop();

		for(int k = 0; k < streets[junction_aux].size(); k++)
		{
			if(visited.count(streets[junction_aux][k]) == 0)
			{
				type_color = colors[junction_aux] * -1;
				visited.insert(streets[junction_aux][k]);
				colors[streets[junction_aux][k]] = type_color;
				junctions_being_processed.push(streets[junction_aux][k]);

				if(type_color == -1)
					red.insert(streets[junction_aux][k]);
				else
					blue.insert(streets[junction_aux][k]);

			}

			else if(colors[streets[junction_aux][k]] == colors[junction_aux])
				return false;
		}
	}

	return true;

}

int main()
{
	int t;

	cin >> t;

	for(int i = 0; i < t; i++)
	{
		int num_junctions, num_streets, u, v, num_guards = 0;

		cin >> num_junctions >> num_streets;

		vector<int> junctions;
		vector<vector<int> > streets(num_junctions, junctions);

		set<int> visited;
		colors.resize(num_junctions);

		if(num_streets == 0)
		{
			cout << num_junctions << endl;
			continue;
		}

		for(int j = 0; j < num_streets; j++)
		{
			cin >> u >> v;

			streets[u].push_back(v);
			streets[v].push_back(u);
		}

		for(int j = 0; j < num_junctions; j++)
		{
			set<int> red;
			set<int> blue;

			if(visited.count(j) == 0)
			{
				if(place_guards(j, streets, red, blue, visited))
				{
					if(red.size() == 1 && blue.size() == 0)
						num_guards += red.size();
					else
						num_guards += min(red.size(), blue.size());
					
				}

				else
				{
					num_guards = -1;
					break;
				}
			}
		}

		cout << num_guards << endl;
	}

	return 0;
}