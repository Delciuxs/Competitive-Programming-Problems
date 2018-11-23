//LINK to the Problem:
//http://codeforces.com/problemset/problem/770/C
//Problem type: Graphs

#include<iostream>
#include<unordered_set>
#include<vector>

using namespace std;

vector<int> solution;


bool search_cycle(int id_course, vector<int> &colors, vector<vector<int> > &courses)
{
	colors[id_course] = 0; //painting gray;

	for(int k = 0; k < courses[id_course].size(); k++)//searching adjacency
	{
		if(colors[courses[id_course][k]] == 0)//is gray an adjacency node, there is a cycle
			return true;

		//is white an adyacency node and the search_cycle for that node return a cycle, return true
		if(colors[courses[id_course][k]] == -1)
			if(search_cycle(courses[id_course][k], colors, courses))
				return true;	
	}

	//After searching all their adjacency node we did not find a cycle, return false
	colors[id_course] = 1; //painting black
	return false;
}

bool has_cycle(vector<int> &main_courses, vector<int> &colors, vector<vector<int> > &courses)
{
	for(int i = 0; i < main_courses.size(); i++)
	{
		if(colors[main_courses[i]] == -1)
		{
			if(search_cycle(main_courses[i], colors, courses))
				return true;			
		}
	}

	return false;
}

void how_to_pass(int num_curse, vector<vector<int> > &courses, unordered_set<int> &visited)
{
	visited.insert(num_curse);

	for(int s = 0; s < courses[num_curse].size(); s++)
	{
		if(visited.count(courses[num_curse][s]) == 0)
		{
			how_to_pass(courses[num_curse][s], courses, visited);
		}
	}

	solution.push_back(num_curse);
}

int main()
{
	int num_online_courses, num_main_courses, num_courses_to_be_done, course;
	
	cin >> num_online_courses >> num_main_courses;

	vector<int> main_courses(num_main_courses);

	vector<int> needed_be_done;
	vector<vector<int> > courses(num_online_courses + 1, needed_be_done);

	for(int i = 0; i < num_main_courses; i++)
	{
		cin >> main_courses[i];
	}

	for(int i = 0; i < num_online_courses; i++)
	{
		cin >> num_courses_to_be_done;

		for(int j = 0; j < num_courses_to_be_done; j++)
		{
			cin >> course;
			courses[i + 1].push_back(course);
		}

	}

	vector<int> color_courses(num_online_courses + 1, -1); // painting them white
	unordered_set<int> visited;

	if(has_cycle(main_courses, color_courses, courses))
		cout << "-1" << endl;

	else
	{
		for(int i = 0; i < main_courses.size(); i++)
		{
			if(visited.count(main_courses[i]) == 0)
				how_to_pass(main_courses[i], courses, visited);			
		}

		cout << solution.size() << endl;

		for(int i = 0; i < solution.size(); i++)
			cout << solution[i] << " ";
	}

	


	return 0;
}