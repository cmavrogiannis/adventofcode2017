#include <iostream>
#include <fstream>
using namespace std;

int get_layer_ID(int in)
{

	int n = 1;
	int ID{1};
	while( in > n*n )
	{
		n += 2;
		ID++;
	}

	return ID;
}


int main(int argc, char *argv[])
{

	int in;
	int ID;
	int side;
	int shortest;

	ifstream input("data.txt");
	input >> in;

	cout << "The input number is " << in << endl;

	// find the layer ID
	ID = get_layer_ID(in);

	// get size of side 
	side = 2*ID - 1;

	cout << "the layer ID is " << ID << endl;	
	cout << "the size of the side of that layer is " << side << endl;	

	// find shortest path elements at that layer
	int mn{4*(side-1)};
	for (int i{0}; i < 4; i++)
	{
		shortest = abs( in - ((side - 2)*(side - 2) + (ID-1) + i*(side-1)));
		if (shortest < mn)
		{
			mn = shortest;
		}
	}
	cout << "the shortest distance within the layer is " << mn << endl;

	cout << "the shortest path length is " << mn + (ID-1) << endl;

	return 0;
}

