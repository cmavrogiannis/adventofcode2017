#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

void get_list(ifstream &file, vector<int> &list)
{
	int a;

	while(file >> a)
	{
		list.push_back(a);
	}
}

int reach_extraction(vector<int> &list)
{

	// state variable
	int x{0};

	// size of list of offsets
	int N = list.size();

	// counter
	int i{0};
	while (x <= N-1)
	{
		
		x += list[x]++;
		i++;

	}

	return i;
}

int main(int argc, char *argv[])
{

	vector<int> list;
	ifstream file("data.txt");
	get_list(file,list);
	int N = list.size();

	int n = reach_extraction(list);
	cout << "Reached extraction in " << n << " steps." << endl;	
	return 0;
}