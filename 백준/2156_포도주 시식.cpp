#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int memo[10001];
int main()
{
	int n, t;
	cin >> n;
	vector<int> v;
	for (int i = 0 ; i < n; i++) {
		cin >> t;
		v.push_back(t);
		if (i == 0) memo[i] = t;
		else if (i == 1) memo[i] = t + memo[0];
	}
	
	for (int i = 2; i < n; i++)
		memo[i] = max(max(memo[i - 2] + v[i], memo[i - 3] + v[i - 1] + v[i]), memo[i-1]);
	
	cout << memo[n-1] << endl;
	return 0;
}