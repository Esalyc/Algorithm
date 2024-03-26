#include <stdio.h>

int fbz(int n);
int fbo(int n);
int setz[41] = {0,};
int seto[41] = {0,};

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
      if(setz[n] != 0) n = setz[n];
      else {
        setz[n] = fbz(n - 1) + fbz(n - 2);
        n = setz[n];
      }
  }
  return n;
}

int fbo(int n) {
  switch(n) {
    case(0): n = 0; break;
    case(1): n = 1; break;
    default: 
      if(seto[n] != 0) n = seto[n];
      else {
      seto[n] = fbo(n - 1) + fbo(n - 2);
      n = seto[n];
      }
  }
  return n;
}