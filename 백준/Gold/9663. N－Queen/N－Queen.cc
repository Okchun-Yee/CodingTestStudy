#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int N; 
bool colChk[15];		// 세로 검사
// 대각선 계산식
// 우하향 : x + y
// 좌하향 : (x - y) + (N - 1)
bool digChk[2][29];		// 대각선 검사 | [0] 우하향, [1] 좌하향 

int cnt = 0;

// 매개변수 : 탐색 Level = row
void DFS(int x) {
	// 탐색 횟수는 총 N 회
	if (x == N) {
		// 탐색 종료 시 경우의 수 증가
		cnt++;
		return;
	}
	// 가능한 열 탐색
	for (int y = 0; y < N; ++y) {
		// * 조건
		// 1. 비어있는 열
		// 2. 비어있는 우하향 대각선
		// 3. 비어있는 좌하향 대각선
		if (!colChk[y] && !digChk[0][x + y] && !digChk[1][(x - y) + (N - 1)]) {
			
			// Qeen 배치
			colChk[y] = true;
			digChk[0][x + y] = true;
			digChk[1][(x - y) + (N - 1)] = true;
			//printf("x: %2d , y: %2d, d1: %2d, d2: %2d \n", x, y, x + y, (x + y) - (N - 1));
			// row 증가
			DFS(x + 1);

			// 백트래킹 (상태 원복)
			colChk[y] = false;
			digChk[0][x + y] = false;
			digChk[1][(x - y) + (N - 1)] = false;
		}
	}
}

int main() {
	cin >> N;

	// 시작 위치는 0,0 고정
	DFS(0);

	cout << cnt;
}