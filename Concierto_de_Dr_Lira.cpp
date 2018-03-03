//LINK to the Problem:
//https://omegaup.com/arena/problem/Concierto-de-Dr-Lira#problems
//Problem type: Dynamic Programming

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int max_volume_final_song(int actual_volume, int max_volume, int position, vector<int> &changes_volume, vector<vector<int> > &memory)
{
	int sum1 = 0, sum2 = 0;

	if(actual_volume < 0)
		return -1;

	else if(actual_volume > max_volume)
		return -1;
	

	else if(position == changes_volume.size())
	{
		memory[actual_volume][position] = actual_volume;
		return actual_volume;
	}

	else if(memory[actual_volume][position] == -1000000)
	{

		sum1 = max_volume_final_song(actual_volume - changes_volume[position], max_volume, position + 1, changes_volume, memory);
		sum2 = max_volume_final_song(actual_volume + changes_volume[position], max_volume, position + 1, changes_volume, memory);
		memory[actual_volume][position] = max(sum1, sum2);	
	}

	return memory[actual_volume][position];
}

int main()
{
	int n, start_volume, top_volume;

	cin >> n;

	vector<int> songs(n);

	for(int i = 0; i < n; i++)
		cin >> songs[i];

	cin >> start_volume >> top_volume;

	vector<int> columns(60,-1000000);
	vector<vector<int> > memo(top_volume + 5, columns);

	cout << max_volume_final_song(start_volume, top_volume, 0, songs, memo);
	return 0;
}