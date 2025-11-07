#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

int N, K;
vector<pair<int, int>> bag;

// 0/1 배낭 알고리즘
void dynamic() {
	vector<int>dp(K + 1, 0);
	// 1. basecase
	dp[0] = 0;

	// * 0/1 배낭 알고리즘의 핵심은 "각 아이템을 한 번만 쓸지, 말지를 순서대로 결정"
	// * 외부 Loop = 아이템 : 배낭 배열 순회
	for (int i = 0; i < N; ++i) {
		// w = 무게 | v = 가치
		int w = bag[i].first;
		int v = bag[i].second;
		// * i 번째 아이템을 넣었을 때 최댓값을 dp 배열에 갱신 - 역방향
		// * dp[j-w] 값이 이번 아이템(i)에 의해 갱신되지 않은 이전 아이템 값(i-1)
		for (int j = K; j >= w; --j) {
			if (j>= w) {
				dp[j] = max(dp[j], dp[j - w] + v);
			}
		}
	}
	cout << dp[K];
	return;
}
int main() {
	cin >> N >> K;
	bag.resize(N);
	for (int i = 0; i < N; ++i) {
		cin >> bag[i].first >> bag[i].second;
	}
	dynamic();
	return 0;
}