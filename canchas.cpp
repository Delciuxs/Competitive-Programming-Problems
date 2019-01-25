//LINK to the Problem:
//https://omegaup.com/arena/problem/COMI-Canchas#problems
//Problem type: Greedy

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){

	vector<pair<int, char> > xAxis, yAxis;
	int coordinate;
	int totalArea, areaRecA, areaRecB, areaIntersection, intersectionX, intersectionY;

	for(int i = 0; i < 8; i++){
		cin >> coordinate;
		if(i < 4){
			if(i % 2 == 0)
				xAxis.push_back(make_pair(coordinate, 'a'));
			else
				yAxis.push_back(make_pair(coordinate, 'a'));
		}else{
			if(i % 2 == 0)
				xAxis.push_back(make_pair(coordinate, 'b'));
			else
				yAxis.push_back(make_pair(coordinate, 'b'));
		}
	}

	areaRecA = (abs(xAxis[0].first - xAxis[1].first)) * (abs(yAxis[0].first - yAxis[1].first));
	areaRecB = (abs(xAxis[2].first - xAxis[3].first)) * (abs(yAxis[2].first - yAxis[3].first));

	sort(xAxis.begin(), xAxis.end());
	sort(yAxis.begin(), yAxis.end());

	if(xAxis[0].second == xAxis[1].second)
		intersectionX = 0;
	else
		intersectionX = abs(xAxis[1].first - xAxis[2].first);
	if(yAxis[0].second == yAxis[1].second)
		intersectionY = 0;
	else
		intersectionY = abs(yAxis[1].first - yAxis[2].first);


	areaIntersection = intersectionX * intersectionY;
	totalArea = areaRecA + areaRecB - areaIntersection;

	cout << totalArea << endl;



	return 0;
	
}