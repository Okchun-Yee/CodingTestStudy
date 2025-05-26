#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> info, int n, int m) {
    static int INIT = 1000;
    int answer = 0;
    int size = info.size();
    vector<vector<int>> dp(size + 1, vector<int>(m, INIT));        //행: 전체 물건 수 / 열: B도둑의 최대 흔적 수

    dp[0][0] = 0;
    for (int i = 1;i <= size; i++) {
        int tempA = info[i-1][0];
        int tempB = info[i-1][1];
        for (int j = 0;j < m;j++) {
            //A도둑
            dp[i][j] = min(dp[i][j], dp[i - 1][j] + tempA);

            //B도둑
            if (j + tempB < m) {
                dp[i][j + tempB] = min(dp[i][j + tempB], dp[i - 1][j]);
            }
        }
    }

    int minNum = INIT;
    for (int j = 0;j < m;j++) {
        minNum = min(minNum, dp[size][j]);
    }
    cout << minNum<<endl;
    answer = minNum >= n ? -1 : minNum;
    
    return answer;
}