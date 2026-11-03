#include <string>
#include <vector>
#include <iostream>
#include <format>

using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer(2,0);
    
    // low = 배열 시작점, mid = 배열 끝점, high = 배열 끝값 (고정)
    long long high = sequence.size() - 1;
    long long low = 0;
    long long mid = low;
    
    // cnt = [low] + [mid] 비교, diff = mid - low 비교, min = low값 비교
    long long cnt = sequence[low];
    long long diff = high;
    long long min = high;
    
    while (low <= mid && mid <= high){ 
        // 1. k보다 작을때 low 증가
        if(cnt < k){
            mid += 1;
            cnt += sequence[mid];
        }
        // 2. k보다 클 때 mid 증가
        else if (cnt > k){
            low += 1;
            cnt -= sequence[low - 1];
        }
        // 3. k와 동일
        else {
            // 3-1. k와 동일한데 diff보다 더 작을때 (짧은 수열)
            if(diff > mid - low){
                answer[0] = low;
                answer[1] = mid;
                diff = mid - low;
            }
            // 3-2. k와 동일한데 min보다 현재 low가 더 작을때 (시작 인덱스)
            else if (diff == mid - low && min > low ){
                answer[0] = low;
                answer[1] = mid;
                min = low;
            }
            // 3-3. k와 동일한데 조건 틀릴때 => low 증가
            else {
                cnt -= sequence[low];
                low += 1;
            }
        }
    }
    return answer;
}