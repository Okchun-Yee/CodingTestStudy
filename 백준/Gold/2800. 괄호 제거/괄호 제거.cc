#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;

vector<pair<int, int>> idx;
vector<string> str;
vector<bool> visited;

string s;

void slove(int depth, int index) {
	if (depth == 0) {
		string temp = "";
		for (int i = 0; i < s.length(); ++i) {
			if (!visited[i]) temp += s[i];
		}
		str.push_back(temp);
		return;
	}
	for (int i = index; i < idx.size(); ++i) {
		visited[idx[i].first] = true;
		visited[idx[i].second] = true;
		slove(depth - 1, i + 1);
		visited[idx[i].first] = false;
		visited[idx[i].second] = false;
	}

}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> s;
	visited.resize(s.length(), false);

	stack<int> stk;
	for (int i = 0; i < s.length(); ++i) {
		if (s[i] == '(')
			stk.push(i);
		else if (s[i] == ')') {
			idx.push_back({ stk.top(), i});
			stk.pop();
		}
	}
	for (int i = 1; i < idx.size() + 1; ++i) {
		slove(i, 0);
	}

	sort(str.begin(), str.end());
	str.erase(unique(str.begin(), str.end()), str.end());
	for (string c : str)
		cout << c << endl;
	return 0;
}