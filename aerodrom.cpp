//LINK to the Problem:
//https://omegaup.com/arena/problem/AERODROM#problems
//Problem type: Binary Search

#include<iostream>
#include<vector>
using namespace std;
long long int minT = 1;
long long int maxT = 1e18 + 5;

bool can(long long int time, vector<long long int> &desksTimes, long long int numPeople){
	long long int numPeopleInDesk;
	for(int i = 0; i < desksTimes.size(); i++){
		numPeopleInDesk = time / desksTimes[i];
		numPeople = numPeople - numPeopleInDesk;
		if(numPeople <= 0)
			return true;
	}
	return false;
}

long long int BinarySearch(vector<long long int> &desksTimes, long long int numPeople){
	long long int middle, minTime;
	while(minT <= maxT){
		middle = (minT + maxT) / 2;
		if(can(middle, desksTimes, numPeople)){
			minTime = middle;
			maxT = middle - 1;
		}else{
			minT = middle + 1;
		}
	}
	return minTime;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	long long int numDesks, numPeople; cin >> numDesks >> numPeople;
	vector<long long int> desksTimes(numDesks);
	
	for (int i = 0; i < numDesks; ++i)
		cin >> desksTimes[i];

	long long int minTime = BinarySearch(desksTimes, numPeople);
	cout << minTime << "\n";

	return 0;
}