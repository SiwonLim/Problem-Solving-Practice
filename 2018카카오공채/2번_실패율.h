#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(pair<double, int> a, pair<double, int> b)
{
	if (a.first == b.first)//�������� ������
		return a.second < b.second;//�������� ��ȣ�� ������ ����

	return a.first > b.first;//�������� ū�� ����
}
vector<int> solution(int N, vector<int> stages)
{
	vector<pair<double, int>> v;
	vector<int> answer;
	int total = stages.size();
	int users[501] = { 0 };
	for (vector<int>::iterator it = stages.begin(); it != stages.end(); it++)
		users[*it - 1]++;//�������� ��������

	for (int i = 0; i < N; i++)
	{
		if (users[i] == 0)
			v.push_back(make_pair(0, i + 1));
		else
		{
			double fail = (double)users[i] / total;
			v.push_back(make_pair(fail, i + 1));
			total -= users[i];
		}
	}
	sort(v.begin(), v.end(), cmp);
	for (vector<pair<double, int>>::iterator it = v.begin(); it != v.end(); it++)
		answer.push_back(it->second);

	return answer;
}