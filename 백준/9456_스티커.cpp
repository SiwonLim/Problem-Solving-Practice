#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int memo[2][100001];

int main()
{
	int T, N;
	cin >> T;

	while (T--) {
		cin >> N;
		vector<vector<int>> v(2, vector<int>(N, 0));
		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < N; j++)
			{
				int test;
				cin >> test;
				v[i][j] = test;
			}
		}

		for (int i = 0; i < N; i++){
			if (i == 0)
				for (int j = 0; j < 2; j++) memo[j][i] = v[j][i];
			else if (i == 1)
				for (int j = 0; j < 2; j++) memo[j][i] = v[j][i] + memo[j ^ 1][i - 1];
			else
			{
				for (int j = 0; j < 2; j++)
					memo[j][i] = max(v[j][i] + memo[j ^ 1][i - 1], v[j][i] + memo[j ^ 1][i - 2]);
			}
		}
		cout << max(memo[0][N - 1], memo[1][N - 1]) << endl;
	}
	return 0;
}