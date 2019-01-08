//LINK to the Problem:
//http://codeforces.com/problemset/problem/474/B
//Problem type: Binary Search

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int BinarySearch(vector<int> &ranges, int juicyWorm){
	int left = 0, right = ranges.size() - 1, middle;
	while(left < right){
		middle = (left + right) / 2;
		if(ranges[middle] >= juicyWorm)
			right = middle;
		else
			left = middle + 1;
	}
	return right;
}
int main(){

	int numPiles; cin >> numPiles;
	vector<int> wormsInPiles(numPiles);
	for(int i = 0; i < numPiles; i++)
		cin >> wormsInPiles[i];
	int sumWorms = 0;
	vector<int> ranges;	ranges.push_back(1);
	for(int i = 0; i < wormsInPiles.size(); i++){
		sumWorms += wormsInPiles[i];
		ranges.push_back(sumWorms);
		ranges.push_back(sumWorms + 1);
	}
	int numJuicyWorms, juicyWorm; cin >> numJuicyWorms;
	for(int i = 0; i < numJuicyWorms; i++){
		cin >> juicyWorm;
		int index = BinarySearch(ranges, juicyWorm);
		cout << (index / 2) + 1 << "\n";
	}
	return 0;
}