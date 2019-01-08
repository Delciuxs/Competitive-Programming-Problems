//LINK to the Problem:
//http://acm.timus.ru/problem.aspx?space=1&num=1081
//Problem type: DP

#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

int how_many_valid_sequences(int n, vector<int> &valid_sequences)
{
	if(n == 0)
		return 1;
	else if(n == 1)
		return 2;
	else if(valid_sequences[n] == -1)
		valid_sequences[n] = how_many_valid_sequences(n - 1, valid_sequences) + how_many_valid_sequences(n - 2, valid_sequences);

	return valid_sequences[n];
}

long long int solve(long int k, vector<int> &valid_sequences)
{
	int block;

	if(k == 1)
		return 0;
	
	else if(k == 2)
		return 1;

	else if(k == 3)
		return 2;

	for(int i = 0; i < valid_sequences.size(); i++)
		if(k <= valid_sequences[i])
		{
			block = i;
			break;
 		}

 	return solve(k - valid_sequences[block - 1], valid_sequences) + (1ll << (block - 1));

}

int main()
{
	int n;
	long int k;
	long long int sequence_decimal, bits;

	int num_valid_sequences;

	cin >> n >> k;

	vector<int> valid_sequences(n + 1, -1);

	num_valid_sequences = how_many_valid_sequences(n, valid_sequences);

	if(k > num_valid_sequences)
		cout << "-1" << endl;


	else
	{
		sequence_decimal = solve(k, valid_sequences);

		for(int i = n - 1; i >= 0; i--)
		{
			bits = sequence_decimal & (1ll << i);
			if(bits != 0)
				cout << "1";
			else
				cout << "0";	
		}

		cout << endl;
		
	}
	
	return 0;	
}

