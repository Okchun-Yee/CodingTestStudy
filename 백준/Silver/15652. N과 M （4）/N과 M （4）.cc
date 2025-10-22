#include <iostream>
#include <vector>

using namespace std;
#define MAX 8

int N, M;
vector<int> list;
vector<int> answer;

void slove(int level, int start) {
	if (level == M) {
		for (int n : answer)
			cout << n << " ";
		cout << "\n";
		return;
	}
	
	for (int k = start; k <= N; ++k) {
		answer.push_back(k);	// Do
		slove(level + 1, k );		// Recurse
		answer.pop_back();		// Undo
	}
}
int main() {
	cin >> N >> M;

	list.resize(N);
	for (int i = 0; i < N; ++i) {
		list[i] = i + 1;
	}
	slove(0, 1);
	return 0;
}