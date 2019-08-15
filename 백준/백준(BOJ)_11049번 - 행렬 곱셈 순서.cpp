#include <iostream>
using namespace std;
int mat[501][2];
int dp[501][501];
int matrix(int x, int y)
{
	if (dp[x][y]) return dp[x][y];
	if (x == y) return 0;
	if (x + 1 == y) return mat[x][0] * mat[x][1] * mat[y][1];
	int &ret = dp[x][y];
	ret = -1;
	for (int i = x; i < y; i++)
	{
		int t1 = matrix(x, i);
		int t2 = matrix(i + 1, y);
		if (ret == -1 || ret > t1 + t2 + mat[x][0] * mat[i][1] * mat[y][1])
			ret = t1 + t2 + mat[x][0] * mat[i][1] * mat[y][1];
	}
	return ret;
}
int main() {
	int N, r, c;
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> r >> c, mat[i][0] = r, mat[i][1] = c;
	cout << matrix(0, N - 1) << endl;
	return 0;
}