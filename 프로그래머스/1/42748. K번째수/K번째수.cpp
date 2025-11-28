#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    int size = commands.size();
    for (int k = 0; k < size; ++k) {
        vector<int> v;
        for (int i = commands[k][0] - 1; i < commands[k][1]; ++i) {
            v.push_back(array[i]);
        }
        sort(v.begin(), v.end());
        answer.push_back(v[commands[k][2] - 1]);
    }
    return answer;
}