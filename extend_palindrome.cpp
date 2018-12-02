//LINK to the Problem:
//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2470
//Problem type: KMP

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

void kmpTable(string pat, vector<int> &lps) 
{ 
    int j = 0; 
    lps[0] = 0; 
    int i = 1; 
    while (i < lps.size()) { 
        if (pat[i] == pat[j]) { 
            j++; 
            lps[i] = j; 
            i++; 
        }else{ 
            if(j != 0){ 
                j = lps[j - 1]; 
            }else{ 
                lps[i] = 0; 
                i++; 
            } 
        } 
    } 
} 

int KMPSearch(string pat, string txt) 
{ 
    int M = pat.size(); 
    int N = txt.size(); 
 
    vector<int> lps(M);
    kmpTable(pat, lps); 
  
    int i = 0; 
    int j = 0; 
    while (i < N) { 
        if (pat[j] == txt[i]) { 
            j++; 
            i++; 
            if(i == N)
            	break;
        } 
        if (j == M)
            j = lps[j - 1]; 
        else if (i < N && pat[j] != txt[i]) { 
            if (j != 0) 
                j = lps[j - 1]; 
            else
                i = i + 1; 
        } 
    } 
    return j;
} 

int main(){

	string word;

	while(cin >> word){
		string wordReversed;
		wordReversed = word;
		reverse(wordReversed.begin(), wordReversed.end());
		int lastMatch = KMPSearch(wordReversed, word);

		cout << word;
		for(int s = lastMatch; s < wordReversed.size(); s++)
			cout << wordReversed[s];
		cout << "\n";

	}

	return 0;
}

