#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int memo[1001];

int main()
{
	vector<int> A;
	int N, t, answer = 0;
	cin >> N;
	for(int i = 0 ; i < N ; i++){
		cin >> t;
		A.push_back(t);
	}
	
	for (int i = 0 ; i < N; i++)
	{
		memo[i] = 1;
		for (int j = 0; j < i; j++){
			if (A[j] < A[i])
				memo[i] = max(memo[i], memo[j] + 1);
		}
		answer = max(answer, memo[i]);
	}
	cout << answer << endl;
	return 0;
}