#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

void print_program_dependencies(vector<vector<string>> programs)
{
	int N = programs.size();
	for (int i{0}; i < N; i++)
	{
		int n = programs[i].size();
		for (int j{0}; j < n; j++)
		{
			cout << programs[i][j];
			if (n > 1)
			{
				if (j == 0)
				{
					cout << " -> ";			
				}
				else if (j < n-1)
				{
					cout << ", ";
				}			
			}
		}
		cout << endl;	
	}
}

vector<string> parse_line(string line)
{

	int len = line.size();
	bool word_in_progress{false};
	string word;
	char c;
	vector<string> dependents;
	for (int i{0}; i < len; i++)
	{
		c = line[i];

		if (isalpha(c))
		{
			word += c;
			if (!word_in_progress)
			{
				word_in_progress = true;
			}
		}			

		if ((c == ',' || c == ' ') && word_in_progress)
		{
			dependents.push_back(word);
			word.clear();
			word_in_progress = false;
		}
	}
	if (word_in_progress)
	{
		dependents.push_back(word);
	}
	return dependents;
}


vector<vector<string>> get_dependencies(ifstream &file)
{
	vector<vector<string>> list;

	string line;
	while (!file.eof())
	{
		getline(file,line);
		list.push_back(parse_line(line));
	}

	return list;
}


int main(int argc, char *argv[])
{

	ifstream file("data.txt");
	vector<vector<string>> program_dependencies;
	string child;

	program_dependencies = get_dependencies(file);

	//print_program_dependencies(program_dependencies);

	int N = program_dependencies.size();
	int m;
	bool root_found{false};
	int child_ID = 0;
	string root;
	bool parent_found;
	while (!root_found)
	{
		parent_found = false;
		child = program_dependencies[child_ID][0];
		for (int j{0}; j < N; j++)
		{
			m = program_dependencies[j].size();	
			if (child_ID != j && m > 1)
			{
				for (int k{1}; k < m; k++)
				{
					if (child == program_dependencies[j][k])
					{
						child_ID = j;
						parent_found = true;
						break;
					}				
				}
			} 	
		}
		if (! parent_found)
		{
			root_found = true;
			root = child;
		}
		child.clear();
	}

	cout << "the root program is " << root << endl;
	return 0;
}

