#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
struct Info
{
	int start;
	int end;
};
int N;
vector<Info> info;

/*
* 1순위) 시작 시간 오름차순으로 정렬
* 2순위: 시작 시간이 동일) 종료 시간 오름차순으로 정렬
*/
bool compare(const Info& a, const Info& b) {
	if (a.start == b.start) return a.end < b.end;
	return a.start < b.start;
}
void slove() {
	// 우선순위 큐 (greater<int> : 오름차순으로 우선순위를 가짐 (작은 값이 높은 우선순위))
	priority_queue<int, vector<int>, greater<int>> pq;
	for (int i = 0; i < N; ++i) {
		int start = info[i].start;
		int end = info[i].end;

		// 1. 시작 (큐 공백)의 경우 강의실 생성
		if (pq.empty()) {
			pq.push(end);
		}
		else {
			// 2. 다음 강의 시작 시간이 현재 강의 종료 시간 이상인 경우 같은 강의실 사용
			int cur = pq.top();
			if (start >= cur) {
				pq.pop();
				pq.push(end);
			}
			// 3. 아닌 경우 다른 강의실 추가
			else {
				pq.push(end);
			}
		}
	}
	cout << pq.size();
	return;
}

int main() {
	cin >> N;
	info.resize(N);
	for (int i = 0; i < N; ++i) {
		cin >> info[i].start >> info[i].end;
	}
	// 정렬
	sort(info.begin(), info.end(), compare);
	slove();

	return 0;
}