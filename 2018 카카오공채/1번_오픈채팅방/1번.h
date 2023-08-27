#pragma once
#include <vector>
#include <string>
#include <map>
#include <sstream>
using namespace std;
vector<string> solution(vector<string> record) {
	vector<string> answer;
	map<string, string> idname;
	string stat, id, name;


	for (vector<string>::iterator it = record.begin(); it != record.end(); it++)
	{
		stringstream ss;
		ss.str(*it);
		ss >> stat;
		if (stat.compare("Enter") == 0 || stat.compare("Change") == 0)
		{
			ss >> id >> name;
			idname[id] = name;
		}
	}

	for (vector<string>::iterator it = record.begin(); it != record.end(); it++)
	{
		stringstream ss;
		ss.str(*it);
		ss >> stat;
		if (stat.compare("Enter") == 0)
		{
			ss >> id;
			answer.push_back(idname[id] + "님이 들어왔습니다.");
		}
		else if (stat.compare("Leave") == 0)
		{
			ss >> id;
			answer.push_back(idname[id] + "님이 나갔습니다.");
		}
	}
	return answer;
}