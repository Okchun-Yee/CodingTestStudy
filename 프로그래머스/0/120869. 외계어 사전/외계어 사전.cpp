#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<string> spell, vector<string> dic) {
    int answer = 0;
    sort(spell.begin(), spell.end());
    string s;
    for (string c :spell) {
        s += c;
    }

    for (int i = 0; i < dic.size(); i++) {
        if (dic[i].size() == spell.size()) {
            sort(dic[i].begin(), dic[i].end());
            if (s == dic[i]) {
                answer = 1;
                return answer;
            }
        }
    }
    answer = 2;
    return answer;
}