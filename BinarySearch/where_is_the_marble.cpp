//LINK to the Problem:
//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1415
//Problem type: Binary Search

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int binarySearch(vector<int> &marbles, int find){
	int leftBoundary = 0, rightBoundary = marbles.size() - 1, middle;
	int index = -1;
	while(leftBoundary <= rightBoundary){
		middle = (leftBoundary + rightBoundary) / 2;
		if(find == marbles[middle]){
			index = middle;
			rightBoundary = middle - 1;
		}else if(marbles[middle] < find){
			leftBoundary = middle + 1;
		}else{
			rightBoundary = middle - 1;
		}
	}
	return index;
}

int main()
{
	int n ,q, cont = 1; cin >> n >> q;

	while((n + q) != 0){
		vector<int> marbles(n);
		int query;
		for(int i = 0; i < n; i++)
			cin >> marbles[i];
		sort(marbles.begin(), marbles.end());
		cout << "CASE# " << cont << ":\n";
		for(int i = 0; i < q; i++){
			cin >> query;
			int lowerBound = binarySearch(marbles, query);
			if(lowerBound == -1)
				cout << query << " not found\n"; 
			else
				cout << query << " found at " << lowerBound + 1 << "\n";
		}
		cont++;
		cin >> n >> q;
	}

	return 0;
}