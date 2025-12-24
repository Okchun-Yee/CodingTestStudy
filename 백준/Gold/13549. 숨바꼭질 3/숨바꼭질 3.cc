#include <iostream>
#include <vector>
#include <deque>
#include <algorithm> // reverse

using namespace std;

#define MAX 100001
int N, K;
vector<int> dist(MAX, -1);
deque<int> q;

void BFS(int start) {
	// 0) 시작 위치 삽입
	dist[start] = 0;
	q.push_back(start);

	while (!q.empty())
	{
		int current = q.front();
		q.pop_front();

		if (current == K) {
			return;
		}
		
		int nextPos = current * 2;
		if (nextPos >= 0 && nextPos < MAX && dist[nextPos] == -1) {
			dist[nextPos] = dist[current];
			q.push_front(nextPos);
		}
		int moveNext[] = { current - 1, current + 1};
		for (int next : moveNext) {
			if (next >= 0 && next < MAX && dist[next] == -1) {
				dist[next] = dist[current] + 1;	// 탐색 Level + 1
				q.push_back(next);					// 다음 탐색
			}
		}
	}
}

int main() {
	cin >> N >> K;

	BFS(N);
	cout << dist[K] << endl;
	return 0;
}