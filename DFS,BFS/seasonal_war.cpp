//LINK to the Problem:
//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=288
//Problem type: BFS

#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int m, num_war_eagles;


int movements[8][2] = {    //x,y
						{0,1},
						{0,-1},
						{1,0},
						{-1,0},
						{1,1},
						{1,-1},
						{-1,1},
						{-1,-1}

};

void BFS(int y, int x, vector<vector<char> > &grid, vector<vector<int> > &visited)
{
	pair<int, int> coordinate, aux;

	queue<pair<int, int> > search_this_nodes;

	coordinate.first = y;
	coordinate.second = x;

	search_this_nodes.push(coordinate);


	while(search_this_nodes.size() != 0)
	{
		aux = search_this_nodes.front();
		search_this_nodes.pop();

		visited[aux.first][aux.second] = num_war_eagles;

		for(int s = 0; s < 8; s++)
		{
			if(aux.first + movements[s][1] >= m || aux.first + movements[s][1] < 0 || aux.second + movements[s][0] >= m || aux.second + movements[s][0] < 0)
				continue;

			if(grid[aux.first + movements[s][1]][aux.second + movements[s][0]] == '1' && visited[aux.first + movements[s][1]][aux.second + movements[s][0]] == -1)
			{
				coordinate.first = aux.first + movements[s][1];
				coordinate.second = aux.second + movements[s][0];

				search_this_nodes.push(coordinate);
			}
		}
	}

}

int main()
{ 
	int cont = 0;
	while(cin >> m)
	{
		cont++;

		vector<char> horizontal(m);
		vector<vector<char> > grid(m, horizontal);

		vector<int> horizontal_1(m, -1);
		vector<vector<int> > visited(m, horizontal_1);


		num_war_eagles = 0;

		for(int i = 0; i < m; i++)
			for(int j = 0; j < m; j++)
				cin >> grid[i][j];
	
		for(int i = 0; i < m; i++)
			for(int j = 0; j < m; j++)
				if(grid[i][j] == '1')
					if(visited[i][j] == -1)
					{
						num_war_eagles++;
						BFS(i, j, grid, visited);
					}
						
		cout << "Image number "<< cont << " contains " << num_war_eagles << " war eagles." << endl;

	}

	return 0; 
}