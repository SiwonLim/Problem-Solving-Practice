#include <iostream>
#include <vector>
using namespace std;
int main()
{
	int N;
	cin >> N;
	vector<vector<int>> memo(N, vector<int>(10, 0));
	memo[0] = {0,1,1,1,1,1,1,1,1,1};//N이 1일경우
	for (int n = 1; n < N ; n++)
	{
		for (int i = 0; i < 10; i++)
		{
			if (i == 0)
				memo[n][i] = memo[n - 1][1];
			else if (i == 9)
				memo[n][i] = memo[n - 1][8];
			else
				memo[n][i] = memo[n - 1][i - 1] + memo[n - 1][i + 1];
			memo[n][i] %= 1000000000;
		}
	}

	int sum = 0;
	for (int j = 0; j < 10; j++)
	{
		sum += memo[N - 1][j];
		sum %= 1000000000;
	}
	cout <<  sum << endl;
	return 0;
}