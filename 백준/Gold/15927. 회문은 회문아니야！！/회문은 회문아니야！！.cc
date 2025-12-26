#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool is_palindrome(string s) {
	string rs = s;
	reverse(rs.begin(), rs.end());

	return s == rs;
}
bool is_one(const string& s) {
	for (int i = 1; i < s.size(); ++i) {
		if (s[i] != s[0]) return false; // 하나라도 다르면 false
	}
	return true;
}
void slove(string s) {
	if (!is_palindrome(s)) {
		cout <<  s.size();
		return;
	}
	else {
		if (is_one(s)) {
			cout << -1;
		}
		else {
			cout << s.size() - 1;
		}
	}
}
int main() {
	string s;
	cin >> s;

	slove(s);
}