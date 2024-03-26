#include <stdio.h>
#include <stdlib.h>    
#include <string.h>




int compare(const void* a, const void* b) {
    const char* str1 = (const char*)a;
    const char* str2 = (const char*)b;
    
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    
    if (len1 < len2) {
        return -1;  // 길이가 짧은 순으로 정렬
    } else if (len1 > len2) {
        return 1;
    } else {
        return strcmp(str1, str2);  // 길이가 같으면 사전 순으로 정렬
    }
}


int main(void) {
  int N;
  char arr[20000][51];
  scanf("%d", &N);
  for(int i = 0; i < N; i++) {
    scanf("%s", arr[i]);
  }
  qsort(arr, N, sizeof(arr[0]), compare);
  
  for(int i = 0; i < N; i++) {
    if(strcmp(arr[i], arr[i + 1]) != 0) { 
      printf("%s\n", arr[i]);
    }
  }
  
}
