#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define SIZE 19
int board[SIZE][SIZE];

bool isRow(int x, int y, int player) {
	// 1. 가로줄 검사
	int cnt = 1;
	// 현재 점의 x 앞으로 검사
	for (int i = 1; i <= SIZE - x; ++i) {
		int nx = x + i;
		if (nx < 0 || nx >= 19)break;
		if (board[nx][y] != player) break;

		cnt++;
	}
	// 현재 점의 x 뒤로 검사
	for (int i = 1; i <= x; ++i) {
		int nx = x - i;
		if (nx < 0 || nx >= 19)break;
		if (board[nx][y] != player) break;

		cnt++;
	}
	if (cnt == 5) return true;
	else return false;
}
bool isCol(int x, int y, int player) {
	// 2. 세로줄 검사
	int cnt = 1;
	// 현재 점의 y 아래로 검사
	for (int i = 1; i <= SIZE - y; ++i) {
		int ny = y + i;
		if (ny < 0 || ny >= 19) break;
		if (board[x][ny] != player) break;

		cnt++;
	}
	// 현재 점의 y 위로 검사
	for (int i = 1; i <= y; ++i) {
		int ny = y - i;
		if (ny < 0 || ny >= 19) break;
		if (board[x][ny] != player) break;

		cnt++;
	}
	if (cnt == 5) return true;
	else return false;
}
bool isRightDown(int x, int y, int player) {
	int cnt = 1;
	for (int i = 1; ; ++i) {
		int nx = x + i;
		int ny = y + i;
		if (nx < 0 || nx >= 19 || ny < 0 || ny >= 19)
			break;
		if (board[nx][ny] != player)
			break;
		cnt++;
	}
	for (int i = 1; ; ++i) {
		int nx = x - i;
		int ny = y - i;
		if (nx < 0 || nx >= 19 || ny < 0 || ny >= 19)
			break;
		if (board[nx][ny] != player)
			break;
		cnt++;
	}
	if (cnt == 5) return true;
	else return false;
}
bool isLeftDown(int x, int y, int player) {
	int cnt = 1;
	for (int i = 1; ; ++i) {
		int nx = x + i;
		int ny = y - i;
		if (nx < 0 || nx >= 19 || ny < 0 || ny >= 19)
			break;
		if (board[nx][ny] != player)
			break;
		cnt++;
	}
	for (int i = 1; ; ++i) {
		int nx = x - i;
		int ny = y + i;
		if (nx < 0 || nx >= 19 || ny < 0 || ny >= 19)
			break;
		if (board[nx][ny] != player)
			break;
		cnt++;
	}
	if (cnt == 5) return true;
	else return false;
}

void slove() {
	for (int j = 0; j < SIZE; ++j) {
		for (int i = 0; i < SIZE; ++i) {
			if (board[i][j] != 0) {
				if (isRow(i, j, board[i][j]) || isCol(i, j, board[i][j]) || isRightDown(i, j, board[i][j]) || isLeftDown(i, j, board[i][j])){
					cout << board[i][j] << endl << i + 1 << " " << j + 1;
					return;
				}
			}
		}
	}
	// 함수가 끝까지 실행되면 = 무승부
	cout << 0 << "\n";
}	

int main() {
	for (int i = 0; i < SIZE; ++i)
		for (int j = 0; j < SIZE; ++j)
			cin >> board[i][j];
	slove();
}