#include <iostream>
#include <vector>

using namespace std;

int N, S;
vector<int> sequence;
int cnt;

void slove(int idx, int sum) {
	// 1) 전체 배열을 탐색 한 후 종료
	if (idx == N) {
		// 2) 합이 정답이면 종료
		if (sum == S) {
			cnt++;
		}
		return;
	}
	// 3) 브루트 포스 재귀함수 
	// 포함 (안함 / 함) 2개의 재귀 함수로 모든 경우의 수를 가진 수열을 만들어 수 있습니다. 
	slove(idx + 1, sum);
	slove(idx + 1, sum + sequence[idx]);
}
int main() {
	cin >> N >> S;

	sequence.assign(N, 0);
	for (int i = 0; i < N; i++) {
		cin >> sequence[i];
	}
	slove(0, 0);
	if (S == 0) --cnt;
    cout << cnt << endl;
	return 0;
}
