#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(pair<double, int> a, pair<double, int> b)
{
	if (a.first == b.first)//실패율이 같으면
		return a.second < b.second;//스테이지 번호가 작은게 먼저

	return a.first > b.first;//실패율이 큰게 먼저
}
vector<int> solution(int N, vector<int> stages)
{
	vector<pair<double, int>> v;
	vector<int> answer;
	int total = stages.size();
	int users[501] = { 0 };
	for (vector<int>::iterator it = stages.begin(); it != stages.end(); it++)
		users[*it - 1]++;//진행중인 스테이지

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