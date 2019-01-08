//LINK to the Problem:
//https://omegaup.com/arena/problem/ride#problems
//Problem type: Modular Arithmetic

/*
For the solution of this problem I use property:
(x*y mod n) = ((x mod n) * (y mod n)) mod n 
*/

#include<iostream>
using namespace std;

int main()
{
	string comet, group;
	cin >> comet >> group;
	int result  = 1, result2 = 1;

	for(int i = 0; i < comet.size(); i++)
	{
		result = result * (comet[i] - 'A' + 1 )%47;
		result = result%47;
	}

	for(int i = 0; i < group.size(); i++)
	{
		result2 = result2 * (group[i] - 'A' + 1)%47;
		result2 = result2%47;
	}

	if(result == result2)
		cout << "GO" << endl;
	else
		cout << "STAY" << endl;
	return 0;
}
