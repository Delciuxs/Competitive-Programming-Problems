//LINK to the Problem:
//https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=484
//Problem type: Sieve of eranthoses

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> Prime_Numbers(int range)
{
	vector<int> sieve(range + 1);
	vector<int> primes;

	for(int i = 2; i <= range; i += 2)
		sieve[i] = 1;
	for(int i = 3; i <= range; i += 2)
	{
		if(sieve[i] == 0)
		{
			primes.push_back(i);
			for(int j = i; j <= range; j += i)
			{
				sieve[j] = 1;
			}
		}
	}
	
	return primes;
}

int main()
{
	int n;
	vector<int> primes;
	primes = Prime_Numbers(1000000);
	
	cin >> n;

	while(n != 0)
	{
		for(int i = 0; i < primes.size(); i++)
		{
			if(binary_search(primes.begin(), primes.end(), n - primes[i]))
			{
				cout << n << " = " << primes[i] << " + " << n - primes[i] << endl;
				break;
			}
		}
		cin >> n;
	}
	
	return 0;
}