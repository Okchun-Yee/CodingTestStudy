#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<vector<int>> tree;
vector<bool> visited;
vector<int> answer;

// 기본 DFS 탐색
void DFS(int now, int before) {
	// 현재 노드 (자식) 방문 체크
	visited[now] = true;
	// * 자식 노드를 Index로 사용 하는 배열에 부모 노드 삽입
	answer[now] = before;
	// 다음 노드 탐색 (기본 DFS)
	for (int next : tree[now]) {
		if (next == before)
			continue;
		if (!visited[next])
			DFS(next, now);
	}
}
int main() {
	cin >> N;
	tree.assign(N + 1, vector<int>());
	answer.assign(N + 1, 0);
	// 양방향 간선 만들기
	for (int i = 0; i < N - 1; ++i) {
		int a1, a2;
		cin >> a1 >> a2;
		tree[a1].push_back(a2);
		tree[a2].push_back(a1);
	}
	visited.assign(N + 1, false);
	DFS(1, 0);

	// 백터의 초기화를 0으로 하였기에 0 == 1번 & 0번 노드 이기에 출력 생략
	for (int i : answer) {
		if(i != 0)
			cout << i<< "\n";
	}
}