#include <iostream>
#include <vector>
#include <queue>
#include <iomanip>  // setw를 사용하기 위해 필요

using namespace std;

vector<vector<int>> graph;		// 문제
vector<vector<bool>> visited;	// 방문 검사
queue<pair<int, int>> q;		// BFS

int dist[1001][1001];			// 최단 거리 탐색용
int moveRow[] = { -1, 1, 0, 0 };	// row 이동
int moveCol[] = { 0, 0, -1, 1 };	// col 이동

// 변수 목록
int N, M; // row, col


void BFS() {
	while (!q.empty())
	{
		int row = q.front().first;
		int col = q.front().second;

		visited[row][col] = true;

		q.pop();

		for (int i = 0; i < 4; ++i) {
			int n_row = row + moveRow[i];
			int n_col = col + moveCol[i];

			if (n_row >= 0 && n_row < N && n_col >= 0 && n_col < M && !visited[n_row][n_col]) {
				if (graph[n_row][n_col] == 0) {
					// 방문 처리
					visited[n_row][n_col] = true;
					// 인덱스 삽입
					q.push({ n_row, n_col });
					// 거리 증가
					dist[n_row][n_col] = dist[row][col] + 1;
				}
			}
		}
	}
	return;
}

int main() {
	cin >> M >> N;

	graph.assign(N, vector<int>(M));
	visited.assign(N, vector<bool>(M, false));

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cin >> graph[i][j];
			if (graph[i][j] == 1) {
				// 1) 그래프 상에서 1인 부분 (익은 토마토) 찾기 = 시작 점
				// 2) 시작점을 큐에 미리 할당
				q.push({ i, j });
			}
		}
	}
	BFS();

	int answer = -1;
	int max = 0;

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			// 3) 익지않은 토마토 (0) 인데 방문 한적 없는 경우
			// 4) 시작점(1)이면서 dist가 0인 경우는 제외해야 함
			if (graph[i][j] == 0 && dist[i][j] == 0) {
				cout << answer << endl;
				return 0;
			}
			// 5) 배열에서 최단 거리 의 최댓값 찾기
			if (max < dist[i][j])
				max = dist[i][j];
		}
	}
	answer = max;
	cout << answer << endl;

	return 0;
}