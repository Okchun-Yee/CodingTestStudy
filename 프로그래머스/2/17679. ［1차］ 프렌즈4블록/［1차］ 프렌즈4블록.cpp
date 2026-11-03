#include <string>
#include <vector>
#include <iostream>

using namespace std;

struct cell
{
    int x, y;
    char c;
};

int solution(int m, int n, vector<string> board)
{
    int answer = 0;
    int nextX = 0;
    int nextY = 0;

    vector<cell> v;
    bool flag = true;

    while (flag)
    {
        // 0. 더이상 4묶음을 찾지 못하면 종료
        flag = false;
        
        // 1. 4묶음 찾기
        for (int i = 0; i < m - 1; i++)
        {
            for (int j = 0; j < n - 1; j++)
            {
                if (board[i][j] == board[i + 1][j] &&
                    board[i][j] == board[i][j + 1] &&
                    board[i][j] == board[i + 1][j + 1] &&
                    board[i][j] != '0')
                {
                    v.push_back({i, j, board[i][j]});
                    flag = true;
                }
            }
        }
        
        // 2. 묶음 제거하기
        for (auto &cell : v)
        {
            if (board[cell.x][cell.y] == cell.c)
            {
                board[cell.x][cell.y] = '0';
            }
            if (board[cell.x][cell.y + 1] == cell.c)
            {
                board[cell.x][cell.y + 1] = '0';
            }
            if (board[cell.x + 1][cell.y] == cell.c)
            {
                board[cell.x + 1][cell.y] = '0';
            }
            if (board[cell.x + 1][cell.y + 1] == cell.c)
            {
                board[cell.x + 1][cell.y + 1] = '0';
            }
        }
        v.clear();  // 제거 완료 후 묶음 벡터 초기화 => 다음 사이클 준비
        
        // 3. 빈칸에 블록 채우기 (더 반복하는 블록이 없을 때 까지)
        bool emptyArea = true;
        while(emptyArea){
            emptyArea = false;
            for(int i = 1; i < m; i++){
                for(int j = 0; j < n; j++){
                    if(board[i][j] == '0' && board[i-1][j] != '0'){
                        char tmp = board[i-1][j];
                        board[i-1][j] = board[i][j];
                        board[i][j] = tmp;
                        emptyArea = true;
                    }
                }
            }
        }
    }
    
    // 4. 터진 블록 개수 세기
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << board[i][j] << " ";
            if(board[i][j] == '0') answer++;
        }
        cout << endl;
    }
    return answer;
}