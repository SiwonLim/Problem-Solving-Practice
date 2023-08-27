#include <vector>
using namespace std;
int N;
vector<vector<int>> Board;
//블록 떨어트릴수 있는가?
bool canFill(int row, int col)
{
	for (int i = 0; i < row; i++)
		if (Board[i][col] != 0) return false;
	return true;
}
//지울수 있는 블록을 찾는다
bool find(int row, int col, int h, int w)
{
	int emptyCnt = 0;
	int lastValue = -1;
	for (int i = row; i < row + h; i++)
	{
		for (int j = col; j < col + w; j++)
		{
			if (Board[i][j] == 0){
				if (!canFill(i, j)) return false;
				if (++emptyCnt > 2) return false;
			}
			else{
				//직사각형안에 다른번호의 블록이 들어갈 경우
				if (lastValue != -1 && lastValue != Board[i][j]) return false;
				lastValue = Board[i][j];
			}
		}
	}
	//영역 지우기
	for (int i = row; i < row + h; i++)
		for (int j = col; j < col + w; j++)
			Board[i][j] = 0;

	return true;
}

int solution(vector<vector<int>> board) {
	Board = board;
	N = board.size();
	int answer = 0, cnt;
	do {
		cnt = 0;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (i <= N - 3 && j <= N - 2 && find(i, j, 3, 2)) cnt++;//3X2직사각형
				else if (i <= N - 2 && j <= N - 3 && find(i, j, 2, 3)) cnt++;//2X3직사각형
			}
		}
		answer += cnt;
	} while (cnt);
	return answer;
}