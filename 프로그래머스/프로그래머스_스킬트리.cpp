#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;
map<char, int> m;
vector<int> origin;

int solution(string skill, vector<string> skill_trees) {
	int answer = 0;
	int s1 = skill.length(), s2 = skill_trees.size();
	for (int i = 0; i < s1; i++) {
		m.insert({ skill[i],i + 1 });
		origin.push_back(i + 1);
	}

	for (int i = 0; i < s2; i++) {
		string str = skill_trees[i];
		bool check = true;
		vector<int> tmp;
		for (int j = 0; j < str.length(); j++) {
			if (m[str[j]] != 0)
				tmp.push_back(m[str[j]]);
		}

		for (int j = 0; j < tmp.size(); j++) {
			if (origin[j] != tmp[j]) {
				check = false;
				break;
			}
		}
		if (check) answer++;
	}
	return answer;
}
