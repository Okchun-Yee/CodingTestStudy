#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;
#define DIR 4

vector<vector<bool>> visited;		// 방문 검사 배열
vector<vector<int>> graph;			// 문제 입력 배열 DFS

int dist[101][101];					// 이동 기록 용 배열

queue<pair<int, int>> q;			// BFS Queue

int N, M;

int moveRow[] = { -1, 1, 0, 0 };	// row 이동
int moveCol[] = { 0, 0, -1, 1 };	// col 이동

void BFS(int start_row, int start_col) {
	// 1) 시작 위치 방문 표시, Queue에 시작 위치 추가, 이동 기록 시작
	visited[start_row][start_col] = true;		// 시작 위치 방문 
	q.push({ start_row, start_col });			// 시작 위치 Queue 에 추가
	dist[start_row][start_col]++;				// 시작 위치 기록 (1부터 시작) << 최단 거리를 기록하기 위해서 필요

	while (!q.empty()) {
		// 현재의 row, col 좌표 기록
		int row = q.front().first;
		int col = q.front().second;

		// cout << "(" << row << ", " << col << ") 방문!\n";
		if (graph[row][col] == 0) continue;		// 만약 다음 위치의 값이 '0' = 벽이면 생략
		q.pop(); //기록한 좌표 제거

		for (int i = 0; i < DIR; i++) {
			// 1. 다음 좌표 계산
			int n_row = row + moveRow[i];
			int n_col = col + moveCol[i];
			// 2. 조건 만족 시 다음 좌표 이동
			if (n_row >= 0 && n_row < N && n_col >= 0 && n_col < M && !visited[n_row][n_col]) {
				// 조건 만족 시
				if (graph[n_row][n_col] == 1) {
					visited[n_row][n_col] = true;
					q.push({ n_row, n_col });
					dist[n_row][n_col] = dist[row][col] + 1;
				}
			}
		}
	}
}

int main() {
	cin >> N >> M;

	graph.assign(N, vector<int>(M));
	visited.assign(N, vector<bool>(M));

	for (int i = 0; i < N; i++) {
		string r_str;
		cin >> r_str;
		for (int j = 0; j < M; j++) {
			int c = r_str[j] - '0';
			graph[i][j] = c;
		}
	}
	BFS(0, 0);
	cout << dist[N - 1][M - 1];
	return 0;
}