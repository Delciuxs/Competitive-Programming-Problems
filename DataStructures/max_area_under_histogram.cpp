//LINK to the Problem:
//https://practice.geeksforgeeks.org/problems/maximum-rectangular-area-in-a-histogram/0
//Problem type: Data Structures: Stack

#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;

int main() {
	int t; cin >> t;
	while(t--){
	    int n; cin >> n;
	    vector<lli> h(n);
	    for(int i = 0; i < n; i++) cin >> h[i];
	    
	    int index = 1;
	    lli area = LLONG_MIN;
	    stack<lli> s;
	    s.push(0);
	    
	    while(index < n){
	        if(h[index] < h[s.top()]){
	            while(true){
	                if(s.empty()) break;
	                if(h[s.top()] <= h[index]) break;
	                lli valTop = s.top();
	                s.pop();
	                if(!s.empty()) area = max(area, (h[valTop]) * (index - s.top() - 1));
	                else area = max(area, (h[valTop]) * (index));
	            }
	        }
	        s.push(index);
	        index++;
	    }
	    
	    while(!s.empty()){
            lli valTop = s.top();
            s.pop();
            if(!s.empty()) area = max(area, (h[valTop]) * (index - s.top() - 1));
            else area = max(area, (h[valTop]) * (index));
        }
	    
	    cout << area << "\n";
	}
	return 0;
}