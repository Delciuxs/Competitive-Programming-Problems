//LINK to the Problem:
//http://codeforces.com/problemset/problem/431/C
//Problem type: Dynamic Programming

#include<iostream>
#include<vector>

using namespace std;

int required_sum, num_edges, required_edge;
long long int module = 1000000007;

vector<pair<long long int, long long int> > memory(105);

pair<long long int, long long int> how_many_paths(int actual_sum, int flag)
{
	

	pair<long long int, long long int> aux, aux2, aux3, aux4;
	long long int cont1 = 0, cont2 = 0;

	
	if(actual_sum == required_sum)
	{
		
		if(flag == 1)
		{
			aux.first = 1;
			aux.second = 1;
		}
		//Found a solution but not using the required edge
		else
		{
			aux.first = 1;
			aux.second = 0;		
		}

		return aux;
	}

	//I have passed the required sum
	else if(actual_sum > required_sum)
	{
		aux.first = 0;
		aux.second = 0;

		return aux;
	}

	else if(memory[actual_sum].first == -1)
	{
		
		for(int i = 1; i <= num_edges; i++)
		{
			if(i >= required_edge)
			{
				aux2 = how_many_paths(actual_sum + i, 1);
				cont1 += aux2.first;
				cont2 += aux2.second;
			}
			else
			{
				aux2 = how_many_paths(actual_sum + i, flag);
				cont1 += aux2.first;
				cont2 += aux2.second;
			}
		}

		aux3.first = cont1 % module;
		aux3.second = cont2 % module;

		memory[actual_sum] = aux3;
	}

	//We have already know the answer
	if(memory[actual_sum].first != -1)
	{
		
		//if the flag is 1 return all the solutions found
		if(flag == 1)
		{
			aux4.first = memory[actual_sum].first;
			aux4.second = memory[actual_sum].first;

		}

		//else return just the solutions using a valid edge
		else
		{
			aux4.first = memory[actual_sum].first;
			aux4.second = memory[actual_sum].second;	
		}

		return aux4;
	}

}


int main()
{

	cin >> required_sum >> num_edges >> required_edge;

	pair<long long int, long long int> answer;

	for (int i = 0; i < memory.size(); ++i)
	{
		memory[i].first = -1;
		memory[i].second = -1;
	}

	answer = how_many_paths(0,0);

	cout << answer.second << endl;


	return 0;
}