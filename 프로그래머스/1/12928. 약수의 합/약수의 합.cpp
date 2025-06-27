#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
using namespace std;

int solution(int n) {
	if (n < 0 || n > 30000) {
		return -1;
	}
	int answer = 0;

	for (int i = 1; i <= sqrt(n); i++) {
		if (n % i == 0) {
			answer += i;
			if (i != n / i) {
				answer += n / i;
			}
		}
	}
	return answer;
}