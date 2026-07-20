#include <string>
#include <vector>

using namespace std;

vector<bool> visited;

void dfs(const vector<vector<int>>& computers, int current){
    visited[current] = true;
    
    for(int next = 0; next < computers.size(); next++){
        if(computers[current][next] != 0 && visited[next] != true){
            dfs(computers, next);
        }
    }
}
int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    visited.assign(n + 1, false);
    
    for(int i=0; i < n; i++){
        if(visited[i] != false) continue;
        dfs(computers, i);
        answer++;
    }
    
    return answer;
}