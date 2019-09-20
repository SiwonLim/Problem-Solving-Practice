#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int T, W;
int plum[1001];
int d[3][1001][31];
//�ڸ��� �ٲܰ��, �ڸ��� �ٲ��� �������
int calcPlum(int tree, int time, int move)
{
	if (time == T) return 0;
	int& ret = d[tree][time][move];
	if (ret != -1) return ret;
	//���� �������� �ڵ� ������
	if (plum[time] == tree)
	{
		if (move < W)//max(����X �ޱ� vs �����̱�)
			return ret = max(calcPlum(tree, time + 1, move)+1,
				calcPlum(3 - tree, time + 1, move + 1));
		else//������������ �ڵ� ����
			return ret = calcPlum(tree, time + 1, move) + 1;
	}
	else//�ٸ��������� �ڵ� ������
	{
		if (move < W)//max(����X ������ vs �������� ����)
			return ret = max(calcPlum(tree, time + 1, move),
				calcPlum(3 - tree, time + 1, move + 1) + 1);
		else//�������̰� �ڵ� ������
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