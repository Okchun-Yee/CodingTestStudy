#include <vector>
#include <unordered_map>
#include <cmath>

using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    unordered_map<int, int> m;
    
    for(int n : nums){
        m[n]++;
    }
    answer = min(m.size(), nums.size() / 2);
    return answer;
}