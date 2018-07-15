//LINK to the Problem:
//https://omegaup.com/arena/problem/moscas#problems
//Problem type: Greedy

#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

int main()
{
	int num_flies, aux;

	cin >> num_flies;

	vector<pair<int, char> > time;

	for(int i = 0; i < num_flies; i++)
	{
		cin >> aux;
		time.push_back(make_pair(aux, 'l'));//LIVE

		cin >> aux;
		time.push_back(make_pair(aux, 'd'));//DEAD
	}
	
	sort(time.begin(), time.end());
	
	map<int, int> living_flies;
	int flies = 0, max_flies = -1;

	for(int i = 0; i < time.size(); i++)
	{	
		if(time[i].second == 'l')
		{
			flies++;
			if(living_flies.count(time[i].first) == 0)
				living_flies[time[i].first] = flies;

			else
				living_flies[time[i].first] = flies;

		}
		else
		{
			flies--;
			if(living_flies.count(time[i].first) == 0)
				living_flies[time[i].first] = flies;

			else
				living_flies[time[i].first] = flies;
		}

		max_flies = max(flies, max_flies);
	}

	cout << max_flies << "\n";

	auto it = living_flies.cbegin();

	while(it != living_flies.cend())
	{
    	if(it->second == max_flies)
    	{
    		cout << it->first << " ";

    		while(it->second == max_flies)
    			it++;
    		cout << it->first << "\n";
    		
    	}
    	else
    		it++;
	}

	return 0;
}