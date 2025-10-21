#include <iostream>
#include <vector>

using namespace std;
#define MAX 8

int N, M;
vector<int> list;
vector<int> answer;
vector<bool> visited(MAX);

void slove(int level) {
	if (level == M) {
		for (int n : answer)
			cout << n << " ";
		cout << "\n";
		return;
	}
	
	for (int k = 1; k <= N; ++k) {
		if (visited[k]) continue;

		answer.push_back(k);
		visited[k] = true;
		slove(level + 1);
		visited[k] = false;
		answer.pop_back();
	}
}
int main() {
	cin >> N >> M;

	list.resize(N);
	for (int i = 0; i < N; ++i) {
		list[i] = i + 1;
	}
	slove(0);
	return 0;
}