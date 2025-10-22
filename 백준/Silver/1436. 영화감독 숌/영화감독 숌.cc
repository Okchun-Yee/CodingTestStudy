#include <iostream>
#include <vector>

using namespace std;
#define NUM 666

int N, cnt = 0;
bool slove(long long n) {
	while (n >= 666) {
		if (n % 1000 == 666) {
			return true;
		}
		n /= 10;
	}
	return false;
}

int main() {
	cin >> N;
	int num = NUM;
	while (cnt != N) {
		if (slove(num)) {
			cnt++;
		}
		num++;
	}
	cout << num - 1;
	return 0;
}