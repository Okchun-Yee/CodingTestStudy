#include <iostream>
#include <vector>
#include <string>
#include <climits>

using namespace std;

int T;

void slove(string s, int k) {
	vector<int> p[26];
	for (int i = 0; i < s.length(); ++i) {
		p[s[i] - 'a'].push_back(i);
	}
	int minL = INT_MAX;
	int maxL = -1;
	for (int i = 0; i < 26; ++i) {
		if (p[i].size() < k)
			continue;
		for (int j = 0; j < p[i].size() - k + 1; ++j) {
			int l = p[i][j + k - 1] - p[i][j] + 1;

			if (l < minL)
				minL = min(l, minL);
			if (l > maxL)
				maxL = max(l, maxL);
		}
	}
	if (minL != INT_MAX && maxL != -1)
		cout << minL << " " << maxL << "\n";
	else
		cout << -1 << "\n";
}
int main() {
	cin >> T;
	for (int i = 0; i < T; ++i) {
		string s; int K;
		cin >> s >> K;

		slove(s, K);
	}
}