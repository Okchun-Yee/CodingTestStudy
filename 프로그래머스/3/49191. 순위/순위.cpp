#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

vector<vector<int>> w_graph(101);
vector<vector<int>> l_graph(101);
vector<bool> visited (51, false);

int bfs(vector<vector<int>>& graph,int& n, int start){
    queue<int> q;
    visited.assign(n + 1, false);
    
    int cnt = 0;
    
    visited[start] = true;
    q.push(start);
    
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        
        for(int next : graph[cur]){
            if(!visited[next]){
                visited[next] = true;
                cnt++;
                q.push(next);
            }
        }
    }
    return cnt;
}

int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    for(int i = 0; i < results.size(); i++){
        w_graph[results[i][0]].push_back(results[i][1]);
        l_graph[results[i][1]].push_back(results[i][0]);
    }
    
    for(int i = 1; i < n + 1; i++){
        int win = bfs(w_graph, n, i);      
        int lose = bfs(l_graph, n, i);
        int result = win + lose;
        
        if(result == n - 1) answer++;
    }
    
    return answer;
}