#include <iostream>
#include <sstream>
using namespace std;
typedef unsigned long long LL;
LL arr[4];
LL calc(int s,int e) {
	stringstream ss;
	ss << arr[s] << arr[e];
	return stoull(ss.str());
}
int main() {
	for (int i = 0; i < 4; i++) cin >> arr[i];
	cout << calc(0, 1) + calc(2, 3) << endl;
	return 0;
}