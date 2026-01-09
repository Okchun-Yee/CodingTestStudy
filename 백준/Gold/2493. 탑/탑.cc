#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int N;
stack<pair<int, int>> st;	// { index, input }
vector<int> v;

// 단조 스택
// 스택을 항상 수열을 유지하게 만드는 알고리즘
// 입력 값보다 (크거나, 작은) 원소들을 스택에서 pop()
void slove() {
	stack<pair<int, int>> st;
	for (int i = 0; i < N; ++i) {
		int cur = v[i];
		while (!st.empty() && st.top().second < cur) {
			st.pop();
		}
		if (st.empty())
			cout << 0 << " ";
		else
			cout << st.top().first + 1 << " ";

		st.push({ i, cur });
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	v.resize(N);
	for (int i = 0; i < N; ++i) {
		cin >> v[i];
	}
	slove();
}