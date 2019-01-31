//LINK to the Problem:
//https://www.spoj.com/problems/KNAPSACK/
//Problem type: DP Top down

#include <bits/stdc++.h>
using namespace std;

int KS(int n, int remain, vector<int> &size, vector<int> &values, vector<vector<int> > &memo){
	if(n == -1){
		return 0;
	}else{
		if(memo[n][remain] == -1){
			int aux1 = KS(n - 1, remain, size, values, memo);
			if(size[n] <= remain)
				aux1 = max(aux1, KS(n - 1, remain - size[n], size, values, memo) + values[n]);
			memo[n][remain] = aux1;
		}
		return memo[n][remain];
	}
}

int main(){
	int s, n; cin >> s >> n;

	vector<int> size(n), values(n);
	vector<int> col(s + 2, -1);

	vector<vector<int> > memo(n, col);
	for(int i = 0; i < n; i++)
		cin >> size[i] >> values[i];

	cout << KS(n - 1, s, size, values, memo);
	return 0;
}