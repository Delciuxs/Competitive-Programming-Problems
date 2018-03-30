//LINK to the Problem:
//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2035
//Problem type: DFS

#include<iostream>
#include<vector>

using namespace std;

int m, n, region;
char land;

int movements[8][2] = {    //x,y
						{0,1},
						{0,-1},
						{1,0},
						{-1,0}

};

void DFS(int y, int x, vector<vector<char> > &grid, vector<vector<int> > &visited)
{
	if(y >= m || y < 0)
		return;

	if(grid[y][x] == land && visited[y][x] == 0)
	{
		region++;
		visited[y][x] = 1;

		for(int s = 0; s < 8; s++)
			DFS(y + movements[s][1], ((x + movements[s][0]) + n)%n, grid, visited);
	}
}

int main()
{
	while(cin >> m >> n)
	{
		int king_xcoor, king_ycoor, area_region = 0;

		vector<char> horizantal(n);
		vector<vector<char> > grid(m, horizantal);

		vector<int> horizantal_2(n, 0);
		vector<vector<int> > visited(m, horizantal_2);

		for(int i = 0; i < m; i++)
			for(int j = 0; j < n; j++)
				cin >> grid[i][j];

		cin >> king_ycoor >> king_xcoor;

		land = grid[king_ycoor][king_xcoor];

		region = 0;

		DFS(king_ycoor, king_xcoor, grid, visited);

		for(int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)
			{
				if(grid[i][j] == land && visited[i][j] == 0)
				{
					region = 0;

					DFS(i, j, grid, visited);

					area_region = max(area_region, region);
				}
			}

		cout << area_region << endl;
	}

	return 0;
}