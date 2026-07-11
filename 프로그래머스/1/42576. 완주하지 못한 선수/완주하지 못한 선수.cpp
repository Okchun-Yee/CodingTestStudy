#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    unordered_map <string, int> m;

    for(string& s : participant){
        m[s]++;
    }
    for(string& s : completion){
        m[s]--;
    }
    for(auto& p : m){
        if(p.second) answer = p.first;  
    }
    return answer;
}