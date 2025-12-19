#include <iostream>
#include <stack>
#include <string>

using namespace std;

void slove(string s) {
	stack<char> st;
	int answer = 0;
	int n = 1;
	bool isErr = false;
	char prec = NULL;

	for (char c : s) {
		if (c == '(') {
			st.push(c);
			n *= 2;
		}
		else if (c == '[') {
			st.push(c);
			n *= 3;
		}
		else if (c == ')') {
			if (st.empty() || st.top() != '(') {
				isErr = true;
				break;
			}
			if (prec != NULL && prec== '(')
				answer += n;
			st.pop();
			n /= 2;
		}
		else if (c == ']') {
			if (st.empty() || st.top() != '[') {
				isErr = true;
				break;
			}
			if (prec != NULL && prec == '[')
				answer += n;
			st.pop();
			n /= 3;
		}
		prec = c;
	}
	if (isErr || !st.empty()) {
		cout << 0;
	}
	else {
		cout << answer;
	}
}

int main() {
	string s;
	cin >> s;
	slove(s);

	return 0;
}