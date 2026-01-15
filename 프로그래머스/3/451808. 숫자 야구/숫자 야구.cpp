#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

extern string submit(int);

// S, B 계산 헬퍼
pair<int, int> getScore(int cand, int guess) {
    int c[4], g[4];
    for (int i = 3; i >= 0; --i) {
        c[i] = cand % 10; cand /= 10;
        g[i] = guess % 10; guess /= 10;
    }

    int s = 0, b = 0;
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (c[i] == g[j]) {
                if (i == j) s++;
                else b++;
            }
        }
    }
    return { s, b };
}

// 숫자 유효성 검사
bool isValid(int n) {
    bool used[10] = { false };
    for (int i = 0; i < 4; ++i) {
        int d = n % 10; n /= 10;
        if (d == 0) return false;
        if (used[d]) return false;
        used[d] = true;
    }
    return true;
}

int solution(int n) {
    // 1. 전체 가능한 숫자 미리 생성
    vector<int> numbers;
    numbers.reserve(3024);
    for (int i = 1234; i <= 9876; ++i) {
        if (isValid(i)) numbers.push_back(i);
    }

    // 2. 현재 정답 후보군
    vector<int> candidates = numbers;

    while (true) {
        int bestGuess = -1;

        // 처음은 무조건 1234
        if (candidates.size() == 3024) {
            bestGuess = 1234;
        }
        // 후보가 1~2개면 그냥 남은거 던짐 (계산 불필요)
        else if (candidates.size() <= 2) {
            bestGuess = candidates[0];
        }
        // [Minimax 알고리즘]
        else {
            int minWorstCase = 9999;

            // guess를 고를 때 전체에서 고르기
            // 후보군에서 고르면 범위가 한정됨
            for (int guess : numbers) {

                int counts[50] = { 0 };

                // guess로 분리될 후보군들 계산
                for (int other : candidates) {
                    if (guess == other) continue; // 자기 자신은 제외
                    pair<int, int> res = getScore(other, guess);
                    // 2차원 [i][j]를 1차원으로 쓰기 위한 방법
                    // 1S 2B의 경우 [1][2]에 저장하는 것이 아니라 [1 2]로 10의 자리는 S, 1의 자리는 B를 표현하는 방식
                    counts[res.first * 10 + res.second]++;
                }

                // 최악의 경우 크기
                int worstCase = 0;
                for (int cnt : counts) worstCase = max(worstCase, cnt);

                // 더 좋은 질문을 찾았다면 갱신
                if (worstCase < minWorstCase) {
                    minWorstCase = worstCase;
                    bestGuess = guess;
                }
                // 만약 성능이 똑같다면, 이왕이면 '정답 후보'에 있는 숫자를 우선함
                // -> 운 좋으면 맞출 수도 있으니까
                else if (worstCase == minWorstCase) {
                }
            }
        }

        string res = submit(bestGuess);
        if (res == "4S 0B") return bestGuess;

        int resS = res[0] - '0';
        int resB = res[3] - '0';

        vector<int> next_candidates;
        next_candidates.reserve(candidates.size());

        for (int cand : candidates) {
            pair<int, int> score = getScore(cand, bestGuess);
            if (score.first == resS && score.second == resB) {
                next_candidates.push_back(cand);
            }
        }
        candidates = next_candidates;
    }
    return 0;
}
