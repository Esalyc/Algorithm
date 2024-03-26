#include <stdio.h>

struct size{
  int w;
  int h;
  int grade;
}wh[50];

int main(void) {
  int N;
  scanf("%d", &N);
  for(int i = 0; i < N; i++) {
    scanf("%d%d", &wh[i].w, &wh[i].h);
  }
  for(int i = 0; i < N; i++) {
    wh[i].grade = 1;
    for(int j = 0; j < N; j++) {
      if(wh[i].w < wh[j].w && wh[i].h < wh[j].h) wh[i].grade++;
    }
    printf("%d ", wh[i].grade);
  }
  
  return 0;
}