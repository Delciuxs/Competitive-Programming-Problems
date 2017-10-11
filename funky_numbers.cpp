//LINK to the Problem:
//http://codeforces.com/problemset/problem/192/A
//Problem type: Math

#include<iostream>
#include<math.h>
using namespace std;

long double solve_quadratic(long double n)
{
	long double positive_integer_solution;
	return positive_integer_solution = (-1 + pow(1 + (8*n),.5))/2;
}

int main()
{
	long int N, new_value; 
	cin >> N;

	for(long int i = 0; i < solve_quadratic(N); i++)
	{
		new_value = N - ((i+1)*(i+2))/2;
		if(new_value == 0)
			break;

		if(solve_quadratic(new_value) == floor(solve_quadratic(new_value)))
		{
			cout << "YES" << endl;
			return 0;
		}
		
	}
	
	cout << "NO" << endl;
	return 0;
}