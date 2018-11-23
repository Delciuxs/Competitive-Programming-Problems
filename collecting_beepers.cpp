//LINK to the Problem:
//https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1437
//Problem type: Travelling Salesman

#include<iostream>
#include<algorithm>
#include<unordered_map>
#include<vector>

using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);	
	cout.tie(0);

	int t; cin >> t;

	for(int i = 0; i < t; i++){
		int maxX, maxY; cin >> maxX >> maxY;

		pair<int, int> start;
		cin >> start.first >> start.second;

		int numBeepers; cin >> numBeepers;
		unordered_map<char, pair<int, int> > coordinates_maped;
		vector<char> beepers;

		char idChar = 'a';
		for(int j = 0; j < numBeepers; j++){
			pair<int, int> aux;
			cin >> aux.first >> aux.second;
			coordinates_maped[idChar] = aux;
			beepers.push_back(idChar);
			idChar++;
		}
		
		int min_path = 1000000000;

		do{
			int distance_path = 0;
			pair<int, int> aux1;
			pair<int, int> aux2;
			for(int s = 0; s < beepers.size() - 1; s++){
				aux1 = coordinates_maped[beepers[s]];
				aux2 = coordinates_maped[beepers[s+1]];

				distance_path += (abs(aux1.first - aux2.first) + abs(aux1.second - aux2.second));
			}

			distance_path += (abs(start.first - coordinates_maped[beepers[0]].first) + abs(start.second - coordinates_maped[beepers[0]].second));
			distance_path += (abs(start.first - coordinates_maped[beepers[beepers.size() - 1]].first) + abs(start.second - coordinates_maped[beepers[beepers.size() - 1]].second));

			min_path = min(min_path, distance_path);

		}while(next_permutation(beepers.begin(), beepers.end()));
		cout << "The shortest path has length " << min_path << "\n";
	}
	return 0;
}