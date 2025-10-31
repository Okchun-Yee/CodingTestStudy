#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
	int answer = 0;
	int cnt = 0;
	vector<bool> debt(n + 1, false);
	vector<bool> credit(n + 1, false);
	sort(lost.begin(), lost.end());
	sort(reserve.begin(), reserve.end());

	for (int i = 0; i < lost.size(); ++i)
		for (int j = 0; j < reserve.size(); ++j)
			if (lost[i] == reserve[j] && !credit[reserve[j]] && !debt[lost[i]]) {
				debt[lost[i]] = true;
				credit[reserve[j]] = true;
				cnt++;
			}

	for (int i = 0; i < lost.size(); ++i) {
		for (int j = 0; j < reserve.size(); ++j) {
			if (lost[i] - 1 == reserve[j] && !credit[reserve[j]] && !debt[lost[i]]) {
				debt[lost[i]] = true;
				credit[reserve[j]] = true;
				cnt++;
			}
			else if (lost[i] + 1 == reserve[j] && !credit[reserve[j]] && !debt[lost[i]]) {
				debt[lost[i]] = true;
				credit[reserve[j]] = true;
				cnt++;
			}
		}
	}
	answer = n - lost.size() + cnt;
	return answer;
}