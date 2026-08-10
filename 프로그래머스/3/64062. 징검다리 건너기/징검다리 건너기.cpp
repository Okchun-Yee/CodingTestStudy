#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool execute (vector<int>& stones, int& k, long long mid ){
    int missing = 0;
    for(int n : stones){
        if(mid > n){
            missing++;
            if(missing >= k) return false;
        }
        else {
            missing = 0;
        }
    }
    return true;
}
int solution(vector<int> stones, int k) {
    int answer = 0;
    
    long long low = 1;
    long long  high = *max_element(stones.begin(), stones.end());
    
    
    while (low <= high){
        long long mid = (low + high) / 2;
        
        if(execute(stones, k, mid)){
            answer = mid;
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return answer;
}