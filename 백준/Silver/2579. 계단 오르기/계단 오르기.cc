#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<int> v;

void slove() {
	int cnt = 0;
	vector<int> dp(N + 1, 0);
	// 1. basecase
	dp[1] = v[1];
	dp[2] = v[1] + v[2];

	// * dp[i] = max(i-1 을 밟지 않는 경우, i-1을 밟는 경우);
	for (int i = 3; i < N + 1;++i) {
		if (i - 3 >= 0) {
			int a = v[i] + dp[i - 2];
			int b = v[i] + v[i - 1] + dp[i - 3];
			dp[i] = max(a, b);
		}
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