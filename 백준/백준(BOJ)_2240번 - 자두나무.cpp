#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int T, W;
int plum[1001];
int d[3][1001][31];
//자리를 바꿀경우, 자리를 바꾸지 않을경우
int calcPlum(int tree, int time, int move)
{
	if (time == T) return 0;
	int& ret = d[tree][time][move];
	if (ret != -1) return ret;
	//현재 나무에서 자두 떨어짐
	if (plum[time] == tree)
	{
		if (move < W)//max(움직X 받기 vs 움직이기)
			return ret = max(calcPlum(tree, time + 1, move)+1,
				calcPlum(3 - tree, time + 1, move + 1));
		else//못움직이지만 자두 받음
			return ret = calcPlum(tree, time + 1, move) + 1;
	}
	else//다른나무에서 자두 떨어짐
	{
		if (move < W)//max(움직X 못받음 vs 움직여서 받음)
			return ret = max(calcPlum(tree, time + 1, move),
				calcPlum(3 - tree, time + 1, move + 1) + 1);
		else//못움직이고 자두 못받음
			return ret = calcPlum(tree, time + 1, move);
	}
}
int main() {
	cin >> T >> W;
	for(int i = 0 ; i < T ; i++)
	{
		cin >> plum[i];
	}
	memset(d, -1, sizeof(d));
	cout << calcPlum(1, 0, 0) << endl;
}