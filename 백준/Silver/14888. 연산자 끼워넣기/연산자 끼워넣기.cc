#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int N;
vector<int> number;
vector<char> operators;
vector<bool> visited;
	
long long maxN = -1000000001;
long long minN = 1000000001;

// 연산 함수
void calculate(const vector<char>& op) {
	long long cur = number[0];
	for (int i = 0; i < N - 1; ++i) {
		if (op[i] == '+') cur += number[i + 1];
		else if (op[i] == '-') cur -= number[i + 1];
		else if (op[i] == '*') cur *= number[i + 1];
		else if (op[i] == '/') cur /= number[i + 1];
	}
	maxN = max(maxN, cur);
	minN = min(minN, cur);
}
void slove(int idx, vector<char>& op) {
	if (idx == N - 1) {
		calculate(op);
		return;
	}
	for (int i = 0; i < N - 1; ++i) {
		if (visited[i]) continue;
		if (i > 0 && operators[i] == operators[i - 1] && !visited[i - 1])continue;

		visited[i] = true;
		op[idx] = operators[i];
		slove(idx + 1, op);
		visited[i] = false;
	}
}

int main() {
	cin >> N;
	number.assign(N, 0);
	visited.assign(N - 1, false);

	for (int i = 0; i < N; ++i) {
		cin >> number[i];
	}
	for (int i = 0; i < 4; ++i) {
		int a;
		cin >> a;
		for (int j = 0; j < a; ++j) {
			if (i == 0) operators.push_back('+');
			else if (i == 1) operators.push_back('-');
			else if (i == 2) operators.push_back('*');
			else operators.push_back('/');
		}
	}
	// 중복 순열을 올바르게 처리하기 위해 정렬이 필수
	sort(operators.begin(), operators.end());

	vector<char> op(N - 1);
	slove(0, op);

	cout << maxN << endl;
	cout << minN << endl;

	return 0;
}