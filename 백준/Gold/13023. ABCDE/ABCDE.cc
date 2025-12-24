#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<vector<int>> v;
vector<bool> visited;
bool flag = false;
void dfs(int node, int depth) {
	if (flag) return;
	visited[node] = true;
	if (depth >= 4) {
		flag = true;
		return;
	}
	for (int next : v[node]) {
		if (!visited[next]) {
			dfs(next, depth + 1);
		}
	}
	visited[node] = false;
}
int main() {
	cin >> N >> M;
	v.resize(N);
	visited.resize(N);

	for (int i = 0; i < M; ++i) {
		int a, b; cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	for (int i = 0; i < N; ++i) {
		dfs(i, 0);
	}
	if (!flag) {
		cout << 0;
	}
	else {
		cout << 1;
	}
	return 0;
}