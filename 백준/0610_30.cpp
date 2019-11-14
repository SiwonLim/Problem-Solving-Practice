#include <iostream>
#include <string>
#include <algorithm>
bool cmp(char a, char b) {
	return a > b;
}
using namespace std;
int main() {
	string str;
	getline(cin,str);
	for (int i = 0; i < str.length(); i++) v.push_back(str[i]);
	//0이 있는지 확인
	if (find(str.begin(), str.end(), '0') == str.end()) {
		cout << -1 << endl;
	}
	else {
		sort(str.begin(), str.end(), cmp);
		int val = 0;
		for (int i = 0; i < v.size(); i++) {
			val += str[i] - '0';
		}

		if (val % 3 == 0) cout << str << endl;
		else cout << -1 << endl;
	}
	return 0;
}
