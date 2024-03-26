#include <stdio.h>
#include <string.h>
#include <stdlib.h>


char* delSp(char str[]); 

int main(void) {
  int N, len, end, result;
  char inp[51];
  scanf("%d", &N);
  for(int i = 0; i < N; i++) {
    scanf("%s", inp);
    len = strlen(inp);
    while(len > 0) {
      result = 1;
      end = 0;
      for(int j = 0; j < len - 1; j++) {
        if(inp[j] == '(' && inp[j+1] == ')') {
          inp[j] = ' ';
          inp[j+1] = ' ';
          end = 1;
          break;
        }
      }
      if(end == 0) {
        result = 0;
        break;
      }
      strcpy(inp, delSp(inp));
      len = strlen(inp);
    }
    printf("%s\n", (result == 1) ? "YES" : "NO"); 
  } 
}

char* delSp(char* str) {
  int k = 0;
  char* s = (char*)malloc(sizeof(char)*51);
  for (int i = 0; i < strlen(str); i++) {
    if (str[i] != ' ') s[k++] = str[i];
  }
  
  return s;
}