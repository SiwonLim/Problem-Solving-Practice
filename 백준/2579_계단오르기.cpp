#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int d[301];
int main()
{
	int n, answer = 0;
	vector<int> v;
	cin >> n;
	for (int i = 0, t = 0; i < n; i++){
		cin >> t;
		v.push_back(t);
	}
	d[0] = v[0];
	for (int i = 1; i < n; i++)
		d[i] = max(v[i] + v[i - 1] + d[i - 3], v[i] + d[i - 2]);
	cout << d[n-1] << endl;
	return 0;
}