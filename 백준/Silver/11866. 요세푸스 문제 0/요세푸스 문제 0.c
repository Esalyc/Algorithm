#include <stdio.h>

int main(void) {
  int N, K, count = 0, out = 0;
  int arr[1000] = {0,};
  scanf("%d%d", &N, &K);
  printf("<");
  while(N != out) {
    for(int i = 1; i <= N; i++) {
      
      if(arr[i] == -1) continue;
      count++;
      if(count == K) {
        if(N - out == 1) {
          printf("%d", i);
          out++;
          break;
        }
        count = 0;
        printf("%d, ", i);
        arr[i] = -1;
        out++;
      }
    }
  }  
  printf(">");
}


