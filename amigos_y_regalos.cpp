//LINK to the Problem:
//https://omegaup.com/arena/problem/Amigos-y-Regalos#problems
//Problem type: Greedy

#include<iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);

	int cantNumA, cantNumB, primoA, primoB, respuesta = 0;
	cin >> cantNumA >> cantNumB >> primoA >> primoB;

	int cantNecesaria = cantNumA + cantNumB;
	int num_faltantes = cantNecesaria;

	if(primoA == primoB){
		while(num_faltantes != 0){
			respuesta += num_faltantes;
			num_faltantes = cantNecesaria - (respuesta - (respuesta / primoA));
		}
	}else{
		while(num_faltantes != 0){
			respuesta += num_faltantes;

			int disponibles = respuesta - (respuesta / (primoA * primoB));
			int usar_A = disponibles - ((respuesta / primoA) - respuesta / (primoA * primoB));
			int usar_B = disponibles - ((respuesta / primoB) - respuesta / (primoA * primoB));
			int usar_ambos = usar_A - ((respuesta / primoB) - respuesta / (primoA * primoB));

			usar_A -= usar_ambos;
			usar_B -= usar_ambos;

			int cuantos_faltan_A = cantNumA - usar_A;
			int cuantos_faltan_B = cantNumB - usar_B;

			if(cuantos_faltan_A < 0)
				cuantos_faltan_A = 0;

			if(cuantos_faltan_B < 0)
				cuantos_faltan_B = 0;

			num_faltantes = cuantos_faltan_A + cuantos_faltan_B - usar_ambos;
		}
	}

	cout << respuesta << "\n";
	return 0;
}

