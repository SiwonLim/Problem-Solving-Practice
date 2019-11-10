#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool cmp(pair<int, int> a, pair<int, int> b) {
	if (a.second == b.second) return a.first < b.first;
	return a.second < b.second;
}
int main() {
	int n,cnt=0,endM=0;
	cin >> n;
	vector<pair<int, int>> v;
	while (n--) {
		int a, b;
		cin >> a >> b;
		v.push_back({ a,b });
	}
	sort(v.begin(), v.end(),cmp);
	for (vector<pair<int, int>>::iterator it = v.begin(); it != v.end(); it++) {
		//이전 회의가 이번에 끝나는지
		if (endM <= it->first) {
			endM = it->second;
			cnt++;
		}
	}
	cout << cnt << endl;
	return 0;
}
