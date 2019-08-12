#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int T, K;
int file[501];
int s[501];
int d[501][501];
int merge(int i, int j)
{
	if (i == j) return 0;
	int &ret = d[i][j];
	if (ret == -1){
		for (int k = i; k <= j - 1; k++){
			int temp = merge(i, k) + merge(k + 1, j) + s[j] - s[i - 1];
			if (ret == -1 || ret > temp) ret = temp;
		}
	}
	return ret;
}
int main() {
	cin >> T;
	while (T--){
		cin >> K;
		memset(d, -1, sizeof(d));
		for (int i = 1; i <= K; i++){
			cin >> file[i];
			s[i] = file[i] + s[i - 1];
		}
		cout << merge(1, K) << endl;
	}
	return 0;
}