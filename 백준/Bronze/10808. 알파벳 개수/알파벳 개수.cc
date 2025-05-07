#include <stdio.h>
#include <string.h>
// [baekjoon] 10808번 - 알바벳 개수

int main() {

	char S[101];
	int cf[123] = { 0 };
	scanf("%s", &S);

	int i = 0;
	while (S[i] != '\0') {
		cf[S[i]]++;
		i++;
	}

	for (int j = 97; j <= 122; j++) {
		printf("%d ", cf[j]);
	}

}