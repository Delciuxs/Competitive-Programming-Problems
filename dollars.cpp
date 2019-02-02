//LINK to the Problem:
//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=83
//Problem type: DP

#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main(){

	vector<int> denominations = {5,10,20,50,100,200,500,1000,2000,5000,10000};
	vector<long long int> ways(30005,0);
	ways[0] = 1;

	for(int i = 0; i < denominations.size(); i++){
		for(int j = denominations[i]; j < ways.size(); j++){
			ways[j] += ways[j - denominations[i]];
		}
	}

	string dollars, auxDollars;
	cin >> dollars;
	auxDollars = dollars;

	while(auxDollars != "0.00"){
		for(int i = 0; i < dollars.size(); i++)
			if(dollars[i] == '.')
				dollars.erase(dollars.begin() + i);

		int dollarsInt = stoi(dollars);

		cout.width(6); cout << right << auxDollars;
		cout.width(17); cout<< right << ways[dollarsInt] << "\n";

		cin >> dollars;
		auxDollars = dollars;
	}



	return 0;
}