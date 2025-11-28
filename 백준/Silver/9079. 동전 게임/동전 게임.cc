#include <iostream>
#include <vector>
#include <climits>

using namespace std;
#define SIZE 3
int T;
char board[SIZE][SIZE];
int answer = INT_MAX;
vector<vector<char>> v;

// 보드칸 뒤집기 메서드
char isFlip(char c) {
	return c == 'T' ? 'H' : 'T';
}
void Rows(int r) {
	for (int c = 0; c < SIZE; ++c) {
		board[r][c] = isFlip(board[r][c]);
	}
}
void Cols(int c) {
	for (int r = 0; r < SIZE; ++r) {
		board[r][c] = isFlip(board[r][c]);
	}
}
void Diagonal(int type) {
	for (int i = 0; i < SIZE; ++i) {
		if (type == 0) {
			board[i][i] = isFlip(board[i][i]);
		}
		else {
			board[i][SIZE - 1 - i] = isFlip(board[i][SIZE - 1 - i]);
		}
	}
}
// 보드칸 전체가 같으면 True : 아니면 False
bool isWin() {
	char c = board[0][0];
	for (int i = 0; i < SIZE; ++i) {
		for (int j = 0; j < SIZE; ++j) {
			if (board[i][j] != c) {
				return false;
			}
		}
	}
	return true;
}
/// <summary>
/// * 보드판 뒤집을 경우의 수 maping
/// 0 ~ 2 - 3가지 경우로 가로줄 뒤집기
/// 3 ~ 5 - 3가지 경우로 세로줄 뒤집기
/// 6 ~ 7 - 2가지 경우로 대각선 뒤집기
/// 보드판은 가로 세로 3 X 3 이기에 가로 세로는 3가지 경우의 수, 대각선은 2가지 경우의 수
/// </summary>
void Check(int idx) {
	if (idx < 3) Rows(idx);
	else if (idx < 6) Cols(idx - 3);
	else Diagonal(idx - 6);
}
void solve(int depth, int idx) {
	// BaseCase - 8가지 경우의 수를 전부 탐색한 후
	if (idx == 8) {
		if (isWin()) {
			answer = min(answer, depth);
		}
		return;
	}
	if (depth >= answer) return;
	// case1 - 현재 방식으로 뒤집지 않고 다음 방식 선택
	solve(depth, idx + 1);

	// case2 - 현재 방식으로 뒤집고 다음 방식으로 넘어가기
	Check(idx);
	solve(depth + 1, idx + 1);
	Check(idx);
}

int main() {
	cin >> T;
	v.resize(3*T);	
	for (int i = 0; i < 3*T; ++i) {
		for (int j = 0; j < SIZE; ++j) {
			char c; cin >> c;
			v[i].push_back(c);
		}
	}

	// 3*T 길이의 배열을 3칸씩 잘라서 탐색
	for (int i = 0; i < 3*T; ++i) {
		for (int j = 0; j < SIZE; ++j) {
			board[i % SIZE][j] = v[i][j];
		}
		if (i % 3 == 2) {
			answer = INT_MAX;
			solve(0, 0);

			if (answer == INT_MAX) cout << -1 << endl;
			else cout << answer << endl;
		}
	}
	return 0;
}