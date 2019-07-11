#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int d[1001];

int main()
{
	vector<int> A;
	int N, t, answer = 0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> t;
		A.push_back(t);
	}
	for (int i = 0; i < N; i++)
	{
		d[i] = 1;
		for (int j = 0; j < i; j++)
			if (A[j] > A[i])
				d[i] = max(d[i], d[j] + 1);
		answer = max(answer, d[i]);
	}
	cout << answer << endl;
	return 0;
}