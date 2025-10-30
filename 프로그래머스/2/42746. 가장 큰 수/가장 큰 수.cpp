#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(int a, int b) {
    string s1 = to_string(a) + to_string(b);
    string s2 = to_string(b) + to_string(a);

    // s1 > s2 이면 a가 b 앞으로 와야함
    return s1 > s2;
}
string solution(vector<int> numbers) {
    string answer = "";
    // * 버블 정렬 = O(N^2) 대신
    // * O(N log N) sort 정렬 사용
    sort(numbers.begin(), numbers.end(), compare);

    for (int n : numbers) {
        answer += to_string(n);
    }
    if (answer[0] == '0') {
        return "0";
    }
    return answer;
}