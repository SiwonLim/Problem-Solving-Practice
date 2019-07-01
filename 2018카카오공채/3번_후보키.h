#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int countBits(int n)
{
	int ret = 0;
	while (n)
	{
		if (n & 1) ret++;
		n = n >> 1;
	}
	return ret;
}

bool cmp(int a, int b)
{
	//���� ��Ʈ�� ī��Ʈ
	int x = countBits(a), y = countBits(b);
	return x > y;//�������� ����
}

bool check(vector<vector<string>> relation, int low, int col, int subset)
{
	for (int i = 0; i < low - 1; i++)
	{
		for (int j = i + 1; j < low; j++)
		{
			bool isSame = true;
			for (int k = 0; k < col; k++)
			{
				if ((subset & 1 << k) == 0) continue;//ex) k�� 1, (0010 & 0001)�� �̶��, �˻��Ϸ��� Attrit�� �ƴϴ�
				if (relation[i][k] != relation[j][k])//col ���ٿ� �ߺ����� �ִ��� Ȯ��
				{
					//���ϼ� ����, �ּҼ��� �����ϹǷ�
					isSame = false;
					break;
				}
			}

			if (isSame)
			{
				return false;
			}
		}
	}
	return true;
}

int solution(vector<vector<string>> relation)
{
	int answer = 0;
	vector<int> candidates;//�ĺ�Ű
	int low = relation.size();
	int col = relation.front().size();

	//�÷���, �ĺ�Ű ã�´�
	for (int i = 1; i <= (1 << col); i++)//
	{
		if (check(relation, low, col, i))
			candidates.push_back(i);
	}
	sort(candidates.begin(), candidates.end(), cmp);
	while (!candidates.empty())
	{
		int n = candidates.back();//1�� ������ ���� ����������
		candidates.pop_back();
		answer++;

		//���ϼ� üũ
		for (vector<int>::iterator it = candidates.begin(); it != candidates.end(); )
		{
			if ((n & *it) == n)
				it = candidates.erase(it);
			else it++;
		}
	}
	return answer;
}
