//LINK to the Problem:
//https://omegaup.com/arena/problem/Noticias#problems
//Problem type: Union Find Disjoint Sets

#include<bits/stdc++.h>

using namespace std;

struct person
{
	int common_friend;
	int num_people_reached;
	int rank;
};

typedef person person;

vector<person> people;


int find_common_friend(int f)
{
	if(people[f].common_friend != f)
		people[f].common_friend = find_common_friend(people[f].common_friend);

	return people[f].common_friend;
}

void meet_this_people(int a, int b)
{	
	int common_friend_A, common_friend_B;

	common_friend_A = find_common_friend(a);
	common_friend_B = find_common_friend(b);

	if(common_friend_A == common_friend_B)
		return;

	if(people[common_friend_A].rank > people[common_friend_B].rank)
	{
		people[common_friend_B].common_friend = common_friend_A;
		people[common_friend_A].num_people_reached += people[common_friend_B].num_people_reached;
	}

	else
	{
		people[common_friend_A].common_friend = common_friend_B;
		people[common_friend_B].num_people_reached += people[common_friend_A].num_people_reached;

		if(people[common_friend_A].rank == people[common_friend_B].rank)
			people[common_friend_B].rank = people[common_friend_B].rank + 1;
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);	

	int num_people, num_instructions, a, b, reach_from_this, super_person;
	char type_instruction;

	cin >> num_people >> num_instructions;

	people.resize(num_people + 1);

	for(int j = 0; j < people.size(); j++)
	{
		people[j].common_friend = j;
		people[j].num_people_reached = 1;
		people[j].rank = 0;
	}

	for(int i = 0; i < num_instructions; i++)
	{
		cin >> type_instruction;

		if(type_instruction == 'A')
		{
			cin >> a >> b;
			meet_this_people(a, b);
		}

		else
		{
			cin >> reach_from_this;

			super_person = find_common_friend(reach_from_this);

			cout << people[super_person].num_people_reached << "\n";
		}
	}


	return 0;
}
