#include <stdio.h>

int main(void) {
  int i, j, n;
  scanf("%d", &n);
  for (i = n; i > 0; i--) {
    for (j = 1; j <= n; j++) {
      if (i <= j)
        printf("*");
      else
        printf(" ");
    }
    printf("\n");
  }
}