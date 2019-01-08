//LINK to the Problem:
//https://omegaup.com/arena/problem/Planetas#problems
//Problem type: Binary Search

#include<iostream>
#include<cmath>
#include<vector>
#include<iomanip>
#include<algorithm>
using namespace std;

double Binary_Search(double left_boundary, double right_boundary, vector<double> &planets2, int place)
{
	int cont = 0;
	double middle;

	while(cont < 40)
	{
		double left_force = 0.0;
		double right_force = 0.0;

		middle = (left_boundary + right_boundary) / 2.0;

		//Left force
		for(int  i = 0; i <= place; i++)
			left_force = left_force + 1/(abs(planets2[i] - middle));

		//Right Force
		for(int  i = place + 1 ; i <= planets2.size() -1; i++)
			right_force = right_force + 1/(abs(planets2[i] - middle));

		if(right_force > left_force)
			right_boundary = middle;

		else
			left_boundary = middle;

		cont++;
	}
	return middle;
}

int main()
{
	int N, K, planet_position;
	double meteorite_position;
	vector<double> planets;

	cin >> N;

	for(int i = 0; i < N; i++)
	{
		cin >> planet_position;
		planets.push_back(planet_position);
	}

	sort(planets.begin(), planets.end());

	K = N - 1;
	cout << K << endl;

	for(int i = 0; i < K; i++)
	{
		meteorite_position = Binary_Search(planets[i], planets[i+1], planets, i);
		cout << setprecision(3) << fixed << meteorite_position << " ";
	}
	
	return 0;
}