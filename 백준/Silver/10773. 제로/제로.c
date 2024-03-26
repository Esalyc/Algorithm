#include <stdio.h>

int stack[100000];
int n = 0;


void push(int x) {
  stack[n] = x;
  n++;
  return;
}

void pop() {
  n--;
  stack[n] = '\0';
  return;
}

int main(void) {
  register int i;
  
  int K, inp, result = 0;
  scanf("%d", &K);
  for (i = 0; i < K; i++) {
    scanf("%d", &inp);
    if(inp == 0) pop();
    else push(inp);
  }
  for(i = 0; i < n; i++) {
    result += stack[i];
  }
  printf("%d\n", result);
  
  return 0;
}
