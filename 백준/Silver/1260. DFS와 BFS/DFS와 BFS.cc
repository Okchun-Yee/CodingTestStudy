#include <iostream>
#include <vector>		// DFS
#include <queue>		// BFS
#include <algorithm>	//sort

using namespace std;

vector<bool> visited;				// 방문 검사 배열
vector<vector<int>> graph;			// 문제 입력 배열
vector<int> answer;					// 정답 출력 배열


void DFS(int current, int before) {
	// 1) 방문 처리
	visited[current] = true;
	// 2) 방문 노드 출력 (Index는 0부터 이기에 + 1 로 현재 정점 표시)
	cout << current << " ";
	// 3) 연결된 다음 노드 검사
	for (int next : graph[current]) {
		// 3-1) 다음 노드가 이전 노드면 생략
		if (next == before) {
			continue;
		}
		if (!visited[next]) {
			DFS(next, current);
		}
	}
}
void BFS(int start) {
	// 1) 시작 노드 추가, 방문 처리
	queue<int> q;		// BFS 용 Queue
	q.push(start);
	visited[start] = true;

	// 2) Queue가 빌 때 까지 반복
	while (!q.empty()) {
		// 1. front 꺼내기 = 방문
		int current = q.front();
		q.pop();
		cout << current << " ";

		// 2. 현재 정점과 연결된 다른 정점 확인
		for (int next : graph[current]) {
			// 3. 미방문 상태이면 방문 처리 후 push
			if (!visited[next]) {
				visited[next] = true;
				q.push(next);
			}
		}
	}
}

int main() {
	int v, e, startV;
	cin >> v >> e >> startV;
	
	graph.assign(v + 1, vector<int>());		// 정점의 수 만큼 배열을 만들기
	for (int i = 0; i < e; ++i) {
		int t1, t2;
		cin >> t1 >> t2;
		// 양방향 그래프 이기에 양쪽에 추가
		graph[t1].push_back(t2);
		graph[t2].push_back(t1);
	}
	for (int i = 1; i <= v; ++i) {
		sort(graph[i].begin(), graph[i].end());
	}

	visited.assign(v + 1, false);			// 방문 배열 fasle로 초기화
	DFS(startV , 0);
	cout << endl;

	visited.assign(v + 1, false);			// 방문 배열 fasle로 초기화
	BFS(startV);

	return 0;
}