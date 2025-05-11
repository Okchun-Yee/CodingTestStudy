#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
//#include "pros.h"

using namespace std;

int sub_soluction(vector<int>& cards) {
    int startIndex = -1;
    int cnt = 0;

    for (int i = 0;i < cards.size();i++) {
        if (cards.at(i) != 0) {
            startIndex = i;
            break;
        }
    }
    if (startIndex == -1) {
        cout << "시작 할 수 없음!" << endl;
        return 0;
    }
    while (cards.at(startIndex) != 0) {
        int newIndex = cards.at(startIndex) - 1;
        cards.at(startIndex) = 0;
        startIndex = newIndex;
        cnt++;
    }
    return cnt;
}
int solution(vector<int> cards) {
    int answer = 0;
    vector<int>b;
    while (true)
    {
        int temp = sub_soluction(cards);
        b.push_back(temp);
        if (temp == 0) break;
    }
    sort(b.begin(), b.end());
    
    int i = b.size() - 1;
    answer = b.at(i) * b.at(i - 1);
    return answer;
}