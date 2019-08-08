#include <iostream>
#include <cstring>
using namespace std;
int d[501][501];
int map[501][501];
int dir[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };
int M, N;
int descent(int x, int y)
{
	if (x == M && y == N) return 1;
	if (d[x][y] == -1){
		d[x][y] = 0;
		for (int i = 0; i < 4; i++){
			int nx = x + dir[i][0];
			int ny = y + dir[i][1];
			if (nx >= 1 && nx <= M && ny >= 1 && ny <= N)
				if (map[x][y] > map[nx][ny]) d[x][y] += descent(nx, ny);
		}
	}
	return d[x][y];
}

int main() {
	cin >> M >> N; //M :세로, N :가로
	for (int i = 1; i <= M ; i++) for (int j = 1; j <= N ; j++) cin >> map[i][j];
	memset(d,-1,sizeof(d));
	cout << descent(1, 1) << endl;
	return 0;
}