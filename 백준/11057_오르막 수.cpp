#include <iostream>
#include <vector>
using namespace std;
int main()
{
	int N;
	cin >> N;
	vector<vector<long long>> memo(N, vector<long long>(10, 0));
	memo[0] = {1,1,1,1,1,1,1,1,1,1};
	for (int n = 1; n < N; n++){
		for (int i = 0; i < 10; i++){
			if (i == 9){
				memo[n][9] = 1;
			}
			else{
				long long temp = 0;
				for (int k = i; k < 10; k++)
					temp += memo[n - 1][k];
				memo[n][i] = temp%10007;
			}
		}
	}
	int sum = 0;
	for (int i = 0; i < 10; i++) sum += memo[N - 1][i];
	cout << sum%10007 << endl;
	return 0;
}