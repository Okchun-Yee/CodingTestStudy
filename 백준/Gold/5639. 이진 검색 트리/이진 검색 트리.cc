#include <iostream>
#include <vector>
#include <map>

using namespace std;

vector<int> numbers;
map<int, pair<int, int>> tree;

void slove(int start, int end) {
	// 모든 Index를 탐색하면 종료 지점
	if (start > end) {
		return;
	}
	// 항상 현재 노드를 서브 트리의 root로 설정
	int root = numbers[start];
	// split = 값이 root 보다 커지는 지점 (오른쪽 서브 트리 시작점)
	int split = end + 1;
	// split 지점 탐색 (root 보다 값이 커지는 지점 탐색)
	for (int i = start + 1; i < end + 1; ++i){
		if (numbers[i] > root)
		{
			// slpit 설정
			split = i;
			break;
		}
	}
	// 1) 왼쪽 서브트리 생성 (root 보다 작음)
	slove(start + 1, split - 1);
	// 2) 오른쪽 서브트리 생성 (slipt을 start로 사용 root 보다 큼)
	slove(split, end);

	// 후위 순회 결과로 출력 
	// 재귀를 통해 "가상"의 이진 트리 생성 -> 출력을 마지막에 배치함 으로 재귀의 종료는 호출의 역순
	// 따라서 전위 순회 호출의 역순으로 cout이 호출 되어 후위 순회의 결과를 출력
	// EX. 50 30 20 순서의 전위 순회로 호출 -> 가상의 이진트리 재귀 -> 20 30 50 순으로 출력
	cout << root << endl;
}
int main() {
	int val;
	
	// 입력 개수를 특정하지않고 EOF가 나올 때 까지 입력을 받는 로직
	// 수동 테스트 시 예제 입력 후 enter -> Ctrl+Z 입력 후 enter
	while (cin >> val)
	{
		numbers.push_back(val);
	}
	slove(0, numbers.size() - 1);
	return 0;
}