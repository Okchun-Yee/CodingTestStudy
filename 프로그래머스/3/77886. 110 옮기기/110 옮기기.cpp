#include <string>
#include <vector>
#include <stack>
#include <algorithm>
#include <iostream>

using namespace std;

string func(string s){
    string st;
    int cnt = 0;
    
    for(int i = 0; i < s.size(); i++){
        st.push_back(s[i]);
        
        //1. "110" 찾아서 빼기.
        if(st.size()>= 3 &&
          st[st.size()-3] == '1' && 
           st[st.size()-2] == '1' && 
           st[st.size()-1] == '0')
        {
            // pop 3회
            cnt++;
            st.erase(st.size() - 3);
        }
    }
    
    string block;
    for(int i = 0; i < cnt; i++) block += "110";
    
    size_t pos = st.find("11");
    
    if(pos != string::npos){
        st.insert(pos, block);
    }
    else if (st != "" && st[st.size() - 1] == '1') {
        st.insert(st.size() - 1, block);
    }
    else {
        st += block;
    }
    return st;
}

vector<string> solution(vector<string> s) {
    vector<string> answer;
    
    for (string str : s){
        answer.push_back(func(str));
    }
    
    return answer;
}