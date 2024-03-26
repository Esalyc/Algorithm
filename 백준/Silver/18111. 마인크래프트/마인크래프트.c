#include <stdio.h>

int main(void) {
  int N, M, B;
  int top = 0, bot = 256;
  int cd[501][501];
  int cb[257] = {0,}, result[257] = {0,};
  
  scanf("%d%d%d", &N, &M, &B);
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < M; j++) {
      int inp;
      scanf("%d", &inp);
      cd[i][j] = inp;
      top = inp > top ? inp : top;
      bot = bot > inp ? inp : bot;
    }
  }

  for(int h = top; h >= bot; h--) {
    cb[h] = B;
    for(int i = 0; i < N; i++) {
      for(int j = 0; j < M; j++) {
        int diff = h - cd[i][j];
        if(diff >= 0) { //설치
          cb[h] -= diff;
          result[h] += diff;
          
        }
        else { //파괴
          cb[h] += -1 * diff;
          result[h] += -2 * diff;
        }
      }
    }
    if(cb[h] < 0) { //남은 블럭이 음수개면 블럭이 부족했던 것이므로 result[높이] = -1
      result[h] = -1;
    }
  }
  int min = 1999999999 , height;

  for(int i = top; i >= bot; i--) {
    if(result[i] < min && result[i] >= 0) {
      min = result[i];
      height = i;
    }
  }  

  printf("%d %d", min, height);
  
  return 0;
}