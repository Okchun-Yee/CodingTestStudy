#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
#define SIZE 3

int board[SIZE][SIZE];
int cnt_1 = 0, cnt_2 = 0, cnt_0 = 0;

bool isWin(int player) {
	// 1. 모든 가로줄 검사
	for (int i = 0; i < SIZE; ++i) {
		if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
			return true;
		}
	}
	// 2. 모든 세로줄 검사
	for (int i = 0; i < SIZE; ++i) {
		if (board[0][i] == player && board[1][i] == player && board[2][i] == player) {
			return true;
		}
	}
	// 3. 좌상단 -> 우하단 대각선에 포함될 때
	if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
		return true;
	}
	// 4. 우상단 -> 좌하단 대각선에 포함될 때
	if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
		return true;
	}

    // 어떤 승리 조건도 만족하지 못한 경우=> 다음 수 진행 or Draw
    return false;
}

// 매개변수: x, y 좌표 , 탐색 LV, 현재 착수
int slove(int player) {
	// 재귀 종료 조건
	// 상대방이 승리한 경우 -> 내가 이길 경우의 수가 없음
	if (isWin(3 - player)) {
		// 상대방 승리 = Lose
		return -1;
	}
	int canWin = -1;
	// Base Case 2: 보드가 꽉 찼는지 확인 (무승부)
	bool isFull = true;
	for (int i = 0; i < SIZE; ++i) {
		for (int j = 0; j < SIZE; ++j) {
			if (board[i][j] == 0) {
				isFull = false;
				break;
			}
		}
		if (!isFull) break;
	}
	if (isFull) {
		return 0; // 보드가 꽉 찼으면 무승부
	}

	for (int i = 0; i < SIZE; ++i) {
		for (int j = 0; j < SIZE; ++j) {
			if (board[i][j] == 0) {
				// 1. Do - 보드 배치
				board[i][j] = player;
				// 상대의 배치 결과 확인
				int rate = slove(3 - player);
				// 나의 결과 = 상대 결과의 역
				int myrate = rate * -1;
				// 최대값 (-1 -> 1 전환)
				canWin = max(canWin, myrate);

				// 3. back 상태복원
				board[i][j] = 0;
			}
		}
	}
	return canWin;
}

int main() {
	int turn = 0;

	for (int i = 0; i < SIZE; ++i) {	
		for (int j = 0; j < SIZE; ++j) {
			cin >> turn;
			board[i][j] = turn;		// 보드에 0 or 1 or 2 삽입

			if (turn == 1) cnt_1++;
			else if (turn == 2) cnt_2++;
			else cnt_0++;
		}
	}

	int player = (cnt_1 == cnt_2) ? 1 : 2;
	int result = slove(player);

	if (result == 1) {
		cout << "W" << endl;
	}
	else if (result == 0) {
		cout << "D" << endl;
	}
	else { // result == -1
		cout << "L" << endl;
	}

	return 0;
 }