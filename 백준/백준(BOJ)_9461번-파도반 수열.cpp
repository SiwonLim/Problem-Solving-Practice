#include <iostream>
using namespace std;
long long d[101] = {1,1,1,2,2,3,4,5,7,9};
int main()
{
	int t;
	cin >> t;
	while (t--){
		int n;
		cin >> n;
		for (int i = 10; i < n; i++)
			d[i] = d[i - 2] + d[i - 3];
		cout << d[n-1] << endl;
	}
	
	return 0;
}