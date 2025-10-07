#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int L, C;
vector<char> a1;
vector<bool> visited;

// 모음 확인 함수
bool isVowel(char c) {
	return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

void slove(int idx, string s) {
	if (s.length() == L) {
		// 모음, 자음 개수 확인 변수
		int vowel = 0;
		int consonant = 0;

		// 모음, 자음 개수 조건 확인
		for (char c : s)
		{
			if (isVowel(c))
				vowel++;
			else
				consonant++;
		}
		if (vowel >= 1 && consonant >= 2) {
			cout << s << endl;
		}
		return;
	}
	// 반복문의 시작을 매개변수로 지정
	for (int i = idx; i < C; ++i) {
		// 방문 지점 생략
		if (visited[i]) 
			continue;
		// 방문 표시
		visited[i] = true;
		// 다음 문자 추가
		slove(i + 1, s + a1[i]);
		// 다음 재귀에서 사용하기 위해 방문 표시 제거
		visited[i] = false;
	}
}
int main() {
	cin >> L >> C;
	a1.assign(C, NULL);
	visited.assign(C, false);
	for (int i = 0; i < C; i++) {
		cin >> a1[i];
	}
	// 1) 문자 배열을 사전식 순서대로 정렬
	sort(a1.begin(), a1.end());

	slove(0, "");

	return 0;
}