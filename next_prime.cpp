//LINK to the Problem:
//http://coj.uci.cu/24h/problem.xhtml?pid=2272
//Problem type: Sieve of eranthoses

#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

vector<int> Prime_Numbers(int range)
{
	vector<int> sieve(range + 1);
	vector<int> primes;

	primes.push_back(2);
	for(int i = 3; i <= range; i += 2)
	{
		if(sieve[i] == 0)
		{
			primes.push_back(i);
			for(int j = i; j <= range; j += 2*i)
				sieve[j] = 1;
		}
	}
	
	return primes;
}

int Its_prime(long long int number, vector<int> &primes)
{
	if(binary_search(primes.begin(), primes.end(), number))
		return 1;
	if(number == 1 || number == 0)
		return 0;

	for(int i = 0; i <= sqrt(number); i++)
	{
		if(number%primes[i] == 0)
			return 0;
	}
	return 1;
}

int main()
{
	long long int number;
	vector<int> primes;
	primes = Prime_Numbers(1000000);

	int t;
	cin >> t;


	for(int i = 0; i < t; i++)
	{
		cin >> number;

		while(true)
		{
			if(Its_prime(number, primes) == 1)
			{
				cout << number <<  endl;
				break;
			}
			else
				number++;	
		}
	}
	return 0;
}