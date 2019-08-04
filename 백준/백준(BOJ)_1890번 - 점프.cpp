#include <iostream>
using namespace std;
long long board[101][101];
long long d[101][101];
int main() {
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> board[i][j];
	
	d[0][0] = 1;
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			int jump = board[i][j];
			if (i != N-1 && i + jump < N)
				d[i + jump][j] += d[i][j];
			if (j != N-1 && j + jump < N)
				d[i][j + jump] += d[i][j];
		}
	}
	cout << d[N - 1][N - 1] << endl;
	return 0;
}