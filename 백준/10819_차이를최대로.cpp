#include <iostream>
#include <algorithm>
#include <deque>
#include <cmath>
using namespace std;
int main() {
	int n, m = 0;
	cin >> n;
	deque<int> arr(n);
	for (int i = 0; i < n; i++) cin >> arr[i];
	//모든 순열 구하기
	for (int i = 0; i < n; i++) {
		int curMax = 0;
		deque<int> temp(n);
		copy(arr.begin(), arr.end(), temp.begin());

		while (next_permutation(temp.begin(), temp.end())) {
			for (int k = 1; k < n; k++) curMax += abs(temp[k] - temp[k - 1]);
			m = max(curMax, m);
			curMax = 0;
		}
		arr.push_front(arr.back());
		arr.pop_back();
	}
	cout << m << endl;
	return 0;
}
