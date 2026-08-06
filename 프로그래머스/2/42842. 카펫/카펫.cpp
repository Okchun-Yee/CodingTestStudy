#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer(2, 0);
    for(int y = 1; y * y <= (brown + yellow); y++){
        if((brown + yellow) % y == 0){
            answer[1] = y;
            int x = (brown + yellow) / y;
            if(yellow == (x-2)*(y-2)){
                answer[0] = x;
                break;
            }
            answer[1] = 0;
        }
    }
    return answer;
}