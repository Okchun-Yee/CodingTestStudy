#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;
int N, Q;
vector<vector<pair<int, int>>> graph;
vector<bool> visited;
int cnt = 0;

void DFS(int cur,int limit) {
	visited[cur] = true;
	for (int i = 0;i < graph[cur].size();i++) {
		pair<int, int> edge = graph[cur][i];
		int next = edge.first;
		int usado = edge.second;

		if (!visited[next] && usado >= limit) {
			cnt++;
			DFS(next, limit);
		}
	}
}

int main(void) {
	cin >> N >> Q;
	graph.assign(N + 1, vector<pair<int, int>>());

	//간선 입력
	for (int i = 0;i < N - 1;i++) {
		int p, q, r;
		cin >> p >> q >> r;
		graph[p].push_back({ q, r });
		graph[q].push_back({ p, r });
	}

	vector<pair<int, int>> queries;
	for (int i = 0;i < Q;i++) {
		int k, v;
		cin >> k >> v;
		queries.push_back({ k, v });
	}

	// ✅ 쿼리 계산은 나중에 한 번에
	for (const auto& query : queries) {
		int k = query.first;
		int v = query.second;
		cnt = 0;
		visited.assign(N + 1, false);
		DFS(v, k);
		cout << cnt << "\n";
	}
	return 0;
}