#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, K;
vector<vector<int>> v;

vector<vector<int>> dist;

void BFS(int startNode) {
	queue<int> q;
	// BFS 마다 방문 배열을 초기화
	vector<bool> visited(N + 1, false);
	q.push(startNode);
	visited[startNode] = true;
	dist[startNode][startNode] = 0;

	while (!q.empty()) {
		int current = q.front();
		q.pop();

		for (int next : v[current]) {
			if (!visited[next]) {
				q.push(next);
				visited[next] = true;
				dist[startNode][next] = dist[startNode][current] + 1;
			}
		}
	}

}
int main() {
	cin >> N >> K;
	v.resize(N + 1);
	dist.assign(N + 1, vector<int>(N + 1, -1));

	for (int i = 0; i < K; ++i) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	// 1 ~ N까지 모든 노드 탐색
	for (int i = 1; i < N + 1; ++i) {
		BFS(i);
	}

	// 간선수가 6이 넘거나, 이어지지않은 간선이 있으면 "넓은 세상"으로 판단
	bool flag = false;
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			if (dist[i][j] == -1 || dist [i][j] > 6) {
				flag = true;
			}
		}
	}
	if (!flag) cout << "Small World!";
	else cout << "Big World!";
	return 0;
}