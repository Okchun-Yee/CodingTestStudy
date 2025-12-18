#include <vector>
#include <deque>
#include <iostream>

using namespace std;

int N, M, cnt;
deque<int> q;
void fun1() {
    q.pop_front();
}
void fun2() {
    int n = q.front();
    q.pop_front();
    q.push_back(n);
    cnt++;
}
void fun3() {
    int n = q.back();
    q.pop_back();
    q.push_front(n);
    cnt++;
}
int main() {
    cin >> N >> M;
    vector<int> arr;
    for (int i = 0; i < M; ++i) {
        int c; cin >> c;
        arr.push_back(c);
    }

    for (int i = 0; i < N; ++i) {
        q.push_back(i + 1);
    }

    for (int i = 0; i < M; ++i) {
        int t = arr[i];
        
        int idx = 0;
        for (int k = 0; k < q.size(); ++k) {
            if (q[k] == t) {
                idx = k;
                break;
            }
        }

        if (idx < q.size() / 2 + 1) {
            while (q.front()!=t)
            {
                fun2();
            }
        }
        else 
            while (q.front()!=t)
            {
                fun3();
            }
        fun1();
    }
    cout << cnt;
    return 0;
}