//LINK to the Problem:
//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1081
//Problem type: Sieve of eranthoses

#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

vector<long long int> Find_Primes_to(long long int N)
{
	vector<long long int> Sieve(N + 1);
	vector<long long int> Primes;

	Primes.push_back(2);

	for(long long int i = 3; i <= N; i += 2)
	{
		if(Sieve[i] == 0)
		{
			Primes.push_back(i);
			for(long long int j = i; j <= N; j += i)
				Sieve[j] = 1;
		}
	}

	return Primes;
}



int Is_Prime(vector<long long int > &prime_numbers, long long int number)
{
	float raiz;

	if(number == 1)
		return 0;
	if(binary_search(prime_numbers.begin(), prime_numbers.end(), number))
		return 1;
	
	else
	{
		long long int k = 0;
		raiz = sqrt(number);

		while(prime_numbers[k] <= raiz)
		{
			if(number % prime_numbers[k] == 0)
				return 0;
			k++;
		}
		return 1;
	}
}

vector<pair<long long int, long long int> > Answer(long long int left_boundary, long long int right_boundary)
{
	vector<long long int> my_primes;
	my_primes = Find_Primes_to(60000);

	vector<pair<long long int, long long int> > my_answer(2);

	long long int minimum_distant = 1000005;
	long long int maximum_distant = -1;
	long long int aux_prime1 = 0, aux_prime2 = 0;

	for(long long int i = left_boundary; i <= right_boundary; i++)
	{
		if(Is_Prime(my_primes, i))
		{
			if(aux_prime1 == 0)//First prime we find
				aux_prime1 = i;
			else
			{
				aux_prime2 = i;
				if((aux_prime2 - aux_prime1) < minimum_distant)
				{
					minimum_distant = aux_prime2 - aux_prime1;
					my_answer[0].first = aux_prime1;
					my_answer[0].second = aux_prime2; 
				}
				if((aux_prime2 - aux_prime1) > maximum_distant)
				{
					maximum_distant = aux_prime2 - aux_prime1;
					my_answer[1].first = aux_prime1;
					my_answer[1].second = aux_prime2; 
				}
				aux_prime1 = aux_prime2;
			}
		}
	}

	return my_answer;
}

int main()
{
	long long int right_boundary, left_boundary;
	vector<pair<long long int, long long int> > adjacent_primes(2);

	while(cin >> left_boundary >> right_boundary)
	{
		adjacent_primes = Answer(left_boundary, right_boundary);

		if(adjacent_primes[0].first && adjacent_primes[0].second != 0)
		{
			cout << adjacent_primes[0].first << "," << adjacent_primes[0].second << " are closest, ";
			cout << adjacent_primes[1].first << "," << adjacent_primes[1].second << " are most distant." << endl;
		}
		else
		{
			cout << "There are no adjacent primes." << endl;
		}
	}	
	return 0;
}
