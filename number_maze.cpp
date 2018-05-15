//LINK to the Problem:
//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=870
//Problem type: SSSP Dijkstra

#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int movements[4][2] = //x,y
{
	{0,1},//bajar
	{0,-1},//subir
	{1,0},//derecha
	{-1,0}//izquiera
};

int num_rows, num_columns;

void Dijkstra(vector<vector<int> > &distances, vector<vector<int> > maze)
{
	int distance;
	pair<int, int> coordinates, adjacency_block;
	pair<int, pair<int, int> > aux_pq;	

	priority_queue<pair<int, pair<int, int> > > pq;

	pq.push(make_pair((-1 * distances[0][0]), make_pair(0,0)));

	while(pq.size() != 0)
	{
		aux_pq = pq.top();
		pq.pop();

		distance = -1 * aux_pq.first;
		coordinates = aux_pq.second;

		if(distance > distances[coordinates.first][coordinates.second])
			continue;

		for(int s = 0; s < 4; s++)
		{
			adjacency_block.first = coordinates.first + movements[s][1];
			adjacency_block.second = coordinates.second + movements[s][0];

			if((adjacency_block.first >= num_rows) || (adjacency_block.second >= num_columns) || (adjacency_block.first < 0) || (adjacency_block.second < 0))	
				continue;

			if(distances[coordinates.first][coordinates.second] + maze[adjacency_block.first][adjacency_block.second] < distances[adjacency_block.first][adjacency_block.second])
			{
				distances[adjacency_block.first][adjacency_block.second] = distances[coordinates.first][coordinates.second] + maze[adjacency_block.first][adjacency_block.second];
				pq.push(make_pair((-1 * distances[adjacency_block.first][adjacency_block.second]), make_pair(adjacency_block.first, adjacency_block.second)));
			}
		}
	}
	
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);	
	cout.tie(0);

	int num_mazes;

	cin >> num_mazes;

	for(int i = 0; i < num_mazes; i++)
	{
		pair<int, int> destination, origin;

		cin >> num_rows >> num_columns;

		origin.first = 0;
		origin.second = 0;

		destination.first = num_rows - 1;
		destination.second = num_columns - 1;

		vector<int> horizontal(num_columns, 0);
		vector<vector<int> > maze(num_rows, horizontal);

		for(int j = 0; j < num_rows; j++)
		{
			for(int k = 0; k < num_columns; k++)
				cin >> maze[j][k];
		}

		vector<int> horizontal_2(num_columns, 1000000);
		vector<vector<int> > distances(num_rows, horizontal_2);
		distances[origin.first][origin.second] = maze[origin.first][origin.second];

		Dijkstra(distances, maze);

		cout << distances[destination.first][destination.second] << "\n";
	}

	return 0;
}