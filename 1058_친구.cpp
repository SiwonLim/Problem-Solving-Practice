#include <iostream>
#include <vector>
#include <string>
#include<algorithm>
using namespace std;

int f_2[51][51];

int findMostFamous(vector<string>& str, int N)
{
	int answer = 0;
	for (int i = 0; i < str.size(); i++) {
		for (int j = 0; j < str[i].size(); j++) {
			if (i == j) f_2[i][j] = 0;
			else if (str[i][j] == 'Y') f_2[i][j] = 1;//서로친구
			else f_2[i][j] = 9999;
		}
	}
	//다리건너 친구
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < N; k++)
			{
				//이조건을 생각 못하고 i==j만 비교했더니 답X
				if (i == j || j == k || i == k) continue;
				else if (f_2[j][k] > f_2[i][j] + f_2[i][k])
				{
					f_2[j][k] = f_2[i][j] + f_2[i][k];
				}
			}
		}
	}
	//가장 유명한 사람을 찾는다
	for (int i = 0; i < N; i++) {
		int sum = 0;
		for (int j = 0; j < N; j++)
		{
			if (i == j) continue;
			else if (f_2[i][j] <= 2) sum++;
		}
		answer = max(answer, sum);
	}
	return answer;
}
int main()
{
	int N;
	vector<string> str;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		string t;
		cin >> t;
		str.push_back(t);
	}
	cout << findMostFamous(str, N) << endl;

	return 0;
}