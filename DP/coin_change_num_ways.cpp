//LINK to the Problem:
//https://practice.geeksforgeeks.org/problems/coin-change/0
//Problem type: DP

#include<iostream>
#include<vector>
using namespace std;

vector<int> coins;

int DP(int coinChange, vector<vector<int> > &memo, int iterator){
 	int aux, ways = 0;
	if(coinChange < 0)
		return 0;
	else if(coinChange == 0)
		return 1;
	else if(memo[coinChange][iterator] == -1){
		for(int i = iterator; i < coins.size(); i++){
			aux = coinChange - coins[i];
			ways += DP(aux, memo, i);
		}
		memo[coinChange][iterator] = ways;

	}
	return memo[coinChange][iterator];
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);	
	cout.tie(0);

	int t; cin >> t;

	for(int i = 0; i < t; i++){
		int numCoins; cin >> numCoins;
		coins.resize(numCoins);

		for(int j = 0; j < numCoins; j++)
			cin >> coins[j];

		int coinChange; cin >> coinChange;

		vector<int> aux(coins.size() + 3, -1);
		vector<vector<int> > memo(coinChange + 3, aux);	

		cout << DP(coinChange, memo, 0) << "\n";
	}

	return 0;
}