#include <stdio.h>

int fbz(int n);
int fbo(int n);
int set[41] = {0,};

int main(void) {
  int N;
  scanf("%d", &N);
  for(int i = 0; i < N; i++) {
    int n;
    scanf("%d", &n);
    printf("%d %d\n", fbz(n), fbo(n));
  }

  return 0;
}

int fbz(int n) {
  switch(n) {
    case(0): n = 1; break;
    case(1): n = 0; break;
    default: 
      if(set[n] != 0) n = set[n];
      else {
        set[n] = fbz(n - 1) + fbz(n - 2);
        n = set[n];
      }
  }
  return n;
}

int fbo(int n) {
  switch(n) {
    case(0): n = 0; break;
    case(1): n = 1; break;
    default: 
      if(set[n+1] != 0) n = set[n+1];
      else {
      set[n+1] = fbo(n - 1) + fbo(n - 2);
      n = set[n+1];
      }
  }
  return n;
}