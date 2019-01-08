//LINK to the Problem:
//http://poj.org/problem?id=1064
//Problem type: Binary Search

#include<iostream>
#include<vector>
#include<algorithm>
#include<iomanip>
#include<cmath>
using namespace std;

bool canCutCables(double distance, vector<double> &cables, int requestedPieces){
	int cuts = 0;
	for(int i = 0; i < cables.size(); i++)
		cuts += (int)(cables[i] / distance);
	if(cuts < requestedPieces)
		return false;
	return true;
}

double BinarySearch(double left, double right, vector<double> &cables, int requestedPieces){
	double middle, maxDistanceCut;
	int cont = 0;
	while(cont < 25){
		middle = (left + right) / 2.0;
		if(canCutCables(middle, cables, requestedPieces)){
			maxDistanceCut = middle;
			left = middle;
		}
		else{
			right = middle;
		}
		cont++;
	}
	return right;
}

int main(){

	int numCables, requestedPieces; cin >> numCables >> requestedPieces;
	vector<double> cables(numCables);
	double maxDistance = -1.0, minDistance = 0, cable;

	for(int i = 0; i < numCables; i++){
		cin >> cable;
		maxDistance = max(maxDistance, cable);
		cables[i] = cable;
	}
	double ans = BinarySearch(minDistance, maxDistance, cables, requestedPieces);
	cout << setprecision(2) << fixed << floor(ans * 100.0) / 100.0 << "\n";
	return 0;
}