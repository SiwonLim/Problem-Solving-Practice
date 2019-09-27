#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> heights) {
	vector<pair<int, int>> top(heights.size());
	vector<int> answer;
	for (int i = 0; i < heights.size(); i++)
		top[i] = {i+1,heights[i]};
	while (!top.empty())
	{
		bool b = false;
		pair<int, int> t = top.back();
		for (int i = top.size() - 1; i >= 0; i--)
		{
			if (top[i] != t && t.second < top[i].second)
			{
				answer.insert(answer.begin(),top[i].first);
				b = true;
				break;
			}
		}
		if (!b) answer.insert(answer.begin(), 0);
		top.pop_back();
	}
	return answer;
}