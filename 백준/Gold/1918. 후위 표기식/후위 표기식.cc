#include <iostream>
#include <vector>
#include <stack>
#include <cctype>

using namespace std;

// 연산자 우선순위 헬퍼
int getPriority(char op) {
	if (op == '*' || op == '/') return 2;
	if (op == '+' || op == '-') return 1;
	return 0;
}

void solution(string s) {
	stack<char> op;
	for (char c : s) {
		if (isalpha(c)) {
			cout << c;
		}
		else if (c == '(') {
			op.push(c);
		}
		else if (c == ')') {
			while (!op.empty() && op.top() != '(')
			{
				cout << op.top();
				op.pop();
			}
			if(!op.empty()) op.pop();
		}
		else {
			if (op.empty()) {
				op.push(c);
			}
			else {
				if(getPriority(op.top()) < getPriority(c)) op.push(c);
				else {
					while (!op.empty() && getPriority(op.top()) >= getPriority(c))
					{
						cout << op.top();
						op.pop();
					}
					op.push(c);
				}
			}
		}
	}
	while (!op.empty())
	{
		cout << op.top(); 
		op.pop();
	}
}
int main() {
	string s; cin >> s;
	solution(s);
}