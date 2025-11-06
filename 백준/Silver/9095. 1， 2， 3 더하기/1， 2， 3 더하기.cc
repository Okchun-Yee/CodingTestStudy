#include <iostream>
#include <vector>

using namespace std;
int T;

void slove(int n) {
	vector<int> dp(n + 1, 0);
	// 아무것도 더하지 않음 = 한가지
	dp[0] = 1;

	for (int i = 1; i <= n; ++i) {
		if (i - 1 >= 0) dp[i] += dp[i - 1];
		if (i - 2 >= 0) dp[i] += dp[i - 2];
		if (i - 3 >= 0) dp[i] += dp[i - 3];
	}
	cout << dp[n] << "\n";
}

int main() {
	cin >> T;
	vector<int> num(T);
	for (int i = 0; i < T; ++i)
		cin >> num[i];
	
	for (int n : num)
		slove(n);

	return 0;	
}