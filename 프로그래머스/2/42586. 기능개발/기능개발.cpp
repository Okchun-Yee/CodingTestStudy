#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<int> q;

    for(int i=0;i<progresses.size();i++){
        q.push((100 - progresses[i] + speeds[i] -1 )/speeds[i]);
    }
    int point = q.front();
    int cnt = 0;
    while (!q.empty())
    {
        /* code */
        if(point >= q.front()){
            q.pop();
            cnt++;
        }
        else {
            point = q.front();
            answer.push_back(cnt);
            cnt = 0;
        }
    }
    answer.push_back(cnt);
    return answer;
}