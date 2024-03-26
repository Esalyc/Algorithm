#include <stdio.h>

int counting[20000010] = {0,};

int main(void) {
  int N, M, inp;
  scanf("%d", &N);
  for(int i = 0; i < N; i++) {
    scanf("%d", &inp);
    counting[inp+10000050]++;
  }
  scanf("%d", &M);
  for(int i = 0; i < M; i++) {
    scanf("%d", &inp);
    printf("%d ", counting[inp+10000050]);
  }
  return 0;
}