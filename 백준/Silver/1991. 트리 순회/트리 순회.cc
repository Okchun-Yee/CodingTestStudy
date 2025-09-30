#include <iostream>
#include <vector>
#include <map>
#include <utility> // pair 사용을 위해 필요

using namespace std;

map <char, pair<char, char>> tree;

void Preorder(char node) {
	cout << node;
	if (tree[node].first != '.') {
		Preorder(tree[node].first);
	}
	if (tree[node].second != '.') {
		Preorder(tree[node].second);
	}
}
void Inorder(char node) {
	if (tree[node].first != '.') {
		Inorder(tree[node].first);
	}
	cout << node;
	if (tree[node].second != '.') {
		Inorder(tree[node].second);
	}
}
void Postorder(char node) {
	if (tree[node].first != '.') {
		Postorder(tree[node].first);
	}
	if (tree[node].second != '.') {
		Postorder(tree[node].second);
	}
	cout << node;
}

int main() {
	// N : 노드 개수
	int N = 0;
	// 0 < N <= 26 범위 지정
	cin >> N;

	for (int i = 0; i < N; i++) {
		char p, left, right;
		cin >> p >> left >> right;
		tree[p] = { left, right };
	}
	Preorder('A'); cout << endl;
	Inorder('A'); cout << endl;
	Postorder('A');
	return 0;
}