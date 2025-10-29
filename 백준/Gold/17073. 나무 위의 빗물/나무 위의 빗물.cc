#include <iostream>
#include <vector>
#include <iomanip>
#include <map>

using namespace std;
int N, W;
vector<vector<int>> tree;
void slove(int startNode) {
	int cnt = 0;
	int left = 0;
	for (int i = startNode; i <= N; ++i) {
		cnt = 0;
		for (int n : tree[i]) {
			cnt++;
		}
		// 현재 노드가 1(root)이 아니고 간선의 수가 1개 = leftNode
		if (i != 1 && cnt == 1) {
			left++;
		}
	}
	double answer = (double)W / left;
	cout << fixed << answer;
}
int main() {
	cin >> N >> W;
	tree.assign(N + 1, vector<int>());

	for (int i = 0; i < N - 1; ++i) {
		int u, v;
		cin >> u >> v;
		// 인접 리스트 (양방향 간선)
		tree[u].push_back(v);
		tree[v].push_back(u);
	}
	slove(1);
	return 0;
}