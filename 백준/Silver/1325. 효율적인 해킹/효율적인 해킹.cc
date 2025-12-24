#include <iostream>
#include <vector>
#include <algorithm>

#define SIZE 10000

using namespace std;
int N, M, MAX;
vector<vector<int>> gragh;
vector<bool>visited;

int dfs(int node) {
	visited[node] = true;
	int size = 1;
	for (int next : gragh[node]) {
		if (!visited[next]) {
			size += dfs(next);
		}
	}
	MAX = max(MAX, size);
	return size;
}
int main() {
	cin >> N >> M;
	gragh.resize(N + 1);
	
	for (int i = 0; i < M; ++i) {
		int u, v;
		cin >> u >> v;

		gragh[v].push_back(u);
	}
	vector<int>answer(N+1);
	for (int i = 1; i <= N; ++i) {
		visited.assign(N + 1, false);
		answer[i] = dfs(i);
	}
	for (int i = 1; i <= N; ++i) {
		if (answer[i] >= MAX) {
			cout << i << " ";
		}
	}
	return 0;
}