#include <string>
#include <vector>
#include <queue>

using namespace std;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = { 0, 0, -1, 1};

int sx, sy, ex, ey, lx, ly;
void bfs(int x, int y, vector<string>& maps, vector<vector<int>>& dist, 
         vector<vector<bool>>& visited){
    dist.assign(maps.size(), vector<int>(maps[0].size(), -1));
    visited.assign(maps.size(), vector<bool>(maps[0].size(), false));
    
    queue<pair<int, int>> q;
    
    dist[x][y] = 0;
    visited[x][y] = true;
    q.push({x, y});
    
    while(!q.empty()){
        int r = q.front().first;
        int c = q.front().second;
        q.pop();
        
        if(maps[r][c] == 'X') continue;
        
        for(int i = 0;i < 4; i++){
            int nx = r + dx[i];
            int ny = c + dy[i];
            
            if(nx >= 0 && ny >= 0 
               && nx < maps.size() && ny < maps[0].size() 
               && visited[nx][ny] != true)
            {
                visited[nx][ny] = true;
                q.push({nx, ny});
                dist[nx][ny] = dist[r][c] + 1;
            }
        }
    }
}

int solution(vector<string> maps) {
    int answer = -1;
    vector<vector<int>> dist;
    vector<vector<bool>> visited;
    
    for(int i = 0;i< maps.size();   i++){
        for(int j = 0;j< maps[0].size(); j++){
            if(maps[i][j]=='S'){
                sx = i;
                sy = j;
            }
            else if(maps[i][j] == 'E'){
                ex = i;
                ey = j;
            }
            else if(maps[i][j] == 'L'){
                lx = i; 
                ly = j;
            }
        }
    }
    bfs(sx, sy, maps, dist, visited);
    if(dist[lx][ly] != -1){
        int dir = dist[lx][ly];
        bfs(lx, ly, maps, dist, visited);
        if(dist[ex][ey] != -1){
            answer = dist[ex][ey] + dir;
        }
    }
    return answer;
}