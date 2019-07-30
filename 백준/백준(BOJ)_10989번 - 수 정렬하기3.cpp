#include <iostream>
#define MAX 10001
using namespace std;
int cSum[MAX];
int main()
{
	int N;
	cin >> N;
	for (int i = 0; i < N; i++){
		int index = 0;
		scanf("%d", &index);
		cSum[index]++;
	}
	for (int i = 1; i < MAX; i++){
		for (int j = 0; j < cSum[i]; j++)
			printf("%d\n", i);
	}
	return 0;
}