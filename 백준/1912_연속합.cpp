#include <iostream>
using namespace std;
int d[100001];
int main() {
	int n;
	cin >> n;
	for (int i = 0, t = 0; i < n; i++) {
		cin >> t;
		d[i] = t;
	}
	int answer = d[0];
	for (int i = 0; i < n; i++) {
		d[i] = (d[i] < d[i] + d[i - 1]) ? d[i] + d[i - 1] : d[i];
	}
	for (int i = 0; i < n; i++) answer = (answer < d[i]) ? d[i] : answer;
	cout << answer << endl;
	return 0;
}