//LINK to the Problem:
//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3638
//Problem type: Union Find Disjoint Sets

#include<iostream>
#include<vector>

using namespace std;

struct student
{
	int header_group;
	int reachable_students;
	int rank;
};

typedef student student;

vector<student> students;

int find_header_group(int st)
{
	if(students[st].header_group != st)
		students[st].header_group = find_header_group(students[st].header_group);
	return students[st].header_group;
}

void join(int stA, int stB)
{
	int header_stA, header_stB;

	header_stA = find_header_group(stA);	
	header_stB = find_header_group(stB);

	if(header_stA == header_stB)
		return;

	if(students[header_stA].rank > students[header_stB].rank)
	{
		students[header_stB].header_group = header_stA;
		students[header_stA].reachable_students += students[header_stB].reachable_students;
	}

	else
	{
		students[header_stA].header_group = header_stB;
		students[header_stB].reachable_students += students[header_stA].reachable_students;

		if(students[header_stA].rank == students[header_stB].rank)
			students[header_stB].rank = students[header_stB].rank + 1;
	}
}


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int num_students, num_groups;

	cin >> num_students >> num_groups;

	while(num_students + num_groups != 0)
	{
		int studentA = 0, studentB = 0, num_members_group = 0;
		students.resize(num_students);

		for(int s = 0; s < num_students; s++)
		{
			students[s].header_group = s;
			students[s].reachable_students = 1;
			students[s].rank = 0;
		}

		for(int i = 0; i < num_groups; i++)
		{
			cin >> num_members_group;

			cin >> studentA;

			if(num_members_group == 1)
				continue;

			for(int j = 1; j < num_members_group; j++)
			{
				cin >> studentB;

				join(studentA, studentB);
			}
		}

		cout << students[find_header_group(0)].reachable_students << endl;

		cin >> num_students >> num_groups;
	}

	


	return 0;
}
