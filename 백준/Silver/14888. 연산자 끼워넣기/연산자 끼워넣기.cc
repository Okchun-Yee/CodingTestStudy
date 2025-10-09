#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int N;					
vector<int> number;		// 숫자 배열
vector<char> operators;	// 연산자 배열
vector<bool> visited;	// 연산자 방문 처리 배열
	
long long maxN = -1000000001;
long long minN = 1000000001;

// 연산 함수
void calculate(const vector<char>& op) {
	// 시작 숫자는 숫자 배열의 첫 숫자
	long long cur = number[0];
	// N - 1 회 반복 (피연산자가 2개 이기에)
	for (int i = 0; i < N - 1; ++i) {
		if (op[i] == '+') cur += number[i + 1];
		else if (op[i] == '-') cur -= number[i + 1];
		else if (op[i] == '*') cur *= number[i + 1];
		else if (op[i] == '/') cur /= number[i + 1];
	}
	// 최댓값 최솟값 저장
	maxN = max(maxN, cur);
	minN = min(minN, cur);
}
void slove(int idx, vector<char>& op) {
	// 1) 종료 조건: 인덱스(탐색 LV)가 N - 1회 일때
	if (idx == N - 1) {
		// 연산자 연산 시작
		calculate(op);
		return;
	}
	for (int i = 0; i < N - 1; ++i) {
		// 2) 방문 검사
		if (visited[i]) continue;
		// 연산자가 이전 연산자와 똑같은데 이전 연산자를 방문하지 않을 시 생략 (중복 수열 방지)
		if (i > 0 && operators[i] == operators[i - 1] && !visited[i - 1])continue;
		// 3) 방문 처리 (백트래킹)
		visited[i] = true;			// 탐색 시작
		op[idx] = operators[i];		// 연산자를 연산자 배열에서 가져오기
		slove(idx + 1, op);			// 탐색 LV 증가
		visited[i] = false;			// 상태 원복
	}
}

int main() {
	cin >> N;
	number.assign(N, 0);
	visited.assign(N - 1, false);

	for (int i = 0; i < N; ++i) {
		cin >> number[i];
	}
	// 연산자 숫자를 입력 받아서 연산자 배열에 해당하는 연산자 추가하기
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
	// 탐색용 연산자 배열
	vector<char> op(N - 1);
	slove(0, op);

	cout << maxN << endl;
	cout << minN << endl;

	return 0;

}
