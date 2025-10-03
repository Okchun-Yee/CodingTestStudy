#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<bool> visited;
vector<vector<int>> graph;
int cnt = 0;

void DFS(vector<vector<int>> computers, int current) {
    // 방문 처리
    visited[current + 1] = true;

    for (int next = 0; next < computers[current].size(); next++) {
        if (next == current || visited[next + 1] != false || computers[current][next] != 1)
            continue;
        DFS(computers, next);
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    visited.assign(n + 1, false);
    vector<int> ans;

    for (int current = 0; current < computers.size(); current++) {
        if (visited[current+1] != false) continue;

        for (int next = 0; next < computers[0].size(); next++) {
            if (current == next || computers[current][next] == 0) continue;
            DFS(computers, next);
        }
        ans.push_back(current + 1);
    }
    
    answer = ans.size();
    return answer;
}