#include <string>
#include <vector>
#include <queue>

using namespace std;
vector<bool> visited(50);

bool comparator(string a, string b){
    int diff = 0;
    for(int i = 0; i<a.size(); i++){
        if(a[i] != b[i]) diff++;
    }
    return diff == 1;
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    queue <pair<string, int>> que;
    
    que.push({begin, 0});

    while(!que.empty()){
        string current = que.front().first;
        int distance = que.front().second;
        que.pop();

        if(current == target){
            answer = distance;
            break;
        }
        
        for(int i=0;i<words.size();i++){
            if(!visited[i] && comparator(current, words[i])){
                visited[i] = true;
                que.push({words[i], distance + 1});
            }
        }
    }
    
    return answer;
}