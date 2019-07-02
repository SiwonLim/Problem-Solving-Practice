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
		foods.push_back(make_pair(food_times.at(i), i + 1));//몇번째음식,초

	sort(foods.begin(), foods.end());

	int pretime = 0;
	for (vector<pair<int, int>>::iterator it = foods.begin(); it != foods.end(); it++, size--)
	{
		//먹는데 걸릴 소요시간을 먼저 구한다
		long long spend = (long long)(it->first - pretime)*size;

		if (spend == 0) continue;//pretime과 it->first가 같다면(즉, 이전과 시간이 같다면)
		if (spend <= k)
		{
			k -= spend;
			pretime = it->first;
		}
		else
		{
			k %= size;//나머지를 구한다
			sort(it, foods.end(), cmp);
			return (it + k)->second;
		}
	}
	return -1;
}