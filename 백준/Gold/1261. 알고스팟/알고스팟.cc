#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> matrix;
vector<vector<bool>> visited;
deque<pair<int, int>> dq;
int N, M;

int moveX[] = { -1, 1, 0, 0 };
int moveY[] = { 0, 0, -1, 1 };

int dist[101][101];

/// <summary>
/// 0 - 1 BFS
/// 경로의 '비용' 을 생각하여 BFS를 탐색
/// * deque 자료 구조를 사용
/// 우선순위가 높은(빈방:0) 경로는 push_front
/// 우선순위가 낮은(벽 : 1) 경로는 push_back
/// </summary>
void BFS(int startX, int startY) {
	visited[startX][startY] = true;
	dist[startX][startY] = 0;
	dq.push_front({ startX, startY });

	while (!dq.empty())
	{
		int x = dq.front().first;
		int y = dq.front().second;

		if (x == N - 1 && y == M - 1)
			return;

		dq.pop_front();
		//cout << "NOW: " << x << " " << y << " " << dist[x][y] << endl;

		for (int i = 0; i < 4; ++i) {
			int nx = x + moveX[i];
			int ny = y + moveY[i];

			if (nx >= 0 && nx < N && ny >= 0 && ny < M && !visited[nx][ny]) {
				if (matrix[nx][ny] == 1) {
					visited[nx][ny] = true;
					// 우선 순위 낮음
					dq.push_back({ nx, ny });
					// 횟수 + 1
					dist[nx][ny] = dist[x][y] + 1;
				}
				else {
					visited[nx][ny] = true;
					// 우선 순위 높음
					dq.push_front({ nx, ny });
					// 횟수 그대로
					dist[nx][ny] = dist[x][y];
				}
			}
		}
	}
}
int main() {
	cin >> M >> N;

	matrix.assign(N, vector<int>(M));
	visited.assign(N, vector<bool>(M));

	for (int i = 0; i < N; ++i) {
		string str;
		cin >> str;
		for (int j = 0; j < M; ++j) {
			matrix[i][j] = str[j] - '0';
		}

	}

	BFS(0, 0);

	cout << dist[N - 1][M - 1] <<endl;
	return 0;
}