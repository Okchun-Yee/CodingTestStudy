#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

//전역 변수
int row, col;
vector<vector<char>> matrix;
vector<vector<bool>> visited; //방문 지점 표시

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

vector<pair<int, int>> cluster; //클러스터 파악

//바닥 검사
bool bc(const vector<pair<int, int>>& c) {
	for (auto& p : c) 
		if (p.first == row - 1) 
			return true;
	return false;
}
//충돌 후 -> 상하좌우 미네랄 탐색
bool cf(const vector<pair<int, int>>& c) {
	for (int i = 0; i < c.size(); i++) {
		int x = c[i].first + 1;
		int y = c[i].second;

		if (x == row - 1 || (matrix[x][y] == 'x' && find(c.begin(), c.end(), make_pair(x, y)) == c.end())) return false;
	}
	return true;
}
bool dm(int h, bool RL, int& bx, int& by) {
	int r = row - h;
	if (RL) {
		for (int i = 0;i < col;i++) {
			if (matrix[r][i] == 'x') {
				matrix[r][i] = '.';
				bx = r; by = i;
				return true;
			}
		}
	}
	else {
		for (int i = col - 1;i >= 0;i--) {
			if (matrix[r][i] == 'x') {
				matrix[r][i] = '.';
				bx = r; by = i;
				return true;
			}
		}
	}
	return false;
}
void dfs(int x, int y) {
	visited[x][y] = true;
	cluster.push_back({ x, y });

	for (int i = 0; i < 4;i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || nx >= row || ny < 0 || ny >= col) continue;
		if (!visited[nx][ny] && matrix[nx][ny] == 'x') {
			dfs(nx, ny);
		}
	}
}
void fc(vector<pair<int, int>>& c) {
	for (auto& p : c) {
		matrix[p.first][p.second] = '.';
	}
	int fallDist = 0;
	bool canFall = true;

	while (canFall) {
		for (auto& p : c) {
			int nx = p.first + fallDist + 1;
			if (nx >= row || (matrix[nx][p.second] == 'x' && find(c.begin(), c.end(), make_pair(nx, p.second)) == c.end())) {
				canFall = false;
				break;
			}
		}
		if (canFall) fallDist++;
	}
	for (auto& p : c)matrix[p.first + fallDist][p.second] = 'x';
}
void printMat() {
	// 출력 확인용
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			cout << matrix[i][j];
		}
		cout << "\n";
	}
}
int main() {
	cin >> row >> col;
	matrix.assign(row, vector<char>(col));

	//동굴 행렬
	for (int i = 0; i < row; i++) {
		string line;
		cin >> line;  // 한 줄씩 입력받기
		for (int j = 0; j < col; j++) {
			matrix[i][j] = line[j];
		}
	}

	//막대 횟수 결정
	int n = 0; cin >> n;
	vector<int> num(n);
	for (int i = 0;i < n;i++) {
		cin >> num[i];
	}

	for (int i = 0;i < n;i++) {
		int bx = -1, by = -1;
		bool RL = (i % 2 == 0);

		if (!dm(num[i], RL, bx, by)) continue;

		visited.assign(row, vector<bool>(col, false));

		for (int j = 0;j < 4;j++) {
			int nx = bx + dx[j], ny = by + dy[j];
			if (nx < 0 || nx >= row || ny < 0 || ny >= col) continue;
			if (matrix[nx][ny] == 'x' && !visited[nx][ny]) {
				cluster.clear();
				dfs(nx, ny);
				if (!bc(cluster) && cf(cluster)) fc(cluster);
			}
		}
	}
	printMat();
	return 0;
}
