#include <iostream>
#include <string>
#include <map>
using namespace std;

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
int solution(string word) {
    int answer = 0;
    int w[] = { 781, 156, 31, 6, 1 };  // 5진법 자릿값 배열
    // 각 알파벳에 숫자 매핑
    map<char, int> alphabet;
    alphabet['A'] = 0;
    alphabet['E'] = 1;
    alphabet['I'] = 2;
    alphabet['O'] = 3;
    alphabet['U'] = 4;

    for (int i = 0; i < word.length(); ++i) {
        answer += (alphabet[word[i]] * w[i]);
    }
    answer += word.length();
    return answer;
}