#include <string>
#include <vector>
#include <map>

using namespace std;

map <string, int> dict;

vector<int> solution(string msg) {
    vector<int> answer;
    int alpha = 26;
    for(int i = 0; i < alpha; i++){
        dict[string(1, 'A' + i)] = i + 1;
    }
    
    int i = 0;
    while(i < msg.size()){
        string cur(1, msg[i]);
        string next = "";
        
        int j = i + 1;
        
        while(j < msg.size() && dict.count(cur + msg[j])){
            cur += msg[j];
            j++;
        }
        
        if(j < msg.size()){
            dict[cur + msg[j]] = ++alpha;
        }
        
        if(dict.count(cur)){
            answer.push_back(dict[cur]);
        }
        i = j;
    }
    
    return answer;
}