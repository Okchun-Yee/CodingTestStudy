#include <string>
#include <vector>
#include <iostream>
//#include "pros.h"

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer = { 0, 0 };

    
    for (int i = 0; i + 1 < words.size(); i++) {
        const string& current = words[i];
        const string& next = words[i + 1];
        bool dupCheck = false;

        char curFirst, curLast, nextFirst, nextLast;
        if (!current.empty()) {
            curFirst = current[0];
            curLast = current[current.size() - 1];
        }
        if (!next.empty()) {
            nextFirst = next[0];
            nextLast = next[next.size() - 1];
        }
        for (int j = 0; j < i; j++) {
            if (words[j] == next) {
                //cout << "check" << endl;
                dupCheck = true;
            }
        }
        if (curLast != nextFirst || dupCheck) {
            int person = (i + 1) % n + 1;
            int turn = (i + 1) / n + 1;
            /*cout << i << " " << n << " " << i % n << endl;
            cout << person << " " << turn << endl;*/
            answer = { person, turn };

            return answer;
        }
    }
    return answer;
}