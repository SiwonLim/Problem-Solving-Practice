#include <iostream>
#include <limits.h>
#include <algorithm>
using namespace std;
int novel[501];
int subset[501];
int d[501][501];
int main() {
	int T, K;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d", &K);
		for (int i = 1; i <= K; i++){
			scanf("%d", &novel[i]);
			subset[i] = novel[i] + subset[i - 1];
		}
		for (int i = 1; i < K; i++){
			for (int j = 1; i + j <= K; j++){
				int q = i + j;
				d[j][q] = INT_MAX;
				for (int mid = j; mid < q; mid++){
					d[j][q] = min(d[j][q], 
						d[j][mid] + d[mid + 1][q] + subset[q] - subset[j - 1]);
				}
			}
		}
		printf("%d\n", d[1][K]);
	}
	return 0;
}