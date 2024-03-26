#include <stdio.h>

int grid(int a, int count) {
  if(a < 0) return -1;  
  if(a % 5 == 0) return a / 5 + count;
  count++;
  return grid(a - 3, count);
}


int main(void) {
  int N;
  scanf("%d", &N);
  printf("%d", grid(N, 0));

  return 0;
}