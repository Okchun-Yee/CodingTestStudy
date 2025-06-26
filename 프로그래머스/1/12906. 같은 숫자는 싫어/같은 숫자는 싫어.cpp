#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    int target = arr[0];

    for(int i = 1; i<arr.size();i++){
        if(target != arr[i]){
            //cout << target << "&" << arr[i]<<endl;
            answer.push_back(target);
            target = arr[i];
        }
    }
    answer.push_back(target);
    return answer;
}