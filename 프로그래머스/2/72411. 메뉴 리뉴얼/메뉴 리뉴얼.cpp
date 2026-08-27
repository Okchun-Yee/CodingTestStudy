#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;
vector<bool> visited(20, false);
map<string, int> counter;


void dfs(string s, int n, string str, int index){
    if(str.size() == n){
        counter[str]++;
        return;
    }
    for(int i = index; i< s.size(); i++){
        if(visited[i]) continue;
        visited[i] = true;
        dfs(s, n, str + s[i], i + 1);
        visited[i] = false;
    }
}
vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    for(int i = 0; i < orders.size(); i++){
        sort(orders[i].begin(), orders[i].end());
        for(int j = 0; j < course.size(); j++){
            dfs(orders[i], course[j], "", 0);
        }
    }
    
    for(int i = 0; i < course.size(); i++){
        int maxVal = 0;
        for(auto& p : counter){
            if(p.first.size() == course[i]){
                maxVal = max(maxVal, p.second);
            }
        }
        if( maxVal < 2) continue;
        for(auto& p : counter){
            if(p.first.size() == course[i] && p.second == maxVal){
                answer.push_back(p.first);
            }
        }
    }
    sort(answer.begin(), answer.end());
    return answer;
}