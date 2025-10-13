#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
#define SIZE 4

vector<vector<int>> matrix;
vector<vector<bool>> visited;
int N, M;
int maxSum = 0;

// 1. (x, y-1) (x, y) (x+1, y)
// 2. (x-1, y) (x, y) (x, y-1)
// 3. (x-1, y) (x, y) (x, y+1)
// 4. (x, y+1) (x, y) (x+1, y)
int dx[4][2] = { {0, 1}, {-1, 0}, {-1, 0}, {0, 1} };
int dy[4][2] = { {-1, 0}, {0, -1}, {0, 1}, {1, 0} };

bool isVal(int x, int y) {
	if (x >= 0 && x < N && y >= 0 && y < M && !visited[x][y]) {
		return true;
	}
	return false;
}
bool chkNode(int x, int y, int idx) {
	if (visited[x][y])
		return false;
	// 날개 Index 구하기
	int x1 = x + dx[idx][0];
	int y1 = y + dy[idx][0];
	int x2 = x + dx[idx][1];
	int y2 = y + dy[idx][1];

	// 중심 노드의 날개 노드의 유효성 검사
	if (isVal(x1, y1) && isVal(x2, y2))
		return true;
	return false;
}

int addNode(int x, int y, int idx) {
	int x1 = x + dx[idx][0];
	int y1 = y + dy[idx][0];
	int x2 = x + dx[idx][1];
	int y2 = y + dy[idx][1];

	// 1. Do - 값 구하기 + 방문 처리
	visited[x][y] = true;
	visited[x1][y1] = true;
	visited[x2][y2] = true;

	// * 중심칸은 X 2
	return (matrix[x][y])*2 + matrix[x1][y1] + matrix[x2][y2];
}

void backNode(int x, int y, int idx) {
	int x1 = x + dx[idx][0];
	int y1 = y + dy[idx][0];
	int x2 = x + dx[idx][1];
	int y2 = y + dy[idx][1];

	// 3. Back - 상태 복원
	visited[x][y] = false;
	visited[x1][y1] = false;
	visited[x2][y2] = false;
	return;
}

void slove(int x, int y, int total) {
	if (x == N) {
		maxSum = max(maxSum, total);
		return;
	}
	int nx = x;
	int ny = y + 1;
	// 만약 y == M - 1 (행의 끝에 도달) -> 행 증가, 열 = 0 부터 다시 시작
	if (y == M - 1) {
		nx = x + 1;
		ny = 0;
	}
	// 방문한 위치면 바로 다음으로 넘어가기 (백트래킹 과정에서 중복 칸 방지)
	if (visited[x][y]) {
		slove(nx, ny, total);
		return;
	}
	for (int i = 0; i < SIZE; ++i) {
		if (chkNode(x, y, i)) {
			// 실행
			int sum = addNode(x, y, i);
			// 재귀
			slove(nx, ny, total + sum);
			// 상태복원
			backNode(x, y, i);
		}
	}
	// * 5번째 경우 (배치하지않는 경우)
	slove(nx, ny, total);
}
int main() {
	cin >> N >> M;
	matrix.assign(N, vector<int>(M));
	visited.assign(N, vector<bool>(M));

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cin >> matrix[i][j];
		}
	}
	slove(0, 0, 0);
	cout << maxSum;
	return 0;
}