#include <stdio.h>
#include <stdlib.h>

typedef struct{
  long long x;
  long long y;
}xy;

int compare(xy *a, xy *b);

int main(void) {
  int N;
  scanf("%d", &N);
  xy* arr = (xy*)malloc(N * sizeof(xy));
  for(int i = 0; i < N; i++) {
    scanf("%lld%lld", &arr[i].x, &arr[i].y);
  }
  qsort(arr, N, sizeof(xy), compare);

  for(int i = 0; i < N; i++) {
    printf("%lld %lld\n", arr[i].x, arr[i].y);
  }
  return 0;
}

int compare(xy *a, xy *b){
  if ((a->x * 200001 + a->y) > (b->x * 200001 + b->y))
    return 1;
  else if ((a->x * 200001 + a->y) < (b->x * 200001 + b->y))
    return -1;
  else
    return 0;
}



