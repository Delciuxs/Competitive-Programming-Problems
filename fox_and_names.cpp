//LINK to the Problem:
//https://codeforces.com/problemset/problem/510/C
//Problem type: Graphs

#include<iostream>
#include<vector>

using namespace std;

vector<bool> visited(26, false);

void topological(int letter, vector<char> &topo, vector<vector<int> > &adjacency_list){
	if(visited[letter] == false){
		visited[letter] = true;
		for(int i = 0; i < adjacency_list[letter].size(); i++){
			if(visited[adjacency_list[letter][i]] == false){
				topological(adjacency_list[letter][i], topo, adjacency_list);	
			}
		}
		topo.push_back(char(letter + 'a'));
	}
	
}

bool hasCycle(int node, vector<int> &colors, vector<vector<int> > &adjacency_list){
	colors[node] = 0;
	for(int i = 0; i < adjacency_list[node].size(); i++){
		if(colors[adjacency_list[node][i]] == 0) return true;
		if(colors[adjacency_list[node][i]] == -1 && hasCycle(adjacency_list[node][i], colors, adjacency_list)) return true;
	}
	colors[node] = 1;
	return false;
}

int main(){

	int n; cin >> n;
	vector<string> names(n);
	vector<int> adjacency_nodes;
	vector<vector<int> > adjacency_list(26, adjacency_nodes);
	bool cycle = false;

	for(int i = 0; i < n; i++)
		cin >> names[i];

	int firstLetter = names[0][0] - 'a';

	for(int i = 0; i < (n - 1); i++){
		int a = 0;
		while(true){
			if(a >= names[i].size() || a >= names[i+1].size()) break;
			if(names[i][a] != names[i + 1][a]) break;
			a++;
		}
		if(a >= names[i].size() || a >= names[i + 1].size()){
			if((a >= names[i].size() && a >= names[i + 1].size()) || a >= names[i].size()) continue;
			cycle = true;
		}
		else{
			adjacency_list[names[i][a] - 'a'].push_back(int(names[i + 1][a] - 'a'));
		}		
	}

	vector<int> colors(26,-1);

	for(int i = 0; i < colors.size(); i++){
		if(colors[i] == -1){
			if(hasCycle(i, colors, adjacency_list)){
				cycle = true;
				break;
			}	
		}
	}

	if(cycle){
		cout << "Impossible" << endl;
	}else{
		vector<char> topo;
		for(int i = 0; i < 26; i++)
			topological(i, topo, adjacency_list);
		int lenArray = topo.size();
		for(int i = lenArray - 1; i >= 0; i--)
			cout << topo[i];
	}
	return 0;
}