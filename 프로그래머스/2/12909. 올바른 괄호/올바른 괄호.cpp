#include<string>
#include <iostream>
#include <stack>

using namespace std;

bool solution(string s)
{
    bool answer = true;
    stack<char> stk;

    for(char c : s){
        if(c == '('){
            stk.push(c);
        }
        else if (c == ')') {
            if(stk.empty()){
                answer = false;
                return answer;
            }
            stk.pop();
        }
    }
    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    answer = stk.empty();
    return answer;
}