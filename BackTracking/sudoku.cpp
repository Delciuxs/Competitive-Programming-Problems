//LINK to the Problem:
//https://projecteuler.net/problem=96
//Problem type: BackTracking

#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

bool finallySolved;

void solveSudoku(vector<vector<int> > &grid, int index, vector<vector<int> > &solution){
	vector<int> numbers(10,0);

	if(index == 82){
		finallySolved = true;
		solution = grid;
		return;
	}
	int row, col;

	if((index % 9) == 0){
		row = (index / 9) -1;
		col = 8;
	}
	else{
		row = (index / 9);
		col = (index % 9) - 1;
	}

	if(grid[row][col] == 0){
		for(int i = 0; i < 9; i++){
			numbers[grid[row][i]]++;
			numbers[grid[i][col]]++;
		}
		int auxRow = floor(row / 3) * 3;
		int auxCol = floor(col / 3) * 3;

		for(int i = auxRow; i <= (auxRow + 2); i++){
			for(int j = auxCol; j <= (auxCol + 2); j++){
				numbers[grid[i][j]]++;		
			}
		}

		for(int i = 1; i <= 9; i++){
			if(finallySolved)
				return;
			if(numbers[i] == 0){
				grid[row][col] = i;
				solveSudoku(grid, index + 1, solution);
			}
			grid[row][col] = 0;
		}
	}else{
		solveSudoku(grid, index + 1, solution);
	}
}

int main(){
	string sudokuId, rowSudoku;
	long long int answer = 0;
	cout << "Enter an Id for this sudoku: " << endl;
	while(getline(cin, sudokuId)){
		vector<int> column(9,0);
		vector<vector<int> > grid(9, column);
		vector<vector<int> > solution(9, column);

		for(int i = 0; i < 9; i++){
			getline(cin, rowSudoku);
			for(int j = 0; j < rowSudoku.size(); j++){
				grid[i][j] = rowSudoku[j] - '0';
			}
		}

		finallySolved = false;
		solveSudoku(grid, 1, solution);

		cout << sudokuId << endl;

		for(int i = 0; i < 9; i++){
			for(int j = 0; j < 9; j++){
				cout << solution[i][j] << " ";
			}
			cout << endl;
		}

		cout << "Enter an Id for this sudoku: " << endl;

	}

	


	return 0; 
}