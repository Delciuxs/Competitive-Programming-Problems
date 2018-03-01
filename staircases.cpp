//LINK to the Problem:
//http://acm.timus.ru/problem.aspx?space=1&num=1017
//Problem type: Dynamic Programming

#include<iostream>
#include<vector>
using namespace std;

long long int num_staircase(long long int n, vector<vector<long long int> > &memory, long long int k)
{
	
	long long int s = 0, aux = 0;
	long long int sum;
	
	if(n <= 2)
		return 0;

	else if(k > n)
		return 0;

	else if(memory[n][k] == -1)
	{
		sum = 0;
		s = n - k;

		if(k + 1 > s)
			return 0;

		else
		{
			for(long long int b = k; b <= s/2; b++)
				sum +=  num_staircase(s, memory ,b + 1);
			sum++;
			memory[n][k] = sum;
			return sum;
		}
	}

	return memory[n][k];
}

int main()
{

	long long int num_blocks, res = 0;

	cin >> num_blocks;

	vector<long long int> columns(300,-1);
	vector<vector<long long int> > grid(505 ,columns);

	for(long long int f = 1; f <= num_blocks / 2; f++)
		res += num_staircase(num_blocks, grid, f);
		
	cout << res << endl;

	return 0;
}
