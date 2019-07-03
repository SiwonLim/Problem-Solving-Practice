#include <iostream>
#include <list>
using namespace std;
int memo[12];

int main()
{
	long long T;
	list<int> v;
	cin >> T;
	while (T--)
	{
		int t;
		cin >> t;
		v.push_back(t);
	}

	memo[1] = 1;
	memo[2] = 2;
	memo[3] = 4;

	while (!v.empty())
	{
		for (int i = 4; i <= v.front(); i++)
		{
			memo[i] = memo[i - 1] + memo[i - 2] + memo[i - 3];
		}
		cout << memo[v.front()] << endl;
		v.pop_front();
	}

	return 0;
}