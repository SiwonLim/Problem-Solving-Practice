#include <vector>
#include <algorithm>
using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b)
{
	return b.second > a.second;
}
int solution(vector<int> food_times, long long k)
{
	vector<pair<int, int>> foods;
	int size = food_times.size();

	for (int i = 0; i < size; i++)
		foods.push_back(make_pair(food_times.at(i), i + 1));//���°����,��

	sort(foods.begin(), foods.end());

	int pretime = 0;
	for (vector<pair<int, int>>::iterator it = foods.begin(); it != foods.end(); it++, size--)
	{
		//�Դµ� �ɸ� �ҿ�ð��� ���� ���Ѵ�
		long long spend = (long long)(it->first - pretime)*size;

		if (spend == 0) continue;//pretime�� it->first�� ���ٸ�(��, ������ �ð��� ���ٸ�)
		if (spend <= k)
		{
			k -= spend;
			pretime = it->first;
		}
		else
		{
			k %= size;//�������� ���Ѵ�
			sort(it, foods.end(), cmp);
			return (it + k)->second;
		}
	}
	return -1;
}