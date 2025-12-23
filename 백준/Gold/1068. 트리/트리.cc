#include <iostream>
#include <vector>

using namespace std;

int N; int target;
vector<vector<int>> tree;
vector<bool> visited;

int dfs(int node) {
	visited[node] = true;

	int cnt = 0;
	int sum	 = 0;
	for (int next : tree[node]) {
		if (!visited[next] && next != target) {
			cnt++;
			sum += dfs(next);
		}
	}
	if (cnt == 0)
		return 1;

	return sum;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	tree.resize(N);
	visited.resize(N);
	int root = 0;
	for (int i = 0; i < N; ++i) {
		int n;
		cin >> n;
		
		if (n == -1) {
			root = i;
		}
		else {
			tree[i].push_back(n);
			tree[n].push_back(i);
		}
	}
	
	cin >> target;
	if (root == target) {
		cout << 0 << "\n";
	}
	else {
		cout << dfs(root) << "\n";
	}
}