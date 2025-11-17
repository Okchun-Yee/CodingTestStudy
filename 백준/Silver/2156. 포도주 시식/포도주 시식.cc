#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> v;

void slove() {
	vector<int> dp(N + 1, 0);
	// 1. basecase
	dp[1] = v[1];
	dp[2] = dp[1] + v[2];

	// * dp[i] = max(i-1 을 밟지 않는 경우, i-1을 밟는 경우);
	for (int i = 3; i < N + 1; ++i) {
		int a = v[i] + dp[i - 2];
		int b = v[i] + v[i - 1] + dp[i - 3];

		// * 계단 오르기 문제와 차별점
		// * dp[i] 의 최대값을 구하는 과정에서 "i번째 잔을 안마시는 경우" 가 추가
		// max(i를 안마시는 경우, i-1을 안마시는 경우, i-1을 마시는 경우)
		// *  max({ dp[i-1], a, b }) 형식으로 쓰면 컴파일 에러 발생 => max 중첩 사용
		dp[i] = max(dp[i - 1], max(a, b));
	}
	cout << dp[N];
	return;
}

int main() {
	cin >> N;
	v.resize(N + 1);
	for (int i = 1; i < N + 1; ++i) {
		cin >> v[i];
	}
	slove();
	return 0;
}