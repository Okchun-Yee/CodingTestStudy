#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int N;
vector<vector<int>> matrix;

/// <summary>
/// * K = 경유지
/// * i = 출발지
/// * j = 도착지
/// * 직항 = i->j
/// * 경유 = i->k, k->j = i->j가 존재한다.
/// </summary>
void BFS(int startNode) {
	for (int k = 0; k < N; ++k)
		for (int i = 0; i < N; ++i)
			for (int j = 0; j < N; ++j)
				if (matrix[i][k] == 1 && matrix[k][j] == 1)
					matrix[i][j] = 1;
	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	matrix.assign(N, vector<int>(N));
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j){
			cin >> matrix[i][j];
		}
	}
	BFS(0);

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cout<< matrix[i][j]<<" ";
		}
		cout << "\n";
	}
	return 0;
}