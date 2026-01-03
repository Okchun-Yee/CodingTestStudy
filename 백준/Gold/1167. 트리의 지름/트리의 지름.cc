#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<vector<pair<int, int>>> tree;
vector<bool> visited;

int n, answer;
int dist, maxNode;

void dfs(int node, int weight) {
	visited[node] = true;
	if (weight > dist) {
		dist = weight;
		maxNode = node;
	}
	for (pair<int, int>& e : tree[node]) {
		int next = e.first;
		int w = e.second;
		if (!visited[next]) {
			dfs(next, weight + w);
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	tree.resize(n + 1);

	tree.resize(n + 1);
	for (int i = 1; i <= n; ++i) {
		int u;
		cin >> u;
		while (true) {
			int v, w;
			cin >> v; 
			if (v == -1) break;

			cin >> w;

			tree[u].push_back({ v, w });
		}

	}
	visited.assign(n + 1, false);
	dist = 0;
	dfs(1, 0);

	visited.assign(n + 1, false);
	dist = 0;
	dfs(maxNode, 0);

	cout << dist;
	return 0;
}