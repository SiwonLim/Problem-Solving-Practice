#include <iostream>
using namespace std;
int board[2001];
int d[2001][2001];

int main() {
	int N, M;
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) scanf("%d", &board[i]);
	
	for (int i = 1; i <= N; i++) d[i][i] = 1;//길이가 0
	for (int i = 1; i <= N - 1; i++)//길이가 1
		if (board[i] == board[i + 1]) d[i][i + 1] = 1;
	for (int i = 3; i <= N + 1; i++)//길이가 2이상{
		for (int j = 1; j <= N - i + 1; j++)
		{
			int isPelin = i + j - 1;
			if (isPelin > N) continue;
			if (board[j] == board[isPelin] && d[j + 1][isPelin - 1])
				d[j][isPelin] = 1;
		}
	}
	scanf("%d", &M);
	while (M--) {
		int S, E;
		scanf("%d %d", &S, &E);
		printf("%d\n", d[S][E]);
	}
	return 0;
}