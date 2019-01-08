//LINK to the Problem:
//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1239
//Problem type: KMP

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int kmpTable(string pat) 
{ 
    vector<int> lps(pat.size());
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
    return lps[lps.size() - 1];
} 

int main(){

	string word;
    cin >> word;

    while(word != "."){

        int index = kmpTable(word);
        if((word.size() % (word.size() - index)) == 0)
            cout << (word.size() / (word.size() - index)) << "\n";
        else
            cout << "1\n";
        cin >> word;
    }
	return 0;
}

