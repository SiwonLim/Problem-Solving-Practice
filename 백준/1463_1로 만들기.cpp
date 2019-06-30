#include <iostream>
#include <algorithm>
using namespace std;

long long c;
int memo[1000001];//�޸������̼�

int main()
{
	int N;
	cin >> N;
	
	//bottom-up
	/*
	N%3==0 then N/=3 -> D[N] = D[N/3]+1
	N%2==0 then N/=2 -> D[N] = D[N/2]+1
	N-- -> D[N] = D[N-1]+1
	*/
	memo[1] = 0;//1�϶��� �����̹Ƿ� Ƚ��X
	for (int i = 2; i <= N; i++)
	{
		memo[i] = memo[i - 1] + 1;
		if (i % 3 == 0)
			memo[i] = min(memo[i],memo[i / 3] + 1);//1���Ѱ��� ������ i/3+1���� ������
		if (i % 2 == 0)
			memo[i] = min(memo[i], memo[i / 2] + 1);//1���Ѱ��� ������ i/2+1���� ������
	}
	cout << memo[N] << endl;
	return 0;
}
