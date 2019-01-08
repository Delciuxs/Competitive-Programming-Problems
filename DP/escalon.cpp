//LINK to the Problem:
//https:https://omegaup.com/arena/problem/escalera#problems
//Problem type: Dynamic Programming

#include<iostream>
#include<vector>
using namespace std;

vector<long long int> memo(10005);

long long int movimiento(int escalon_actual, int escalon_final, int saltos)
{
	int suma;

	if(escalon_actual == escalon_final)
		return 1;
	else if(escalon_actual > escalon_final)
		return 0;
	else if(memo[escalon_actual] == 0)
	{
		for(int i = 1; i <= saltos; i++)
		{
			memo[escalon_actual] += movimiento(escalon_actual + i, escalon_final, saltos);
		}

	}



	return memo[escalon_actual];

}

int main()
{
	int n, k;

	cin >> n >> k;

	cout << movimiento(0, n, k) << endl;

	return 0;
}