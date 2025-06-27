#include <string>
#include <vector>

using namespace std;

int solution(vector<int> sides) {
    int answer = 0;
	int maxSide = max(sides[0], sides[1]);
    int minSide = min(sides[0], sides[1]);
    for (int i = 1; i <= sides[0] + sides[1]; i++) {
        if (i <= maxSide && (i + minSide) > maxSide) {
            answer++;
        }
        else if (i > maxSide && (sides[0] + sides[1]) > i){
            answer++;
        }
    }
    return answer;
}