//LINK to the Problem:
//https://omegaup.com/arena/problem/carboles#problems
//Problem type: Dynamic Programming

#include<iostream>
#include<vector>
using namespace std;

long long int how_many_trees(long long int nodes, vector<long long int> &memory)
{

	if(nodes == 1 or nodes == 0)
		return 1;
	
	else if(nodes == 2)
		return 2;
	
	else if(memory[nodes] == 0)
	{
		for(long long int k = 1; k <= nodes; k++ )
			memory[nodes] += how_many_trees(k - 1, memory) * how_many_trees(nodes - k, memory);
	}

	return memory[nodes] % 1000000;
}

int main()
{

	long long int n;

	cin >> n;

	vector<long long int> memo(n + 1);

	cout << how_many_trees(n, memo) << endl;
	
	return 0;
}