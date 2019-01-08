//LINK to the Problem:
//https://omegaup.com/arena/problem/Divide-and-conquer-1#problems
//Problem type: Kadane's Algorithm

#include<iostream>
#include<vector>
using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<long long int> numeros(n);

	for(int i = 0; i < numeros.size(); i++)
		cin >> numeros[i];

	long long int max_sum = -1000000000;
	long long int sum = -1000000000;

	for(int i = 0; i < numeros.size(); i++){	
		sum += numeros[i];
		sum = max(sum, numeros[i]);
		max_sum = max(sum, max_sum);
	}

	cout << max_sum << "\n";
	return 0;
}