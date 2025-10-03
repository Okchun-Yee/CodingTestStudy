#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, K; // 컴퓨터 수, 연결된 컴퓨터 수
vector<vector<int>> computers;	// 문제 배열
vector<bool> visited;			// 방문 배열

int answer = 0;					// 정답 변수

void DFS(int current, int before) {
	visited[current] = true;
	//cout << current << " ";

	for (int next : computers[current]) {
		if (next == before)
			continue;
		else if (visited[next] != true) {
			answer++;
			DFS(next, current);
		}
	}
}

int main() {
	cin >> N >> K;
	computers.assign(N+1, vector<int>());
	visited.assign(N + 1, false);
	for (int i = 0; i < K; i++) {
		int a1, a2;
		cin >> a1 >> a2;
		// 양방향으로 간선 추가
		computers[a1].push_back(a2);
		computers[a2].push_back(a1);
	}
	DFS(1, 0);
	cout << answer;
	return 0;
}