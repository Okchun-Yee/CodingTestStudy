#include <string>
#include <vector>
#include <queue>

using namespace std;

int dx[4] = { -1, 1, 0, 0};
int dy[4] = { 0, 0, -1, 1};

vector<vector<int>> dist;

bool bfs(int x, int y, vector<string>& map){
    queue<pair<int, int>> q;
    dist.assign(5, vector<int>(5, -1));
    
    dist[x][y] = 0;
    q.push({x, y});
    
    while(!q.empty()){
        int r = q.front().first;
        int c = q.front().second;
        q.pop();
        
        if(dist[r][c] >= 2) continue;
        
        for(int i =0; i< 4; i++){
            int nx = r + dx[i];
            int ny = c + dy[i];
            
            if(nx >= 0 && ny >= 0 &&
              nx < 5 && ny < 5){
                if(map[nx][ny] == 'P' && dist[nx][ny] == -1){
                    return false;
                }
                if(map[nx][ny] == 'O' && dist[nx][ny] == -1){
                    q.push({nx, ny});
                    dist[nx][ny] = dist[r][c] + 1;
                }
            }
        }
    }
    return true;
}
vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    for(vector<string>& m : places){
        bool flag = true;
        for(int i = 0; i < 5; i++){
            for(int j = 0; j < 5; j++){
                if(m[i][j] == 'P'){
                    if(!bfs(i, j, m)){
                        flag = false;
                        break;
                    }
                }
            }
        }
        if(!flag) answer.push_back(0);
        else answer.push_back(1);
    }
    return answer;
}