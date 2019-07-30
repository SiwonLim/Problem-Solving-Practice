#include <iostream>
using namespace std;
int d[41][2] = { {1,0},{0,1} };
int main()
{
	int T;
	cin >> T;
	while (T--){
		int N;
		cin >> N;
		for (int i = 2; i <= N; i++){
			d[i][0] = d[i - 1][0] + d[i - 2][0];
			d[i][1] = d[i - 1][1] + d[i - 2][1];
		}
		cout << d[N][0] << ' ' << d[N][1] << '\n';
	}
	return 0;
}