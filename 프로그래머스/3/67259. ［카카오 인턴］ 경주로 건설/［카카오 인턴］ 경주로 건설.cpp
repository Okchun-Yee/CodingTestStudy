#include <string>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>

using namespace std;

struct Node {
    int r, c, dir, cost;
};

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

int visited[25][25][4];

void bfs(int x, int y, int dir, vector<vector<int>>& board){
    queue<Node> q;
    
    q.push({x, y, dir, 0});
    
    while(!q.empty()){
        Node cur = q.front();
        q.pop();
        
        int r = cur.r;
        int c = cur.c;
        int cost = cur.cost;
        int nextCost = 0;
        
        if(board[r][c] == 1) continue;
        
        for(int i = 0; i < 4; i++){
            int nx = r + dx[i];
            int ny = c + dy[i];
            if(nx >= 0 && ny >= 0 &&
              nx < board.size() && ny < board.size()){
                // 비용 계산 (cur이 스타트 지점이였으면 무조건 직진 판정)
                if(cur.dir == -1) 
                    nextCost = cost + 100;
                else 
                    nextCost = (cur.dir != i)? cost + 600 : cost + 100;
                
                if(nextCost < visited[nx][ny][i]){
                    visited[nx][ny][i] = nextCost;
                    q.push({nx, ny, i, nextCost});
                }
            }
        }
    }
}
int solution(vector<vector<int>> board) {
    int answer = INT_MAX;
    
    fill (&visited[0][0][0], &visited[0][0][0] + 25 * 25 * 4, INT_MAX);
    
    bfs(0, 0, -1, board);
    
    for(int i = 0;i<4;i++){
        answer = min(answer, visited[board.size()-1][board.size()-1][i]);
    }
    return answer;
}