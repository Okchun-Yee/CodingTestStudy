    #include <string>
    #include <vector>
    #include <stack>
    #include <algorithm>

    using namespace std;

    string solution(string number, int k) {
        string answer = "";
        stack<char> st;
        int cnt = 0;
        for(int i = 0; i<number.size(); ++i){
            while(!st.empty() && st.top() < number[i] && cnt < k){
                st.pop();
                cnt++;
            }
            st.push(number[i]);
            
        }
        while (!st.empty())
        {
            answer += st.top();
            st.pop();
        }
        reverse(answer.begin(), answer.end());
        string s = "";
        for(int i = 0; i<number.size() - k; i++){
            s+= answer[i];
        }
        return s;
    }