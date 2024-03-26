#include <stdio.h>

int main(void) {
  int N, count = 0;
  scanf("%d", &N);
  int i = 666, tmp;
  while(1) {
    tmp = i;
    while(tmp > 665) {
      if(tmp % 1000 == 666) {
        count++;
        break;
      }
      else tmp /= 10;
    }
    if(count == N) break;
    i++;
  }
  printf("%d", i);
}