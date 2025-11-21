#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int len = 0;
int solution(string name) {
    int answer = 0;
    // 알파벳 배열
    vector<char> alphabet = {
    'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
    'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'
    };
    // 1. 문자열의 각 자리수의 인덱스를 찾기
    // 2. A에서 올라가는 경우와 Z 에서 내려오는 경우를 비교
    // 3. 둘 중 최소값을 해당 알파벳의 값으로 사용
    for (char c : name) {
        auto it = find(alphabet.begin(), alphabet.end(), c);
        answer += min(it - alphabet.begin(), alphabet.end() - it);
    }

    // 이동 횟수 계산하기
    // Basecase = 문자열 길이 - 1 (A로 인한 유턴이 없는 경우)
    int len = name.length() - 1;
    int n = name.length();
    for (int i = 0; i < n; ++i) {
        int next = i + 1;
        // 현재 위치 부터 끝까지 A의 개수를 구하기
        while (next < n && name[next] == 'A')
        {
            next++;
        }
        // 1. 오른쪽 진행 중 유턴하는 경우
        // * 시작점 부터 i까지 갔다가 유턴: i*2
        // * 끝점 부터 'A' 위치 까지 가는 값: len - next
        len = min(len, i * 2 + n - next);

        // 2. 왼쪽 진행 중 유턴하는 경우 
        // * 시작점에서 'A' 위치 까지 뒤로 갔다가 유턴: len-next
        // * 시작점에서 i 위치까지 이동
        len = min(len, (n - next) * 2 + i);
    }
    cout << answer << " " << len;
    return answer + len;
}