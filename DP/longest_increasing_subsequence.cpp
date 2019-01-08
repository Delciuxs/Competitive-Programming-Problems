//LINK to the Problem:
//https://www.spoj.com/problems/ELIS/
//Problem type: Dynamic Programming

#include<iostream>
#include<vector>
using namespace std;

int LIS(vector<int> &numeros, vector<int> &d){

	int res = -1;
	for(int i = 0; i < numeros.size(); i++){
		int aux = 1;
		int aux_max = 1;
		for(int j = 0; j < i; j++){
			if(numeros[j] < numeros[i]){
				aux = max(1, d[j] + 1);	
				aux_max = max(aux, aux_max);
			}
		}
		d[i] = aux_max;
	}
	for(int s = 0; s < d.size(); s++)
		res = max(res, d[s]);
	return res;
}

int main(){
	int n;
	cin >> n;
	
	vector<int> numeros(n);
	vector<int> d(n);

	for(int i = 0; i < n; i++)
		cin >> numeros[i];

	cout << LIS(numeros, d) << "\n";
	return 0;
}