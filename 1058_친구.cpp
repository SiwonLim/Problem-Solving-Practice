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
			else if (str[i][j] == 'Y') f_2[i][j] = 1;//����ģ��
			else f_2[i][j] = 9999;
		}
	}
	//�ٸ��ǳ� ģ��
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < N; k++)
			{
				//�������� ���� ���ϰ� i==j�� ���ߴ��� ��X
				if (i == j || j == k || i == k) continue;
				else if (f_2[j][k] > f_2[i][j] + f_2[i][k])
				{
					f_2[j][k] = f_2[i][j] + f_2[i][k];
				}
			}
		}
	}
	//���� ������ ����� ã�´�
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