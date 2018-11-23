//LINK to the Problem:
//https://www.spoj.com/problems/BYTESM2/
//Problem type: Dynamic Programming

#include<iostream>
#include<vector>
#include<vector>

using namespace std;

int h, w;

long long int DP(int coorX, int coorY, vector<vector<int> > &grid, vector<vector<int> > &memo){
	long long int moveDown = 0, moveLeftDiagonally = 0, moveRightDiagonally = 0, max1, max2;
	if(coorX < 0 || coorX >= w || coorY >= h)
		return 0;
	else if(coorY == h - 1)
		return grid[coorY][coorX];
	else if(memo[coorY][coorX] == -1){
		moveDown = grid[coorY][coorX] + DP(coorX, coorY + 1, grid, memo);
		moveLeftDiagonally = grid[coorY][coorX] + DP(coorX - 1, coorY + 1, grid, memo);
		moveRightDiagonally = grid[coorY][coorX] + DP(coorX + 1, coorY + 1, grid, memo);

		max1 = max(moveDown, moveLeftDiagonally);
		max2 = max(max1, moveRightDiagonally);

		memo[coorY][coorX] = max2;
	}
	return memo[coorY][coorX];

}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);	
	cout.tie(0);

	int t; cin >> t;

	for(int s = 0; s < t; s++){
		cin >> h >> w;

		vector<int> columns(w);
		vector<vector<int> > grid(h, columns);
		vector<int> colmemo(w,-1);
		vector<vector<int> > memo(h, colmemo);

		for(int i = 0; i < h; i++){
			for(int j = 0; j < w; j++){
				cin >> grid[i][j];
			}
		}

		long long int max_stones = -1;

		for(int i = 0; i < grid[0].size(); i++){
			max_stones = max(max_stones, DP(i , 0, grid, memo));
		}

		cout << max_stones << "\n";
	}

	return 0;
}