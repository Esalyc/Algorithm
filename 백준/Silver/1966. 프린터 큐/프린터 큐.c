#include <stdio.h>

typedef struct {
  char P;
  int imp;
}queue;

queue q[1000];

int sizeh, sizel;
int count;

void popush() {
  q[sizeh] = q[sizel];
  sizel++;
  sizeh++;
}

void remv() {
  sizel++; 
}

int roop() {
  for(int i = sizel; i < sizeh; i++) {
    if(q[sizel].imp < q[i].imp) {
      popush();
      return roop();
    }
  }
  if(q[sizel].P) return count;
  remv();
  count++;
  return roop();
  
}

int main(void) {
  int c;
  int N, M;
  scanf("%d", &c);
  for(int i = 0; i < c; i++) {
    scanf("%d%d", &N, &M);
    count = 1;
    sizel = 0;
    for(int j = 0; j < N; j++) {
      scanf("%d", &q[j].imp);
      q[j].P = 0;
    }
    q[M].P = 1;
    sizeh = N;
    printf("%d\n", roop());
  }
  return 0;
}