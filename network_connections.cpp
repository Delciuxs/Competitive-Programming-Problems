//LINK to the Problem:
//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=734
//Problem type: Union Find Disjoint Sets

#include<iostream>
#include<string>
#include<sstream>
#include<vector>
using namespace std;

struct comp
{
	int mainC;
	int rank;
};

typedef comp comp;

vector<comp> computers;

int find_main_computer(int c)
{
	if(computers[c].mainC != c)
		computers[c].mainC = find_main_computer(computers[c].mainC);
	return computers[c].mainC;
}

bool are_they_connected(int c1, int c2)
{
	return find_main_computer(c1) == find_main_computer(c2);
}

void join_computers(int co1, int co2)
{
	int main_comp1, main_comp2;

	main_comp1 = find_main_computer(co1);
	main_comp2 = find_main_computer(co2);

	if(main_comp1 == main_comp2)
		return;

	if(computers[main_comp1].rank > computers[main_comp2].rank)
		computers[main_comp2].mainC = main_comp1;
	
	else
	{
		computers[main_comp1].mainC = main_comp2;
		if(computers[main_comp1].rank == computers[main_comp2].rank)
		{

			computers[main_comp2].rank = computers[main_comp2].rank + 1;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);	

	int t, num_computers;
	string linea_blanca, cadena, test_case, num_comput;

	getline(cin, test_case);
	getline(cin, linea_blanca);

	t = stoi(test_case);

	for(int i = 0; i < t; i++)
	{
		int success = 0, unsuccess = 0;
		getline(cin,num_comput);
		getline(cin, cadena);

		num_computers = stoi(num_comput);
		computers.resize(num_computers + 1);

		for(int j = 0; j < computers.size(); j++)
		{
			computers[j].mainC = j;
			computers[j].rank = 0;
		}

		while(cadena.size() != 0)
		{
			stringstream ss(cadena);

			char type;
			int computer1, computer2;

			ss >> type;
			ss >> computer1;
			ss >> computer2;

			
			if(type == 'c')
				join_computers(computer1, computer2);

			else
			{
				if(are_they_connected(computer1, computer2))
					success++;
		
				else
					unsuccess++;
			}

			getline(cin, cadena);

		}

		if(i == t - 1)
			cout << success << "," << unsuccess << "\n";
		else
			cout << success << "," << unsuccess << "\n\n";
		

	}

	

	return 0;
}