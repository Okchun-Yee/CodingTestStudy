#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(int a, int b, int c, int d) {
    int answer = 0;
    int ans[7] = {0};
    int distanct = 0; int max = 0;
    int val[4];
    int cnt[4];
    
    ans[a]++; ans[b]++; ans[c]++; ans[d]++;
    
    int p, q = 777, r;
    for(int i = 1; i <= 6; i++){
        if(ans[i] == 0) continue;
        val[distanct] = i;
        cnt[distanct] = ans[i];
        if(ans[i] > max) max = ans[i];
        distanct++;
    }
    if(max == 4) {
        answer = 1111 * val[distanct - 1];
    }
    else if(max == 3) {
        for(int i = 0;i < distanct;i++){
            if(cnt[i] == 3) p = val[i];
            if(cnt[i] == 1) q = val[i];
        }
        answer = (10 * p + q) * (10 * p + q);
    }
    else if(max == 2 && distanct == 2){
        p = val[0];
        q = val[1];
        answer = (p + q) * abs(p - q);
    }
    else if (max == 2 && distanct == 3){
        for(int i = 0;i < distanct;i++){
            if(cnt[i] == 2) p = val[i];
            if(cnt[i] == 1) {
                if (q == 777) q = val[i];
                else r = val[i];
            }
        }
        answer = q * r;
    }
    else {
        answer = val[0];
    }
    return answer;
}