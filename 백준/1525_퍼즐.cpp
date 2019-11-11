#include <iostream>
#include <map>
#include <queue>
#include <algorithm>
#include <string>
#define WH 3
#define MAX 9
using namespace std;
int dir[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };
string TARGET = "123456789";
int main() {
	int p[WH][WH];
	string chk;
	for (int i = 0; i < WH; i++) {
		for (int j = 0; j < WH; j++) {
			cin >> p[i][j];
			if (p[i][j] == 0) p[i][j] = 9;
			chk += to_string(p[i][j]);
		}
	}
	queue<string> q;
	map<string, int> visited;
	q.push(chk);
	visited[chk] = 0;
	while (!q.empty()) {
		string curChk = q.front();
		q.pop();
		if (curChk == TARGET) break;
		else {
			int empty = curChk.find('9');//9위치 찾음
			int x = empty/3, y = empty%3;
			for (int i = 0; i < 4; i++) {//상하좌우 움직일수 있는곳 찾음
				int nx = x + dir[i][0], ny = y + dir[i][1];
				if (nx >= 0 && nx < WH && ny >= 0 && ny < WH) {
					//9와의 위치와 스왑
					string temp = curChk;
					swap(temp[x*3+y], temp[nx*3+ny]);
					//map에 이미 temp가 있는지 확인, 없으면 큐에 추가
					if (!visited.count(temp)) {
						visited[temp] = visited[curChk] + 1;
						q.push(temp);
					}
				}
			}
		}
	}
	if (!visited.count(TARGET)) cout << -1 << endl;
	else cout << visited[TARGET] << endl;
	return 0;
}
