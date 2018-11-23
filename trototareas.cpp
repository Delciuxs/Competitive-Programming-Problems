//LINK to the Problem:
//https://omegaup.com/arena/problem/trototareas#problems
//Problem type: Dynamic Programming

#include <bits/stdc++.h>
using namespace std;


int min_tiempo(int posicion, int puntos_req, vector<int> &puntos, vector<int> &tiempos, vector<vector<int> > &memo)
{	
	int aux1 = 0, aux2 = 0;
	
	if(puntos_req <= 0)
		return 0;

	else if(posicion == puntos.size())
		return (1<<30);
	else if(memo[posicion][puntos_req] == -1){
		aux1 = min_tiempo(posicion + 1, puntos_req - puntos[posicion], puntos, tiempos, memo) + tiempos[posicion];
		aux2 = min_tiempo(posicion + 1, puntos_req, puntos, tiempos, memo);

		memo[posicion][puntos_req] = min(aux1, aux2);
	}
	return memo[posicion][puntos_req];
}


int main (){

	int num_tareas, min_puntos;

	cin >> num_tareas >> min_puntos;

	vector<int> puntos_tarea(num_tareas);
	vector<int> tiempo_tarea(num_tareas);

	for(int i = 0; i < num_tareas; i++){	
		cin >> puntos_tarea[i];
		cin >> tiempo_tarea[i];
	}
		
	vector<int> columnas(1005,-1);
	vector<vector<int> > memoria(num_tareas + 5, columnas);

	cout << min_tiempo(0, min_puntos, puntos_tarea, tiempo_tarea, memoria) << endl;
	return 0;
}