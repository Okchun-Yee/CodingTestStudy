#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int element[100001];

// 튜플 문제의 핵심 : 집합에 많이 등장한 순서가 튜플의 순서다.
vector<int> solution(string s) {
    vector<int> answer;
    
    int num = 0;
    
    // 문자열 파싱 = 숫자만
    for(char c : s){
        // 자릿수 맞추기 (구분자 등장전까지의 숫자는 전부 한 묶음)
        if(isdigit(c)) num = num * 10 + (c - '0');
        else if( num > 0){
            // 등장한 수 횟수 세기
            element[num]++;
            num = 0;
        }
    }
    
    // 횟수가 있는 숫자만 골라내기
    vector<pair<int, int>> v;
    for(int i = 0; i < 100001; i++){
        if(element[i] > 0) v.push_back({i, element[i]});
    }
    // 등장 횟수로 정렬
    sort(v.begin(), v.end(), [](auto& a, auto& b) {
        return a.second > b.second;
    });
    
    for(auto& p : v){
        answer.push_back(p.first);
    }
    
    return answer;
}