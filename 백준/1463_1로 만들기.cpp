#include <iostream>
#include <algorithm>
using namespace std;

long long c;
int memo[1000001];//메모이제이션

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
	memo[1] = 0;//1일때는 정답이므로 횟수X
	for (int i = 2; i <= N; i++)
	{
		memo[i] = memo[i - 1] + 1;
		if (i % 3 == 0)
			memo[i] = min(memo[i],memo[i / 3] + 1);//1더한값이 작은지 i/3+1값이 작은지
		if (i % 2 == 0)
			memo[i] = min(memo[i], memo[i / 2] + 1);//1더한값이 작은지 i/2+1값이 작은지
	}
	cout << memo[N] << endl;
	return 0;
}
