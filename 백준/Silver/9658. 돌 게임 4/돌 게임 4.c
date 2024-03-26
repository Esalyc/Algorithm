#include <stdio.h>

int main() {
  int N, stone[1000] = {0,};
  scanf("%d", &N);
  stone[1] = stone[3] = 0;
  stone[2] = stone[4] = stone[5] = 1;
  for (int i = 6; i <= N; i++) {
    if (stone[i - 1] == 1 && stone[i - 3] == 1 && stone[i - 4] == 1) stone[i] = 0;
    else stone[i] = 1; 
  }
  printf("%s", (stone[N] == 1) ? "SK" : "CY");
  return 0;
}
