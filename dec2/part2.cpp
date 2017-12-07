#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

int main(int argc, char *argv[])
{
	int sum{0};
	string line;
	int n;
	int N;
	int mn, mx;
	vector<int> A;
	vector<int>::iterator iter;
	bool leave{false};


	ifstream input("data.txt");

	while(!input.eof())
	{
		getline(input,line);
		istringstream is(line);
		leave = false;

		while(is >> n)
		{
			A.push_back(n);
		}
		N = A.size();

		for (int i{0}; i < N-1; i++)
		{
			for (int j{i+1}; j < N; j++)
			{
				if (A[i]%A[j] == 0)
				{
					cout << A[i] << " " << A[j] << endl;
					sum += A[i]/A[j];
					leave = true;
				}
				if (A[j]%A[i] == 0)
				{
					cout << A[j] << " " << A[i] << endl;
					sum += A[j]/A[i];
					leave = true;
				}	
				if (leave == true)
				{
					break;
				}
			}
			if (leave == true)
			{
				break;
			}		
		}

		A.clear();
	}

	cout << "the answer is " << sum << endl;	
	return 0;
}