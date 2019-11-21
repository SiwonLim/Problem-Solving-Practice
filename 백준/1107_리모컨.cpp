#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#define INF 987654321
#define MAX 1000001//수빈이가 이동하려는 채널
using namespace std;
int n, m;
vector<int> broken;

//가려는 채널이 532일때 5,3,2버튼 중 하나라도 망가졌는지 확인
//하나라도 망가짐 : false
bool possi(int channel) {
	string c = to_string(channel);
	int size = c.size();
	for (int i = 0; i < size; i++) {
		if (find(broken.begin(), broken.end(), c[i] - '0') != broken.end())
			return false;
	}
	return true;
}

//100에서 채널 누르고 +/-
int changeChannelWithBtn() {
	int ret = INF;
	int find = 0;
	for (int i = 0; i < MAX; i++) {
		if (possi(i)) {//해당 채널을 누를 수 있다면
			int pushCnt = abs(n - i);
			if (ret > pushCnt) {
				ret = pushCnt;
				find = i;
			}
		}
	}
	return ret + to_string(find).size();
}

int main() {
	int cnt = 0, channel = 100;
	cin >> n >> m;
	for (int i = 0, idx = 0; i < m; i++)
		cin >> idx, broken.push_back(idx);
	//1. 기존채널에서 +,-
	//2. 버튼눌러 채널 입력 후 +,-
	cout << min(abs(n-100), changeChannelWithBtn()) << endl;
	return 0;
}
