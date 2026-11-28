#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> graph;

void bfs(int start, int end, vector<int>& dist){
    queue<int> q;
    
    dist[start] = 0;
    q.push(start);
    
    while(!q.empty()){
        int now = q.front();
        q.pop();
        
        for(int next : graph[now]){
            if(dist[next] != -1) continue;
            
            dist[next] = dist[now] + 1;
            q.push(next);
        }
    }
}

vector<int> solution(int n, vector<vector<int>> roads, vector<int> sources, int destination) {
    vector<int> answer;
    vector<int> dist(n + 1, -1);
    graph.assign(n + 1, vector<int>());
    
    for(auto& e : roads){
        graph[e[0]].push_back(e[1]);
        graph[e[1]].push_back(e[0]);
    }
    
    bfs(destination, n, dist);
    
    for(int num : sources){
        answer.push_back(dist[num]);
    }
    return answer;
}