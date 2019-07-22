#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int d[10001];
int main() {
	vector<int> v = {0};
	int N,answer=0;
	cin >> N;
	for (int i = 0, t = 0 ; i < N; i++){
		cin >> t;
		v.push_back(t);
	}
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= i; j++)
			d[i] = max(d[i], d[i - j] + v[j]);
	cout << d[N] << endl;
	return 0;
}