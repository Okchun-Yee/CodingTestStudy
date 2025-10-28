#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>

using namespace std;
int V, E, K;
vector<vector<pair<int, int>>> graph;	// 인접 리스트

const long long LL_INF = LONG_MAX;
const int INT_INF = INT_MAX;

void dijkstra(int startNode) {
	priority_queue<pair<int, int>> pq;		// 우선 순위 큐 { w, v } 
	vector<long long> dist(V + 1, LL_INF);

	pq.push({0, startNode});
	dist[startNode] = 0;

	while (!pq.empty())
	{
		/* priority_queue는 MAX-Heap을 사용하기 떄문에 가중치가 큰 순서, 이를 이용해서 음수를 저장하면 양수일때 작은 수가 
		음수인 경우에서는 가장 크기에 음수로 우선 순위 큐에 저장*/

		long long cur_dist = pq.top().first * -1;	// 가중치가 가장 짧은 노드 (가중치 정렬이 음수기에 다시 양수로)
		int u = pq.top().second;
		pq.pop();

		if (cur_dist > dist[u])	// 더 짧은 경로가 저장된 경우 생략
			continue;

		for (const auto& edge : graph[u]) {
			int v = edge.first;
			int w = edge.second;

			if (dist[u] + w < dist[v]) {
				dist[v] = dist[u] + w;
				pq.push({ dist[v] * -1, v });	// 가중치가 작아야 우선순위가 높으니 음수로 저장
			}
		}
	}
	for (int i = 1; i < V + 1; ++i) {
		if (i == startNode) cout << 0 << "\n";
		else if (dist[i] == LL_INF) cout << "INF\n";
		else cout << dist[i] << "\n";
	}
	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> V >> E >> K;

	graph.resize(V + 1);
	for (int i = 0; i < E; ++i) {
		int u, v, w;
		cin >> u >> v >> w;

		graph[u].push_back({ v, w });
	}
	dijkstra(K);
	return 0;
}