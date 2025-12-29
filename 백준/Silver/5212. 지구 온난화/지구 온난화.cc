#include <iostream>
#include <vector>
#include <queue>
#include <algorithm> // min, max 함수 사용을 위해

using namespace std;

int R, C;
vector<vector<char>> map;
vector<vector<char>> newmap;
queue<pair<int, int>> q;

int dx[] = { -1, 1, 0, 0 };	// row 이동
int dy[] = { 0, 0, -1, 1 };	// col 이동

void bfs() {
	while (!q.empty())
	{
		int cnt = 0;

		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; ++i) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || nx >= R || ny < 0 || ny >= C) {
				cnt++;
			}
			if (nx >= 0 && nx < R && ny >= 0 && ny < C) {
				if (map[nx][ny] == '.') {
					cnt++;
				}
			}
		}
		if (cnt >= 3) {
			newmap[x][y] = '.';
		}
	}
}
void ArrayResize(vector<vector<char>> arr) {
	int n = arr.size();
	int m = arr[0].size();

	int minRow = n, maxRow = -1;
	int minCol = m, maxCol = -1;
	bool flag = false;

	// 2. 전체 탐색하며 'X'의 경계 찾기
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (arr[i][j] == 'X') {
				flag = true;
				minRow = min(minRow, i); // 가장 위쪽 행 갱신
				maxRow = max(maxRow, i); // 가장 아래쪽 행 갱신
				minCol = min(minCol, j); // 가장 왼쪽 열 갱신
				maxCol = max(maxCol, j); // 가장 오른쪽 열 갱신
			}
		}
	}

	for (int i = minRow; i <= maxRow; ++i) {
		for (int j = minCol; j <= maxCol; ++j) {
			cout << arr[i][j];
		}
		cout << endl;
	}
}
int main() {
	cin >> R >> C;
	map.assign(R, vector<char>(C));
	for (int i = 0; i < R; ++i) {
		for (int j = 0; j < C; ++j) {
			cin >> map[i][j];
			if (map[i][j] == 'X')
				q.push({ i, j });
		}
	}
	newmap = map;
	bfs();

	ArrayResize(newmap);
	return 0;
}