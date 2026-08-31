#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

bool visited[2][101][101];   //방향 (가로, 세로) , 행, 열

struct Robot{
    int r;
    int c;      // 기준칸 (회전축)
    
    int dir;    // 방향 (0 = 가로, 1 = 세로)
    int time;
};

vector<Robot> isNext(Robot cur, vector<vector<int>>& board){
    vector<Robot> result;
    
    int r2 = (cur.dir == 0) ? cur.r : cur.r + 1;
    int c2 = (cur.dir == 0) ? cur.c + 1 : cur.c;
    
    for(int i = 0; i < 4; i++){
        int nx1 = cur.r + dx[i]; int ny1 = cur.c + dy[i];
        int nx2 = r2 + dx[i]; int ny2 = c2 + dy[i];
        
        if(nx1 >= 0 && ny1 >= 0 && nx2 >= 0 && ny2 >= 0 &&
          nx1 < board.size() && ny1 < board[0].size() &&
          nx2 < board.size() && ny2 < board[0].size()){
            if(board[nx1][ny1] != 1 && board[nx2][ny2] != 1){
                result.push_back({nx1, ny1, cur.dir, cur.time + 1});
            }
        }
    }
    if(cur.dir == 0){
        for(int d : { -1, 1}){
            int nx1 = cur.r + d; int ny1 = cur.c;
            int nx2 = cur.r + d; int ny2 = cur.c + 1;
            
            if(nx1 >= 0 && ny1 >= 0 && nx2 >= 0 && ny2 >= 0 &&
                nx1 < board.size() && ny1 < board[0].size() &&
                nx2 < board.size() && ny2 < board[0].size()){
                if(board[nx1][ny1] != 1 && board[nx2][ny2] != 1){
                    int origin = min(cur.r, cur.r + d); // 기준점을 항상 위쪽
                    
                    result.push_back({origin, cur.c, 1, cur.time + 1});
                    result.push_back({origin, cur.c + 1, 1, cur.time + 1});
                }
            }    
        }
    }
    else {
        for(int d : { -1, 1}){
            int nx1 = cur.r; int ny1 = cur.c + d;
            int nx2 = cur.r + 1; int ny2 = cur.c + d;
            
            if(nx1 >= 0 && ny1 >= 0 && nx2 >= 0 && ny2 >= 0 &&
                nx1 < board.size() && ny1 < board[0].size() &&
                nx2 < board.size() && ny2 < board[0].size()){
                if(board[nx1][ny1] != 1 && board[nx2][ny2] != 1){
                    int origin = min(cur.c, cur.c + d); // 기준점을 항상 위쪽
                    
                    result.push_back({cur.r, origin, 0, cur.time + 1});
                    result.push_back({cur.r+1, origin, 0, cur.time + 1});
                }
            }    
        }
    }
    return result;
}

int bfs(vector<vector<int>>& board, int dir, int startX, int startY){
    queue<Robot> q;
    
    visited[dir][startX][startY] = true;
    q.push({startX, startY, dir, 0});
    
    while(!q.empty()){
        Robot cur = q.front();
        q.pop();
        
        int r2 = (cur.dir == 0) ? cur.r : cur.r + 1;
        int c2 = (cur.dir == 0) ? cur.c + 1 : cur.c;
        if(cur.r == board.size() - 1 && cur.c == board[0].size() - 1||
          r2 == board.size() - 1 && c2 == board[0].size() - 1){
            return cur.time;
        }
        
        for(Robot next : isNext(cur, board)){
            if(!visited[next.dir][next.r][next.c]){
                visited[next.dir][next.r][next.c] = true;
                q.push({next.r, next.c, next.dir, next.time});
            }
        }
    }
}
int solution(vector<vector<int>> board) {
    int answer = 0;
    
    answer = bfs(board, 0, 0, 0);
    
    return answer;
}