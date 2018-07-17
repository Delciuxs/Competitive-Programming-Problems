//LINK to the Problem:
//https://omegaup.com/arena/problem/8Reinas#problems
//Problem type: BackTracking

#include<iostream>
#include<map>
#include<set>
#include<vector>
using namespace std;

vector<pair<int, int> > soluciones; 
bool encontre = false;

void Reinas(set<int> filas, set<int> columnas, map<pair<int, int>, bool> casillas, int filaA, int colA, vector<pair<int, int> > temporal)
{
	int i, j;
	if(encontre)
		return;

	filas.erase(filaA);
	columnas.erase(colA);

	if((filas.size() == 0) && (columnas.size() == 0))
	{
		temporal.push_back(make_pair(filaA, colA));
		soluciones = temporal;
		encontre = true;
		return;
	}

	if((filaA != 10) )
	{
		if((colA != 10))
		{
			temporal.push_back(make_pair(filaA, colA));

			i = filaA;
			j = colA;

			while(true)
			{
				if(i >= 8 || j >= 8)
					break;

				if(casillas.count(make_pair(i,j)) == 0)
					casillas[make_pair(i,j)] = true;		

				i++;
				j++;		
			}

			i = filaA;
			j = colA;

			while(true)
			{
				if(i < 0 || j < 0)
					break;

				if(casillas.count(make_pair(i,j)) == 0)
					casillas[make_pair(i,j)] = true;		

				i--;
				j--;		
			}

			i = filaA;
			j = colA;

			while(true)
			{
				if(i >= 8 || j < 0)
					break;

				if(casillas.count(make_pair(i,j)) == 0)
					casillas[make_pair(i,j)] = true;		

				i++;
				j--;		
			}

			i = filaA;
			j = colA;

			while(true)
			{
				if(i < 0 || j >= 8)
					break;

				if(casillas.count(make_pair(i,j)) == 0)
					casillas[make_pair(i,j)] = true;		

				i--;
				j++;		
			}
		}
		
	}

	for(auto &x : columnas)
		for(auto & y : filas)
			if(casillas.count(make_pair(y, x)) == 0)
				Reinas(filas, columnas, casillas, y, x, temporal);
}

int main()
{
	int num_reinas, f, c, i, j;

	cin >> num_reinas;

	set<int> filas;
	set<int> columnas;

	for(int s = 0; s <= 7; s++)
	{
		filas.insert(s);
		columnas.insert(s);
	}

	filas.insert(10);
	columnas.insert(10);

	map<pair<int, int>, bool> casillas;
	vector<pair<int, int> > tempo;

	for(int s = 0; s < num_reinas; s++)
	{
		cin >> f >> c;

		f = f - 1;
		c = c - 1;
		tempo.push_back(make_pair(f, c));

		if(filas.count(f) == 1)
			filas.erase(f);
		if(columnas.count(c) == 1)
			columnas.erase(c);
		i = f;
		j = c;

		while(true)
		{
			if(i >= 8 || j >= 8)
				break;

			if(casillas.count(make_pair(i,j)) == 0)
				casillas[make_pair(i,j)] = true;		
			i++;
			j++;		
		}

		i = f;
		j = c;

		while(true)
		{
			if(i < 0 || j < 0)
				break;
			if(casillas.count(make_pair(i,j)) == 0)
				casillas[make_pair(i,j)] = true;		

			i--;
			j--;		
		}

		i = f;
		j = c;
		while(true)
		{
			if(i >= 8 || j < 0)
				break;
			if(casillas.count(make_pair(i,j)) == 0)
				casillas[make_pair(i,j)] = true;		

			i++;
			j--;		
		}

		i = f;
		j = c;

		while(true)
		{
			if(i < 0 || j >= 8)
				break;
			if(casillas.count(make_pair(i,j)) == 0)
				casillas[make_pair(i,j)] = true;		

			i--;
			j++;		
		}
	}

	Reinas(filas, columnas, casillas, 10, 10, tempo);		

	if(soluciones.size() == 8)
	{
		for(int s = 0; s < soluciones.size(); s++)
			cout << soluciones[s].first + 1 << " " << soluciones[s].second + 1<< "\n";	
	}

	else
			cout << "0" << "\n";
	
	return 0;
}