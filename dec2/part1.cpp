#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

int main(int argc, char *argv[])
{
	int sum{0};
	string line;
	int n;
	int mn, mx;

	ifstream input("data.txt");

	while(!input.eof())
	{
		getline(input,line);
		istringstream is(line);
		is >> mn;
		mx = mn;
		while(is >> n)
		{
			if (n<mn)
			{
				mn = n;
			}
			if (n>mx)
			{
				mx = n;
			}
		}
		cout << mn << " ";
		cout << mx << endl;
		sum += mx-mn;
	}

	cout << "the answer is " << sum << endl;	
	return 0;
}