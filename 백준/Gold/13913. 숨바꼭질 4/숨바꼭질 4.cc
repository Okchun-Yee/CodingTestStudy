#include <iostream>
#include <vector>
#include <queue>
#include <algorithm> // reverse

using namespace std;

#define MAX 100001
int N, K;
vector<int> dist(MAX, -1);
vector<int>path(MAX, 0);
queue<int> q;

/// <summary>
/// 최단거리 역추적
/// * BFS 탐색 + 경로를 저장하는 배열 추가
/// * N -> K 까지 경로를 저장
/// * BFS 종료 후 K -> N 까지 경로를 출력
/// * 경로 저장 방법 = 자식 노드 위치에 부모 노드를 저장
/// </summary>
void BFS(int start) {
	// 0) 시작 위치 삽입
	dist[start] = 0;
	q.push(start);

	while (!q.empty())
	{
		int current = q.front();
		q.pop();

		if (current == K) {
			return;
		}
		// 1) -1, +1, *2 위치 이동
		int moveNext[] = { current - 1, current + 1, current *2 };
		for (int next : moveNext) {
			// 제약 조건 0보다 커야하고 && MAX 보다 작아야하고 && 방문한적 없어야함
			if (next >= 0 && next < MAX && dist[next] == -1) {
				dist[next] = dist[current] + 1;	// 탐색 Level + 1
				path[next] = current;			// 자식 노드 위치에 부모노드 저장
				q.push(next);					// 다음 탐색
			}
		}
	}
}

int main() {
	cin >> N >> K;

	BFS(N);
	cout << dist[K] << endl;

	vector<int> tracking;
	int current = K;

	while (current!=N)
	{
		tracking.push_back(current);	// K -> N 까지 부모노드 저장 (경로)
		current = path[current];		// 다음 탐색
	}
	tracking.push_back(N);				// 마지막 위치 N 삽입
	reverse(tracking.begin(), tracking.end());	// K -> N 으로 저장하였기에 N -> K 순서로 출력을 위해 뒤집기

	for (int i : tracking)
		cout << i << " ";
	return 0;
}