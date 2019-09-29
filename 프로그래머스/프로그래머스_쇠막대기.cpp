#include <string>
#include <stack>

using namespace std;

int solution(string arrangement) {
	string s = arrangement;
	int answer = 0;
	stack<char> st;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == '(') st.push('(');
		else
		{
			st.pop();
			if (s[i - 1] == '(')
				answer += st.size();
			else
				answer++;
		}
	}
	return answer;
}