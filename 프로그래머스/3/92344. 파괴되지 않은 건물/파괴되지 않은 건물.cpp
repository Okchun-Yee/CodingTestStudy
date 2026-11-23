#include <string>
#include <vector>
#include <iostream>

using namespace std;
int N, M;

void Calculator(vector<vector<int>>& board, vector<vector<int>>& value){
    for(int i = 0; i < board.size(); i++){
        for(int j = 0; j < board[0].size(); j++){
            board[i][j] += value[i][j];
        }
    }
}

int solution(vector<vector<int>> board, vector<vector<int>> skill) {
    int answer = 0;
    
    N = board.size(); M = board[0].size();
    
    vector<vector<int>> value(N + 1, vector<int>(M + 1, 0));
                              
    for(int k = 0; k < skill.size();k++){
        int val = (skill[k][0] == 1) ? -skill[k][5] : skill[k][5];
        
        // start
        value[skill[k][1]][skill[k][2]] += val;
        // ex + 1, sy -= val : row end
        value[skill[k][3] + 1][skill[k][2]] -= val;    
        // sx, ey + 1 -= val : col end
        value[skill[k][1]][skill[k][4] + 1] -= val;
        // end
        value[skill[k][3] + 1][skill[k][4] + 1] += val;
    }
    
    // col 누적합 구하기
    for(int i = 0; i < N + 1; i++){
        for(int j = 1; j < M + 1; j++){
            value[i][j] += value[i][j-1];
        }
    }
    // row 누적합 구하기
    for(int i = 1; i < N + 1; i++){
        for(int j = 0; j < M + 1; j++){
            value[i][j] += value[i-1][j];
        }
    }
    
    Calculator(board, value);
    
    for(int i = 0; i < board.size(); i++){
        for(int j = 0; j < board[0].size(); j++){
            if(board[i][j] > 0) answer++;
        }
    }
    return answer;
}