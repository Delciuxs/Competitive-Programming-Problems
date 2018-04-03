//LINK to the Problem:
//http://coj.uci.cu/24h/problem.xhtml?pid=3577
//Problem type: Meet in the middle

#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int main()
{
	int num_soups, num_main_dishes, num_desserts, num_beravages;
	long long int num_lunches, lunch_price_limit, search, quantity;

	cin >> lunch_price_limit >> num_soups >> num_main_dishes >> num_desserts >> num_beravages;

	while(lunch_price_limit + num_soups + num_main_dishes + num_desserts + num_beravages != 0)
	{
		num_lunches = 0;

		vector<long int> prices_soups(num_soups);
		vector<long int> prices_main_dishes(num_main_dishes);
		vector<long int> prices_desserts(num_desserts);
		vector<long int> prices_beravages(num_beravages);

		unordered_map<long long int, int> aux;

		for(int i = 0; i < num_soups; i++)
			cin >> prices_soups[i];
		for(int i = 0; i < num_main_dishes; i++)
			cin >> prices_main_dishes[i];
		for(int i = 0; i < num_desserts; i++)
			cin >> prices_desserts[i];
		for(int i = 0; i < num_beravages; i++)
			cin >> prices_beravages[i];


		for(int i = 0; i < prices_soups.size(); i++)
			for(int j = 0; j < prices_main_dishes.size(); j++)
			{
				quantity = lunch_price_limit - (prices_soups[i] + prices_main_dishes[j]);
				if(quantity >= 0)
					aux[quantity]++;				
			}

		for(int i = 0; i < prices_desserts.size(); i++)
			for(int j = 0; j < prices_beravages.size(); j++)
			{
				search = prices_desserts[i] + prices_beravages[j];
				for(auto x : aux)
				{
					if(x.first >= search)
					{
						num_lunches += aux[x.first];
					}
				}
			}

		cout << num_lunches << endl;

		cin >> lunch_price_limit >> num_soups >> num_main_dishes >> num_desserts >> num_beravages;
	}


	return 0;
}