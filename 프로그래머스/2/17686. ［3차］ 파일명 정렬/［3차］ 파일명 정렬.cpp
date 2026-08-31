#include <string>
#include <vector>
#include <cctype>
#include <algorithm>

using namespace std;

struct Files{
    string head;
    string num;
    string origin;
};

bool compare(const Files& a, const Files& b){
    if(a.head != b.head) return a.head < b.head;
    return stoi(a.num) < stoi(b.num);
};

vector<string> solution(vector<string> files) {
    vector<string> answer;
    vector<Files> v;
    
    for(string s : files){
        int i = 0;
        while(i < s.size() && !isdigit(s[i])) i++;
        int numIdx = i;
        
        while(i < s.size() && isdigit(s[i])) i++;
        int tailIdx = i;
        
        string head = s.substr(0, numIdx);
        for(char & c : head) c = tolower(c);
        
        string num = s.substr(numIdx, tailIdx - numIdx);
        
        v.push_back({head, num, s});
    }
    
    stable_sort(v.begin(), v.end(), compare);
        
    for(const Files& F : v) answer.push_back(F.origin);
    
    return answer;
}