#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
	vector<int> answer;
	vector<pair<int, int>> jobs(speeds.size());
	for (int i = 0; i < speeds.size(); i++)
		jobs[i] = { progresses[i],speeds[i] };
	while (!jobs.empty())
	{
		pair<int, int> t = jobs.front();
		if (t.first >= 100)//맨 앞 진도가 100%라면
		{
			int idx = 0;
			while (idx < jobs.size() && jobs[idx].first >= 100)//빠져나가는 갯수를 체크
				idx++;
			answer.push_back(idx);
			jobs.erase(jobs.begin(), jobs.begin() + idx);//범위 삭제
		}
		else
		{
			for (int i = 0; i < jobs.size(); i++)
				if(jobs[i].first < 100)
					jobs[i].first += jobs[i].second;
		}
	}
	return answer;
}