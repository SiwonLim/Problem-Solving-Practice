#include <iostream>
#include <vector>
#include <algorithm>
#define INF 1e9//1000000000
#define MAX 11
using namespace std;
bool visited[MAX];
int weight[MAX][MAX];//가중치
int startNode, n, ans = INF;
void dfs(int node, int added, int cnt) {
	if (cnt == n-1) {
		if (weight[node][startNode]) {
			ans = min(ans, added + weight[node][startNode]);
			return;
		}
	}
	for (int i = 0; i < n; i++) {//아직 마지막 지점까지 도달X
		if (weight[node][i] && !visited[i]) {
			visited[i] = true;
			dfs(i, added + weight[node][i], cnt + 1);
			visited[i] = false;
		}
	}
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> weight[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		startNode = i;
		visited[i] = true;
		dfs(i,0,0);//시작점
		visited[i] = false;
	}
	cout << ans << endl;
	return 0;
}
