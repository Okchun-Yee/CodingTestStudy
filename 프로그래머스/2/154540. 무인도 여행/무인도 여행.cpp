#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> grid;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void mapping(vector<string>& maps){
    grid.assign(maps.size(), vector<int>(maps[0].size(), 0));
    for(int i = 0; i<maps.size();i++){
        for(int j = 0; j < maps[0].size();j++){
            if(maps[i][j] == 'X'){
                grid[i][j] = -1;
            }
            else {
                grid[i][j] = maps[i][j] - '0';
            }
        }
    }
}

int  dfs(int x, int y){
    int total = grid[x][y];
    grid[x][y] = -1;
    
    for(int i = 0; i<4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx>=0&&nx<grid.size()&&ny>=0&&ny<grid[0].size()&&grid[nx][ny] != -1 ){
            total += dfs(nx, ny);
        }
    }
    return total;
}

vector<int> solution(vector<string> maps) {
    vector<int> answer;
    mapping(maps);
    
    for(int i = 0; i<maps.size();i++){
        for(int j = 0; j < maps[0].size();j++){
            if(grid[i][j] != -1){
                int num = dfs(i, j);
                answer.push_back(num);
            }
        }
    }
    
    sort(answer.begin(), answer.end());
    
    if(answer.empty()){
        answer.push_back(-1);
    }
    return answer;
}