#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
string str;
int pld[2501][2501];
int d[2501];

int isPelin(int s, int e)
{
	if (s>=e) return 1;
	int ret = pld[s][e];
	if (ret) return ret;
	if (str[s] != str[e]) ret = 0;
	else ret = isPelin(s + 1, e - 1);
	return ret;
}

int main() {
	cin >> str;
	int len = str.length();
	for (int i = 0 ; i < len; i++){
		d[i] = 2147483647;
		for (int j = 0 ; j <= i; j++)
			if (isPelin(j, i)) d[i] = min(d[i], d[j - 1] + 1);
	}
	cout << d[len-1] << endl;
	return 0;
}