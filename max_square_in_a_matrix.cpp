//LINK to the Problem:
//https://practice.geeksforgeeks.org/problems/largest-square-formed-in-a-matrix/0
//Problem type: DP

#include<iostream>
#include<vector>

using namespace std;

int Min(int a, int b, int c){
	int minNumber;
	minNumber = min(a,b);
	minNumber = min(minNumber, c);
	return minNumber;
}

int MaxSquareSubMatrix(vector<vector<int> > &grid, int numRows, int numCols){
	int maxSubMatrix = 0, minNumber = 0;

	for(int i = 0; i < numRows; i++){
		for(int j = 0; j < numCols; j++){
			if((i - 1 < 0) || (j - 1 < 0))
				minNumber = 0;
			else
				minNumber = Min(grid[i - 1][j], grid[i][j - 1], grid[i - 1][j - 1]);
			if(minNumber == 0)
				maxSubMatrix = max(maxSubMatrix, grid[i][j]);
			else{
				if(grid[i][j] != 0){
					grid[i][j] = minNumber + 1;
					maxSubMatrix = max(maxSubMatrix, grid[i][j]);
				}
			}
		}
	}

	return maxSubMatrix;
}

int main(){

	int t; cin >> t;

	for(int s = 0; s < t; s++){
		int rows; cin >> rows;
		int cols; cin >> cols;
		vector<int> auxCol(cols);
		vector<vector<int> > grid(rows, auxCol);

		for(int i = 0; i < rows; i++)
			for(int j = 0; j < cols; j++)
				cin >> grid[i][j];

		cout << MaxSquareSubMatrix(grid, rows, cols) << "\n";
	}

	return 0;
}