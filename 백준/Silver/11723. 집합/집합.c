#include <stdio.h>
#include <string.h>

char S[21] = {0,};

void addx(int x) {
  S[x] = 1;
}
void removex(int x) {
  S[x] = 0;
}
void checkx(int x) {
  printf("%d\n", S[x]);
}
void togglex(int x) {
  S[x] = !S[x];
}
void all() {
  for(int i = 1; i <=20; i++) S[i] = 1;
}
void empty() {
  for(int i = 1; i <=20; i++) S[i] = 0;
}

int main(void) {
  int M;
  char inpc[7];
  short inpx;
  scanf("%d", &M);
  for(int i = 0; i < M; i++) {
    scanf("%s", inpc);
    if(strncmp(inpc, "add", 3) == 0) {
      scanf("%hd", &inpx);
      addx(inpx);
    }
    else if(strncmp(inpc, "remove", 6) == 0) {
      scanf("%hd", &inpx);
      removex(inpx);
    }
    else if(strncmp(inpc, "check", 5) == 0) {
      scanf("%hd", &inpx);
      checkx(inpx);
    }
    else if(strncmp(inpc, "toggle", 6) == 0) {
      scanf("%hd", &inpx);
      togglex(inpx);
    }
    else if(strncmp(inpc, "all", 3) == 0) {
      all();
    }
    else if(strncmp(inpc, "empty", 5) == 0) {
      empty();
    }
  }
  return 0;
}