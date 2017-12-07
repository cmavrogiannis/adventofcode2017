#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char *argv[])
{
	string code;
	int j;
	int sum{0};
	char *temp = new char[2];

	ifstream input("data.txt");
	input >> code;
	int len = code.size();
	cout << "the length of the code string is " << len << endl;

	for (int i{0}; i < len; i++)
	{
		j = (i+1)%len;
		cout << j-i << endl;

		if (code[i] == code[j])
		{
			temp[0] = code[i];
			temp[1] = '\0';
			sum += atoi(temp);
		}
	}
	cout << "the answer is " << sum << endl;	
	return 0;
}