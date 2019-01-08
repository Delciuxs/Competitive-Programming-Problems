//LINK to the Problem:
//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1594
//Problem type: Short Path BFS

#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int movements[4][2] ={

					//x,y
					{0,1},
					{0,-1},
					{1,0},
					{-1,0}
};

int rows, columns;

void BFS(int start_row, int start_column, vector<vector<int> > &distance_map, vector<vector<int> > &bombs_map)
{
	pair<int, int> aux, aux2;
	vector<int> horizontal3(columns, 0);
	vector<vector<int> > visited(rows, horizontal3);
	queue<pair<int, int> > coordiantes;

	aux.first = start_row;
	aux.second= start_column;

	coordiantes.push(aux);

	while(coordiantes.size() != 0)
	{
		aux = coordiantes.front();
		coordiantes.pop();

		for(int s = 0; s < 4; s++)
		{
			aux2.first = aux.first + movements[s][1];
			aux2.second = aux.second + movements[s][0];

			if(aux2.first >= rows || aux2.second >= columns || aux2.first < 0 || aux2.second < 0)
				continue;

			if(visited[aux2.first][aux2.second] == 0 && bombs_map[aux2.first][aux2.second] == 0)
			{
				visited[aux2.first][aux2.second] = 1;
				distance_map[aux2.first][aux2.second] = distance_map[aux.first][aux.second] + 1;

				coordiantes.push(aux2);
			}
		}
	}


}

int main()
{

	cin >> rows >> columns;

	while(rows + columns != 0)
	{
		int num_rows_with_bombs, row_id, num_bombs_row, column_id, start_row, start_column, destination_row, destination_column;

		vector<int> horizontal(columns, 0);
		vector<vector<int> > bombs_map(rows, horizontal);

		vector<int> horizontal2(columns, (1 << 30));
		vector<vector<int> > distance_map(rows, horizontal2);

		cin >> num_rows_with_bombs;

		for(int i = 0; i < num_rows_with_bombs; i++)
		{
			cin >> row_id >> num_bombs_row;

			for(int j = 0; j < num_bombs_row; j++)
			{
				cin >> column_id;
				bombs_map[row_id][column_id] = 1;
			}

		}

		cin >> start_row >> start_column;
		cin >> destination_row >> destination_column;

		distance_map[start_row][start_column] = 0;

		BFS(start_row, start_column, distance_map, bombs_map);

		cout << distance_map[destination_row][destination_column] << endl;


		cin >> rows >> columns;
	}

	return 0;
}