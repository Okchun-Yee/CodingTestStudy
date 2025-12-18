#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>

// 왠지 오늘따라 네임스페이스 쓰기가 싫네
int N;
std::vector<int> v;
void slove() {
	std::queue<int> q;
	for (int i = 0; i < v.size(); ++i) {
		q.push(v[i]);
	}
	int maxN = 0;
	while (!q.empty())
	{
		int r = q.front() * q.size();
		maxN = std::max(maxN, r);
		q.pop();
	}
	std::cout << maxN;
}

int main() {
	std::cin >> N;
	for (int i = 0; i < N; ++i) {
		int n; std::cin >> n;
		v.push_back(n);
	}
	sort(v.begin(), v.end());
	slove();
}