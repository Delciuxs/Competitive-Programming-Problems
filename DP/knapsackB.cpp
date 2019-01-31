//LINK to the Problem:
//https://www.spoj.com/problems/KNAPSACK/
//Problem type: DP Button Up

#include<iostream>
#include<vector>
using namespace std;

int main(){

	int maxWeight; cin >> maxWeight;
	int numObjects; cin >> numObjects;
	vector<int> values(numObjects + 1);
	vector<int> weights(numObjects + 1);

	for(int i = 1; i <= numObjects; i++)
		cin >> weights[i] >> values[i];

	vector<int> w(maxWeight + 1, 0);
	vector<vector<int> > memo(numObjects + 1, w);

	for(int i = 1; i <= numObjects; i++){
		for(int j = 1; j <= maxWeight; j++){
			if(j - weights[i] < 0)
				memo[i][j] = memo[i-1][j];
			else
				memo[i][j] = max(memo[i-1][j], memo[i-1][j - weights[i]] + values[i]);
		}
	} 

	cout << memo[numObjects][maxWeight] << "\n";

	return 0;
}