#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int dfs(int cur, vector<vector<int>>& graph, vector<bool>& visited){
    visited[cur] = true;
    int cnt = 1;
    
    for(int next : graph[cur]){
        if(!visited[next]){
            cnt+= dfs(next, graph, visited);
        }
    }
    return cnt;
}

int solution(int n, vector<vector<int>> wires) {
    int answer = 102;
    
    vector<bool> visited (n + 1, false);
    
    for(int k = 0; k < wires.size(); k++){
        vector<vector<int>> graph(n + 1);
        for(int i = 0; i < wires.size(); i++){
            if(i == k) continue;
            graph[wires[i][0]].push_back(wires[i][1]);
            graph[wires[i][1]].push_back(wires[i][0]);
        }
        visited.assign(n + 1, false);
        int a = dfs(1, graph, visited);
        int b = n - a;
        
        answer = min(answer, abs(a - b));
    }
    return answer;
}