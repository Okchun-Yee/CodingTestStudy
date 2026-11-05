#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <limits.h>

using namespace std;

vector<vector<pair<int, int>>> adj;
vector<int> dist;

void dijkstra(vector<int>& gates, vector<int>& summits){
    priority_queue<pair<int, int>> pq;
    
    // 모든 출발 지점을 queue에 넣고 시작하기.
    for (int g : gates) {
        dist[g] = 0;
        pq.push({0, g});
    }
    
    while(!pq.empty()){
        int w = -(pq.top().first);
        int cur = pq.top().second;
        pq.pop();

        // end 지점이 아닌 다른 산봉우리 인 경우
        if(find(summits.begin(), summits.end(), cur) != summits.end()) continue;
            
        if (dist[cur] < w) continue;        // 이미 더 짧게 확정된 경로
        
        for(auto next : adj[cur]){
            // 다음 노드가 출발 지점이 아님
            if(find(gates.begin(), gates.end(), next.first) != gates.end()) 
                continue;
            
            int cost = max(w, next.second);
            
            if (cost < dist[next.first]) {
                dist[next.first] = cost;
                pq.push({-cost, next.first});
            }
        }
    }
}

vector<int> solution(int n, vector<vector<int>> paths, vector<int> gates, vector<int> summits) {
    
    adj.assign(n + 1, vector<pair<int, int>>());
    // 0. 인접 리스트 구성
    for(auto& e : paths){
        adj[e[0]].push_back({e[1], e[2]});
        adj[e[1]].push_back({e[0],e[2]});
    }
    
    sort(summits.begin(), summits.end());
    vector<int> answer(2, INT_MAX);
    
    dist.assign(n + 1, INT_MAX);
    dijkstra(gates, summits);
    
    for (int s : summits) {
    if (answer[1] > dist[s]) {
        answer[0] = s;
        answer[1] = dist[s];
    }
}
    
    return answer;
}