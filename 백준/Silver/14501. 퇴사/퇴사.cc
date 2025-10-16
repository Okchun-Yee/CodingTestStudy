#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int N;
int maxTotal = 0;
vector<vector<int>> matrix;

void slove(int level, int total) {
	// 1. 종료 조건: level이 N 이상
	if (level >= N) {
		// N과 동일한 경우 최댓값 갱신
		if (level == N) {
			maxTotal = max(maxTotal, total);
		}
		// N과 동일하지 않을 경우 초과이므로 갱신 X
		return;
	}

	// 1. 경우의 수 - 다음으로 그냥 넘어가기
	slove(level + 1, total);
	// 2. 경우의 수 - 현재 level + t가 N 이하인 경우 상담 진행 + p 증가
	if (level + matrix[level][0] <= N) {
		slove(level + matrix[level][0], total + matrix[level][1]);
	}
}
int main() {
	cin >> N;
	matrix.assign(N, vector<int>(2));
	int t, p = 0;
	for (int i = 0; i < N; ++i) {
		cin >> t >> p;
		matrix[i][0] = t;
		matrix[i][1] = p;
	}
	slove(0, 0);
	cout << maxTotal;

	return 0;
}