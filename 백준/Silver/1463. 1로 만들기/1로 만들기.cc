#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void slove(int n) {
	vector<int>dp(n + 1);
	dp[1] = 0; // 1인경우 연산이 필요가없음 = 최소 횟수

	/*
	* dp[N] = N를 1로 만드는 최소 횟수
	* dp[N-1] + 1 
	* dp[N/2] + 1
	* dp[N/3] + 1
	* 3가지 경우의 수를 가짐 (+1은 이번 연산)
	*/

	for (int i = 2; i <= n; ++i) {
		dp[i] = dp[i - 1] + 1;
		if (i % 2 == 0)
			dp[i] = min(dp[i], dp[i / 2] + 1);
		if (i % 3 == 0)
			dp[i] = min(dp[i], dp[i / 3] + 1);
	}
	cout << dp[n];
}
int main() {
	int N;
	cin >> N;
	slove(N);
}