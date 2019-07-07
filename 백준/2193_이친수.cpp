#include <iostream>
using namespace std;
long long memo[100];
int main()
{
	int N;
	cin >> N;
	memo[0] = memo[1] = 1;

	for (int i = 2; i < N; i++)
		memo[i] = memo[i - 1] + memo[i - 2];
	
	cout << memo[N-1] << endl;
	return 0;
}