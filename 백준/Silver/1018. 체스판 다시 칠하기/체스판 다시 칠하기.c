#include <stdio.h>

int WB = 0;
int countB, countW;

int chessing(int y, int x, char arr[][51]) {
  countB = 0;
  countW = 0;
  
  for(int i = 0; i < 8; i++) {
    for(int j = 0; j < 8; j++) {
      if(arr[y+i][x+j] == ((WB == 0) ? 'B' : 'W')) countB++;
      else countW++;
      WB = !WB;
    }
    WB = !WB;
  }
  /*
  WB = !WB;
  
  for(int i = 0; i < 8; i++) {
    for(int j = 0; j < 8; j++) {
      if(arr[y+i][x+j] == ((WB == 0) ? 'B' : 'W')) countW++;
      WB = !WB;
    }
  }
  */

  return (countB <= countW) ? countB : countW;
}

int main(void) {
  int N, M, MIN = 64, temp;
  char chess[51][51];
  scanf("%d%d", &N, &M); // N = y, M = x
  for(int y = 0; y < N; y++) {
    scanf("%s", chess[y]);
  }
  for(int y = 0; y <= N-8; y++) {
    for(int x = 0; x <= M-8; x++) {
      temp = chessing(y, x, chess);
      if(temp < MIN) MIN = temp;
    }
  }
  printf("%d", MIN);
  
}

