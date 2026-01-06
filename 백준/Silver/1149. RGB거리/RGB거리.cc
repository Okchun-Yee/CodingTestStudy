#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<vector<int>> v;
vector<int> r;
vector<int> g;
vector<int> b;

void slove() {
	v[1][0] = r[1];
	v[1][1] = g[1];
	v[1][2] = b[1];

	for (int i = 1; i < N + 1; ++i) {
		v[i][0] = min(v[i - 1][1], v[i - 1][2]) + r[i];
		v[i][1] = min(v[i - 1][0], v[i - 1][2]) + g[i];
		v[i][2] = min(v[i - 1][0], v[i - 1][1]) + b[i];
	}
	cout << min(v[N][0], min(v[N][1], v[N][2]));
}

int main() {
	cin >> N;
	v.assign(N + 1, vector<int>(3));
	r.resize(N + 1);
	g.resize(N + 1);
	b.resize(N + 1);

	for (int i = 1; i < N + 1; ++i) {
		cin >> r[i] >> g[i] >> b[i];
	}
	slove();
	return 0;
}