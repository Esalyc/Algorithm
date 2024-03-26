#include <stdio.h>
#include <string.h>

int pan();

int stack[100];
int n;

void push(int x) {
  stack[n] = x;
  n++;
  return;
}

void pop(int x) {
  if(stack[n-1] == x) n--;
  else n -= 100;
  return;
}

int main(void) {
  pan();
  return 0;
}

int pan() {
  char str[110] = "";
  char inp;
  n = 0;
  for(int i = 0; ; i++) {
    scanf("%1c", &inp);
    str[i] = inp;
    if(inp == '.') break;
  }
  getchar();
  if(str[0] == '.') return 0;
  for(int i = 0; i < strlen(str) && n >= 0; i++) {
    if(str[i] == '(') push(0);
    if(str[i] == ')') pop(0);
    if(str[i] == '[') push(1);
    if(str[i] == ']') pop(1);
  }
  printf("%s", (n == 0) ? "yes\n" : "no\n");
  return pan();
}
