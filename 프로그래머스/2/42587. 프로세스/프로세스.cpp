#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
bool compare(int a, int b){
    return a > b;
}
int solution(vector<int> priorities, int location) {
    int answer = 0;
    queue<pair<int, int>> q;
    for(int i =0; i<priorities.size();i++){
        q.push({priorities[i], i});
    }
    sort(priorities.begin(), priorities.end(), compare);
    int idx = 0;
    
    while (!q.empty())
    {
        auto& a = q.front();
        int val = a.first;
        int index = a.second;
        q.pop();

        if(val == priorities[idx]){
            if(index == location){
                answer = idx + 1;
                return answer;
            }
            idx++;
        }
        else {
            q.push({val, index});
        }
    }
    
    return answer;
}