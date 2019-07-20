#include <iostream>
using namespace std;
long long d[201][201];
int main()
{
	int N, K;
	cin >> N >> K;
	for (int i = 1; i <= K; i++) d[0][i] = 1;

	for (int i = 1 ; i <= N; i++){
		for (int j = 1 ; j <= K; j++)
			d[i][j] = (d[i - 1][j] + d[i][j - 1])%1000000000;
	}
	cout << d[N][K] << endl;
	return 0;
}