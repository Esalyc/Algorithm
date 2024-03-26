#include <stdio.h>

int div2(int N) {
  int count = 0;
  while(1) {
    if(N % 2 == 0) {
      count++;
      N /= 2;
    }
    else break;
  }
  return count;
}

int div5(int N) {
  int count = 0;
  while(1) {
    if(N % 5 == 0) {
      count++;
      N /= 5;
    }
    else break;
  }
  return count;
}

int main(void) {
  int N;
  int arr2[500], arr5[500];
  int count2 = 0, count5 = 0;
  scanf("%d", &N);
  
  for(int i = 0; i < N; i++) {
    count2 += div2(N-i);
    count5 += div5(N-i);
  }
  printf("%d", (count2 > count5) ? count5 : count2);


  return 0;
}