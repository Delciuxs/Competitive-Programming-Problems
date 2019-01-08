//LINK to the Problem:
//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1446
//Problem type: Bipartite

#include<iostream>
#include<vector>
#include<set>
#include<queue>
#include<algorithm>
using namespace std;

vector<int> colors;

bool divide_families(int person, vector<vector<int> > &relations, set<int> &Montesco, set<int> &Capuleto, set<int> &visited)
{
	int aux_person, family;
	bool flag = true;

	queue<int> people;

	people.push(person);
	colors[person] = -1;
	visited.insert(person);
	Montesco.insert(person);

	while(people.size() != 0)
	{
		aux_person = people.front();
		people.pop();

		

		for(int k = 0; k < relations[aux_person].size(); k++)
		{
			if(visited.count(relations[aux_person][k]) == 0)
			{
				family = colors[aux_person] * -1;
				visited.insert(relations[aux_person][k]);
				people.push(relations[aux_person][k]);
				colors[relations[aux_person][k]] = family;

				if(family == -1)//Montesco
					Montesco.insert(relations[aux_person][k]);
				else
					Capuleto.insert(relations[aux_person][k]);


			}

			else if(colors[relations[aux_person][k]] == colors[aux_person])
				flag = false;
		}
	}

	return flag;
}

int main()
{
	int t;

	cin >> t;

	for(int i = 0; i < t; i++)
	{
		int number_people, num_enemies, num_invitations = 0, enemie;
		set<int> visited;

		cin >> number_people;

		colors.resize(number_people + 1);
		vector<int> enemies;
		vector<vector<int> > relations(number_people + 1, enemies);

		for(int j = 1; j < number_people + 1; j++)	
		{
			cin >> num_enemies;

			for(int s = 0; s < num_enemies; s++)
			{
				cin >> enemie;

				if(enemie > number_people)
					continue;
				else
				{
					relations[j].push_back(enemie);
					relations[enemie].push_back(j);
				}
				

			}

		}

		for(int j = 1; j < number_people + 1; j++)
		{
			set<int> Montesco;
			set<int> Capuleto;

			if(visited.count(j) == 0)
			{
				if(divide_families(j, relations, Montesco, Capuleto, visited))
					num_invitations += max(Montesco.size(), Capuleto.size());
	
				else
					num_invitations += 0;		
			}	
		}

		cout << num_invitations << endl;

	}

	return 0;
}