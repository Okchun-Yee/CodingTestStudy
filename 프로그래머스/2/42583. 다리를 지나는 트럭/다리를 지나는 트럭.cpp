#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    int index = 0; int total = 0;
    queue<int> q;
    // 다리 채우기
    for(int i=0;i<bridge_length;i++){
        q.push(0);
    }
    // 다리 건너기
    while(index < truck_weights.size()){
        answer++;
        total -= q.front();
        q.pop();

        if(total + truck_weights[index] <= weight){
            q.push(truck_weights[index]);
            total += truck_weights[index];
            index++;
        }
        else {
            q.push(0);
        }
    }
    return answer + bridge_length;
}