#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<bool> visited;
vector<vector<int>> graph;
int cnt = 0;

void DFS(vector<vector<int>> computers, int current) {
    // 1) 현재 노드 방문 처리
    visited[current + 1] = true;
    // 2) 다음 노드 탐색 
    for (int next = 0; next < computers[current].size(); next++) {
        // 노드 탐색 조건
        // 1. 다음 노드가 현재 노드가 아닐 때 
        // 2. 방문하지 않은 노드 일 때
        // 3. 다음 노드가 0 이 아닐 때 (0 즉, 연결되지 않은 노드)
        if (next == current || visited[next + 1] != false || computers[current][next] != 1)
            continue;
        // 3) 조건 맞을 시 탐색
        DFS(computers, next);
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    visited.assign(n + 1, false);
    vector<int> ans;        // 정답 배열

    // * 전체 배열 사이즈 만큼 탐색
    for (int current = 0; current < computers.size(); current++) {
        // 1) 방문 검사
        if (visited[current+1] != false) continue;

        // 2) 한 개 컴퓨터씩 연결된 노드 탐색
        for (int next = 0; next < n; next++) {
            // * 노드 탐색 조건
            // 1. 다음 노드가 현재 노드가 아닐 때
            // 2. 다음 노드가 0이 아닐 때 (연결되어있는 노드만 탐색)
            if (current == next || computers[current][next] == 0) continue;
            DFS(computers, next);
        }
        // DFS가 끝날 때 마다 배열에 + 1
        ans.push_back(current + 1);
    }
    
    answer = ans.size();
    return answer;
}
