//LINK to the Problem:
//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2231
//Problem type: Greedy

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	long long int t, num_coins, dif_coins, sum;

	cin >> t;

	for(int i = 0; i < t; i++)
	{
		cin >> num_coins;

		dif_coins = num_coins;

		sum = 1;

		vector<long long int> coins(num_coins);
		
		for(int  j = 0; j < num_coins; j++)
			cin >> coins[j];

		sort(coins.begin(), coins.end());
		
		for(int j = 0; j < coins.size() - 1; j++)
		{
			if(sum < coins[j + 1])
			{
				sum += coins[j + 1];
				continue;
			}

			else
			{
				dif_coins--;
				sum = sum - coins[j];
				sum += coins[j + 1];
				continue;
			}

		}

		cout << dif_coins << endl;
	}


	return 0;

}