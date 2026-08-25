#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<vector<int>> graph;

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    graph.assign(n+1, vector<int>());
    
    for(auto& e : edge){
        graph[e[0]].push_back(e[1]);
        graph[e[1]].push_back(e[0]);
    }
    
    vector<int> dist(n+1, -1);
    queue<int> q;
    
    q.push(1);
    dist[1] = 0;
    
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        for(int next : graph[cur]){
            if(dist[next] == -1){
                dist[next] = dist[cur] + 1;
                q.push(next);
            }
        }
    }
    
    int maxlen = *max_element(dist.begin(), dist.end());
    for(int num : dist){
        if(maxlen == num){
            answer++;
        }
    }
    return answer;
}