#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<int> arr;
bool visited[9] = { false };
vector<int> answer;

void slove(int level) {
	if (level == M) {
		for (int n : answer) {
			cout << n << " ";
		}
		cout << "\n";
		return;
	}
	for (int i = 0; i < N; ++i) {
		if (visited[i])
			continue;
		// D0 - 정답 배열에 추가
		answer.push_back(arr[i]);
		visited[i] = true;
		// Next - 다음 탐색
		slove(level + 1);
		// Back - 상태 복구 (정답 배열에서 제거, 방문 해제)
		answer.pop_back();
		visited[i] = false;
	}
}
int main() {
	cin >> N >> M;
	arr.resize(N);
	for (int i = 0; i < N; ++i) {
		cin >> arr[i];
	}
	// 사전순이기에 미리 오름차순으로 정렬해두기
	sort(arr.begin(), arr.end());
	slove(0);
	return 0;
}