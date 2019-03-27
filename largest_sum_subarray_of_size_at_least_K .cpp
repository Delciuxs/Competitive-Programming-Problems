//LINK to the Problem:
////https://practice.geeksforgeeks.org/problems/largest-sum-subarray-of-size-at-least-k/0
//Problem type: Dynamic Programming

#include<iostream>
#include<vector>
using namespace std;
#define inf -1000000000

int main(){

	int t; cin >> t;

	while(t--){
		int n, k; cin >> n;

		vector<int> numbers(n);
		for(int i = 0; i < n; i++)
			cin >> numbers[i];
		cin >> k;

		long long int carry = 0;
		for(int i = 0; i < k; i++)
			carry += numbers[i]; 

		long long int maxAns = carry;
		long long int aux = carry;

		for(int i = 1; i < numbers.size(); i++){
			long long int newSubArray;
			int index = i + k - 1;
			carry -= numbers[i-1];
			if(index <= (numbers.size()-1)){
				carry += numbers[index];
				newSubArray = carry;	
			}else newSubArray= inf;
			if(newSubArray == inf) break;			
			long long int continueSubArray = aux + (numbers[i + k -1]);
			if(newSubArray >= continueSubArray) aux = newSubArray;
			else aux = continueSubArray;
			maxAns = max(maxAns, aux);
		}

		cout << maxAns << endl;
	}

	return 0;
}