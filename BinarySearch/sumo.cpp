//LINK to the Problem:
//https://omegaup.com/arena/problem/SUMO#problems
//Problem type: Binary Search

#include<iostream>
#include<vector>
#include<unordered_set>
#include<queue>
using namespace std;

int lastFight;
int numFighters, numFights; 

int findIndex(vector<int> &fight, int key){
	int index = -1;
	for(int i = 0; i < fight.size(); i++){
		if(fight[i] == key){
			index = i;
			break;
		}
	}
	return index;
}
void eraseFights(vector<vector<int> > &fights, vector<pair<int, int> > &matches, int idFight){
	int index1, index2;
	for(int i = lastFight; i >= idFight; i--){
		index1 = findIndex(fights[matches[i].first], matches[i].second);
		fights[matches[i].first].erase(fights[matches[i].first].begin() + index1);	
		index2 = findIndex(fights[matches[i].second], matches[i].first);
		fights[matches[i].second].erase(fights[matches[i].second].begin() + index2);
	}
	lastFight = idFight - 1;
}
void addFights(vector<vector<int> > &fights, vector<pair<int, int> > &matches, int idFight){
	for(int i = lastFight + 1; i < idFight; i++){
		fights[matches[i].first].push_back(matches[i].second);
		fights[matches[i].second].push_back(matches[i].first);
	}
	lastFight = idFight  - 1;
}
bool BipartiteCheck(int fighter, vector<vector<int> > &fights, unordered_set<int> &visited, vector<int> &teams){
	int auxIdFighter;
	queue<int> fighters;
	fighters.push(fighter);
	visited.insert(fighter);
	teams[fighter] = -1;
	while(fighters.size() != 0){
		auxIdFighter = fighters.front();
		fighters.pop();
		for(int i = 0; i < fights[auxIdFighter].size(); i++){
			if(visited.count(fights[auxIdFighter][i]) == 0){
				visited.insert(fights[auxIdFighter][i]);
				teams[fights[auxIdFighter][i]] = teams[auxIdFighter] * -1;
				fighters.push(fights[auxIdFighter][i]);
			}
			else if(teams[fights[auxIdFighter][i]] == teams[auxIdFighter])
				return false;
		}
	}
	return true;
}
bool canDivideFighters(int idFight, vector<vector<int> > &fights, vector<pair<int, int> > &matches){
	idFight = idFight - 1;
	if(idFight < lastFight)
		eraseFights(fights, matches, idFight);
	else if(idFight > lastFight)
		addFights(fights, matches, idFight);
	unordered_set<int> visited;
	vector<int> teams(numFights + 1);
	bool can = true;
	for(int i = 1; i <= numFighters; i++){
		if(visited.count(i) == 0){
			if(!BipartiteCheck(i, fights, visited, teams)){
				can = false;
				break;
			}
		}	
	}
	return can;
}
int BinarySearch(int left, int right, vector<vector<int> > &fights, vector<pair<int, int> > &matches){
	int middle;
	int answer;
	while(left <= right){
		middle = (left + right) / 2;
		if(canDivideFighters(middle, fights, matches)){
			answer = middle;
			left = middle + 1;
		}else
			right = middle - 1;
	}
	return answer;
}
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> numFighters >> numFights;
	int fighterA, fighterB;
	vector<pair<int, int> > matches(numFights);
	vector<int> fight;
	vector<vector<int> > fights(numFighters + 1, fight);
	for(int i = 0; i < numFights; i++){
		cin >> fighterA >> fighterB;
		matches[i].first = fighterA;
		matches[i].second = fighterB;
		fights[fighterA].push_back(fighterB);
		fights[fighterB].push_back(fighterA);
		lastFight = i;
	}
	int left = 1, right = numFights;
	cout << BinarySearch(left, right, fights, matches) << "\n";
	return 0;
}