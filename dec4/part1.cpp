#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

bool is_valid(istream &input)
{
	vector<string> word;
	string w;
	string line;
	getline(input,line);
	istringstream is(line);

	while(is >> w)
	{
		word.push_back(w);
	}

	int N = word.size();
	for (int i{0}; i < N-1; i++)
	{
		for (int j{i+1}; j < N; j++ )
		{
			if ( word[i] == word[j] )
			{
				return false;
			}
		}
	}

	return true;
}

int main(int argc, char *argv[])
{
	int n{0};

	ifstream input("data.txt");

	while(!input.eof())
	{
		if (is_valid(input))
		{
			n++;
		}
	}

	cout << "the answer is " << n << endl;	
	return 0;
}