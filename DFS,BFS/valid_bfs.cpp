//LINK to the Problem:
//https://codeforces.com/problemset/problem/1037/D
//Problem type: BFS

#include<iostream>
#include<unordered_set>
#include<queue>
using namespace std;

int main(){

	ios_base::sync_with_stdio(0);
	cin.tie(0);	
	cout.tie(0);


	int u,v;
	int numNode; cin >> numNode;
	vector<int> adjacencyNodes, path(numNode);
	vector<vector<int> > adjacencyList(numNode + 1, adjacencyNodes);
	queue<int> q;

	for(int i = 0; i < numNode - 1; i++){
		cin >> u >> v;
		adjacencyList[u].push_back(v);
		adjacencyList[v].push_back(u);
	}

	for(int i = 0; i < numNode; i++)
		cin >> path[i];


	int it = 0, aux;
	q.push(1);
	unordered_set<int> needed;
	unordered_set<int> used;
	bool valid = true;

	while(q.size() != 0){
		if(!valid)
			break;
		if(it == path.size() - 1)
			break;
		aux = q.front(); q.pop();
		used.insert(aux);
		for(int i = 0; i < adjacencyList[aux].size(); i++){
			if(used.count(adjacencyList[aux][i]) == 0){
				needed.insert(adjacencyList[aux][i]);	
			}
		}
		for(int j = 1; j <= needed.size(); j++){
			if(needed.count(path[it + j])){
				q.push(path[it + j]);
			}else{
				valid = false;
				break;
			}
		}
		it += needed.size();
		needed.clear();

	}

	if (valid){	
		cout << "Yes" << "\n";
	}else{
		cout << "No" << "\n";
	}

	return 0;

}