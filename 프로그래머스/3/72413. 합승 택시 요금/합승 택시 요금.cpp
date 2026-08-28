#include <string>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>

using namespace std;

vector<vector<pair<int, int>>> graph(201);


void dijkstra(int node, vector<int>& dist){
    priority_queue<pair<int, int>> pq;
    
    dist[node] = 0;
    pq.push({node, 0});
    
    while(!pq.empty()){
        int cur = pq.top().first;
        int w = -(pq.top().second);
        pq.pop();
        
        if(dist[cur] < w) continue;
        
        for(auto next : graph[cur]){
            int cost = w + next.second;
            if(cost < dist[next.first]){
                dist[next.first] = cost;
                pq.push({next.first, -cost});
            }
        }
    }
}

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = INT_MAX;
    vector<int> distS(n+1, INT_MAX);
    vector<int> distA(n+1, INT_MAX);
    vector<int> distB(n+1, INT_MAX);
    
    for(int i = 0; i < fares.size(); i++){
        // start, end, weight
        graph[fares[i][0]].push_back({fares[i][1], fares[i][2]});
        graph[fares[i][1]].push_back({fares[i][0], fares[i][2]});
    }
    dijkstra(s, distS);
    dijkstra(a, distA);
    dijkstra(b, distB);
    
    for(int i = 1; i < n+1; i++){
        answer = min(answer, distS[i] + distA[i] + distB[i]);
    }
    return answer;
}