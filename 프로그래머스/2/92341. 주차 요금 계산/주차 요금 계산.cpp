#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    map<string, int> times;
    map<string, int> during;
    
    int last = (23 * 60) + 59;
    for(string s : records){
        int time = stoi(s.substr(0, 2)) * 60 + stoi(s.substr(3, 2));
        string carnum = s.substr(6, 4);
        string cmd = s.substr(11);
        
        if(cmd == "IN"){
            times[carnum] = time;
        }
        else {
            during[carnum] += time - times[carnum];
            times.erase(carnum);
        }
    }
    
    for (auto& p : times){
        during[p.first] += last - p.second;
    }
    
    for(auto& p : during){
        int total = 0;
        
        if(p.second <= fees[0]) answer.push_back(fees[1]);
        else {
            total = (p.second - fees[0] + fees[2] - 1) / fees[2] * fees[3] + fees[1]; 
            answer.push_back(total);
        }
    }
    return answer;
}