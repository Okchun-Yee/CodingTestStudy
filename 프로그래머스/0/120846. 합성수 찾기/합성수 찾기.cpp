#include <stdlib.h>
#include <math.h>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n) {
	int answer = 0;
	int cnt = 0;
	for (int k = 1; k <= n; k++) {
		cnt = 0;
		for (int i = 1; i <= sqrt(k); i++) {
			if (k % i == 0) {
				cnt++;
				if (i != k / i) {
					cnt++;
				}
			}
		}
		if (cnt >= 3) 
		{
			//cout << k << endl;
			answer++;
		}
	}
	return answer;
}