#include <iostream>
#include <vector>
#include <cstdlib> // exit() 함수를 위해 추가

using namespace std;
#define SIZE 9

vector<vector<int>> board(SIZE, vector<int>(SIZE));
bool rowChk[SIZE][SIZE];			// 가로 검사
bool colChk[SIZE][SIZE];			// 세로 검사
bool boxChk[SIZE][SIZE];			// 3 * 3 box 검사
// Box 계산식
// index = (row / 3) * 3 + (col / 3)
// row를 3의 배수로 내림 하여 박스의 위치를 계산

// 출력 매서드
void printBoard() {
	for (int i = 0; i < SIZE; ++i) {
		for (int j = 0; j < SIZE; ++j) {
			cout << board[i][j] << " ";
		}
		cout << endl;
	}
}

void DFS(int level) {
	if (level == 81) {
		// 최종 결과 출력
		printBoard();
		exit(0);
	}
	int row = level / 9;
	int col = level % 9;
	// 스도쿠 빈칸 확인 = 빈칸이 아니면 다음 탐색 진행
	if (board[row][col] != 0)
		DFS(level + 1);
	else {
		for (int num = 1; num <= 9; ++num) {
			if (!rowChk[row][num - 1] && !colChk[col][num - 1] && !boxChk[(row / 3) * 3 + (col / 3)][num - 1]) {
				// 스도쿠 보드에 숫자 삽입
				board[row][col] = num;
				// i 행에 숫자 num이 존재한다고 체크
				rowChk[row][num - 1] = true;
				// j 열에 숫자 num이 존재한다고 체크
				colChk[col][num - 1] = true;
				// 해당 3x3 박스에 숫자 num이 존재한다고 체크
				boxChk[(row / 3) * 3 + (col / 3)][num - 1] = true;

				// 다음 위치 탐색
				DFS(level + 1);

				// 백트래킹 (상태 원복)
				board[row][col] = 0;
				// i 행에 숫자 num이 존재한다고 체크
				rowChk[row][num - 1] = false;
				// j 열에 숫자 num이 존재한다고 체크
				colChk[col][num - 1] = false;
				// 해당 3x3 박스에 숫자 num이 존재한다고 체크
				boxChk[(row / 3) * 3 + (col / 3)][num - 1] = false;
			}

		}
	}
}

int main() {
	for (int i = 0; i < SIZE; ++i) {
		for (int j = 0; j < SIZE; ++j) {
			cin >> board[i][j];
			// 0은 빈칸이기에 입력이 0이 아니면 배열에 숫자 체크
			if (board[i][j] != 0) {
				int num = board[i][j];

				// i 행에 숫자 num이 존재한다고 체크
				rowChk[i][num - 1] = true;
				// j 열에 숫자 num이 존재한다고 체크
				colChk[j][num - 1] = true;
				// 해당 3x3 박스에 숫자 num이 존재한다고 체크
				boxChk[(i / 3) * 3 + (j / 3)][num - 1] = true;
			}
		}
	}
	cout << endl;

	DFS(0);
}