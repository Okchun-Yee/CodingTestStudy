#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int expand(const string& s, int left, int right){
    while(left>= 0 && right < s.size() && s[left] == s[right]){
        left--;
        right++;
    }
    return (right - left) - 1;
}
int solution(string s)
{
    int answer =  0;
    
    for(int i = 0; i < s.size(); i++){
        answer = max(answer, expand(s, i, i));
        answer = max(answer, expand(s, i, i+1));
    }
    return answer;
}