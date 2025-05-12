#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
//#include "pros.h"

using namespace std;

struct Compare {
	bool operator()(const vector<int>& a, const vector<int>& b) {
		if (a[2] != b[2]) return a[2] > b[2];         // 소요 시간 짧은 게 우선
		if (a[1] != b[1]) return a[1] > b[1];         // 요청 시각 빠른 게 우선
		return a[0] > b[0];                           // 작업 번호 작은 게 우선
	}
};

int solution(vector<vector<int>> jobs) {
	int answer = 0;

	int jobSize = jobs.size();
	sort(jobs.begin(), jobs.end(), [](const vector<int>& a, const vector<int>& b) {
		if (a[0] == b[0])
			return a[1] > b[1];

		return a[0] > b[0];
		});
    priority_queue<vector<int>, vector<vector<int>>, Compare> stayQueue;
	int curTime = 0;
	int curWork = 0;
	int idx = 0;
	while (!stayQueue.empty() || !jobs.empty()) {
		// 1. 현재 시간에 도착한 작업들을 대기 큐에 삽입
		while (!jobs.empty() && jobs.back()[0] <= curTime) {
			// 작업 정보를 큐에 삽입 (vector<int> with index, start, duration)
			vector<int> entry = {
			idx++,
			jobs.back()[0],  // 요청시간
			jobs.back()[1]   // 작업시간
			};
			stayQueue.push(entry);
			jobs.erase(jobs.end() - 1);
		}

		// 2. 현재 작업이 없고 대기 큐에 작업이 있을 경우 → 하나 꺼내서 처리
		if (curWork == 0 && !stayQueue.empty()) {
			// stayQueue.top() 작업을 수행
			int reqTime = stayQueue.top()[1];
			int workTime = stayQueue.top()[2];

			answer += (curTime - reqTime) + workTime;
			curWork = workTime;
			stayQueue.pop();
		}

		// 3. 현재 작업이 없고, 큐도 비었고, 다음 작업은 미래에 있을 경우 → 시간 점프
		if (curWork == 0 && stayQueue.empty() && !jobs.empty()) {
			curTime = jobs.back()[0];  // 시간 점프
		}
		else {
			++curTime;  // 일반 시간 증가
		}

		// 4. 현재 작업이 진행 중이라면 남은 시간 감소
		if (curWork > 0) --curWork;
	}

	return answer / jobSize;
}
