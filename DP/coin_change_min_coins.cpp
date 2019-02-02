//LINK to the Problem:
//https://practice.geeksforgeeks.org/problems/number-of-coins/0
//Problem type: DP

#include<iostream>
#include<vector>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);	
	cout.tie(0);

	int t; cin >> t;

	for(int s = 0; s < t; s++){
		int change; cin >> change;
		int numCoins; cin >> numCoins;
		vector<int> denominations(numCoins);

		for(int i = 0; i < denominations.size(); i++)
			cin >> denominations[i];

		vector<int> aux(change + 1, 0);
		vector<vector<int> > memo(denominations.size() + 1, aux);

		memo[0][0] = 0;
		for(int i = 1; i <= change; i++){
			if((i % denominations[0]) == 0)
				memo[0][i] = i / denominations[0];
			else
				memo[0][i] = 10000000;
		}

		for(int i = 1; i < denominations.size(); i++){
			for(int j = 0; j <= change; j++){
				if(j < denominations[i])
					memo[i][j] = memo[i-1][j];
				else
					memo[i][j] = min(memo[i-1][j], memo[i][j - denominations[i]] + 1);
			}
		}

		if(memo[denominations.size() - 1][change] >= (10000000))
			cout << "-1\n";
		else
			cout << memo[denominations.size() - 1][change] << "\n";

	}

	return 0;
}