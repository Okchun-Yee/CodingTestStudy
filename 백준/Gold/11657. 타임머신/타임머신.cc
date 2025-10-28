#include <iostream>
#include <vector>
#include <climits>
#include <queue>
#include <algorithm>

using namespace std;

// dist(long long)용과 graph(int)용 INF
const long long LL_INF = LONG_MAX;
const int INT_INF = INT_MAX;

int N, M;
vector<vector<int>> graph;


void BFS(int startNode) {
	queue<int> q;							// BFS용 큐
	vector<long long> dist(N + 1, LL_INF);	// 최단거리 간선의 정보를 저장하기 위한 vec
	vector<bool> visited(N + 1, false);		// 해당 노드의 방문여부 검사 vec
	vector<int> count(N + 1, 0);			// 음수가 나온 횟수 카운트 vec

	q.push(startNode);
	dist[startNode] = 0;			// 거리 = 0
	visited[startNode] = true;		// 방문 표시
	count[startNode] = 1;			// 음수 카운트 = 1부터

	while (!q.empty()) {
		int u = q.front();
		q.pop();				// que 에서 제거
		visited[u] = false;		// 큐에 방문 철회

		for (int v = 1; v < N + 1; ++v) {
			int w = graph[u][v];
			if (w == INT_INF)		// w == INT_MAX 는 간선이 존재하지 않는다. (생략)
				continue;

			if (dist[u] == LL_INF)		// u 가 도달 불가면 생략
				continue;

			if (dist[u] + w < dist[v]) {		// 거리가 더 짧은 간선이 존재할 때 실행
				dist[v] = dist[u] + w;			// 최단 거리 업데이트
				if (!visited[v]) {
					q.push(v);
					visited[v] = true;
					count[v]++;
					if (count[v] >= N) {		// 음수 사이클 음수의 수가 >= N
						cout << -1 << "\n";
						return;
					}
				}
			}
		}
	}
	for (int i = 2; i <= N; ++i) {
		if (dist[i] == LL_INF)		// 거리 배열에 INT_MAX가 존재 = 도달 불가능
			cout << -1 << "\n";
		else
			cout << dist[i] << "\n";
	}
}
int main() {
	// 입출력
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;
	graph.assign(N + 1, vector<int>(N + 1, INT_INF));

	for (int i = 0; i < M; ++i) {
		int u, v, w;
		cin >> u >> v >> w;
		graph[u][v] = min(graph[u][v], w);		// 중복간선인 경우 최솟값 저장
	}
	BFS(1);
	return 0;
}