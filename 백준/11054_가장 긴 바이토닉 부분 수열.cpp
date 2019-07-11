#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int d[1001],d2[1001];
int main()
{
	vector<int> A;
	int N, t, answer = 0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> t;
		A.push_back(t);
		d[i] =  1;
	}
	for (int i = 0 ; i < N ; i++){
		for (int j = 0; j < i; j++)
			if (A[j] < A[i]) d[i] = max(d[i], d[j] + 1);
		answer = max(answer, d[i]);
	}
	for (int i = N-1; i >=0; i--) {
		for (int j = N-1; j > i; j--)
			if (A[j] < A[i]) d2[i] = max(d2[i], d2[j] + 1);
		answer = max(answer, d[i]+d2[i]);
	}
	cout << answer << endl;
	return 0;
}