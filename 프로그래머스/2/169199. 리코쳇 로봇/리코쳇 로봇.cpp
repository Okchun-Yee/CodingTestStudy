#include <string>
#include <vector>
#include <queue>

using namespace std;

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

void bfs(int x, int y, vector<string>& board, 
         vector<vector<int>>& dist, vector<vector<bool>>& visited){
    queue<pair<int, int>> q;
    
    visited[x][y] = true;
    dist[x][y] = 0;
    q.push({x, y});
    
    while(!q.empty()){
        int r = q.front().first;
        int c = q.front().second;
        q.pop();
        
        for(int i = 0; i < 4; i++){
            int nx = r;
            int ny = c;
            while(nx + dx[i] >= 0 && ny + dy[i] >= 0 
                  && nx + dx[i] < board.size() 
                  && ny + dy[i] < board[0].size()
                  && board[nx + dx[i]][ny + dy[i]] != 'D'){
                nx += dx[i];
                ny += dy[i];
            }
            if(!visited[nx][ny]){
                visited[nx][ny] = true;
                dist[nx][ny] = dist[r][c] + 1;
                q.push({nx, ny});
            }
        }
    }
}

int solution(vector<string> board) {
    int answer = 0;
    
    int sx, sy, ex, ey;
    for(int i = 0;i< board.size(); i++){
        for(int j = 0;j< board[0].size(); j++){
            if(board[i][j] =='R'){
                sx = i; sy = j;
            }
            else if(board[i][j] == 'G'){
                ex = i; ey = j;
            }
        }
    }
    
    vector<vector<int>> dist
        (board.size(), vector<int>(board[0].size(), -1));
    vector<vector<bool>> visited
        (board.size(), vector<bool>(board[0].size(), false));
    
    bfs(sx, sy, board, dist, visited);
    answer = dist[ex][ey];
    return answer;
}