//LINK to the Problem:
//https://omegaup.com/arena/problem/Longest-Common-Subsequence/#problems
//Problem type: Dynamic Programming

#include<iostream>
#include<vector>
using namespace std;

string palabraA, palabraB;
int LCS(int n, int m, vector<vector<int> > &memoria){
	int quitaA, quitaB, maximo;

	if(n < 0 || m < 0)
		return 0;
	else if(memoria[n][m] == -1){
		if(palabraA[n] == palabraB[m])
			maximo = 1 + LCS(n - 1, m - 1, memoria);		
		else{
			quitaA = LCS(n - 1, m, memoria);
			quitaB = LCS(n, m - 1, memoria);
			maximo = max(quitaA, quitaB);
		}
		memoria[n][m] = maximo;
	}
	return memoria[n][m];
}
int main(){
	int tamA, tamB;
	cin >> palabraA >> palabraB;

	tamA = palabraA.size();
	tamB = palabraB.size();

	vector<int> horizontal(tamB + 2, -1);
	vector<vector<int> > memo(tamA + 2, horizontal);

	cout << LCS(tamA - 1, tamB - 1, memo) << "\n";
	return 0;
}