#include <stdio.h>
#include <string.h>
#include <memory.h>
#include <stdlib.h>


int compare(const void* a, const void* b) {
  const char* str1 = (const char*)a;
  const char* str2 = (const char*)b;
  return strcmp(str1, str2);
}


int main(void) {
  char word[51], spl[3][51],result[2500][51];
  int count = 0;
  scanf("%s", word);
  const int len = strlen(word);
  for(int i = 1; i <= len-2; i++) {
    for(int j = 1; j <= len -1 -i; j++) {
      memset(spl, 0, sizeof(spl));
      strncpy(spl[0], word, i);
      strncpy(spl[1], word + i, j);
      strncpy(spl[2], word + i + j, len - i - j); //자르기
      for(int k = 0; k < 3; k++) {
        for(int l = 0; l < strlen(spl[k]) / 2; l++) {
          char temp;
          temp = spl[k][l];
          spl[k][l] = spl[k][strlen(spl[k])-l-1]; 
          spl[k][strlen(spl[k])-l-1] = temp;
        }
      }  //뒤집기
      
      for(int k = 0; k < 3; k++) {
        strcat(result[count], spl[k]);
      } //문자열합치기
      count++;
    }
  }
  qsort(result, count, sizeof(result[0]), compare);
  printf("%s", result[0]);

  return 0;
}