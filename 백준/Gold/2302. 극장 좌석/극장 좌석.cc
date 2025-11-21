#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX_SIZE 41
int N, M;
int answer = 1;
vector<int> vip;

void slove() {
	if (N == M) {
		cout << 1;
		return;
	}
	vector<int>dp(MAX_SIZE);
	dp[0] = 1; dp[1] = 1; dp[2] = 2;

	for (int i = 3; i < N + 1; ++i) {
		// N까지의 피보나치 수열 구해두기
		dp[i] = dp[i - 1] + dp[i - 2];
	}

	// * 각 VIP 사이의 일반 좌석의 길이를 구하기
	// * 각 길이 마다 존재하는 경우의 수를 곱하기
	// * `End - Start - 1` 수식으로 각 vip 사이의 일반좌석의 길이 구하기
	int start = 0;
	for (int i = 0; i < M + 1; ++i) {
		int end = vip[i];
		answer = answer * dp[end - start - 1];
		start = end;
	}
	cout << answer;
}
int main() {
	cin >> N >> M;
	vip.resize(M+1);
	for (int i = 0; i < M; ++i) {
		cin >> vip[i];
	}
	// 제일 마지막 자리 + 1을 vip로 설정
	vip[M] = N + 1;
	slove();
}