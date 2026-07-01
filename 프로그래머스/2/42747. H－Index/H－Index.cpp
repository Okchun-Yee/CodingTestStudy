#include <string>
#include <vector>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    int h[10001]={0};
    
    for(int i=0;i<citations.size()+1;i++){
        for(int j=0;j<citations.size();j++){
            if(citations[j] >= i){
                h[i]++;
            }
        }
        if(h[i] >= i){
            if(i > answer) answer = i;
        }
    }
    return answer;
}