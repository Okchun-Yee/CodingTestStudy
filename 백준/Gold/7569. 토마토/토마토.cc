#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct	P {
	int z, x, y;
};

vector<vector<vector<int>>> map;		// 문제
vector<vector<vector<bool>>> visited;	// 방문 검사
queue<P> q;			// BFS

int dist[101][101][101];			// 최단 거리 탐색용

int dz[] = { -1, 1, 0, 0, 0, 0 };
int dx[] = { 0, 0, -1, 1, 0, 0 };
int dy[] = { 0, 0, 0, 0, -1, 1 };

int m, n, h;
void bfs() {
	while (!q.empty())
	{
		P p = q.front();
		int z = p.z;
		int x = p.x;
		int y = p.y;

		q.pop();
		
		for (int i = 0; i < 6; ++i) {
			int nz = z + dz[i];
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx >= 0 && nx < m && ny >= 0 && ny < n && nz < h && nz >= 0) {
				if (map[nz][nx][ny] == 0 && !visited[nz][nx][ny]) {
					visited[nz][nx][ny] = true;
					q.push({ nz, nx, ny });
					dist[nz][nx][ny] = dist[z][x][y] + 1;
				}
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m >> h;
	map.resize(h, vector<vector<int>>(m, vector<int>(n, 0)));
	visited.resize(h, vector<vector<bool>>(m, vector<bool>(n, false)));

	for (int k = 0; k < h; ++k) {
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				cin >> map[k][i][j];
				if (map[k][i][j] == 1) {
					q.push({ k, i, j });
					dist[k][i][j] = 0;
				}
			}
		}
	}
	bfs();

	int answer = -1;
	int max = 0;

	for (int k = 0; k < h; ++k) {
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				if (map[k][i][j] == 0 && dist[k][i][j] == 0) {
					cout << answer << endl;
					return 0;
				}
				if (max < dist[k][i][j])
					max = dist[k][i][j];
			}
		}
	}
	answer = max;
	cout << answer << endl;

	return 0;
}