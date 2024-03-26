#include <stdio.h>
#include <stdlib.h>

int compare();

int main() {
  int N;
  scanf("%d", &N);
  int *arrPtr = malloc(sizeof(int) * N);
  for(int i = 0; i < N; i++) {
    scanf("%d", &arrPtr[i]);
  }
  qsort(arrPtr, N, sizeof(int), compare);
  for(int i = 0; i < N; i++) {
    printf("%d\n", arrPtr[i]);
  }
  free(arrPtr);
  return 0;
}

int compare(const void* a, const void* b) {
  if (*(int*)a > *(int*)b) return 1;
  else if (*(int*)a < *(int*)b) return -1;
  else return 0; 

}

