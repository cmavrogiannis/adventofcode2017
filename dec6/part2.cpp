#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

void reallocate(vector<int> &list)
{

	int N = list.size();
	int max_ID{0};
	int max = list[0];

	// get bank with most blocks
	for (int i{0}; i < N; i++)
	{
		if (max < list[i])
		{
			max = list[i];
			max_ID = i;
		}
	}

	// remove banks from that memory location
	list[max_ID] = 0;
	int k;
	for (int j{max_ID+1}; j < max_ID + max + 1; j++)
	{

		k = (j < N) ? j : j%N;
		list[k]++;

	}
}

void print_memory(vector<int> list)
{
	int N = list.size();
	for (int i{0}; i < N; i++)
	{
		cout << list[i] << " ";
	}
	cout << endl;
}

vector<int> get_memory(ifstream &file)
{
	vector<int> list;

	int a;
	while (file >> a)
	{
		list.push_back(a);
	}

	return list;
}

bool check_if_seen(vector<vector<int>> state)
{
	int N = state.size();
	int M = state[0].size();

	int k;
	for (int i{0}; i < N-1; i++)
	{
		k = 0;
		for (int j{0}; j < M; j++)
		{
			if (state[N-1][j]-state[i][j] == 0)
			{
				k++;
				if (k == M)
				{
					return true;
				}
			}
		}
	}
	return false;
}

bool check_if_seen(vector<vector<int>> state, int seen_state_ID)
{
	int N = state.size();
	int M = state[0].size();

	int k{0};
	for (int j{0}; j < M; j++)
	{
		if (state[seen_state_ID][j]-state[N-1][j] == 0)
		{
			k++;
			if (k == M)
			{
				return true;
			}
		}
	}
	return false;
}

int main(int argc, char *argv[])
{

	ifstream file("data.txt");
	vector<int> list;
	list = get_memory(file);

	print_memory(list);

	vector<vector<int>> state;;
	state.push_back(list);

	int k{0};
	int times_seen{0};
	int seen_state_ID = -1;
	while(true)
	{
		reallocate(list);

		k++;

		state.push_back(list);

		if (times_seen == 0)
		{
			if (check_if_seen(state))
			{
				times_seen++;
				k = 0;
				seen_state_ID = state.size()-1;
			}
		}
		else
		{
			if (check_if_seen(state, seen_state_ID))
			{
				break;
			}
		}

	}
	

	cout << "Reached same configuration after " << k << " steps." << endl;	
	return 0;
}

