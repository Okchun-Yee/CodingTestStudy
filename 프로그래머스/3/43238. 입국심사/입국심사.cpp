#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool execute(long long mid, int& n, vector<int>& times){
    long long cnt = 0;
    for(int t : times){
        cnt += mid / t;
        if(cnt >= n) return true;
    }
    return cnt >= n;
}
long long solution(int n, vector<int> times) {
    long long answer = 0;
    
    sort(times.begin(), times.end());
    
    long long low = 1;
    long long high = (long long)times[times.size() - 1] * n;
    
    while(low <= high){
        long long mid = (low + high) / 2;
        
        if(execute(mid, n, times)){
            answer = mid;
            high = mid - 1;
        }else {
            low = mid + 1;
        }
    }
    return answer;
}