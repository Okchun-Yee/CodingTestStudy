#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>

using namespace std;

int n, m;
int START, END;
const int INT_INF = INT_MAX;

vector<vector<pair<int, int>>> graph;	// 인접 리스트
void dijkstra(int start_u) {
	vector<int> dist(n + 1, INT_INF);	// 최단 거리 배열
	vector<int> parent(n + 1, -1);		// 역추적 배열: -1로 초기화 하여 첫 위치까지 추적
	vector<int> answer;					// 정답 배열
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;		// { w, v }

	pq.push({ 0, start_u });
	dist[start_u] = 0;

	while (!pq.empty())
	{
		int current = pq.top().first;			// 시작 - u 까지 w합
		int u = pq.top().second;				// 현재 처리할 노드
		pq.pop();
		if (current > dist[u]) {
			continue;
		}
		for (const auto& edge : graph[u]) {
			int v = edge.first;
			int w = edge.second;

			if (dist[u] + w < dist[v]) {
				dist[v] = dist[u] + w;
				parent[v] = u;				// 최단 거리 갱신 마다 부모 노드 기록
				pq.push({ dist[v], v });
			}
		}
	}
	int current = END;
	while (current != -1)
	{
		answer.push_back(current);
		current = parent[current];
	}
	reverse(answer.begin(), answer.end());		// 역추적이니까 역순으로 저장되어있음
	cout << dist[END] << "\n";
	cout <<  answer.size()<< "\n";
	for (int n : answer)
		cout << n << " ";
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	graph.resize(n + 1);
	for (int i = 0; i < m; ++i) {
		int u, v, w;
		cin >> u >> v >> w;

		graph[u].push_back({v, w});
	}
	cin >> START >> END;
	dijkstra(START);
	return 0;
}
