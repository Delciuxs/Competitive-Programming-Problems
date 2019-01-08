//LINK to the Problem:
//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1927
//Problem type: SSSP Dijkstra

#include<iostream>
#include<vector>
#include<queue>

using namespace std;

void Dijkstra(vector<int> &time_to_sent_message, int source_server, vector<vector<pair<int, int> > > adjacency_list)
{
	int distance, id_server;
	pair<int, int> aux_pq, aux_adj_list;

	time_to_sent_message[source_server] = 0;

	priority_queue<pair<int, int> > pq;

	pq.push(make_pair(0, source_server));

	while(pq.size() != 0)
	{
		aux_pq = pq.top();
		pq.pop();

		distance = -1 * aux_pq.first;
		id_server = aux_pq.second;

		if(distance > time_to_sent_message[id_server])
			continue;

		for(int s = 0; s < adjacency_list[id_server].size(); s++)
		{
			aux_adj_list = adjacency_list[id_server][s];

			if(time_to_sent_message[id_server] + aux_adj_list.second < time_to_sent_message[aux_adj_list.first])
			{
				time_to_sent_message[aux_adj_list.first] = time_to_sent_message[id_server] + aux_adj_list.second;
				pq.push(make_pair(time_to_sent_message[aux_adj_list.first] * -1, aux_adj_list.first));
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);	
	cout.tie(0);

	int t;

	cin >> t;

	for(int i = 0; i < t; i++)
	{
		int num_servers, num_connections, source_server, destination_server, serverA, serverB, time;

		cin >> num_servers >> num_connections >> source_server >> destination_server;

		vector<pair<int, int> > adjacency_nodes;
		vector<vector<pair<int, int> > > adjacency_list(num_servers, adjacency_nodes);

		vector<int> time_to_sent_message(num_servers, 1000000);
		

		for(int j = 0; j < num_connections; j++)
		{
			cin >> serverA >> serverB >> time;
			adjacency_list[serverA].push_back(make_pair(serverB, time));
			adjacency_list[serverB].push_back(make_pair(serverA, time));
		}

		Dijkstra(time_to_sent_message, source_server, adjacency_list);

		if(time_to_sent_message[destination_server] == 1000000)
			cout << "Case #" << i + 1 << ": unreachable\n";

		else
			cout << "Case #" << i + 1 << ": " << time_to_sent_message[destination_server] << "\n";
		

	}

	return 0;
}