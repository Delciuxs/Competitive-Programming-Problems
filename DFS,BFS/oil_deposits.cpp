//LINK to the Problem:
//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=513
//Problem type: DFS

#include<iostream>
#include<vector>

using namespace std;

int m, n, num_oil_deposites;


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

void DFS(int y, int x, vector<vector<char> > &grid, vector<vector<int> > &visited)
{
	if(y >= m || y < 0 || x >= n || x < 0)
		return;
	
	if(grid[y][x] == '@')
	{
		if(visited[y][x] == 0)
		{
			visited[y][x] = num_oil_deposites;
			for(int s = 0; s < 8; s++)
				DFS(y + movements[s][1], x + movements[s][0], grid, visited);
		}
	}
}

int main()
{
	cin >> m >> n;

	while(m + n != 0)
	{
		vector<char> horizontal(n);
		vector<vector<char> > grid(m, horizontal);

		vector<int> horizontal_1(n, 0);
		vector<vector<int> > visited(m, horizontal_1);


		num_oil_deposites = 0;

		for(int i = 0; i < m; i++)
			for(int j = 0; j < n; j++)
				cin >> grid[i][j];
	
		for(int i = 0; i < m; i++)
			for(int j = 0; j < n; j++)
				if(grid[i][j] == '@')
					if(visited[i][j] == 0)
					{
						num_oil_deposites++;
						DFS(i, j, grid, visited);
					}
						
		cout << num_oil_deposites << endl;

		cin >> m >> n;
	}

	return 0; 
}