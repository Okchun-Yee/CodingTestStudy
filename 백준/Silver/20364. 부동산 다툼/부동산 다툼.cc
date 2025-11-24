#include <iostream>
#include <vector>

using namespace std;

vector<bool> visited;
int N, Q;

// * target에서 root 까지 올라가는 방식
void slove(int target) {
    int answer = 0;         // 정답 위치
    int current = target;

    while (current > 0)
    {
        // 현 위치에 방문한적 있으면 정답 위치 갱신
        if (visited[current]) {
            answer = current;
        }
        // 부모 노드로 올라가기
        current /= 2;
    }
    if (answer == 0) {
        cout << 0 << "\n";
        visited[target] = true;
    }
    else {
        cout << answer << "\n";
    }
}

int main() {
    // 입출력 속도 향상 (필수)
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> target;
    cin >> N >> Q;
    visited.resize(N + 1, false);
    for (int i = 0; i < Q; ++i) {
        int t;
        cin >> t;
        target.push_back(t);
    }
    for (int i = 0; i < target.size(); ++i) {
        slove(target[i]);
    }
    return 0;
}