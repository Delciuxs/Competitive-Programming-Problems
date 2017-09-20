//LINK to the Problem:
//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1415

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


int Binary_Search(vector<int> &set, int element, int left_boundary, int right_boundary)
{
	int middle;
	int position = -1;
	int cont = 0;
	while(cont < 40)
	{
		middle = (left_boundary + right_boundary) / 2;
		if(element == set[middle])
		{
			position = middle;
			right_boundary = middle - 1;
		}
	
		else
		{
			if(element < set[middle])
				right_boundary = middle - 1;
			else if(element > set[middle])
				left_boundary = middle + 1;
		}
		cont++;
	}

	return position;
}

int main()
{
	int N, Q, num_case = 1; 	

	cin >> N >> Q;

	while(N != 0 && Q != 0)
	{
		vector<int> numbers;
		vector<int> elements_to_search;
		int search_this, number, position;

		for(int i = 0; i < N; i++)
		{
			cin >> number;
			numbers.push_back(number);
		}

		sort(numbers.begin(), numbers.end());

		for(int i = 0; i < Q; i++)
		{
			cin >> search_this;
			elements_to_search.push_back(search_this);
		}
		

		cout << "CASE# " << num_case << ":" << endl;

		for(int i = 0; i < elements_to_search.size(); i++)
		{
			position = Binary_Search(numbers, elements_to_search[i], 0, numbers.size()-1);
			
			if(position == -1)				
				cout << elements_to_search[i] << " not found" << endl;
			else
				cout << elements_to_search[i] << " found at " << position + 1<< endl;
		}
		
		num_case++;
		cin >> N >> Q;

	}

	return  0;
}
