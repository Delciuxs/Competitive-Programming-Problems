//LINK to the Problem:
//https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=812
//Problem type: BFS

#include<iostream>
#include<vector>
using namespace std;

int dimension_horizontal, dimension_vertical;
int cuantos_encontre;

int movimientos[8][2] = {
						//x, y
						{0,1},
						{0,-1},
						{1,0},
						{-1,0},
						{1,1},
						{1,-1},
						{-1, -1},
						{-1, 1},
};

void DFS(int y, int x, vector<vector<int> > &visitados, vector<vector<int> > &matriz)
{
	if(y >= dimension_vertical || x >= dimension_horizontal || y < 0 || x < 0)
		return;

	if(matriz[y][x] == 1 && visitados[y][x] == -1)
	{
		cuantos_encontre++;
		visitados[y][x] = 1;

		for(int i = 0; i < 8; i++)
			DFS(y + movimientos[i][1], x + movimientos[i][0], visitados, matriz);
			
	}
}

int main()
{

	int t;
	string linea_blanca, fila, test_case;

	getline(cin, test_case);
	getline(cin, linea_blanca);

	t = stoi(test_case);

	for(int i = 0; i < t; i++)
	{	
		int maximos_encontrado = 0;

		vector<string> filas;

		getline(cin, fila);

		dimension_horizontal = fila.size();

		while(fila.size() != 0)
		{
			filas.push_back(fila);

			getline(cin, fila);
		}

		dimension_vertical = filas.size();

		vector<int> horizontal(dimension_horizontal);
		vector<vector<int> > matriz(dimension_vertical, horizontal);

		vector<int> horizontal_2(dimension_horizontal, -1);
		vector<vector<int> > visitados(dimension_vertical, horizontal_2);

		for(int i = 0; i < dimension_vertical; i++)
			for(int j = 0; j < dimension_horizontal; j++)
			{
				if(filas[i][j] == '1')
					matriz[i][j] = 1;
				else
					matriz[i][j] = 0;
				
			}


		for(int i = 0; i < dimension_vertical; i++)
			for(int j = 0; j < dimension_horizontal; j++)
			{
				if(visitados[i][j] == -1)
				{
					cuantos_encontre = 0;
					DFS(i , j, visitados, matriz);
					maximos_encontrado = max(cuantos_encontre, maximos_encontrado);
				}
			}

		if(i != 0)
			cout << "\n" << endl;

		cout << maximos_encontrado;

		if(i == t - 1)
			cout << "\n";
		
	}
	return 0; 

}