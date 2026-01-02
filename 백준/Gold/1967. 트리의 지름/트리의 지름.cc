#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<vector<pair<int, int>>> tree;
vector<bool> visited;

int n, answer;
void dfs(int node, int weight) {
	visited[node] = true;
	bool isLeaf = true;
	for (pair<int, int>& e : tree[node]) {
		int next = e.first;
		int w = e.second;
		if (!visited[next]) {
			isLeaf = false;
			dfs(next, weight + w);
		}
	}
	if (isLeaf) {
		answer = max(answer, weight);
	}
	visited[node] = false;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	tree.resize(n + 1);
	visited.assign(n + 1, false);
	
	tree.resize(n + 1);
	for (int i = 1; i < n; ++i) {
		int u, v, w;
		cin >> u >> v >> w;

		tree[u].push_back({ v, w });
		tree[v].push_back({ u, w });
	}
	for (int i = 1; i <= n; ++i) {
		dfs(i, 0);
	}
	cout << answer;
	return 0;
}		