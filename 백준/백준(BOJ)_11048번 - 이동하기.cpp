#include <iostream>
#include <algorithm>
using namespace std;
int d[1001][1001];
int maze[1001][1001];
int main(){
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> maze[i][j];
	
	for (int i = 0; i < N; i++){
		for (int j = 0; j < M; j++){
			d[i][j] = maze[i][j] + max(d[i-1][j-1],max(d[i-1][j],d[i][j-1]));
		}
	}
	cout << d[N-1][M-1] << endl;
	return 0;
}