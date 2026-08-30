#include <string>
#include <vector>
#include <stack>

using namespace std;

stack<int> stk;

void del(vector<int>& prev, vector<int>& next, int cur, int n, vector<bool>& check){
    if(prev[cur] != -1) next[prev[cur]] = next[cur];
    if(next[cur] != n) prev[next[cur]] = prev[cur];
    
    check[cur] = true;
    stk.push(cur);
}

void undo(vector<int>& prev, vector<int>& next, int cur, int n, vector<bool>& check){
    if(prev[cur] != -1) next[prev[cur]] = cur;
    if(next[cur] != n) prev[next[cur]] = cur;
    
    check[cur] = false;
    stk.pop();
}

string solution(int n, int k, vector<string> cmd) {
    string answer = "";
    
    vector<bool> check(n, false);
    
    // 앞, 뒤를 가진 배열 연결리스트
    vector<int> prev(n);
    vector<int> next(n);
    for(int i = 0; i < n; i++){
        prev[i] = i - 1;
        next[i] = i + 1;
    }
    
    int cur = k;
    for(string s : cmd){
        char c = 0; int x = 0;
        if(s.size() == 1){
            c = s[0];
        }else {
            c = s[0];
            x = stoi(s.substr(2));
        }
        
        if(c == 'U'){
            while(x--){
                cur = prev[cur];
            }
        }
        else if(c == 'D'){
            while(x--){
                cur = next[cur];
            }
        }
        else if( c == 'C'){
            del(prev, next, cur, n, check);
            cur = ((next[cur]) < n) ? next[cur] : prev[cur];
        }
        else if(c == 'Z'){
            undo(prev, next, stk.top(), n, check);
        }
    }
    
    for(bool b : check){
        if(!b) answer += 'O';
        else answer += 'X';
    }
    
    return answer;
}