#include <iostream>
#include <vector>

using namespace std;

long long combination3(long long n) {
    if (n < 3) return 0;
    return n * (n - 1) * (n - 2) / 6;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    vector<vector<int>> tree(N + 1);
    vector<pair<int, int>> edges; // 'D' 계산을 위해 간선 목록 저장

    for (int i = 0; i < N - 1; ++i) {
        int u, v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
        edges.push_back({ u, v });
    }

    long long cntD = 0;
    long long cntG = 0;

    // 'G' 트리 개수 계산
    // 모든 정점 i에 대해 degree(i)C3을 더함
    for (int i = 1; i <= N; ++i) {
        cntG += combination3(tree[i].size());
    }

    // 'D' 트리 개수 계산
    // 모든 간선 (u, v)에 대해 (degree(u)-1) * (degree(v)-1)을 더함
    for (const auto& edge : edges) {
        long long u = edge.first;
        long long v = edge.second;
        cntD += (long long)(tree[u].size() - 1) * (long long)(tree[v].size() - 1);
    }

    // 최종 비교
    if (cntD > 3 * cntG)
        cout << 'D' << '\n';
    else if (cntD < 3 * cntG)
        cout << 'G' << '\n';
    else // cntD == 3 * cntG
        cout << "DUDUDUNGA" << '\n';

    return 0;
}