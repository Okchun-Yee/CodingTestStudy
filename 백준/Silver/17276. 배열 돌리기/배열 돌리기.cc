#include <iostream>
#include <vector>


using namespace std;

int T;

void slove(vector<vector<int>> prev, int angle, int n) {
	vector<vector<int>> curv;
	curv = prev;

	bool flag = false;
	if (angle > 0) flag = false;	// 시계
	else flag = true;				// 반시계

	for (int k = 0; k < abs(angle) / 45; ++k) {
		if (flag) {
			for (int i = 0; i < n; ++i) {
				curv[i][i] = prev[i][n / 2];
				curv[n / 2][i] = prev[i][i];
				curv[n - i - 1][i] = prev[n / 2][i];
				curv[n-i-1][n / 2] = prev[n - i - 1][i];
			}
		}
		else {
			for (int i = 0; i < n; ++i) {
				curv[i][i] = prev[n / 2][i];
				curv[n / 2][i] = prev[n - i - 1][i];
				curv[i][n-i-1] = prev[i][n / 2];
				curv[i][n / 2] = prev[i][i];
			}
		}
		prev = curv;
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cout << curv[i][j] << " ";
		}
		cout << "\n";
	}
	//cout << "================================================================\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> T;
	int n, d;
	vector<vector<int>> v;

	for (int k = 0; k < T; ++k) {
		cin >> n >> d;
		v.assign(n, vector<int>(n));
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				cin >> v[i][j];
			}
		}
		//cout << "================================================================\n";
;		slove(v, d, n);
	}
	return 0;
}