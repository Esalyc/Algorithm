#include <stdio.h>

int main(void) {
  int N, count = 0;
  int dohwaji[100][100] = {0,};
  int inp[2][100];
  scanf("%d", &N);
  for(int i = 0; i < N; i++) {
    scanf("%d%d", &inp[0][i], &inp[1][i]);
    for(int j = 0; j < 10; j++) {
      for(int k = 0; k < 10; k++) {
        if(dohwaji[inp[0][i]+j][inp[1][i]+k] == 1) count++;
        dohwaji[inp[0][i]+j][inp[1][i]+k] = 1;
      }
    }
  }
  printf("%d", 100 * N - count);
  
  
  return 0;
}