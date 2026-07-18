#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    stack<int> st;

    for(int n : moves){
        for(int i=0;i<board.size();i++){
            int col = n -1;
            if(board[i][col]!= 0){
                if(!st.empty() && st.top() == board[i][col]){
                    st.pop();
                    answer+=2;
                }
                else {
                    st.push(board[i][col]);
                }
                board[i][col] = 0;
                break;
            }
        }
    }
    return answer;
}