#include <iostream>
using namespace std;

long long c;
int memo[1001];//�޸������̼�

int main()
{
	int n;
	cin >> n;

	memo[1] = 1;
	for (int i = 2; i <= (n+1); i++)
		memo[i] = (memo[i - 1] + memo[i - 2])%10007;
	cout << memo[(n+1)] << endl;//1���� ���������Ƿ�
	return 0;
}
