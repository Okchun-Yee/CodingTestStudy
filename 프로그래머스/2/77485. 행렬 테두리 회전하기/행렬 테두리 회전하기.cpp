#include <string>
#include <vector>
#include <stdio.h>

using namespace std;

int Movegrid(int x1, int y1, int x2, int y2, vector<vector<int>>& grid){
    int prev = grid[x1][y1];
    int temp = 0;
    int minNum = prev;
    
    // 1. 오른쪽 밀기
    for(int i = y1; i < y2; i++){
        temp = grid[x1][i + 1];
        grid[x1][i + 1] = prev;
        prev = temp;
        if(prev < minNum) minNum = prev;
    }
    // 2. 아래쪽 밀기
    for(int i = x1; i < x2; i++){
        temp = grid[i + 1][y2];
        grid[i + 1][y2] = prev;
        prev = temp;
        if(prev < minNum) minNum = prev;
    }
    // 3. 왼쪽 밀기
    for(int i = y2; i > y1; i--){
        temp = grid[x2][i - 1];
        grid[x2][i - 1] = prev;
        prev = temp;
        if(prev < minNum) minNum = prev;
    }
    // 4. 위쪽 밀기
    for(int i = x2; i > x1; i--){
        temp = grid[i - 1][y1];
        grid[i - 1][y1] = prev;
        prev = temp;
        if(prev < minNum) minNum = prev;
    }
    
    return minNum;
}

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    vector<vector<int>> grid(rows+1, vector<int>(columns+1, 0));
    
    for(int i = 1; i <= rows; i++){
        for(int j = 1; j <= columns; j++){
            grid[i][j] = (i - 1) * columns + j;;
        }
    }
    
    for(auto& q : queries){
        answer.push_back(Movegrid(q[0], q[1], q[2], q[3], grid));
    }
    
    return answer;
}