#include <iostream>
#include <vector>
#include <string>

using namespace std;
#define STRAT 123
#define END 987

// 문제의 정보를 가지는 구조체 생성
struct qurey {
	string numStr;	// 문제의 숫자
	int s;			// 스트라이크 수
	int b;			// 볼 수
};
int N;
vector<qurey> number;	// 구조체 벡터
int answer = 0;

// 용의자 검사 메서드 (중복, 0 검사)
bool isVal(int index) {
	// 숫자 중복 검사를 위한 0~9 숫자 배열
	bool dightChk[10] = { false };
	string s = to_string(index);

	for (char c : s) {
		int dight = c - '0';

		if (c == '0') return false;			// 문자중 0 이 있으면 사용 불가
		if (dightChk[dight]) return false;	// 중복된 문자가 있으면 사용 불가

		dightChk[dight] = true;				// 문자 방문 처리
	}
	return true;	// 사용 가능
}

void slove() {
	// 123 ~ 987 까지 용의자 검사
	for (int i = STRAT; i <= END; ++i) {
		if (!isVal(i)) {
			continue;
		}
		bool isOk = true;
		string cur = to_string(i);

		// 용의자 i를 4명의 후보와 비교
		for (int j = 0; j < N; ++j) {
			string str = number[j].numStr;
			int strike = number[j].s;
			int ball = number[j].b;

			// 현재 용의자와 입력값을 비교 스트라이크와 볼이 입력 값과 동일한지
			int cnt_s = 0, cnt_b = 0;
			for (int r = 0; r < 3; ++r) {
				for (int c = 0; c < 3; ++c) {
					if (cur[r] == str[c]) {
						if (r == c) cnt_s++;	// 인덱스까지 동일하면 = 스트라이크
						else cnt_b++;			// 인덱스는 다르면 = 볼
					}
				}
			}
			// 스트라이크와 볼의 수가 입력된 값과 다르면 용의자 제거
			if (cnt_s != strike || cnt_b != ball) {
				isOk = false;
				break;
			}
		}
		// 전부 맞을 시 정답 증가
		if (isOk == true) answer++;
	}
}

int main() {
	cin >> N;
	number.resize(N);
	for (int i = 0; i < N; ++i) {
		cin >> number[i].numStr >> number[i].s >> number[i].b;
	}
	slove();

	cout << answer;
	return 0;
}