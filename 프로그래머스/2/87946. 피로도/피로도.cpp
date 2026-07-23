#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int visited[8];

int dfs(int k, vector<vector<int>>& dungeons, int depth){
    if(k <= 0 || depth == dungeons.size()){
        return depth;
    }
    
    int best = depth;
    
    for(int i =0; i< dungeons.size(); i++){
        if(visited[i] || k < dungeons[i][0]) continue;
        
        visited[i] = 1;
        best = max(best, dfs(k - dungeons[i][1], dungeons, depth + 1));
        visited[i] = 0;
    }
    return best;
}

int solution(int k, vector<vector<int>> dungeons) {
    int answer = dfs(k, dungeons, 0);
    return answer;
}