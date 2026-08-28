#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>

using namespace std;

int dist[500001];

void dijkstra(vector<vector<pair<int, int>>>& graph, int start, int& k){
    priority_queue<pair<int, int>> pq;
    
    pq.push({start, 0}); // 시작 위치 (위치, 비용)
    dist[start] = 0;
    
    while(!pq.empty()){
        int cur = pq.top().first;
        int w = -(pq.top().second);   // top에 가장 큰 수가 오기 때문에 음수화해서 순서 뒤집기
        pq.pop();
        
        if(dist[cur] < w) continue; // 이미 최단 경로
        
        for(int i = 0; i < graph[cur].size(); i++){
            int cost = w + graph[cur][i].second;
            if(cost < dist[graph[cur][i].first]){
                dist[graph[cur][i].first] = cost;
                pq.push({graph[cur][i].first, -cost});
            }
            
        }
    }
}

int solution(int N, vector<vector<int>> road, int K) {
    int answer = 0;
    vector<vector<pair<int, int>>> graph(51);
    for(int i = 0; i < road.size();i++){
        graph[road[i][0]].push_back({road[i][1], road[i][2]});
        graph[road[i][1]].push_back({road[i][0], road[i][2]});
    }
    
    fill(dist, dist + 500001, INT_MAX);
    
    dijkstra(graph, 1, K);
    
    for(int i = 1; i < N + 1; i++){
        if(dist[i] <= K) answer++;
    }
    return answer;
}