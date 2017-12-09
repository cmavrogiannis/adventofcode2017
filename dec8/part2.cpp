#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>

using namespace std;

typedef map<string,int>::value_type element;
typedef map<string,int>::iterator registerIterator;

void print_register(map<string,int> reg)
{
	for (auto it = reg.begin(); it != reg.end(); it++)
	{
		cout << it->first << " " << it->second << endl;
	}
}

bool check_condition(int lhs, string symbol, int rhs)
{

	if (lhs > rhs)
	{
		if (symbol == ">" || symbol == "!=" || symbol == ">=")
		{
			return true;
		}
	}
	else if(lhs < rhs)
	{
		if (symbol == "<" || symbol == "!=" || symbol == "<=")
		{
			return true;
		}
	}
	else
	{
		if (symbol == "<=" || symbol == ">=" || symbol == "==")
		{
			return true;
		}
	}

	return false;
}

void parse_instruction(string line, map<string,int> &reg, int &MAX)
{

	vector<string> iss;
	string s;
	istringstream broken_string(line);
	while(broken_string >> s)
	{
		iss.push_back(s);
	}
	string name = iss[0];

	// check if there is an entry for this element already
	// otherwise initialize a new entry
	registerIterator i1 = reg.find(name);
	if (i1 == reg.end())
	{
		// element not found, initialize entry in the map
		element new_element1(name,0);
		reg.insert(new_element1);
	}


	int operation = stoi(iss[2]);
	if (iss[1] == "dec")
	{
		operation = -operation;
	}

	registerIterator p = reg.find(iss[4]);
	if (p == reg.end())
	{
		// element not found, initialize entry in the map
		element new_element2(iss[4],0);
		reg.insert(new_element2);
	}

	// check condition
	if (check_condition(reg[iss[4]],iss[5],stoi(iss[6])))
	{
		reg[name] += operation;
	}

	// compare with global MAX
	if (reg[name] > MAX)
	{
		MAX = reg[name];
	}

}



int main(int argc, char *argv[])
{

	map<string,int> reg;

	ifstream file("data.txt");
	
	string line;
	int MAX{0};
	while(!file.eof())
	{
		getline(file,line);
		parse_instruction(line, reg, MAX);
		line.clear();
	}

	int mx{0};
	for (auto it = reg.begin(); it != reg.end(); ++it)
	{
		if (it->second > mx)
		{
			mx = it->second;
			cout << mx << endl;
		}
	}

	print_register(reg);

	cout << "the largest value in the register throughout the whole process was: " << MAX << endl;
	return 0;
}

