#include <iostream>
#include <string>
#include <vector>
#include <climits>

#define SIZE 25

using namespace std;

vector<int> numbers;
vector<char> operators;

int mx[SIZE][SIZE], mn[SIZE][SIZE];

int calculate(int a, int b, char op) {
    if (op == '+') return a + b;
    if (op == '-') return a - b;
    if (op == '*') return a * b;
    return 0;
}


int main() {
    int len;
    string expression;

    cin >> len;
    cin >> expression;

    //최대 배열 최소 배열 초기화
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            mx[i][j] = INT_MIN;
            mn[i][j] = INT_MAX;
        }
    }

    //수식을 숫자와 연산자로 분리
    for (int i = 0; i < len; i++) {
        if (i % 2 == 0) {
            mx[i][i] = expression[i] - '0';
            mn[i][i] = expression[i] - '0';
        }
    }

    for (int size = 3; size <= len; size += 2) {
        for (int i = 0; i < len; i+=2) {
            int j = i + size - 1;
            if (j >= len) continue;

            for (int k = i + 1; k < j; k+=2) {
                mx[i][j] = max(mx[i][j], calculate(mx[i][k - 1], mx[k + 1][j], expression[k]));
                mx[i][j] = max(mx[i][j], calculate(mx[i][k - 1], mn[k + 1][j], expression[k]));

                mx[i][j] = max(mx[i][j], calculate(mn[i][k - 1], mx[k + 1][j], expression[k]));
                mx[i][j] = max(mx[i][j], calculate(mn[i][k - 1], mn[k + 1][j], expression[k]));
                


                mn[i][j] = min(mn[i][j], calculate(mx[i][k - 1], mx[k + 1][j], expression[k]));
                mn[i][j] = min(mn[i][j], calculate(mx[i][k - 1], mn[k + 1][j], expression[k]));

                mn[i][j] = min(mn[i][j], calculate(mn[i][k - 1], mx[k + 1][j], expression[k]));
                mn[i][j] = min(mn[i][j], calculate(mn[i][k - 1], mn[k + 1][j], expression[k]));
            }
        }
    }
    cout << mx[0][len - 1];
    return 0;
}