#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int N, K;
vector<vector<int>>matrix;
vector<vector<int>>chess;
vector<vector<vector<int>>> board;
int gameCnt = 0;

int isBlueTile(int dir) {
	if (dir % 2 != 0) {
		dir += 1;
	}
	else {
		dir -= 1;
	}
	return dir;
}

void MoveDir() {
	while (gameCnt < 1000) { 
		gameCnt++;
		for (int i = 0;i < K; i++) {
			int row = chess[i][0];
			int col = chess[i][1];
			int dir = chess[i][2];

			vector<int>& curStack = board[row][col];

			// 제일 아래가 아니면 이동 불가
			if (curStack.empty() || curStack.front() != i) continue;
			

			int nextCol = col, nextRow = row;
			switch (dir) {
			case 1: nextCol += 1; break;
			case 2: nextCol -= 1; break;
			case 3: nextRow -= 1; break;
			case 4: nextRow += 1; break;
			}
			bool blueTile = false;
			if (nextRow < 0 || nextRow >= N || nextCol < 0 || nextCol >= N) {
				blueTile = true;
			}
			else if (matrix[nextRow][nextCol] == 2) {
				blueTile = true;
			}

			if (blueTile) {
				dir = isBlueTile(dir);
				chess[i][2] = dir;

				// 다시 이동 시도
				nextRow = row;
				nextCol = col;
				switch (dir) {
				case 1: nextCol += 1; break;
				case 2: nextCol -= 1; break;
				case 3: nextRow -= 1; break;
				case 4: nextRow += 1; break;
				}
				blueTile = false;
				if (nextRow < 0 || nextRow >= N || nextCol < 0 || nextCol >= N) {
					blueTile = true;
				}
				else if (matrix[nextRow][nextCol] == 2) {
					blueTile = true;
				}

				if (blueTile) continue;  // 이동 불가
			}

			// 전체 이동
			vector<int> moving = curStack;
			curStack.clear();

			//R 역순 로직
			if (matrix[nextRow][nextCol] == 1) {
				reverse(moving.begin(), moving.end());
			}

			//W or R는 일단 이동
			for (int m : moving) {
				chess[m][0] = nextRow;
				chess[m][1] = nextCol;
				//Stack 처리
				board[nextRow][nextCol].push_back(m);
			}
			if (board[nextRow][nextCol].size() >= 4) {
				return;
			}
		}
	}
	gameCnt = -1;
	return;
}
int main() {
	cin >> N >> K;

	matrix.assign(N, vector<int>(N));
	chess.assign(K, vector<int>(3));
	board.assign(N, vector<vector<int>>(N));

	int cnt = 0;
	for (int i = 0; i < N;i++) {
		for (int j = 0; j < N;j++) {
			cin >> matrix[i][j];
		}
	}
	for (int i = 0; i < K;i++) {
		int r, c, d;
		cin >> r >> c >> d;
		chess[i][0] = r - 1;
		chess[i][1] = c - 1;
		chess[i][2] = d;
		board[r - 1][c - 1].push_back(i);
	}
	MoveDir();
	cout << gameCnt;
	return 0;
}