#include <string>
#include <vector>
#include <queue>

using namespace std;

int f(int x, int n, int type){
    if(type == 0) return x + n;
    if(type == 1) return x * 2;
    else return x * 3;
}

void bfs(int x, int y, int n, vector<int>& dist){
    queue<int> q;
    int next[3] = { 0 };
    
    dist[x] = 0;
    q.push(x);
    
    while(!q.empty()){
        int now = q.front();
        q.pop();
        
        for(int i = 0; i<3;i++){
            next[i] = f(now, n, i);
            if(next[i] > x && next[i] <= y && dist[next[i]] == -1){
                dist[next[i]] = dist[now] + 1;
                q.push(next[i]);
            }
        }
    }
}
int solution(int x, int y, int n) {
    int answer = 0;
    vector<int> dist(y + 1, -1);
    
    bfs(x, y, n, dist);
    
    answer = dist[y];
    return answer;
}