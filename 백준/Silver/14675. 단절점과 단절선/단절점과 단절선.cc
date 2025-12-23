#include <iostream>
#include <vector>

using namespace std;

int N, q;
vector<vector<int>> tree;

void slove(int node) {
	if (tree[node].size() == 1) {
		cout << "no\n";
	}
	else {
		cout << "yes\n";
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	tree.resize(N + 1);

	for (int i = 0; i < N-1; ++i) {
		int t, k;
		cin >> t >> k;
		tree[t].push_back(k);
		tree[k].push_back(t);
	}

	cin >> q;
	for (int i = 0; i < q; ++i) {
		int t, k;
		cin >> t >> k;
		
		if (t == 1) {
			slove(k);
		}
		else {
			cout << "yes\n";
		}
	}
}