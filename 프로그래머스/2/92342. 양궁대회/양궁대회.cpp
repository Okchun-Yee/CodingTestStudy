#include <string>
#include <vector>

using namespace std;

vector<int> A;
vector<int> B(11, 0);
int maxDiff = 0;


void dfs(int idx, int left, vector<int>& answer) {
    // 종료 조건: 11칸을 다 정했을 때
    if (idx == 11) {
        // 1. left 처리
        B[10] += left;
        // 2. A 와 B 점수 계산
        int a = 0; int b = 0;
        for(int i = 0; i <= 10; i++){
            if(A[i] == 0 && B[i] == 0) continue;
            
            if(A[i] >= B[i]) {
                a += (10 - i);
            }
            else{
                b += (10 - i);
            }
        }
        // 3. max update
        if(maxDiff < (b - a)){
            maxDiff = b - a;
            answer = B;
        }
        else if((b - a) > 0 && maxDiff == (b - a)){
            for(int i = 10; i >= 0; i--){
                if(B[i] != answer[i]){
                    if(B[i] > answer[i]){
                        answer = B;
                    }
                    break;
                }
            }
        }
        // 4. 복원
        B[10] -= left;
        return;
    }

    // 칸 승리 = a + 1
    int need = A[idx] + 1;
    if (left >= need) {
        B[idx] = need;                          // select
        dfs(idx + 1, left - need, answer);      // next
        B[idx] = 0;                             // back
    }

    // 칸 포기 = 0
    dfs(idx + 1, left, answer);
}

vector<int> solution(int n, vector<int> info) {
    vector<int> answer;
    A = info;
    
    dfs(0, n, answer);
    
    if(maxDiff == 0) return {-1};
    
    return answer;  
}