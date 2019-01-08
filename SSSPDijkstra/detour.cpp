//LINK to the Problem:
//https://open.kattis.com/problems/detour
//Problem type: SSSP Dijkstra

#include<iostream>
#include<vector>
#include<queue>
#include<map>

using namespace std;

void Dijkstra(vector<int> &distances, vector<vector<pair<int, int> > > &adjacency_list)
{
	pair<int, int> aux_pq, aux_adj_list;
	int distance, id_intersection;
	priority_queue<pair<int, int> > pq;

	pq.push(make_pair(0, 1));

	while(pq.size() != 0)
	{
		aux_pq = pq.top();
		pq.pop();
		distance = -1 * aux_pq.first;
		id_intersection = aux_pq.second;

		if(distance > distances[id_intersection])
			continue;

		for(int s = 0; s < adjacency_list[id_intersection].size(); s++)
		{
			aux_adj_list = adjacency_list[id_intersection][s];

			if(distances[id_intersection] + aux_adj_list.second < distances[aux_adj_list.first])
			{
				distances[aux_adj_list.first] = distances[id_intersection] + aux_adj_list.second;	
				pq.push(make_pair(-1 * distances[aux_adj_list.first], aux_adj_list.first));
			}
		}
	}
}

void Dijkstra2(vector<int> &distances, vector<vector<pair<int, int> > > &adjacency_list, vector<int> &parents, vector<int> &minimal_distance)
{
	pair<int, int> aux_pq, aux_adj_list;
	int distance, id_intersection;
	priority_queue<pair<int, int> > pq;

	pq.push(make_pair(0, 0));

	while(pq.size() != 0)
	{
		aux_pq = pq.top();
		pq.pop();
		distance = -1 * aux_pq.first;
		id_intersection = aux_pq.second;

		if(distance > distances[id_intersection])
			continue;

		for(int s = 0; s < adjacency_list[id_intersection].size(); s++)
		{
			aux_adj_list = adjacency_list[id_intersection][s];

			if(minimal_distance[id_intersection] - aux_adj_list.second == minimal_distance[aux_adj_list.first])
				continue;
			
			if(distances[id_intersection] + aux_adj_list.second < distances[aux_adj_list.first])
			{
				parents[aux_adj_list.first] = id_intersection;
				distances[aux_adj_list.first] = distances[id_intersection] + aux_adj_list.second;	
				pq.push(make_pair(-1 * distances[aux_adj_list.first], aux_adj_list.first));
			}
		}
	}
}


void get_path(vector<int> &solution_path, int destination, int source, vector<int> &parents2)
{
	if(destination == source)
	{
		solution_path.push_back(source);
		return;
	}

	get_path(solution_path, parents2[destination], source, parents2);
	solution_path.push_back(destination);
}


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);	
	cout.tie(0);
	
	int num_intersections, num_roads, intersectionA, intersectionB, distance_road;

	cin >> num_intersections >> num_roads;

	vector<pair<int, int> > adjacency_road;
	vector<vector<pair<int, int> > > adjacency_list(num_intersections, adjacency_road);


	for(int i = 0; i < num_roads; i++)
	{
		cin >> intersectionA >> intersectionB >> distance_road;

		adjacency_list[intersectionA].push_back(make_pair(intersectionB, distance_road));
		adjacency_list[intersectionB].push_back(make_pair(intersectionA, distance_road));
	}

	vector<int> distances(num_intersections, 1000000);
	distances[1] = 0;
	
	Dijkstra(distances, adjacency_list);

	vector<int> solution_path;

	vector<int> distances2(num_intersections, 1000000);
	distances2[0] = 0;

	vector<int> parents2(num_intersections, -1);

	Dijkstra2(distances2, adjacency_list, parents2, distances);

	if(parents2[1] == -1)
		cout << "impossible" << endl;
	else
	{
		get_path(solution_path, 1, 0, parents2);	
		cout << solution_path.size() << " ";
		for(int i = 0; i < solution_path.size(); i++)
			cout << solution_path[i] << " ";
		cout << endl;
	}


	return 0;
}