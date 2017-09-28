//LINK to the Problem:
//http://codeforces.com/problemset/problem/474/B
//Problem type: Binary_Search

#include<iostream>
#include<vector>
using namespace std;

int Binary_Search(vector<int long> &set, long int element, long int left_boundary, long int right_bounday)
{
	int cont = 0;
	int middle;

	while(cont < 50)
	{	
		middle = (left_boundary + right_bounday) / 2;
		if(element == set[middle])
			break;
		else if(element > set[middle])
			left_boundary = middle;
		else if (element < set[middle])
			right_bounday = middle;
		cont++;
	}
	return middle;
}

int main()
{
	long int numer_piles, numer_worms, numer_juicy_worms, id_juicy_worms, pile;
	int j, sum = 0;
	vector<long int> worms;

	cin >> numer_piles;
	
	worms.push_back(1);//add numer 1 for default
	
	cin >> numer_worms;
	worms.push_back(numer_worms);//add just the first input 

	j = 1;
	sum = numer_worms;
	//add the remain inputs, with the problem logic described
	for(int i = 0; i < numer_piles - 1; i++)
	{
		worms.push_back(worms[j] + 1);
		cin >> numer_worms;
		sum += numer_worms;
		worms.push_back(sum);
		j += 2;
	}

	cin >> numer_juicy_worms;
	for(int i = 0; i < numer_juicy_worms; i++)
	{
		cin >> id_juicy_worms;
		pile = (Binary_Search(worms, id_juicy_worms, 0, worms.size() - 1) + 2 ) / 2;
		cout << pile << endl;
	}

	return 0;
}