//LINK to the Problem:
//https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1282
//Problem type: Binary Search

#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;
#define eps 1e-4

double evaluation(int p, int q, int r, int s, int t, int u, double x){
	return p*(exp(-x)) + q*(sin(x)) + r*(cos(x)) + s*(tan(x)) + t*(x*x) + u;
}

double BinarySearch(int p, int q, int r, int s, int t, int u){
	double left = 0, right = 1, x, eval;
	int cont = 0;

	while(cont < 30){
		x = (left + right) / 2.0;
		eval = evaluation(p, q, r, s, t, u, x);
		if(eval > 0)
			left = x;
		else
			right = x;
		cont++;
	}
	if(abs(eval) < eps)
		return x;
	return -1.0;
}

int main(){

	int p, q, r, s, t, u;

	while(cin >> p >> q >> r >> s >> t >> u){
		double answer = BinarySearch(p, q, r, s, t, u);
		if(answer == -1.0)
			cout << "No solution" << "\n";
		else
			cout << fixed << setprecision(4) << answer << "\n";
	}
	return 0;
}