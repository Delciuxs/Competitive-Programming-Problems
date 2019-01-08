//LINK to the Problem:
//https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=3104
//Problem type: DFS

#include<iostream>
#include<vector>

using namespace std;

int m, num_ship_alive;

int movements[4][2] = {		//x,y	
							{0,1},
							{0,-1},
							{1,0},
							{-1,0}

};

void DFS(int y, int x, vector<vector<char> > &grid, vector<vector<int> > &visited)
{
	if(y >= m || y < 0 || x >= m || x < 0)
		return;

	if(grid[y][x] == 'x' || grid[y][x] == '@')
	{
		if(visited[y][x] == 0)
		{
			visited[y][x] = num_ship_alive;
			for(int k = 0; k < 4; k++)
				DFS(y + movements[k][1], x + movements[k][0], grid, visited);			
		}
		
		
	}

	
} 

int main()
{
	int t;

	cin >> t;

	for(int s = 0; s < t; s++)
	{
		cin >> m;

		vector<char> horizontal(m);
		vector<vector<char> > grid(m , horizontal);

		vector<int> horizontal_2(m, 0);
		vector<vector<int> > visited(m , horizontal_2);

		num_ship_alive = 0;

		for(int i = 0; i < m; i++)
			for(int j = 0; j < m; j++)
				cin >> grid[i][j];

		for(int i = 0; i < m; i++)
			for(int j = 0; j < m; j++)
			{
				if(grid[i][j] == 'x' && visited[i][j] == 0)
				{
					num_ship_alive++;
					DFS(i, j, grid, visited);
				}
			}

		cout << "Case " << s + 1 << ": " << num_ship_alive << endl;

	}
	return 0;
}