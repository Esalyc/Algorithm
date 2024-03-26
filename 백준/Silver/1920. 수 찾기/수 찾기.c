#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b);
int binsearch(int data[], int n, int target);

int main(void) {
  int N, M, inp;
  scanf("%d", &N);
  int *Narr = (int*)malloc(sizeof(int) * N);
  for(int i = 0; i < N; i++) {
    scanf("%d", &Narr[i]);
  }
  qsort(Narr, N, sizeof(int), compare);
  scanf("%d", &M);
  for(int i = 0; i < M; i++) {
    scanf("%d", &inp);
    printf("%d\n", binsearch(Narr, N, inp));
  }
  return 0;
}

int compare(const void *a, const void *b) {
  int x = *(int*)a;
  int y = *(int*)b;
  if(x>y) return 1;
  if(x<y) return -1;
  return 0;
}

int binsearch(int data[], int n, int target) {
  int low = 0;
  int high = n - 1;
  int mid;

  while(low<=high) {
    mid = (low + high) / 2;
    if(target > data[mid]) low = mid + 1;
    else if(target < data[mid]) high = mid - 1;
    else return 1;
  }
  return 0;
}
