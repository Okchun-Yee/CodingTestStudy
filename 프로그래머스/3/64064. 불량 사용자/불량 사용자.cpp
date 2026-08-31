#include <string>
#include <vector>
#include <set>

using namespace std;

set<vector<bool>> result;

bool comp(string& a, string& b){
    if(a.size() != b.size()) return false;
    for(int i = 0; i < a.size(); i++){
        if(a[i] != b[i] && b[i] != '*'){
            return false;
        }
    }
    return true;
}

void dfs(vector<bool>& visited, vector<string>& user_id, vector<string>& banned_id, int depth){
    if(depth == banned_id.size()){
        result.insert(visited);
        return;
    }
    
    for(int i = 0; i < user_id.size(); i++){
        if(visited[i]) continue;
        if(!comp(user_id[i], banned_id[depth])) continue;
        
        visited[i] = true;
        dfs(visited, user_id, banned_id, depth+1);
        visited[i] = false;
    }
}

int solution(vector<string> user_id, vector<string> banned_id) {
    int answer = 0;
    
    vector<bool> visited(8, false);
    
    dfs(visited, user_id, banned_id, 0);
    
    answer = result.size();
    return answer;
}