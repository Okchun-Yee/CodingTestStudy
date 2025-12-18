#include <queue>
#include <vector>
#include <iostream>

using namespace std;

#define MAX 100001
int N, K;
vector<int> dist(MAX, -1);
queue<int> q;

void bfs(int start) {
	dist[start] = 0;
	q.push(start);
	while (!q.empty())
	{
		int cur = q.front();
		q.pop();

		if (cur == K) return;

		int moveNext[] = { cur - 1, cur + 1, cur * 2 };
		for (int next : moveNext) {
			if (next >= 0 && next < MAX && dist[next] == -1) {
				dist[next] = dist[cur] + 1;
				q.push(next);
			}
		}
	}
}
int main() {
	cin >> N >> K;
	bfs(N);

	cout << dist[K];
	return 0;
}