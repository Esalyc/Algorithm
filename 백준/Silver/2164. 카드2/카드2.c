#include <stdio.h>
#include <string.h>

int queue[1000000];
int sizeh, sizel = 0;

void popush() {
  queue[sizeh] = queue[sizel];
  sizel++;
  sizeh++;
}

void remv() {
  sizel++;
}

int main(void) {
  int N, num;
  scanf("%d", &N);
  sizeh = N;
  for(int i = 0; i < N; i++) {
    queue[i] = i + 1;
  }
  while(sizeh-sizel > 1) {
    remv();
    popush();
  }
  printf("%d", queue[sizel]);
  return 0;
}