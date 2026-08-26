#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int compact(string s, int unit){
    string prev = s.substr(0, unit);
    int cnt = 1, len = 0;
    
    for(int i = unit; i < s.size(); i += unit){
        string cur = s.substr(i, unit);
        if(cur == prev){
            cnt++;
        }
        else {
            len += (cnt > 1) ? unit + to_string(cnt).size() : unit;
            prev = cur;
            cnt = 1;
        }
    }
     len += (cnt > 1) ? prev.size() + to_string(cnt).size() : prev.size();
    return len;
}

int solution(string s) {
    int answer = s.size();
    
    for (int i = 1; i <= s.size()/2; i++){
        int length = compact(s, i);
        answer = min(answer, length);
    }
    
    return answer;
}