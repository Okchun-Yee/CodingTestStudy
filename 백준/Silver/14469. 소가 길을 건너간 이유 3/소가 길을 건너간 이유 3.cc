#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<vector<int>> farm;

int slove() {
	//도착 시간 기준으로 정렬
	sort(farm.begin(), farm.end(), [](const vector<int>& a, const vector<int>& b) {
		return a[0] < b[0];
		});

	int result = 0;
	for (int i = 0; i < farm.size(); i++) {
		if (result < farm[i][0]) {
			result = farm[i][0];
			result += farm[i][1];
		}
		else {
			result += farm[i][1];
		}
	}
	return result;
}
int main() {
	cin >> N;
	farm.assign(N, vector<int>(2));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 2; j++) {
			cin >> farm[i][j];
		 }
	}
	int r = slove();
	cout << r;
    
    return 0;
}