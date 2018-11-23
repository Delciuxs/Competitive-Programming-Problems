//LINK to the Problem:
//https://www.spoj.com/problems/INVCNT/
//Problem type: Divide and Conquer

#include<bits/stdc++.h>
using namespace std;

long long int Merge(vector<int> &numbers, int left, int middle, int right, vector<int> &temp){	
	long long int inversions = 0;
	int i = left, j = middle, k = left;

	while((i <= (middle - 1)) && (j <= right)){
		if(numbers[i] <= numbers[j]){
			temp[k] = numbers[i];
			k++; i++;
		}else{
			temp[k] = numbers[j];
			k++;j++;
			inversions = inversions + (middle - i);
		}
	}
	while(i <= middle - 1){
		temp[k] = numbers[i];
		k++; i++;
	}
	while(j <= right){
		temp[k] = numbers[j];
		k++; j++;	
	}
	for(int s = left; s <= right; s++){
		numbers[s] = temp[s];
	}
	return inversions;
}

long long int MergeSort(vector<int> &numbers, int left, int right, vector<int> &temp){
	long long int inversions = 0;
	int middle = (left + right) / 2;

	if(left == right)
		return 0;
	inversions += MergeSort(numbers, left, middle, temp);
	inversions += MergeSort(numbers, middle + 1, right, temp);
	inversions += Merge(numbers, left, middle + 1, right, temp);
	return inversions;
}


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);

	int t;
	cin >> t;

	for(int T = 0; T < t; T++){
		int n;
		cin >> n;

		vector<int> numbers(n);
		vector<int> temp(n);

		for(int i = 0; i < n; i++)
			cin >> numbers[i];
		long long int res = MergeSort(numbers, 0, numbers.size() - 1, temp);
		cout << res << "\n";
	}
	return 0;
}