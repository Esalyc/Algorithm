#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int compare(const void *a, const void *b){
  int *x = (int*)a;
  int *y = (int*)b;
  return *x - *y;
}

int main(void) {
  int n, k, avg = 0;
  
  scanf("%d", &n);
  if(n == 0) {
    printf("0");
    return 0;
  }
  
  int* inp = (int*)malloc(sizeof(int) * n);
  
  for(int i = 0; i < n; i++) {
    scanf("%d", &inp[i]);
  }
  qsort(inp, n, sizeof(int), compare);
  
  k = (int)floor(n * 0.15 + 0.5001);
  
  for(int i = k; i < n - k; i++) {
    avg += inp[i];
  }
  
  avg = floor(avg / (double)(n - k - k) + 0.50001);
  
  printf("%d", (int)floor(avg + 0.5));
  
  return 0;
}
