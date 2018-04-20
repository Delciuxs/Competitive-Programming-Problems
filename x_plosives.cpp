//LINK to the Problem:
//https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1645
//Problem type: Disjoint Sets

#include<iostream>
#include<vector>
#include<algorithm>
#include<sstream>
#include<string>
using namespace std;

struct component
{
	int common_component;
	int rank;
};

typedef component component;

vector<component> components;

int find_common_component(int c)
{
	if(components[c].common_component != c)
		components[c].common_component = find_common_component(components[c].common_component);
	return components[c].common_component;
}

bool same_set(int c1, int c2)
{
	if(find_common_component(c1) == find_common_component(c2))
		return true;
	return false;
}

void join_sets(int co1, int co2)
{
	int component1, component2;

	component1 = find_common_component(co1);
	component2 = find_common_component(co2);

	if(components[component1].rank > components[component2].rank)
		components[component2].common_component = component1;

	else
	{
		components[component1].common_component = component2;
		if(components[component1].rank == components[component2].rank)
			components[component2].rank++;
	}
}

int main()
{
	int componentA, componentB, max_component = -1, not_taken;
	vector<pair<int, int> > edges;
	pair<int, int> aux, aux2; 
	
	
	while(cin >> componentA)
	{
		if(componentA == -1)
		{
			not_taken = 0;
			components.resize(max_component + 1);

			for(int i = 0; i < components.size(); i++)
			{
				components[i].common_component = i;
				components[i].rank = 0;
			}

			for(int i = 0; i < edges.size(); i++)
			{
				aux2 = edges[i];

				if(!same_set(aux2.first, aux2.second))
					join_sets(aux2.first, aux2.second);

				else
					not_taken++;
			}

			cout << not_taken << endl;

			edges.clear();

			max_component = -1;
		}

		else
		{
			max_component = max(max_component, componentA);

			cin >> componentB;

			max_component = max(max_component, componentB);

			aux.first = componentA;
			aux.second = componentB;

			edges.push_back(aux);
		}
	}

}
