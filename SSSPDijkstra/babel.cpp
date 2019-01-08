//LINK to the Problem:
//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2487
//Problem type: SSSP Dijkstra

#include<iostream>
#include<queue>
#include<vector>
#include<unordered_map>

using namespace std;

void Dijkstra(vector<int> &distances, vector<vector<pair<int, pair<int, char> > > > adjacency_list, int id_languaje_origin)
{
		//distance node letter
	int distance;
	pair<int, pair<int, char> > aux_pq;
	pair<int, char> move;

		//node distance letter
	pair<int, pair<int, char> > aux_adj_list; 

	priority_queue<pair<int, pair<int, char> > > pq;

	pq.push(make_pair(0 , make_pair(id_languaje_origin, '*')));

	while(pq.size() != 0)
	{
		aux_pq = pq.top();
		pq.pop();

		distance = -1 * aux_pq.first;
		move = aux_pq.second;

		if(distance > distances[move.first])
			continue;

		for(int s = 0; s < adjacency_list[move.first].size(); s++)
		{
			aux_adj_list = adjacency_list[move.first][s];

			if(move.second == aux_adj_list.second.second)
				continue;
			
			if(distances[move.first] + aux_adj_list.second.first < distances[aux_adj_list.first])
			{
				distances[aux_adj_list.first] = distances[move.first] + aux_adj_list.second.first;
				pq.push(make_pair(-1 * distances[aux_adj_list.first], make_pair(aux_adj_list.first, aux_adj_list.second.second)));
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);	
	cout.tie(0);

	int num_words;

	cin >> num_words;

	while(num_words != 0)
	{
		int cont = 0, num_languages;

		unordered_map<string, int> id_languaje;

		string language_origin, language_destination, languajeA, languajeB, word;

		cin >> language_origin;
		id_languaje[language_origin] = cont++;

		cin >> language_destination; 
		id_languaje[language_destination] = cont++;

		vector<pair<string, pair<string, string> > > info;
		pair<string, pair<string, string> > aux_info;

		for(int i = 0; i < num_words; i++)
		{	
			cin >> languajeA;

			if(id_languaje.count(languajeA) == 0)
				id_languaje[languajeA] = cont++;

			cin >> languajeB;

			if(id_languaje.count(languajeB) == 0)
				id_languaje[languajeB] = cont++;

			cin >> word;

			info.push_back(make_pair(languajeA, make_pair(languajeB, word)));

		}

		num_languages = id_languaje.size();

		vector<int> distances(num_languages, 1000000);
		int id_languaje_origin, id_languaje_destination;
		
		id_languaje_origin = id_languaje[language_origin];
		id_languaje_destination = id_languaje[language_destination];

		distances[id_languaje_origin] = 0;

				//node distance letter
		vector<pair<int, pair<int, char> > > adjacency_languaje;
		vector<vector<pair<int, pair<int, char> > > > adjacency_list(num_languages, adjacency_languaje);
		int id_languajeA, id_languajeB;
		char letter_word;

		for(int i = 0; i < info.size(); i++)
		{
			aux_info = info[i];

			id_languajeA = id_languaje[aux_info.first];
			id_languajeB = id_languaje[aux_info.second.first];

			word = aux_info.second.second;

			letter_word = word[0];

			adjacency_list[id_languajeA].push_back(make_pair(id_languajeB, make_pair(word.size(), letter_word)));
			adjacency_list[id_languajeB].push_back(make_pair(id_languajeA, make_pair(word.size(), letter_word)));
		}

		Dijkstra(distances, adjacency_list, id_languaje_origin);

		int iteracion1, iteracion2, aux;

		iteracion1 = distances[id_languaje_destination];

		vector<int> distances2(num_languages, 1000000);

		aux = id_languaje_origin;

		id_languaje_origin = id_languaje_destination;
		id_languaje_destination = aux;

		distances2[id_languaje_origin] = 0;

		Dijkstra(distances2, adjacency_list, id_languaje_origin);		

		iteracion2 = distances2[id_languaje_destination];

		if(iteracion1 == iteracion2)
		{
			if(iteracion1 == 1000000)
				cout << "impossivel" << "\n";
			else
				cout << iteracion1 << "\n";
		}

		else
		{
			if(iteracion1 == 1000000)
			{
				if(iteracion2 != 1000000)
					cout << iteracion2 << "\n";
			}
			else if(iteracion2 == 1000000)
			{
				if(iteracion1 != 1000000)
					cout << iteracion1 << "\n";
				
			}
		}
		cin >> num_words;
	}

	return 0;
}

