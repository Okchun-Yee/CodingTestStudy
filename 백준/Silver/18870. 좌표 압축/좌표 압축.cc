#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int N;
vector<int> graph;
void slove() {

}
int main() {
	cin >> N;
	graph.resize(N);
	for (int i = 0; i < N; ++i) {
		cin >> graph[i];
	}
	vector<int> temp = graph;
	// 값 순서대로 정렬 -> 중복 뒤로 이동 -> 중복 부분 제거 = 중복 없는 임시 배열 완성
	sort(temp.begin(), temp.end());
	auto it = unique(temp.begin(), temp.end());
	temp.erase(it, temp.end());

	map<int, int> answer;
	for (int i = 0; i < temp.size(); ++i) {
		answer[temp[i]] = i;
	}
	for (int n : graph) {
		cout << answer[n] << " ";
	}
	return 0;
}