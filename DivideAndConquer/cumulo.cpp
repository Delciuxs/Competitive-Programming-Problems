//LINK to the Problem:
//https://omegaup.com/arena/problem/Cumulo#problems
//Problem type: Divide And Conquer

#include<bits/stdc++.h>
using namespace std;

struct coord{
	double X, Y;
};
typedef struct coord coord;

bool ordenaCoorX(coord &a, coord &b){
	return a.X < b.X;
}
bool ordenaCoorY(coord &a, coord &b){
	return a.Y < b.Y;
}

double minimaEntreLados(vector<coord> &puntos_medios, double rango_minimo){
	double minima = rango_minimo;
	sort(puntos_medios.begin(), puntos_medios.end(), ordenaCoorY);

	for(int i = 0; i < puntos_medios.size(); i++){
		for(int j = i + 1; (j < puntos_medios.size()) && (puntos_medios[j].Y - puntos_medios[i].Y < minima); j++){
			if(hypot(puntos_medios[j].X - puntos_medios[i].X, puntos_medios[j].Y - puntos_medios[i].Y) < minima)
				minima = hypot(puntos_medios[j].X - puntos_medios[i].X, puntos_medios[j].Y - puntos_medios[i].Y);
		}
	}
	return minima;
}

double minimaDistancia(vector<coord> &puntos, int lim_izq, int lim_der){
	if(lim_izq == lim_der)
		return DBL_MAX;
	if(lim_der - lim_izq == 1)
		return hypot((puntos[lim_der].X - puntos[lim_izq].X), (puntos[lim_der].Y - puntos[lim_izq].Y));

	int mitad = (lim_izq + lim_der) / 2;
	coord punto_medio = puntos[mitad];

	double min_izq = minimaDistancia(puntos, lim_izq, mitad);
	double min_der = minimaDistancia(puntos, mitad + 1, lim_der);

	double min_ambos = min(min_izq, min_der);

	vector<coord> puntos_medios;

	for(int k = lim_izq; k <= lim_der; k++){
		if(abs(puntos[k].X - punto_medio.X) < min_ambos)
			puntos_medios.push_back(puntos[k]);
	}
	return min(min_ambos, minimaEntreLados(puntos_medios, min_ambos));
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);	
	cout.tie(0);

	int num_estrellas;
	cin >> num_estrellas;

	vector<coord> puntos(num_estrellas);
	coord coordenada_aux;

	for(int i = 0; i < num_estrellas; i++){
		cin >> coordenada_aux.X >> coordenada_aux.Y;
		puntos[i] = coordenada_aux;
	}
	sort(puntos.begin(), puntos.end(), ordenaCoorX);
	double res = minimaDistancia(puntos, 0, puntos.size() - 1);
	cout << setprecision(3) << fixed << res << "\n";
	return 0;
}