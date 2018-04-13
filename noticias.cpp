//LINK to the Problem:
//https://omegaup.com/arena/problem/Noticias#problems
//Problem type: Union Find Disjoint Sets

#include<bits/stdc++.h>

using namespace std;

struct person
{
	int commond_friend;
	int num_people_reached;
	int rank;
};

typedef person person;

vector<person> people;


int find_commond_friend(int f)
{
	if(people[f].commond_friend != f)
		people[f].commond_friend = find_commond_friend(people[f].commond_friend);

	return people[f].commond_friend;
}

void meet_this_people(int a, int b)
{	
	int commond_friend_A, commond_friend_B;

	commond_friend_A = find_commond_friend(a);
	commond_friend_B = find_commond_friend(b);

	if(commond_friend_A == commond_friend_B)
		return;

	if(people[commond_friend_A].rank > people[commond_friend_B].rank)
	{
		people[commond_friend_B].commond_friend = commond_friend_A;
		people[commond_friend_A].num_people_reached += people[commond_friend_B].num_people_reached;
	}

	else
	{
		people[commond_friend_A].commond_friend = commond_friend_B;
		people[commond_friend_B].num_people_reached += people[commond_friend_A].num_people_reached;

		if(people[commond_friend_A].rank == people[commond_friend_B].rank)
			people[commond_friend_B].rank = people[commond_friend_B].rank + 1;
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
		people[j].commond_friend = j;
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

			super_person = find_commond_friend(reach_from_this);

			cout << people[super_person].num_people_reached << "\n";
		}
	}


	return 0;
}