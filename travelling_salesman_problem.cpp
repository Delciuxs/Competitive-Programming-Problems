//LINK to the Problem:
//https://practice.geeksforgeeks.org/problems/travelling-salesman-problem/0
//Problem type: SSSP Dijkstra

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){

	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		vector<int> horizontal(n , 0);
		vector<vector<int> > costs(n, horizontal);
		vector<int> path;
		for(int i = 0; i < n; i++){
			if(i != 0) path.push_back(i);
			for(int j = 0; j < n; j++){
				cin >> costs[i][j];
			}
		}

		int minCost = 10000 * 15;

		do{
			int auxCost = 0;
			for(int i = 0; i < path.size() - 1; i++){
				auxCost += costs[path[i]][path[i + 1]];
			}	
			
			auxCost += costs[0][path[0]];
			auxCost += costs[path[path.size() - 1]][0];

			minCost = min(minCost, auxCost);
		} while(next_permutation(path.begin(), path.end()));
		

		cout << minCost << "\n";

	}

	return 0;
}