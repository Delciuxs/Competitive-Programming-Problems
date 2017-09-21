//LINK to the Problem:
//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1282
//Problem type: Binary Search

#include<iostream>
#include<math.h>
#include<iomanip>
using namespace std;

int main()
{
	int p, q, r, s, t, u;
	double evaluation, x, left_boundary, right_boundary, res;

	while(cin >> p >> q >> r >> s >> t >> u)
	{

		left_boundary = 0;
		right_boundary = 1;

		int cont = 0;

		while(cont < 50)
		{
			//This means that the funtion never make a change from f(x) to -f(x) if it was, the funtion will pass trough the y axis
			if(p * exp(-1) + q * sin(1) + r * cos(1) + s * tan(1) + t + u > 1e-9 || p + r + u < 0)
			{
				x = -1;
				break;
			}
			x = (left_boundary + right_boundary) / 2.0;
			evaluation = p*(exp(-x)) + q*(sin(x)) + r*(cos(x)) + s*(tan(x)) + t*(x*x) + u;
	
			
			if(evaluation > 0)
				left_boundary = x;
			else
				right_boundary = x;
		
			cont++;
		}

		if(x == -1)
			cout << "No solution" << endl;
		else
			cout << setprecision(4) << fixed << x << endl;
	}

	return 0;
}

