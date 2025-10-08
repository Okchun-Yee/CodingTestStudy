#include <iostream>
#include <vector>
#include <map>

using namespace std;

vector<vector<char>> board;
vector<vector<bool>> visited;
map<char, bool> checked;

int moveRow[] = { -1, 1, 0, 0 };	// row 이동
int moveCol[] = { 0, 0, -1, 1 };	// col 이동

int R, C;
int maxCnt = 0;

void DFS(int x, int y, int cnt) {
	// 1) 최대 탐색 길이 저장
	maxCnt = max(maxCnt, cnt);
	/*cout << board[x][y] << " " << maxCnt << endl;*/
	// 미로 탐색 알고리즘 조건 검사 후 DFS 발동 시킬 때 마다 + 1
	for (int i = 0; i < 4; i++) {
		int n_row = x + moveRow[i];
		int n_col = y + moveCol[i];

		if (n_row >= 0 && n_row < R && n_col >= 0 && n_col < C){
			if (!checked[board[n_row][n_col]]) {
				checked[board[n_row][n_col]] = true;	// 방문 표시
				DFS(n_row, n_col, cnt + 1);
				checked[board[n_row][n_col]] = false;	// 백트래킹
			}
		}
	}
}

int main() {
	cin >> R >> C;
	board.assign(R, vector<char>(C));
	for (int i = 0; i < R; ++i) {
		string str;
		cin >> str;
		for (int j = 0; j < C; ++j) {
			char c = str[j];
			board[i][j] = c;
			checked[c] = false;
		}
	}
	// 0) 방문 처리 (시작 지점 알파벳은 탐색에 포함 시킬 필요가 없음)
	checked[board[0][0]] = true;
	DFS(0, 0, 1); // 시작 시점 포함

	cout << maxCnt;
}