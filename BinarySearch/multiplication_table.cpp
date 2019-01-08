//LINK to the Problem:
//http://codeforces.com/problemset/problem/448/D
//Problem type: Binary Search

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

typedef long long int lli;
lli n, m, k; 

lli howManyNumberBehind(lli middle){
	lli numbersBehind = 0;
	for(int i = 1; i <= n; i++)
		numbersBehind += min(m, middle / i);
	return numbersBehind;
}

lli BinarySearch(lli left, lli right){
	lli middle, numbersBehind;
	while(left < right){
		middle = (left + right) / 2;
		numbersBehind = howManyNumberBehind(middle);
		if(numbersBehind < k)
			left = middle + 1;
		else
			right = middle;
	}
	return right;
}

int main(){
	cin >> n >> m >> k;
	lli left = 1, right = n * m;
	cout << BinarySearch(left, right) << "\n";
	return 0;
}
