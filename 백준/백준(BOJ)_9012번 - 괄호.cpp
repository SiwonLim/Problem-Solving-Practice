#include <iostream>
#include <string>
using namespace std;
int main() {
	int T;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		string s;
		cin >> s;
		int len = s.length(), check = 0;
		for (int j = 0; j < len; j++) {
			check += (s[j] == '(') ? 1 : -1;
			if (check < 0) break;
		}
		(!check) ? puts("YES") : puts("NO");
	}
	return 0;
}