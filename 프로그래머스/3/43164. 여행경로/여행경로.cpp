#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

map<string, vector<pair<string, bool>>> graph;

bool dfs(vector<vector<string>> &tickets, vector<string> &answer, int depth, string city)
{
    if (depth == tickets.size())
    {
        return true;
    }
    for(auto& next : graph[city]){
        if(next.second != true){
            next.second = true;
            answer.push_back(next.first);

            if(dfs(tickets, answer, depth+1, next.first)){
                return true;
            }

            next.second = false;
            answer.pop_back();
        }
    }
    return false;
}

vector<string> solution(vector<vector<string>> tickets)
{
    vector<string> answer;
    for (auto &t : tickets)
    {
        graph[t[0]].push_back({t[1], false});
    }
    for (auto &[key, val] : graph)
    {
        sort(val.begin(), val.end());
    }
    answer.push_back("ICN");
    dfs(tickets, answer, 0, "ICN");
    return answer;
}