#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer(numbers.size());
    stack<int> st;
    for(int i = numbers.size() - 1; i >= 0; --i){
        int n = numbers[i];

        while (st.size() > 0)
        {
            /* code */
            if(st.top() > n) break;
            st.pop();
        }
        if(st.size() == 0) answer[i] = -1;
        else answer[i] = st.top();

        st.push(n);
    }
    return answer;
}