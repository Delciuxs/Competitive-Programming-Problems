//LINK to the Problem:
//http://codeforces.com/problemset/problem/584/D
//Problem type: Sieve of eranthoses

#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

vector<long int> Find_Primes_to(long int N)
{
	vector<long int> Sieve(N + 1);
	vector<long int> Primes;

	Primes.push_back(2);

	for(long int i = 3; i <= N; i += 2)
	{
		if(Sieve[i] == 0)
		{
			Primes.push_back(i);
			for(long int j = i; j <= N; j += i)
				Sieve[j] = 1;
		}
	}

	return Primes;
}

int Is_Prime(vector<int long> &prime_numbers, int long number)
{
	if(binary_search(prime_numbers.begin(), prime_numbers.end(), number))
		return 1;
	if(number == 1)
		return 0;

	else
	{
		int long k = 0;

		while(prime_numbers[k] <= sqrt(number))
		{
			if(number % prime_numbers[k] == 0)
				return 0;
			k++;
		}

		return 1;

	}
}


int main()
{
	long int number, iterator = 0;

	vector<int long> my_primes;

	my_primes = Find_Primes_to(1000000);

	cin >> number;

	if(Is_Prime(my_primes, number))
		cout << "1\n" << number << endl;
	
	else
	{
		cout << "3" << endl;

		number = number - 3;

		while(true)
		{			
			if(Is_Prime(my_primes, number - my_primes[iterator]))
			{
				cout << "3 " << my_primes[iterator] << " " << number - my_primes[iterator] << endl;
				return 0;
			}
			else
				iterator++;
		}
	}
		
	
}