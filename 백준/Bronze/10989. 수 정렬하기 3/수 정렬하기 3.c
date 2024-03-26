#include <stdio.h>
#include <stdlib.h>

int main() {
  int N, count[10001] = {0,};
  short num;
  
  scanf("%d", &N);
  for(int i = 0; i < N; i++) {
    scanf("%hd", &num);
    count[num-1]++;
  }
  for(short i = 0; i < 10001; i++) {
    for(int j = 0; j < count[i]; j++) {
      printf("%d\n", i + 1);
    }
  }
  return 0;
}
