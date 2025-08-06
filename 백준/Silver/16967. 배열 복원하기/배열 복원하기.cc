#include <iostream>
#include <vector>

using namespace std;

int H, W, X, Y;
vector<vector<int>> arrB;

void printM(vector<vector<int>> arr) {
    // 입력 확인용 출력 (필요 시 제거 가능)
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
}
void slove() {
    vector<vector<int>> arrA(H, vector<int>(W));
    int ni = 0, nj = 0;

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (i >= X && j >= Y) {
                int result = arrB[i][j] - arrB[i - X][j - Y];
                arrB[i][j] = result;
                arrA[i][j] = result;
            }
            else { arrA[i][j] = arrB[i][j]; }
        }
    }

    printM(arrA);
}

int main() {
    cin >> H >> W >> X >> Y;

    // 전체 크기: (H + X) x (W + Y)
    arrB.assign(H + X, vector<int>(W + Y));

    // 배열 입력 받기
    for (int i = 0; i < H + X; ++i) {
        for (int j = 0; j < W + Y; ++j) {
            cin >> arrB[i][j];
        }
    }
    slove();
    return 0;
}
