#include <string>
#include <vector>
#include <algorithm>

using namespace std;
bool execute(long long mid, vector<int>& rocks, int n){
    int cnt = 0;
    long long start = 0;
    
    for (int i =0;i<rocks.size();i++){
        if(rocks[i] - start < mid){
            cnt++;
        }else {
            start = rocks[i];
        }
    }
    return cnt <= n;
}
int solution(int distance, vector<int> rocks, int n) {
    int answer = 0; 
    rocks.push_back(distance);
    sort(rocks.begin(), rocks.end());
    
    long long low = 1;
    long long high = (long long) distance;
    
    while (low <= high){
        long long mid = (high + low) / 2;
        
        if(execute(mid, rocks, n)) {
            answer = mid;
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    
    return answer;
}