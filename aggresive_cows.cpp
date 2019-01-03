//LINK to the Problem:
//https://www.spoj.com/problems/AGGRCOW/
//Problem type: Binary Search

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool canPositionCows(int separation, vector<int> &stalls, int numCows){
	int positionStall = stalls[0];
	int idStall = 0;
	numCows--;

	while(true){
		if(numCows == 0)
			return true;
		positionStall += separation;
		std::vector<int>::iterator low;
		low=std::lower_bound (stalls.begin(), stalls.end(), positionStall);
		idStall = low - stalls.begin();
		if(idStall == stalls.size())
			return false;
		else{
			numCows--;
			positionStall = stalls[idStall];
		}
	}
}

int BinarySearch(int left, int right, vector<int> &stalls, int numCows){
	int middle, minMaxDistance;
	while(left <= right){
		middle = (left + right) / 2;
		if(canPositionCows(middle, stalls, numCows)){
			minMaxDistance = middle;
			left = middle + 1;
		}
		else
			right = middle - 1;
	}
	return minMaxDistance;
}

int main(){
	int t; cin >> t;
	for(int s = 0; s < t; s++){
		int numStalls, numCows; cin >> numStalls >> numCows;
		vector<int> stalls(numStalls);
		for(int i = 0; i < numStalls; i++)
			cin >> stalls[i];
		sort(stalls.begin(), stalls.end());

		int maxPosibleDistance = stalls[stalls.size() - 1] - stalls[0];
		int minPosibleDistance = stalls[1] - stalls[0];

		cout << BinarySearch(minPosibleDistance, maxPosibleDistance, stalls, numCows) << "\n";
	}

	return 0;
}