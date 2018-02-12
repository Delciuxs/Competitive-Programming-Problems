//LINK to the Problem:
//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=657&page=show_problem&problem=3836
//Problem type: Greedy

#include<iostream>
using namespace std;

int main()
{
	int t, n;
	string field;

	cin >> t;

	for(int i = 0; i < t; i++)
	{
		int num_scarecrows = 0;
		int j = 0;

		cin >> n;
		cin >> field;

		while(j < n)
		{
			if(field[j] == '#')
				j++;
			else
			{
				num_scarecrows++;
				j += 3;
			}
		}

		cout << "Case " << i + 1 << ": " << num_scarecrows << endl;

	}

	return 0;
}