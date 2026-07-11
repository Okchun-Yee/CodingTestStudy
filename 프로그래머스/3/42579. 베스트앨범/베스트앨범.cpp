#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;

    map<string, int> total;
    map<string, vector<pair<int, int>>> songs;

    for(int i=0;i<genres.size();i++){
        total[genres[i]] += plays[i];
        songs[genres[i]].push_back({plays[i], i});
    }

    vector<pair<string, int>> SL(total.begin(), total.end());
    // 장르 : 총 재생수
    sort(SL.begin(), SL.end(), [](const pair<string, int>& a, const pair<string, int>& b){
        return a.second > b.second;
    });
    // 장르 : <재생 수 , 고유번호>
    for(auto &p : songs){
        sort(p.second.begin(), p.second.end(), [](const pair<int, int>& a, const pair<int, int>& b){
            if (a.first != b.first) return a.first > b.first;
            return a.second < b. second;
        });
    }

    int count = 0;
    for(auto& p : SL){
        string genre = p.first;
        auto& list = songs[genre];
        
        answer.push_back(list[0].second);
        if(list.size() >= 2) answer.push_back(list[1].second);
    }
    
    return answer;
}