#include <stdio.h>
#include <string.h>

int stack[10000] = {0,};
int sizes = 0;

void push(int a) {
  stack[sizes] = a;
  sizes++;
}

void pop() {
  if(sizes > 0) {
    printf("%d\n", stack[sizes-1]);
    stack[sizes] = 0;
    sizes--;
  }
  else printf("-1\n");
}

void size() {
  printf("%d\n", sizes);
}

void empty() {
  if(sizes > 0) printf("0\n");
  else printf("1\n");
}

void top() {
  if(sizes > 0) printf("%d\n", stack[sizes-1]);
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
    else if(strcmp(inp, "top")==0) {
      top();
    }
    
  }
  return 0;
}
