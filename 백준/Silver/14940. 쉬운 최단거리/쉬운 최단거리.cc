#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m;
vector<vector<int>> map;
vector<vector<int>> answer;
vector<vector<bool>> visited;

int dist[1001][1001];

int moveRow[] = { -1, 1, 0, 0 };	// row 이동
int moveCol[] = { 0, 0, -1, 1 };	// col 이동

void bfs(int x, int y) {
	queue<pair<int, int>> q;

	visited[x][y] = true;
	q.push({ x, y });
	dist[x][y] = 0;

	while (!q.empty()) {
		int row = q.front().first;
		int col = q.front().second;
		//cout << "(" << row << ", " << col << ") 방문!\n";
		q.pop();
		
		for (int i = 0; i < 4; ++i) {
			int nx = row + moveRow[i];
			int ny = col + moveCol[i];
			if (nx >= 0 && nx < n && ny >= 0 && ny < m && !visited[nx][ny]) {
				if (map[nx][ny] != 0) {
					visited[nx][ny] = true;
					q.push({ nx, ny });
					dist[nx][ny] = dist[row][col] + 1;
				}
			}
		}
	}
}

int main() {
	cin >> n >> m;
	int targetX, targetY;

	map.resize(n, vector<int>(m, 0));
	answer.resize(n, vector<int>(m, 0));
	visited.resize(n, vector<bool>(m, false));

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> map[i][j];
			if (map[i][j] == 2) {
				targetX = i;
				targetY = j;
			}
		}
	}
	bfs(targetX, targetY);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (map[i][j] == 0)
				cout << 0 << " ";
			else if (!visited[i][j])
				cout << -1 << " ";
			else {
				cout << dist[i][j] << " ";
			}
		}
		cout << "\n";
	}
	return 0;
}