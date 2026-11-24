#include <iostream>
#include <string>
#include <stack>

using namespace std;

int solution(string s)
{
    int answer = -1;
    stack<char> stk;
    
    for(char c : s) {
        if(stk.empty()) {
            stk.push(c);
            continue;
        }
        
        if(stk.top() == c) stk.pop();
        else stk.push(c);
    }
    
    answer = stk.empty();

    return answer;
}