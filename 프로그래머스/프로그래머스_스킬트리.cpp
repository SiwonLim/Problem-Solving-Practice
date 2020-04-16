#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;
map<char, int> m;

int solution(string skill, vector<string> skill_trees) {
	int answer = 0;
	int s1 = skill.length(), s2 = skill_trees.size();
	for (int i = 0; i < s1; i++) {
		m.insert({skill[i],i+1});
	}
	for (int i = 0; i < s2; i++) {
		string str = skill_trees[i];
		string dummy = "";
		bool notMatch = false;
		vector<int> check;
		for (int j = 0; j < str.length(); j++) {
			if(m[str[j]] != 0)
				check.push_back(m[str[j]]);
		}
		
		for (int j = 1; j < check.size(); j++) {
			if (check[j-1] > check[j]) {
				notMatch = true;
				break;
			}
		}
		if (!check.empty() && check.back() != check.size()) notMatch = true;
		if (!notMatch) answer++;
	}
	return answer;
}
