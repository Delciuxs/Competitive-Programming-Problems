//LINK to the Problem:
//https://omegaup.com/arena/problem/maria?fbclid=IwAR1E9y99hOTEhKoYqfAFiuMHdDli9ubJJqrloO1A9KC-y09PmFW_hJEMGiM#problems
//Problem type: Data Structures (stack)

#include<iostream>
#include<cmath>
#include<vector>
#include<stack>
using namespace std;

typedef long long int lli;

vector<lli> computeArray(vector<lli> &nums, bool right){
	vector<lli> ans(nums.size());
	stack<lli> s;
	lli k, indexTop, len = nums.size();
	if(right){
		s.push(0);	
		k = 1;
	} 
	else{
		s.push(len - 1);
		k = len - 2;
	} 
	while(true){
		if(right){
			if(k >= nums.size()) break;	
		}else{
			if(k <= -1) break;
		}if(nums[k] > nums[s.top()]) s.push(k);
		else{
			indexTop = s.top();
			while((s.size() != 0) && (nums[k] < nums[s.top()])){
				ans[s.top()] = indexTop;
				s.pop();
			}
			s.push(k);
		}
		if(right) k++;
		else k--;
	}indexTop = s.top();
	while(s.size() != 0){
		ans[s.top()] = indexTop;
		s.pop();
	}
	return ans;
}

int main(){

	int n; cin >> n;
	vector<lli> nums(n);
	for(int i = 0; i < n; i++) cin >> nums[i];
	vector<lli> right = computeArray(nums, true);
	vector<lli> left = computeArray(nums, false);

	lli ans = 0;

	for(int i = 0; i < n; i++){
		ans += ((abs(i - right[i]) + 1ll) * (abs(i - left[i]) + 1ll) * (nums[i]));
	}

	cout << ans << "\n";

	return 0;
}