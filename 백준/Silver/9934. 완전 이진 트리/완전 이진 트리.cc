#include <iostream>
#include <vector>

using namespace std;

int K, SIZE;
vector<int> node;
vector<int> tree;

int index = 0;
// 중위 순회 입력값 -> 완전 이진 트리 제작 헬퍼
void makeTree(int idx) {
	if (idx > SIZE) return;
	makeTree(idx * 2);
	tree[idx] = node[index++];
	makeTree(idx * 2 + 1);
}
// 레벨에 따라서 엔터
void solution() {
	int idxEnter = 1;
	for (int i = 1; i < SIZE + 1; ++i) {
		cout << tree[i] << " ";
		if (i == idxEnter) {
			cout << "\n";
			idxEnter = i * 2 + 1;
		}
	}
}
int main() {
	cin >> K;
	SIZE = (1 << K) - 1;	//2^K -1
	node.resize(SIZE);
	tree.resize(SIZE + 1);
	for (int i = 0; i < SIZE; ++i) {
		cin >> node[i];
	}
	makeTree(1);
	solution();
	return 0;
}