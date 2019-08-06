#include <iostream>
#include <sstream>
#include <cstring>
using namespace std;
class myStack {
private:
	int d[10001];
	int len;
public:
	myStack() {
		memset(d, 0, 10001);
		len = 0;
	}
	void push(int n) { d[len++] = n; }
	int pop() { return (len == 0) ? -1 : d[--len]; }
	int size() { return len; }
	int empty() { return (len == 0) ? 1 : 0; }
	int top() { return (len == 0) ? -1 : d[len - 1]; }
};
int main() {
	int N;
	myStack st;
	cin >> N;
	while (N--) {
		string s[3];
		cin >> s[0];
		stringstream ss(s[0]);
		ss >> s[1];
		if (s[1].compare("push") == 0) {
			cin >> s[2];
			st.push(atoi(s[2].c_str()));
		}
		else if (s[1].compare("pop") == 0) cout << st.pop() << endl;
		else if (s[1].compare("size") == 0) cout << st.size() << endl;
		else if (s[1].compare("empty") == 0) cout << st.empty() << endl;
		else cout << st.top() << endl;
	}
	return 0;
}