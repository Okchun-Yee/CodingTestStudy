#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

vector<vector<int>> graph;
vector<vector<bool>> visited;

int N = 0; // 지도의 크기
int cnt = 0; // 단지 수 체크

// 상하좌우
int moveRow[] = { -1, 1, 0, 0 };	// row 이동
int moveCol[] = { 0, 0, -1, 1 };	// col 이동

void DFS(int row, int col) {
	if (visited[row][col])
		return;

	visited[row][col] = true;
	cnt++;
	for (int i = 0; i < 4; i++) {
		int n_row = row + moveRow[i];
		int n_col = col + moveCol[i];

		if (n_row >= 0 && n_row < N && n_col >= 0 && n_col < N && visited[n_row][n_col] != true) {
			if (graph[n_row][n_col] != 0) {
				
				DFS(n_row, n_col);
			}
		}
	}
}
int main() {
	cin >> N;
	graph.assign(N, vector<int>(N));
	visited.assign(N, vector<bool>(N));

	vector<int> answer; // 정답 배열
	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < N; j++) {
			int c = str[j] - '0';
			graph[i][j] = c;
		}
	}
	int count = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (graph[i][j] != 0 && visited[i][j] != true) {
				cnt = 0;
				count++;
				DFS(i, j);
				answer.push_back(cnt);
			}
		}
	}
	sort(answer.begin(), answer.end());
	cout << count << endl;

	for (int a : answer)
		cout << a << endl;
	return 0;
}