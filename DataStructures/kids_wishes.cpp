//LINK to the Problem:
//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3400
//Problem type: Union Find Disjoint Sets

#include<iostream>
#include<vector>
#include<map>
#include<unordered_map>
using namespace std;

long long int num_groups;
unordered_map<long long int, vector<long long int>> children;

long long int find_common_friend(long long int f)
{
	if(children[f][0] != f)
		children[f][0] = find_common_friend(children[f][0]);

	return children[f][0];
}

bool sit_kids_together(long long int f1, long long int f2)
{
	long long int common_friendA, common_friendB;

	common_friendA = find_common_friend(f1);
	common_friendB = find_common_friend(f2);

	if(common_friendA == common_friendB)
		return true;//there is a cycle

	if(children[common_friendA][1] > children[common_friendB][1])
	{
		children[common_friendB][0] = common_friendA;
		num_groups--;
	}

	else
	{
		children[common_friendA][0] = common_friendB;
		num_groups--;
		if(children[common_friendA][1] == children[common_friendB][1])
			children[common_friendB][1]++;
	}

	return false;//no cycle
}


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);	

	long long int num_kids, num_wishes;

	cin >> num_kids >> num_wishes;

	while(num_kids + num_wishes != 0)
	{
		map<pair<long long int, long long int>, bool> wishes_used;
		pair<long long int, long long int> aux;
		children.clear();
		
		int overload_child = 0, cycle_detected = 0;
		long long int childA, childB;

		vector<long long int> info(3);

		num_groups = num_kids;

		for(int i = 0; i < num_wishes; i++)
		{
			cin >> childA;

			if(children.count(childA) == 0)
			{
				children[childA] = info;
				children[childA][0] = childA;//common child
				children[childA][1] = 0;//rank
				children[childA][2] = 0;//adjacency
			}

			cin >> childB;

			if(children.count(childB) == 0)
			{
				children[childB] = info;
				children[childB][0] = childB;//common child
				children[childB][1] = 0;//rank
				children[childB][2] = 0;//adjacency
			}

			if(childA == childB)
				continue;

			aux.first = childA;
			aux.second = childB;

			if(wishes_used.count(aux) == 0)
			{
				wishes_used[aux] = 1;

				aux.first = childB;
				aux.second = childA;

				wishes_used[aux] = 1;
			}

			else
				continue;

			if(children[childA][2] < 2 && children[childB][2] < 2)
			{
				children[childA][2]++;
				children[childB][2]++;

				if(sit_kids_together(childA, childB))
					cycle_detected  = 1;
							
			}

			else
				overload_child = 1;
		


		}

		if(num_wishes == 0)
			cout << "Y" << endl;

		else
		{
			if(overload_child == 1)
				cout << "N" << endl;			

			else if(cycle_detected == 1)
			{
				if(num_groups != 1)
					cout << "N" << endl;
				else
					cout << "Y" << endl;
					
			}

			else
				cout << "Y" << endl;
		}

		

		cin >> num_kids >> num_wishes;
	}

	return 0;
}