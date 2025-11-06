#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>

using namespace std;

int C, N;
vector<pair<int, int>> citys;

void slove() {
	vector<int> dp(C + 101, INT_MAX);
	dp[0] = 0;
	for (int i = 1; i <= C + 100; ++i) {
		for (int j = 0; j < N; ++j) {
			int w = citys[j].first;
			int v = citys[j].second;
			if (i >= v && dp[i - v] != INT_MAX) {
				dp[i] = min(dp[i], dp[i - v]+ w);
			}
		}
	}
	int answer = INT_MAX;
	for (int i = C; i <= C + 100; ++i) {
		answer = min(answer, dp[i]);
	}
	cout << answer;
}

int main() {
	cin >> C >> N;
	citys.resize(N);
	for (int i = 0; i < N; ++i) {
		cin >> citys[i].first >> citys[i].second;
	}
	slove();
	return 0;
}