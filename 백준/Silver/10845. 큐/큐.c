#include <stdio.h>
#include <string.h>

int queue[10000] = {0,};
int sizeh = 0, sizel = 0;

void push(int a) {
  queue[sizeh] = a;
  sizeh++;
}

void pop() {
  if(sizeh-sizel != 0) {
    printf("%d\n", queue[sizel]);
    queue[sizel] = 0;
    sizel++;
  }
  else printf("-1\n");
}

void size() {
  printf("%d\n", sizeh-sizel);
}

void empty() {
  if(sizeh-sizel == 0) printf("1\n");
  else printf("0\n");
}

void front() {
  if(sizeh-sizel != 0) printf("%d\n", queue[sizel]);
  else printf("-1\n");
}

void back() {
  if(sizeh-sizel != 0) printf("%d\n", queue[sizeh-1]);
  else printf("-1\n");
}


int main(void) {
  int N, num;
  char inp[10];
  scanf("%d", &N);
  for(int i = 0; i < N; i++) {
    scanf("%s", inp);
    if(strcmp(inp, "push")==0) {
      scanf("%d", &num);
      push(num);
    }
    else if(strcmp(inp, "pop")==0) {
      pop();
    }
    else if(strcmp(inp, "size")==0) {
      size();
    }
    else if(strcmp(inp, "empty")==0) {
      empty();
    }
    else if(strcmp(inp, "front")== 0) {
      front();
    }
    else if(strcmp(inp, "back")== 0) {
      back();
    }
    
  }
  return 0;
}
