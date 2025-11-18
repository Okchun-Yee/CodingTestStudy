#include <iostream>
#include <vector>

using namespace std;
#define SIZE 15

int N;
long double dir[4];
bool visited[32][32];
long double answer = 0;

int dr[] = { -1, 1, 0, 0 };	// row 이동
int dc[] = { 0, 0, -1, 1 };	// col 이동;

/// <summary>
/// * [SIZE][SIZE] 중심점에서 시작
/// * 각 방향으로 이동 할때 마다 해당 방향의 확률을 누적
/// * 중복 방문 없이 탐색 Lv이 N에 도달할 경우에 누적 확률을 출력
/// * 백트래킹 방식 사용
/// </summary>

void dfs(int r, int c, int level, long double result) {
	// 1. BaseCase
	// 탐색 lv이 N과 동일 해지면 종료.
	if (level == N) {
		answer += result;
		return;
	}
	// 2. 방문 처리
	visited[r][c] = true;	

	for (int i = 0; i < 4; ++i) {
		// 3. 좌표 갱신 
		// 다음 좌표로 이동
		int nr = r + dr[i];
		int nc = c + dc[i];
		// 범위 검사
		if (nr > 0 && nr < 32 && nc > 0 && nc < 32) {
			// 방문 검사
			if (!visited[nr][nc]) {
				dfs(nr, nc, level + 1, result * dir[i]);
			}
		}
	}
	visited[r][c] = false;
}
int main() {
	cin >> N;

	for (int i = 0; i < 4; ++i) {
		int n;
		cin >> n;
		// 나눗셈 할 때 피연산자도 무조건 실수형으로 하기....
		dir[i] = n / 100.0;
	}
	dfs(SIZE, SIZE, 0, 1);

	cout.precision(11); cout << fixed; // 소수점 출력용
	cout << answer;
	return 0;
}