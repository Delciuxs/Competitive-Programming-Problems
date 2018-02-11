//LINK to the Problem:
//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1431
//Problem type: Sieve of eranthoses

#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

vector<long long int> Find_Primes_to(long long int n)
{
	vector<long long int> Sieve(n + 1);
	vector<long long int> Primes;

	Primes.push_back(2);

	for(long long int i = 3; i <= n; i += 2)
	{
		if(Sieve[i] == 0)
		{
			Primes.push_back(i);
			for(long long int j = i; j <= n; j += i)
				Sieve[j] = 1;
		}
	}
	
	return Primes;
}

bool Is_Prime(vector<long long int> &primes, long long int number)
{
	long long int k = 0;
	float root;
	root = sqrt(number);

	if(number == 1)
		return false;

	if(binary_search(primes.begin(), primes.end(), number))
		return true;

	else
	{
		while(primes[k] <= root)
		{
			if(number % primes[k] == 0)
				return false;
			k++;
		}

		return true;
	}
	
}


int main()
{
	int input;
	long long int prime_Mersenne, perfect_number;
	vector<long long int> my_primes;

	my_primes = Find_Primes_to(50000);

	cin >> input;

	while(input != 0)
	{
		if(Is_Prime(my_primes, input))
		{
			prime_Mersenne = pow(2, input) - 1;

			if(Is_Prime(my_primes, prime_Mersenne))
			{
				perfect_number = (pow(2, input - 1));
				cout << "Perfect: " << prime_Mersenne * perfect_number << "!" << endl;
			}
			else
				cout << "Given number is prime. But, NO perfect number is available." << endl;
		}

		else
			cout << "Given number is NOT prime! NO perfect number is available." << endl;

		cin >> input;
	}

	return 0;
}