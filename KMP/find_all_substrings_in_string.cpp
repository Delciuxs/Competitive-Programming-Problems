//LINK to the Problem:
//https://www.geeksforgeeks.org/kmp-algorithm-for-pattern-searching/
//Problem type: KMP

#include<iostream>
#include<vector>
using namespace std;

vector<int> kmpTable(string &pattern){
	vector<int> table(pattern.size());
	int j = 0, i = 1;
	table[j] = 0;
	while(i < pattern.size()){
		if(pattern[j] == pattern[i]){
			table[i] = j + 1;
			j++, i++;
		}else{
			if(j != 0) j = table[j - 1];
			else{
				table[i] = 0;
				i++;
			}
		}
	}
	return table;
}

vector<int> findAllIndexesSubstring(string &text, string &pattern){
	vector<int> table = kmpTable(pattern);
	vector<int> indexes;

	int i = 0, j = 0;

	while(i < text.size()){
		if(text[i] == pattern[j]){
			i++, j++;
			if(j == pattern.size()){
				indexes.push_back(i - pattern.size());
				j = table[j - 1];
			}
		}else{
			if(j != 0) j = table[j - 1];
			else i++;
		}
	}
	return indexes;
}

int main(){

	string text, pattern;
	cin >> text >> pattern;
	vector<int> indexes = findAllIndexesSubstring(text, pattern);

	for(int i = 0; i < indexes.size(); i++) cout << indexes[i] << " ";

	return 0;
}