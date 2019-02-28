//LINK to the Problem:
//https://practice.geeksforgeeks.org/problems/edit-distance/0
//Problem type: Dynamic Programming

#include <iostream>
#include<vector>
using namespace std;

int main() {
	int t; cin >> t;
	
	while(t--){
	    int n, m; cin >> n >> m;
	    string wordA, wordB; cin >> wordA >> wordB;
	    vector<int> horizontal(n + 1, 0);
	    vector<vector<int> > memo(m + 1, horizontal);
	    int cost = 0, auxMin;
	    
	    for(int i = 0; i <= n; i++){
	        memo[0][i] = i;
	    }
	    for(int i = 0; i <= m; i++){
	        memo[i][0] = i;
	    }
	    
	    for(int i = 1; i <= m; i++){
	        for(int j = 1; j <= n; j++){
	           cost = 0;
	           if(wordA[j-1] != wordB[i-1]) cost = 1;
	           auxMin = min(memo[i-1][j] + 1, memo[i][j-1] + 1);
	           auxMin = min(auxMin, memo[i-1][j-1] + cost);
	           memo[i][j] = auxMin;
	        }
	    }
	    cout << memo[m][n] << "\n";
	}
	return 0;
}